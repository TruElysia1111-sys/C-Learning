#include <iostream>
using namespace std;

/*  静态多态： 函数重载和运算符重载
		静态多态的函数地址早绑定-编译阶段确定函数地址 */
		/*  动态多态： 派生类和虚函数实现运行时多态
				动态多态的函数地址晚绑定-运行阶段确定函数地址 */
				/*
					1. 继承关系
					2. 子类要重写父类的虚函数
				*/
				/*
					1. 父类的 指针/引用 指向子类的对象
					2.
				*/

class Animal {
	// 动物类，父类
public:
	// 不加virtual
	//void speak() {
	//	cout << "动物会说话" << endl;
	//}

	// 加了virtual，变为虚函数，地址晚绑定
	virtual void speak() {
		cout << "动物会说话" << endl;
	}
};

class Cat :public Animal {
	// 派生类，子类
public:
	void speak() {
		cout << "Cat可以说话" << endl;
	}
};
// 一个执行speak的函数
void doSpeak1(Animal& animal) {
	// 不加virtual
	// 地址早绑定，在编译阶段就确定了函数的地址
	// 在编译阶段就确定了animal类的函数地址

	// 加了virtual
	// 地址晚绑定，在运行阶段确定函数地址
	// 在运行阶段确定了cat类的函数地址
	animal.speak();
}


int main17() {
	Cat cat;
	// 父类引用，子类引用是允许的
	doSpeak1(cat);   // 动物会说话，调用了父类的speak()函数

	/*原理*/
	cout << "sizeof(animal)" << sizeof(Animal) << endl; // 8:virtual;4:no virtual
	return 0;
}


/*
	原理：
		virtual:
			有一个 vfptr： 虚函数指针
			指针指向vftable：  虚函数表
			虚函数表中记录虚函数的地址

			Animal的虚函数表：
				&Animal::speak()
			Cat的虚函数表，继承了父类的虚函数表：
				&Animal::speak()
				当子类重写了父类的虚函数，子类虚函数内部会替换成子类的徐函数地址
				&Cat::speak()

			当父类的指针或者引用指向子类对象的时候，发生多态


*/