#include<iostream>
#include<stack>
using namespace std;
/*
stack 栈

先进后出FIFO
top()
push()	入栈
pop()	出栈
*/

void prints(stack<int> s) {
	/* 查看栈顶 */
	while (!s.empty()) {
		// 查看栈顶元素
		cout << s.top() << "  ";
		// 出栈
		s.pop();
	}
	cout << endl;
}

/*
构造
*/
void test05_01() {
	cout << "----构造函数---------------------" << endl;
	/* stack<T> stk */
	stack<int> s1;
	for (int i = 0; i < 10; i++) {
		s1.push(i);
	}
	prints(s1);
	/* stack<T> stk() */
	stack<int> s2(s1);
	prints(s2);
	/* = */
	stack<int> s3;
	s3 = s2;
	prints(s3);
}
/*
常用接口
*/
void test05_02() {
	cout << "----常用接口---------------------" << endl;
	/* stack<T> stk */
	stack<int> s1;
	stack<int> s2;
	for (int i = 0; i < 10; i++) {
		s1.push(i);
	}
	cout << "s1 = ";
	prints(s1);
	cout << "s2 = ";
	prints(s2);
	/* 栈的大小 */
	cout << "栈的size是 " << s1.size() << endl;
	/* 入栈 */
	s1.push(11);
	cout << "出栈   ";
	prints(s1);
	/* 出栈 */
	s1.pop();
	cout << "出栈   ";
	prints(s1);
	/* 栈顶 */
	cout << "栈顶元素是 " << s1.top() << endl;
	/* 判断是否为空 */
	cout << "s1是否为空 " << s1.empty() << endl;
	cout << "s2是否为空 " << s2.empty() << endl;

}


int main05() {
	/* 栈的构造 */
	test05_01();
	cout << endl << endl;

	/* 栈的常用接口 */
	test05_02();
	cout << endl << endl;

	return 0;
}