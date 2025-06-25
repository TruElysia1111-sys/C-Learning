#include <iostream>
using namespace std;

/*
	函数调用运算符()重载

	仿函数： 重载后的使用方式非常像函数的调用，因此成为仿函数
*/

class Myinfo {
public:
	// 重载的函数调用运算符
	void operator()(string test) {
		cout << test << endl;
	}
};

class Myadd {
public:
	int operator()(int n1,int n2) {
		return n1 + n2;
	}
};


int main09() {

	Myinfo my;
	my("Hello world");   // 对象使用重载后的 (), 由于使用起来十分像函数，因此成为仿函数


	Myadd myadd;
	int rst = myadd(1, 2);   // 3
	cout << rst << endl;


	/* 使用匿名对象调用仿函数 类名() 当前行执行完立即释放 */  
	cout << Myadd()(100, 100) << endl;

	return 0;
}