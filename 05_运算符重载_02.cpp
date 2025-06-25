#include <iostream>
using namespace std;

// 左移运算符重载，可以输出自定义数据类型

class Person {
	// 友元访问私有属性
	friend ostream& operator<<(ostream& out, Person& p);
private:
	int m_A;
	int m_B;

	// 通过成员函数重载左移运算符
	// 一般不使用成员函数重载左移
	//void operator<<(cout) {

	//}
public:
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}
};

// 全局函数重载运算符
ostream & operator<<(ostream &out, Person &p) {
	out << "m_A = " << p.m_A << endl << "m_B = " << p.m_B << endl;
	return out;
}


int main05() {
	Person p1(1,2);

	cout << p1;
	return 0;
}