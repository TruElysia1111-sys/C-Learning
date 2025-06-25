#include<iostream>
using namespace std;

template <class T1,class T2>
class Person85 {
public:
	Person85(T1 name, T2 age);
	//Person85(T1 name, T2 age) {
	//	this->m_name = name;
	//	this->m_age = age;
	//}
	void showPerson85() {
		cout << "姓名:	" << this->m_name << endl;
		cout << "年龄：	" << this->m_age << endl;
	}
	T1 m_name;
	T2 m_age;
};
//构造函数的类外实现：
template<class T1,class T2>
Person85<T1, T2>::Person85(T1 name, T2 age) {
	this->m_name = name;
	this->m_age = age;
}

int main08() {
	Person85<string ,int> p("Elysia", 16);
	p.showPerson85();
}