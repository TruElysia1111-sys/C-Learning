#include <iostream>
using namespace std;

/*
c++编译器至少给类提供四个函数：
	构造函数
	析构函数
	拷贝函数
	赋值，对属性进行值拷贝
*/

// 注意同一项目中的类名要进行区分（在正儿八经做项目时，否则会发生访问权限冲突
class Person1 {
public:
	Person1(int age) {
		/* 将传进来的age储存在堆区，并用指针来维护 */
		m_Age = new int(age);
	}
	~Person1() {
		/* 释放堆区数据 */
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL; // 浅拷贝会导致重复释放内存，导致程序崩溃，因此需要重载赋值操作
		}
	}

	/* 重载赋值操作 */
	 Person1 &operator=(Person1& p) {  // 返回自身，支持链式操作
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		// 重新开辟一段内存空间，用来赋值，防止不同类的值记录在一个内存地址
		m_Age = new int(*p.m_Age);

		return *this;  // 返回自身
	}
public:
	int* m_Age;
};


int main07() {
	Person1 p1(18);
	cout << "p1的年龄是:" << *(p1.m_Age) << endl;
	Person1 p2(20);
	cout << "p2的年龄是:" << *(p2.m_Age) << endl;

	p1 = p2;  // 赋值
	cout << "p1的年龄是:" << *(p1.m_Age) << endl;
	cout << "p2的年龄是:" << *(p2.m_Age) << endl;
	Person1 p3(11);
	p1 = p2 = p3;
	cout << "p1的年龄是:" << *(p1.m_Age) << endl;
	cout << "p2的年龄是:" << *(p2.m_Age) << endl;
	cout << "p3的年龄是:" << *(p3.m_Age) << endl;

	return 0;
}