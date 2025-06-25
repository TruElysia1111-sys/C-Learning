# include<iostream>
using namespace std;

/*
	继承同名成员的处理方式
*/
class Basement {
public:
	Basement() {
		m_A = 100;
	}
	int m_A;

	void func() {
		cout << "父类下的func函数" << endl;
	}

};
class OffSpring :public Basement {
public:
	OffSpring() {
		m_A = 200;
	}
	int m_A; // 同名成员属性

	void func() { // 同名成员函数
		cout << "子类下的func函数" << endl;
	}

};

int main13() {
	OffSpring offspring;
	cout << "子类的m_A = " << offspring.m_A << endl;  // 同名访问自己下面的
	cout << "父类下的m_A = " << offspring.Basement::m_A << endl; // 通过子类对象访问到父类中的同名成员 
																			// 对象.父类::成员
	cout << endl << endl << endl;
	offspring.func();	// 子类会隐藏父类所有的同名函数（包括重载的）
	offspring.Basement::func();
	return 0;
}
