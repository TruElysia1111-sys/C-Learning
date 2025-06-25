#include<iostream>
using namespace std;

/*
继承中出现的同名静态成员
*/
class Base {
public:
	static int m_A;   // 静态成员

	static void func() {
		cout << "Base下的静态函数" << endl;
	}
};
int Base::m_A = 100;  // 类内声明，类外初始化

class Son :public Base {
public:
	static int m_A;

	static void func() {
		cout << "Son 下的静态函数" << endl;
	}
};
int Son::m_A = 200;

int main14() {
	// 通过对象访问静态成员
	Son s;
	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;
	// 通过类名访问静态成员
	cout << "通过类名访问Son下的Son::m_A = " << Son::m_A << endl;
	cout << "通过父类名访问Base下的Base::m_A = " << Base::m_A << endl;
	cout << "通过子类名访问Base下的Son::Base::m_A = " << Son::Base::m_A << endl;

	// 通过对象访问静态成员函数
	cout << "通过对象" << endl;
	s.func(); // 直接调用自己的
	s.Base::func(); // 调用父类
	// 通过类名
	cout << "通过类名" << endl;
	Son::func();
	Son::Base::func();

	return 0;

}