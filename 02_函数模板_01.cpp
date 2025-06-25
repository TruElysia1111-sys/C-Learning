#include<iostream>
using namespace std;

/*
函数模板：
建立一个通用函数，其函数返回值类型和形参类型可以不具体制定，用一个虚拟的类型来代表

语法：
	template<typename T>
	函数声明或定义

	template-----声明创建模板
	typename-----表明其后面的符号是一种数据类型，可以用class代替
	T------------通用的数据类型，名称可以替换，通常为大写字母
*/

/*  不使用模板: 每种数据类型的交换都得写一个交换函数，非常麻烦 */
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}
void test02_01() {	//	测试函数
	int a0 = 10;
	int b0 = 20;
	swapInt(a0, b0);
	cout << "a0 = " << a0 << endl;
	cout << "b0 = " << b0 << endl;

	double a1 = 1.15;
	double b1 = 2.187;
	swapDouble(a1, b1);
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;
}

/* 函数模板: */
template<typename T>   // 声明一个模板，告诉编译器，后面代码中T是一个通用数据类型
void Swap(T &a, T&b) {
	T temp = a;
	a = b;
	b = temp;
}
void test02_02() { // 测试函数
	// 两种使用模板的方式
	// 1. 自动类型推导
	int a0 = 1;
	int b0 = 2;
	Swap(a0, b0);
	cout << "a0 = " << a0 << endl;
	cout << "b0 = " << b0 << endl;
	// 2. 显示指定类型
	char a1 = 'a';
	char b1 = 'b';
	Swap<char>(a1, b1); // 指定传入数据的类型
	cout << "a1 = " << a1 << endl;
	cout << "b1 = " << b1 << endl;
}
int main02() {
	cout << "不使用模板" << endl;
	test02_01();
	cout << "使用模板" << endl;
	test02_02();



	system("pause");
	return 0;
}