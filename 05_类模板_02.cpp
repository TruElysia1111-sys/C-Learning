#include<iostream>
using namespace std;

// 类模板中的成员函数的创建时机是在调用时才创建
// 普通类中的成员函数的创造时机是在一开始就可以创建

class Person1 {
public:
	void showPerson1() {
		cout << "Show Person1" << endl;
	}
};
class Person2 {
public:
	void showPerson2() {
		cout << "Show Person2" << endl;
	}
};

template<class T>
class Myclass {	// 如果不调用，可以运行成功，因为在编译过程中不会创建，只有在调用的时候才会去创建类中的实例
public:
	T obj;

	// 类模板中的成员
	void func1() {
		obj.showPerson1();	
	}
	void func2() {
		obj.showPerson2();
	}
};

void test05_01() {
	// 出错，因为调用了m.func2(),报错
	Myclass<Person1>m;
	m.func1();
	//m.func2();
}


int main05() {
	test05_01();
	return 0;
}