#include<iostream>

using namespace std;


/*
	函数对象：
		重载函数调用操作符的类，其对象称为函数对象
		函数对象使用重载的()，也叫仿函数
		本质是一个类，不是一个函数

	特点：
		可以像普通函数一样调用，可以有参数，可以有返回值
		超出普通函数的状态，可以有自己的状态
		函数对象可以作为参数传递
*/

/*
普通函数一样调用，可以有参数，可以有返回值
*/
class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
void test11_01() {
	MyAdd myAdd;
	// 像普通函数一样调用
	cout << "MyAdd myAdd(10,10) = "<<myAdd(10, 10) << endl;
}
/*
超出普通函数的状态，可以有自己的状态
*/
class MyPrint {
public:

	MyPrint() {
		this->count = 0;
	}
	void operator()(string test) {
		this->count++;
		cout << test << endl;
	}
	int count;	// 内部自己的状态
};
void test11_02() {
	/* 记录状态 */
	MyPrint myPrint;
	myPrint("Hello World");
	myPrint("Hello World");
	myPrint("Hello World");
	myPrint("Hello World");
	myPrint("Hello World");
	myPrint("Hello World");

	cout << "MyPrint 调用了:" << myPrint.count << endl;
}
/*
函数对象可以作为参数传递
*/
void doPrint(MyPrint& mp, string test) {
	mp(test);
}
void test11_03() {
	MyPrint myPrint;
	doPrint(myPrint, "Hello,C++");
}

int main11() {
	test11_01();
	cout << endl << endl;
	test11_02();
	cout << endl << endl;
	test11_03();

	return 0;
}