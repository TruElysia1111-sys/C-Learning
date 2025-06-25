#include<iostream>
#include<queue>
using namespace std;

/*
queue:
队列容器，先进先出
push()
back()
front()
pop()
*/

/* 打印 */
void printq(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

/* 构造函数 */
void test06_01() {
	cout << "----构造--------------------" << endl;
	/* queue<int> que */
	queue<int> q1;
	for (int i = 0; i < 10; i++) {
		q1.push(i);
	}
	printq(q1);
	/* queue<int> q(q) */
	queue<int> q2(q1);
	printq(q2);
	/* = */
	queue<int> q3;
	q3 = q2;
	printq(q3);
}

/* 常用接口 */
void test06_02() {
	cout << "----接口--------------------" << endl;
	queue<int> q1;
	queue<int> q2;
	for (int i = 0; i < 10; i++) {
		q1.push(i);
	}
	cout << "q1 = ";
	printq(q1);
	cout << "q2 = ";
	printq(q2);

	/* push() */
	q1.push(10);
	cout << "q1.push(10) = ";
	printq(q1);

	/* pop() */
	q1.pop();
	cout << "q1.pop() = ";
	printq(q1);

	/* back() */
	cout << "q1.back() = " << q1.back() << endl;

	/* front() */
	cout << "q1.front() = " << q1.front() << endl;

	/* size() */
	cout << "q1.size() = " << q1.size() << endl;

	/* empty() */
	cout << "q1是否为空？ " << q1.empty() << endl;
	cout << "q2是否为空？ " << q2.empty() << endl;

}
int main06() {
	/* 构造 */
	test06_01();
	cout << endl << endl;
	/* 接口 */
	test06_02();
	cout << endl << endl;
	return 0;
}