#include <iostream>
using namespace std;


class Person {
public:
	int m_A;
	int m_B;

	// 通过成员函数重载   +
	Person operator+ (Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;

		return temp;

	}


	Person operator+ (int a) {
		Person temp;
		temp.m_A = this->m_A + a;
		temp.m_B = this->m_B + a;

		return temp;
	}

	void showinfo() {
		cout << "m_A = " << this->m_A << endl;
		cout << "m_B = " << this->m_B << endl;
	}
};


// 通过全局函数重载   -
Person operator- (Person& p1, Person& p2) {
	Person temp;
	temp.m_A = p1.m_A - p2.m_A;
	temp.m_B = p1.m_B - p2.m_B;

	return temp;
}


int main04() {
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;

	Person p2;
	p2.m_A = 20;
	p2.m_B = 20;

	Person p3 = p1 + p2;
	Person p4 = p3 - p2;

	p3.showinfo();
	p4.showinfo();

	// 运算符重载可以发生函数重载
	Person p5 = p4 + 17;
	p5.showinfo();

	return 0;
}


