#include<iostream>
#include<functional>	// 内建函数对象
using namespace std;

/*
算数仿函数
关系仿函数
逻辑仿函数
*/

/*
算数仿函数，实现四则运算
*/
void test13_01() {
	/* 取反(一元)*/
	negate<int>n;
	cout << "10取反 = " <<n(10)<< endl;
	/* 加法 */
	plus<int>p;
	cout << "10+20 = " << p(10, 20) << endl;
	/* 减法 */
	minus<int> mi;
	cout << "10-20 = " << mi(10, 20) << endl;
	/* 乘法 */
	multiplies<int> mul;
	cout << "13*17 = " << mul(13, 17) << endl;
	/* 除法 */
	divides<float> di;
	cout << "43/17 = " << di(43, 17) << endl;
	/* 取余 */
	modulus<int> mo;
	cout << "47//14 = " << mo(47, 14) << endl;
}
/*
关系仿函数
返回bool值
*/
void test13_02() {
	/* 等于 */
	equal_to<int> e;
	cout << "3==7? " << e(3, 7) << endl;
	/* 不等于 */
	not_equal_to<int> ne;
	cout << "3!=3? " << ne(3, 7) << endl;
	/* 大于 */
	greater<int> g;
	cout << "3>3? " << g(3, 3) << endl;
	/* 大于等于 */
	greater_equal<int> ge;
	cout << "3>=3? " << ge(3, 3) << endl;
	/* 小于 */
	less<int> l;
	cout << "3<3? " << l(3, 3) << endl;
	/* 小于等于 */
	less_equal<int> le;
	cout << "3<=3? " << le(3, 3) << endl;
}
/*
逻辑仿函数
*/
void test13_03() {
	/* 逻辑与 */
	logical_and<bool> la;
	cout << "True and False = " << la(true, false) << endl;
	/* 逻辑或 */
	logical_or<bool> lo;
	cout << "True or False = " << lo(true, false) << endl;
	/* 逻辑非 */
	logical_not<bool> ln;
	cout << "Not True = " << ln(true) << endl;
}

int main() {
	/* 算数仿函数 */
	test13_01();
	cout << endl << endl;
	/* 关系仿函数 */
	test13_02();
	cout << endl << endl;
	/* 逻辑仿函数 */
	test13_03();
	cout << endl << endl;
	return 0;
}