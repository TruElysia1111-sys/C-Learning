#include <iostream>
using namespace std;
#include <vector>
/*
	和数组非常相似，也称为单端数组

	数组是静态空间，vector 可以动态扩展

	并不是在远空间之后接续新空间
	而是找到更大的内存空间，将原数据拷贝到新空间，释放原空间
*/
void printv(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
/*

	vector 容器：

	front()
	v.rend()
	v.begin()
	insert()
	v.rbegin()
	v.end()
	back()
	push_back()
	pop_back()

	vector容器的迭代器是支持“随机访问”的迭代器
*/

/*
	构造函数
*/
void test03_01() {
	cout << "---构造函数--------------" << endl;
	/* 模板类 */
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);	// 在末尾添加元素
	}
	printv(v1);
	/* 区间方式构造 (拷贝) */
	vector<int> v2(v1.begin(), v1.end());
	printv(v2);
	/* 将n个elem拷贝给本身*/
	vector<int> v3(10, 1);	// 10个1
	printv(v3);
	/* 拷贝构造函数 */
	vector<int> v4(v1);
	printv(v4);
}
/*
赋值操作
*/
void test03_02() {
	cout << "---赋值--------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printv(v1);
	/* = */
	vector<int>v2;
	v2 = v1;
	printv(v2);
	/* assign(beg,end) */
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());	// 前闭后开
	printv(v3);
	/* assign(n,elem) */
	vector<int> v4;
	v4.assign(10, 2);
	printv(v4);
}
/*
容量和大小
*/
void test03_03() {
	cout << "---容量和大小--------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
	printv(v1);
	printv(v2);
	/* empty() 判断是否为空*/
	cout << "v1是否为空？" << v1.empty() << endl;
	cout << "v2是否为空？" << v2.empty() << endl;
	
	/* capacity() 容量*/
	cout << "v1的capacity()是 " << v1.capacity() << endl;	// 13
	cout << "v2的capacity()是 " << v2.capacity() << endl;

	/* size() 元素个数*/
	cout << "v1的size()大小是 " << v1.size() << endl;	// capacity >= size
	cout << "v2的size()大小是 " << v2.size() << endl;

	/* resize(int num) 重新指定长度*/
	v1.resize(19);
	printv(v1);
	cout << "resize之后 v1的capacity()是 " << v1.capacity() << endl;	// 
	cout << "resize之后 v1的size()大小是 " << v1.size() << endl;

	/* resize(int num, elem) 重新指定长度并以elem填充*/
	v2.resize(17, 13);
	printv(v2);
	cout << "resize之后 v2的capacity()是 " << v2.capacity() << endl;	// 
	cout << "resize之后 v2的size()大小是 " << v2.size() << endl;
}
/*
插入和删除
*/
void test03_04() {
	cout << "---插入和删除--------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printv(v1);
	/* push_back 尾插 */
	v1.push_back(15);
	cout << "push_back  ";
	printv(v1);

	/* pop_back 删除最后一个元素*/
	v1.pop_back();
	cout << "pop_back  ";
	printv(v1);

	/* insert(pos,ele) 第一个参数是迭代器 v1.begin() */
	v1.insert(v1.begin() + 4, 13);
	cout << "insert(pos,elem)  ";
	printv(v1);

	/* insert(pos,int num, ele) */
	v1.insert(v1.begin(),2, 14);
	cout << "insert(pos, int num, elem)  ";
	printv(v1);

	/* erase(pos) */
	v1.erase(v1.begin() + 1);
	cout << "erase(pos)  ";
	printv(v1);

	/* erase(start, end) */
	v1.erase(v1.begin() + 1, v1.end() - 5);
	cout << "erase(start,end)  ";
	printv(v1);

	/* clear */
	v1.clear();
	printv(v1);
}
/*
数据存取
*/
void test03_05() {
	cout << "---数据存取--------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printv(v1);
	/* at(int idx) */
	cout <<"v1索引为2的值为，v1.at(2):   " << v1.at(2) << endl;
	/* operator[] */
	cout << "v1[3]:   " << v1[3] << endl;
	/* front() */
	cout << "front():  " << v1.front() << endl;
	/* back() */
	cout << "back():   " << v1.back() << endl;
}
/*
互换容器
常用来收缩容器
	因为c++中每扩充一次容器，实际会扩充多个空位，以防下次再增加数据
	resize并不能收缩容器，只是修改了数据量的大小，vector不能访问后面的空间，而不是释放内存

	vector<int>(v).swap(v)常用来收缩容器：
		vector<int>(v)：	创建了一个匿名对象
							里面包含了v的所有数据，但是没有多余的内存空间，即size = capacity
		.swap(v)：			和原来的容器交换
							释放没有使用的内存
*/
void test03_06() {
	cout << "---互换容器--------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printv(v1);
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v2.push_back(i*i);
	}
	printv(v2);

	v1.swap(v2);
	cout << "v1: ";
	printv(v1);
	cout << "v2: ";
	printv(v2);

	cout << "常用来释放内存空间" << endl;
	vector<int> v3;
	for (int i = 0; i < 10; i++) {
		v3.push_back(i);
	}
	cout << "v3的内容，capacity，size分别是" << endl;
	printv(v3);
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;
	cout << "v3释放内存空间后的内容，capacity，size分别是" << endl;
	vector<int>(v3).swap(v3);
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;
}
/*
预留空间
*/
void test03_07() {
	cout << "---预留空间--------------" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "v1的capacity和size分别是  " << endl;
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	
	// 使用swap清除多余的内存空间
	cout << "使用swap清除多余的内存空间" << endl;
	vector<int>(v1).swap(v1);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;

	// 使用reserve预留空间
	v1.reserve(30);	// reserve不得小于size，否则无意义
	cout << "预留空间后v1的capacity和size分别是   "<< endl;
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
}
int main03() {
	/*构造*/
	test03_01();
	cout << endl << endl;
	/*赋值*/
	test03_02();
	cout << endl << endl;
	/*容量和大小*/
	test03_03();
	cout << endl << endl;
	/*插入和删除*/
	test03_04();
	cout << endl << endl;
	/*数据存取*/
	test03_05();
	cout << endl << endl;
	/*互换容器*/
	test03_06();
	cout << endl << endl;
	/*预留空间*/
	test03_07();
	cout << endl << endl;

	return 0;
}