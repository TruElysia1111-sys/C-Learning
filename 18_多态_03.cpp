#include<iostream>
using namespace std;

/*
纯虚函数和抽象类
*/
//
// 由于父类中的虚函数通常是无意义的，主要调用子类重写的内容，因此可以在父类中用纯虚函数定义
// 纯虚函数写法：
// virtual 返回值类型 函数名(参数列表) = 0

// 抽象类： 当类中有了纯虚函数，这个类成为抽象类
// 抽象类无法实例化对象
// 子类必须重写抽象类中的纯虚函数，否则也属于抽象类

class Abstract {  // 抽象类： 无法实例化/子类必须重写父类的纯虚函数
public:
	virtual void func() = 0; // 纯虚函数
};
class A : public Abstract {
public:
	virtual void func() {  /* virtual 可写，可不写*/
		cout << "重写父类的纯虚函数" << endl;
	}
};

int main18() {
	//Abstract a; // 报错，无法实例化
	//new Abstract; // 报错，无法实例化

	//A a; // 如果不重写，则也属于抽象类，无法实例化
	A a;
	a.func();

	return 0;
}