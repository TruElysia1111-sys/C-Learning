#include<iostream>
using namespace std;

/*
类模板对象做函数参数

- 指定传入的类型----直接显示对象的数据类型
- 参数模板化--------将对象中的参数变为模板进行传递
- 整个类模板化------将这个对象类型模板化进行传递

*/

// 类模板
template<class T1,class T2>
class Person63 {
public:
	Person63(T1 name, T2 age) {
		this->m_Name = name;
		this->m_Age = age;
	}
	void showP63() {
		cout << "Name:	" << this->m_Name << endl;
		cout << "Age:	" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};



// 1. 指定传入的类型
void printPerson1(Person63<string,int>&p) {
	cout << "test06_01:指定传入的类型" << endl;
	p.showP63();
}
void test06_01() {
	Person63<string, int> p("Elysia", 16);
	printPerson1(p);
}
// 2. 参数模板化
template<class T1,class T2>
void printPerson2(Person63<T1, T2>&p) {
	cout << "test06_02:参数模板化" << endl;
	cout << "T1推导的类型是： " << typeid(T1).name() << endl;	// string类型名很长
	cout << "T2推导的类型是： " << typeid(T2).name() << endl;
	p.showP63();
}
void test06_02() {
	Person63<string, int>p("Kevien", 17);
	printPerson2(p);
}
// 3. 整个类模板化
template<class T>
void printPerson3(T &p) {
	cout << "test06_03:整个类模板化" << endl;
	cout << "T推导的类型是： " << typeid(T).name() << endl;	

	p.showP63();
}

void test06_03() {
	Person63<string, int>p("Sakura", 19);
	printPerson3(p);

}






int main06() {
	test06_01();
	test06_02();
	test06_03();
	return 0;
}