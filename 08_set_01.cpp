#include <iostream>
#include<set>
#include<random>
using namespace std;
/*
set 集合

所有元素会在插入时自动被排序

set/multiset 属于关联式容器，底层结构用二叉树实现

set容器中不允许有重复的元素
multiset容器中允许有重复的元素
*/

void printset(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " " ;
	}
	cout << endl;
}
void printmultiset(multiset<int>& s) {
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
/*
构造和赋值
*/
void test08_01() {
	cout << "----构造和赋值----------" << endl;
	/* set<int> s1 */
	set <int> s1;
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
	}
	cout << "s1 = ";
	printset(s1);
	/* set<int> s2(s1) */
	set<int> s2(s1);
	cout << "s2 = ";
	printset(s2);
	/* set 会自动排序 */
	set <int> s3;
	for (int i = 0; i < 10; i++) {
		s3.insert(rand()%17);
	}
	cout << "s3会自动排序 = ";
	printset(s3);
	/* set 不允许插入重复的值 */
	set <int> s4;
	for (int i = 0; i < 10; i++) {
		s4.insert(i%3);
	}
	cout << "s4不允许插入重复的值 = ";
	printset(s4);

	/* 赋值 = */
	set<int> s5;
	s5 = s3;
	cout << "s5 = s3 = ";
	printset(s5);
}
/*
大小和交换
*/
void test08_02() {
	cout << "----大小和交换--------------" << endl;
	set <int> s1;
	set <int> s2;
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
	}
	cout << "s1 = ";
	printset(s1);
	cout << "s2 = ";
	printset(s2);
	/* 大小 */
	cout << "s1.size() = " << s1.size() << endl;
	/* empty() */
	cout << "s1.empty() = " << s1.empty() << endl;
	cout << "s2.empty() = " << s2.empty() << endl;
	/* swap() */
	s1.swap(s2);
	cout << "s1.swap(s2)操作" << endl;
	cout << "s1 = ";
	printset(s1);
	cout << "s2 = ";
	printset(s2);
}
/*
插入和删除
*/
void test08_03() {
	cout << "----插入和删除--------------" << endl;
	set <int> s1;
	set <int> s2;
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
	}
	cout << "s1 = ";
	printset(s1);
	cout << "s2 = ";
	printset(s2);
	/* insert */
	s2.insert(1);
	s2.insert(10);
	cout << "s2.insert(1&10) = ";
	printset(s2);
	/* clear() */
	s2.clear();
	cout << "s2.clear() = ";
	printset(s2);
	/* erase(elem) */
	s1.erase(2);
	cout << "s1.erase(2) = ";
	printset(s1);
	/* erase(pos) */	
	s1.erase(s1.begin());
	cout << "s1.erase(s1.begin()) = ";
	printset(s1);
	/* erase(beg,end) */
	s1.erase(s1.begin(), s1.end());
	cout << "s1.erase(s1.begin(), s1.end()) = ";
	printset(s1);
	/*
	迭代器同list，不能直接+num，需要使用++操作或者--操作
	*/
}
/*
查找和统计
*/
void test08_04() {
	cout << "----查找和统计--------------" << endl;
	set <int> s1;
	set <int> s2;
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
	}
	cout << "s1 = ";
	printset(s1);
	cout << "s2 = ";
	printset(s2);
	/* find(key) */
	set<int>::iterator pos1 = s1.find(1);	// 用迭代器接受
	if (pos1 != s1.end()) {
		cout << "s1寻找1 结果是 ： " << *pos1 << endl;
	}
	else {
		cout << "s1中未找到1" << endl;
	}
	set<int>::iterator pos2 = s2.find(1);
	if (pos2 != s2.end()) {
		cout << "s2寻找1 结果是 ： " << *pos2 << endl;
	}
	else {
		cout << "s2中未找到1" << endl;
	}

	/* 统计 count() */
	int c = s1.count(1);
	cout << "s1中1的个数是 " << c << endl;
}
/*
multiset
*/
void test08_05() {
	cout << "----multiset--------------" << endl;
	set <int> s1;
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
	}
	cout << "s1 = ";
	printset(s1);
	/* multiset */
	multiset <int> s2;
	for (int i = 0; i < 10; i++) {
		s2.insert(i%4);
	}
	cout << "s2 = ";
	printmultiset(s2);
}
/*
改变排序规则
*/
class MyCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};
void test08_06() {
	cout << "----改变排序规则--------" << endl;
	set<int, MyCompare> s1;
	for (int i = 0; i < 10; i++) {
		s1.insert(i);
	}
	cout << "s1 = ";
	for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}cout << endl;
}
int main08() {
	// 构造和赋值
	test08_01();
	cout << endl << endl;

	// 大小和交换
	test08_02();
	cout << endl << endl;

	// 插入和删除
	test08_03();
	cout << endl << endl;

	// 查找和统计
	test08_04();
	cout << endl << endl;

	// multiset
	test08_05();
	cout << endl << endl;

	/* 排序规则 */
	test08_06();
	cout << endl << endl;
	return 0;
}