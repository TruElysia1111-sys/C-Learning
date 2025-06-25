#include<iostream>
#include<list>
#include<random>
using namespace std;
/*
list	双向链表
节点:	数据域/指针域
采用动态存储分配，不会造成内存的浪费和溢出
链表执行插入和删除操作方便，直接使用指针即可，不用移动大量元素

额外耗费较大

push_front()
push_back()

pop_front()
pop_back()
insert()

begin()
end()

front()
back()
*/

void printl(list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
/*
构造
*/
void test07_01() {
	cout << "----构造----------" << endl;
	/* list<T> lst */
	list<int> l1;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}
	cout << "l1 = ";
	printl(l1);
	/* list(beg,end) */
	list<int> l2(l1.begin(), l1.end());
	cout << "l2 = ";
	printl(l2);
	/* list(n,elem) */
	list<int> l3(10, 1);
	cout << "l3 = ";
	printl(l3);
	/* list(&lst) */
	list<int> l4(l3);
	cout << "l4 = ";
	printl(l4);
}
/*
赋值和交换
*/
void test07_02() {
	cout << "----赋值----------" << endl;
	list<int> l1;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}
	cout << "l1 = ";
	printl(l1);
	/* assign(beg,end) */
	list<int> l2;
	l2.assign(l1.begin(), l1.end());
	cout << "l2 = ";
	printl(l2);
	/* assign(n,elem) */
	list<int> l3;
	l3.assign(10, 2);
	cout << "l3 = ";
	printl(l3);
	/* = */
	list<int> l4;
	l4 = l3;
	cout << "l4 = ";
	printl(l4);

	cout << endl << endl;
	cout << "----交换----------" << endl;
	list<int> l5(l1);
	list<int> l6;
	l6.assign(5, 1);
	cout << "交换前" << endl;
	cout << "l5 = ";
	printl(l5);
	cout << "l6 = ";
	printl(l6);
	cout << "交换后" << endl;
	l5.swap(l6);
	cout << "l5 = ";
	printl(l5);
	cout << "l6 = ";
	printl(l6);
}

/*
大小操作
*/
void test07_03() {
	cout << "----大小操作----------" << endl;
	list<int> l1;
	list<int> l2;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}
	cout << "l1 = ";
	printl(l1);
	cout << "l2 = ";
	printl(l2);
	
	/* size() */
	cout << "l1中元素的个数,size = " << l1.size() << endl;
	cout << "l2中元素的个数,size = " << l2.size() << endl;

	/* empty()*/
	cout << "l1.empty() = " << l1.empty() << endl;
	cout << "l2.empty() = " << l2.empty() << endl;

	/* resize(num) */
	l1.resize(7);
	cout << "l1.resize(7) = ";
	printl(l1);
	cout << "l1.size() = " << l1.size() << endl;

	/* resize(num,elem) */
	l2.resize(7, 2);
	cout << "l2.resize(7,2) = ";
	printl(l2);
	cout << "l2.size() = " << l2.size() << endl;
}

/*
插入和删除
*/
void test07_04() {
	cout << "----插入删除----------" << endl;
	list<int> l1;
	list<int> l2;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}
	l2 = l1;
	cout << "l1 = ";
	printl(l1);
	cout << "l2 = ";
	printl(l2);
	/* push_back(elem) */
	l1.push_back(10);
	cout << "l1最后添加一个10 = ";
	printl(l1);
	/* pop_back() */
	l1.pop_back();
	cout << "l1删除最后一位 = ";
	printl(l1);
	/* push_front(elem) */
	cout << "l1最后添加一个 -1 =";
	l1.push_front(-1);
	printl(l1);
	/* pop_front() */
	l1.pop_front();
	cout << "l1删除第一位 = ";
	printl(l1);
	/* insert(pos,elem) */
	l1.insert(l1.begin(),7);
	cout << "l1的第一位插入一个 7 = ";
	printl(l1);
	/* insert(pos,n,elem) */
	l1.insert(l1.begin(),6, 7);
	cout << "l1的第一位插入六个 7 = ";
	printl(l1);
	/* insert(pos,beg,end) */
	l1.insert(l1.end(), l2.begin(),l2.end());
	cout << "l1的第一位插入l2 = ";
	printl(l1);
	/* clear() */
	l2.clear();
	cout << "l2.clear() = ";
	printl(l2);
	/* erase(beg,end) */
	list<int>l3 = l1;
	cout << "l3 = ";
	printl(l3);
	cout << "l3.erase = ";
	l3.erase(l3.begin(), l3.end());
	printl(l3);
	/* erase(pos) */
	l1.erase(l1.begin());
	cout << "l1.erase(l1.begin()) = ";
	printl(l1);
	/* remove(elem) */
	l1.remove(7);
	cout << "l1.remove(7) = ";
	printl(l1);
}

/*
数据存储
*/
void test07_05() {
	cout << "----数据存储----------" << endl;
	list<int> l1;
	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}
	cout << "l1 = ";
	printl(l1);

	/* front() */
	cout << "front() = " << l1.front() << endl;
	/* back() */
	cout << "end() = " << l1.back() << endl;

	/* 迭代器 */
	/* 不支持迭代器随机访问 */
	
	//it = it + 3;	// 报错,不支持随机访问
	cout << "迭代器不支持随机访问,只能一次+1或者-1:" << endl;
	for (list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
/*
反转和排序
*/
bool myCompare(int v1, int v2) {
	return v1 > v2;	// 判断方法
}
void test07_06() {
	cout << "----数据存储----------" << endl;
	list<int> l1;
	for (int i = 0; i < 10; i++) {
		l1.push_back(rand()%20);
	}
	cout << "l1 = ";
	printl(l1);
	/* reverse() */
	l1.reverse();
	cout << "反转列表 = " ;
	printl(l1);
	/* sort() */
	l1.sort();
	cout << "升序排序 = " ;
	printl(l1);
	/* 反向sort() */
	l1.sort(myCompare);
	cout << "降序排序 = ";
	printl(l1);
}	

int main07() {

	/* 构造 */
	test07_01();
	cout << endl << endl;

	/* 赋值和交换 */
	test07_02();
	cout << endl << endl;

	/* 大小操作 */
	test07_03();
	cout << endl << endl;

	/* 插入和删除 */
	test07_04();
	cout << endl << endl;

	/* 数据存储 */
	test07_05();
	cout << endl << endl;

	/* 反转和排序 */
	test07_06();
	cout << endl << endl;

	return 0;
}