#include<iostream>
using namespace std;

class Myinteger {
	friend ostream& operator<<(ostream& out, Myinteger myint);
public:
	Myinteger() {
		m_Num = 0;
	}
	// 成员函数重载递增运算符
	Myinteger& operator++() {  // 引用： 为了对同一个数据参数进行操作
		// 前置运算符
		m_Num += 1;
		return *this;
	}

	Myinteger& operator++(int) {  // 引用： 为了对同一个数据参数进行操作，int代表一个占位参数
		// int 用于区分前置和后置递增
		// 后置运算符
		Myinteger temp = *this; // 记录当前值
		m_Num += 1;
		return temp;
	}
private:
	int m_Num;
};

// 重载左移运算符
ostream& operator<<(ostream& out, Myinteger myint) {
	out << myint.m_Num;
	return out;
}




int main06() {
	Myinteger myint;

	cout << ++myint << endl; // 1
	cout << myint++ << endl; // 1
	cout << myint << endl; // 2

	return 0;
}