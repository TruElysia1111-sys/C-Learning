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
void doSpeak(Animal& animal) {
	// 不加virtual
	// 地址早绑定，在编译阶段就确定了函数的地址
	// 在编译阶段就确定了animal类的函数地址

	// 加了virtual
	// 地址晚绑定，在运行阶段确定函数地址
	// 在运行阶段确定了cat类的函数地址
	animal.speak();
}


int main16() {
	Cat cat;
	// 父类声明，子类引用是允许的
	doSpeak(cat);   // 
	return 0;
}