#include<iostream>
using namespace std;

/*继承中构造函数和析构函数顺序*/

class Base {
public:
	Base() {
		cout << "Base构造函数" << endl;
	}
	~Base() {
		cout << "Base析构函数" << endl;
	}
};

class Offspring :public Base {
public:
	Offspring() {
		cout << "offspring构造函数" << endl;
	}
	~Offspring() {
		cout << "offspring析构函数" << endl;
	}
};
int main12() {
	//Base b;
	Offspring offspring;
	/*
	父类构造
	子类构造
	子类析构
	父类析构
	*/
	return 0;
}