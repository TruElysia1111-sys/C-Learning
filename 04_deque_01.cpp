#include <iostream>
#include <deque>
#include<random> // 使用随机函数
#include<algorithm>	// 排序算法sort
using namespace std;

/*
deque 容器
	双端数组，可以对头端进行插入和删除操作

	vector对于头部数据的插入效率低
	deque相对而言，对头部的插入删除比vector快
	vector访问元素速度比deque快

	front()
	back()
	begin()
	end()
	push_front()
	pop_front()
	pop_front()
	pop_back()
	insert()

	中控器维护每段缓冲区的内容-->使得deque像一片连续的内存空间，实际不是
*/
void printdeq(const deque<int> &d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " " ;
	}
	cout << endl;
}
/* 构造函数 */
void test04_01(){
	cout << "---构造函数-------------------" << endl;
	/* 默认构造 */
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printdeq(d1);

	/* deque(beg,end) */
	deque<int> d2(d1.begin(), d1.end());
	printdeq(d2);

	/* deque(n,elem) */
	deque<int> d3(10, 1);
	printdeq(d3);

	/* deque(&deq) */
	deque<int> d4(d3);
	printdeq(d4);
}
/*
赋值操作
*/
void test04_02() {
	cout << "---赋值操作-------------------" << endl;
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	cout << "d1 = ";
	printdeq(d1);

	/* = */
	deque<int> d2;
	d2 = d1;
	cout << "d2 = ";
	printdeq(d2);

	/* assign(beg,end) */
	deque<int> d3;
	d3.assign(d1.begin(), d1.end());
	cout << "d3 = ";
	printdeq(d3);

	/* assign(n,elem) */
	deque<int> d4;
	d4.assign(10, 13);
	cout << "d4 = ";
	printdeq(d4);
}
/*
大小操作
*/
void test04_03() {
	cout << "---大小操作-------------------" << endl; // 无容量操作
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	cout << "d1 = ";
	printdeq(d1);
	/* empty() */
	cout << "d1是否为empty?" << d1.empty() << endl;

	/* size() */
	cout << "d1的size是 " << d1.size() << endl;

	/* resize(num) */ // 重新指定长度num，变长则以默认元素填充，变短则删除末尾元素
	d1.resize(12);
	cout << "d1 = ";
	printdeq(d1);
	cout << "resize(12)之后d1的size是 " << d1.size() << endl;

	/* resize(num,elem) */
	d1.resize(15, 0);
	cout << "d1 = ";
	printdeq(d1);
	cout << "resize(15,0)之后d1的size是 " << d1.size() << endl;
}
/*
插入和删除
*/
void test04_04() {
	cout << "---插入删除-------------------" << endl; // 无容量操作
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	deque<int> d2(d1);
	cout << "d1 = ";
	printdeq(d1);
	cout << "d2 = ";
	printdeq(d2);
	deque<int> d3(d1);
	deque<int> d4(d1);

	/* push_back(elem) */
	d1.push_back(10);
	cout << "尾插 10, d1 = ";
	printdeq(d1);

	/* push_front(elem) */
	d2.push_front(-1);
	cout << "头插 -1, d2 = ";
	printdeq(d2);

	/* pop_back() */
	d1.pop_back();
	cout << "尾删 d1 = ";
	printdeq(d1);

	/* pop_front() */
	d2.pop_front();
	cout << "头删 d2 = ";
	printdeq(d2);

	/* insert(pos,elem) */
	d1.insert(d1.end(), 10);
	cout << "end() 位置插入 10, d1 = ";
	printdeq(d1);
	d2.insert(d2.begin(), -1);
	cout << "begin() 位置插入 -1, d2 = ";
	printdeq(d2);

	/* insert(pos,n,elem) */
	d1.insert(d1.end(), 5, 11);
	cout << "end() 位置插入5个11, d1 = ";
	printdeq(d1);
	d2.insert(d2.begin(), 5, -2);
	cout << "begin() 位置插入5个-2, d2 = ";
	printdeq(d2);

	/* insert(pos,beg,end) */
	d1.insert(d1.end(), d2.begin()+10,d2.end());
	cout << "end() 位置插入d2.begin()+10,d2.end(), d1 = ";
	printdeq(d1);
	d2.insert(d2.begin(), d1.begin(),d1.end()-10);
	cout << "end() 位置插入d1.begin(),d1.end()-10, d2 = ";
	printdeq(d2);

	/* clear() */
	cout << "d3 = ";
	printdeq(d3);
	d3.clear();
	cout << "d3.clear() = ";
	printdeq(d3);

	/* erase(beg,end) */
	cout << "d4 = ";
	printdeq(d4);
	d4.erase(d4.begin() + 1, d4.end() - 1);
	cout << "d4.erase(d4.begin() + 1, d4.end() - 1) = ";
	printdeq(d4);

	/* erase(pos) */
	d4.erase(d4.begin());
	cout << "d4.erase(d4.begin()) = ";
	printdeq(d4);
}
/*
数据存取
*/
void test04_05() {
	cout << "---数据存取-------------------" << endl; // 
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printdeq(d1);

	/* at(int idx) */
	cout << "d1.at(3) = ";
	cout << d1.at(3) << endl;

	/* [] */
	cout << "d1[5] = ";
	cout << d1[5] << endl;

	/* front(), back() */
	cout << "d1.front() = " << d1.front() << endl;
	cout << "d1.back() = " << d1.back() << endl;
}
/*
排序操作
*/
void test04_06() {
	cout << "---排序操作-------------------" << endl; // 
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(rand()%(51));
	}
	deque<int> d2(d1);
	cout << "d1,d2原始值为： " << endl;
	printdeq(d1);
	printdeq(d2);

	/* sort(beg,end) */
	sort(d1.begin(), d1.end());	// sort内部使用归并排序，时间复杂度nlogn
	cout << "sort(d1.begin(), d1.end()), d1 = ";
	printdeq(d1);

	sort(d2.begin() + 5, d2.end());
	cout<< "sort(d2.begin() + 5, d2.end()), d2 = ";
	printdeq(d2);
}
int main04() {
	// 构造
	test04_01();
	cout << endl << endl;

	// 赋值
	test04_02();
	cout << endl << endl;

	// 大小操作
	test04_03();
	cout << endl << endl;

	// 插入和删除
	test04_04();
	cout << endl << endl;

	// 数据存取
	test04_05();
	cout << endl << endl;

	// 排序操作
	test04_06();
	cout << endl << endl;

	return 0;
}