#include<iostream>
#include<map>
#include<random>

using namespace std;

/*
map中所有的元素都是pair
	第一个值是key
	第二个值是value
	所有的元素会根据元素的key进行自动排序

map / multimap属于关联式容器，底层结构是使用二叉树实现

可以通过key值快速找到value

map不允许重复key值出现
multimap允许容器中有重复的key值
*/

void printmap(map <int, int>& m) {
	for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
		cout <<(*it).first << ": ";
		cout << it->second << endl;
	}
	cout << endl;
}
void printmultimap(multimap <int, int>& m) {
	for (multimap<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << ": ";
		cout << it->second << endl;
	}
	cout << endl;
}
/*
构造和赋值
*/
void test10_01() {
	cout << "----构造和赋值----" << endl;
	/* map<t,t> m */
	map<int, int> m1;
	for (int i = 1; i < 6; i++) {
		m1.insert(pair<int, int>(i, 10 * i));	// insert必须是pair类型
	}
	cout << "m1 = " << endl;
	printmap(m1);
	/* 自动排序 */
	map<int, int> m2;
	for (int i = 1; i < 6; i++) {
		m2.insert(pair<int, int>(rand()%11, 10 * i));	// insert必须是pair类型
	}
	cout << "m2 = " << endl;
	printmap(m2);

	/* 拷贝构造 */
	map<int, int> m3(m2);
	cout << "m3 = " << endl;
	printmap(m3);

	/* 赋值 */
	map<int, int> m4;
	m4 = m3;
	cout << "m4 = " << endl;
	printmap(m4);
}
/*
大小和交换
*/
void test10_02() {
	cout << "----大小和交换----" << endl;
	/* map<t,t> m */
	map<int, int> m1;
	for (int i = 1; i < 6; i++) {
		m1.insert(pair<int, int>(i, 10 * i));	// insert必须是pair类型
	}
	cout << "m1 = " << endl;
	printmap(m1);
	/* 自动排序 */
	map<int, int> m2;
	for (int i = 1; i < 6; i++) {
		m2.insert(pair<int, int>(rand() % 11, 10 * i));	// insert必须是pair类型
	}
	cout << "m2 = " << endl;
	printmap(m2);

	map<int, int> m3;
	cout << "m3 = " << endl;
	printmap(m3);

	/* size() */
	cout << "m1.size() = " << m1.size() << endl;
	cout << "m2.size() = " << m2.size() << endl;
	cout << endl;

	/* empty() */
	cout << "m1.empty() = " << m1.empty() << endl;
	cout << "m2.empty() = " << m2.empty() << endl;
	cout << "m3.empty() = " << m3.empty() << endl;
	cout << endl;

	/* swap() */
	cout << "m1.swap(m2)" << endl;
	m1.swap(m2);
	cout << "m1 = " << endl;
	printmap(m1);
	cout << "m2 = " << endl;
	printmap(m2);
}
/*
插入和删除
*/
void test10_03() {
	cout << "----插入和删除----" << endl;
	/* map<t,t> m */
	map<int, int> m1;
	for (int i = 1; i < 6; i++) {
		m1.insert(pair<int, int>(i, 10 * i));	// insert必须是pair类型
	}
	cout << "m1 = " << endl;
	printmap(m1);
	/* 自动排序 */
	map<int, int> m2;
	for (int i = 1; i < 6; i++) {
		m2.insert(pair<int, int>(rand() % 11, 10 * i));	// insert必须是pair类型
	}
	cout << "m2 = " << endl;
	printmap(m2);

	map<int, int> m3;
	cout << "m3 = " << endl;
	printmap(m3);

	/* insert() */
	m3.insert(pair<int, int>(rand() % 101, rand() % 11));
	cout << "m3.insert(pair) = " << endl;
	printmap(m3);

	/* insert(make_pair(key,val)) */
	m3.insert(make_pair(2, 3));
	cout << "m3.insert(make_pair) = " << endl;
	printmap(m3);

	/* insert(map<int,int>::value_type(key,val)) */
	m3.insert(map<int, int>::value_type(3, 10));
	cout << "m3.insert(map::value_type()) = " << endl;
	printmap(m3);

	/* [] */
	m3[4] = 40;		// 不推荐
	cout << "m3[] = " << endl;
	printmap(m3);
	/* insert() 已经存在的key 不会生效*/
	cout << "insert()三次一样的key值:" << endl << "m3 = " << endl;
	m3.insert(pair<int, int>(1, 1));
	m3.insert(pair<int, int>(1, 2));
	m3.insert(pair<int, int>(1, 3));
	printmap(m3);	// 1,1

	/* erase(pos) */
	m3.erase(m3.begin());	// 不赞成随机访问
	cout << "m3.erase(pos) = " << endl;
	printmap(m3);

	/* erase(key) */
	m3.erase(3);	
	m3.erase(233); // 无操作，不报错
	cout << "m3.erase(key) = " << endl;
	printmap(m3);

	/* erase(beg,end) */
	m3.erase(m3.begin(), m3.end());
	cout << "m3.erase(beg,end) = " << endl;
	printmap(m3);

	/* clear() */
	m1.clear();
	cout << "m1.clear() = ";
	printmap(m3);
}
/*
查找和统计
*/
void test10_04() {
	cout << "----查找和统计----" << endl;
	/* map<t,t> m */
	map<int, int> m1;
	for (int i = 1; i < 6; i++) {
		m1.insert(pair<int, int>(i, 10 * i));	// insert必须是pair类型
	}
	cout << "m1 = " << endl;
	printmap(m1);

	/* find(key) 返回迭代器*/
	map<int,int>::iterator pos1 = m1.find(1);
	cout << "m1.find(1) = " << (*pos1).first << ": " << pos1->second << endl;
	map<int, int>::iterator pos2 = m1.find(11);	// 不存在返回.end()
	if (pos2 == m1.end()) {
		cout << "m1.find(11) = NULL" << endl;
	}

	/* count(key) */
	cout << "m1.count(1) = " << m1.count(1) << endl;
	cout << "m1.count(11) = " << m1.count(11) << endl;

}
/*
multimap
*/
void test10_05() {
	cout << "----multimap----" << endl;
	/* map<t,t> m */
	multimap<int, int> m1;
	for (int i = 1; i < 10; i++) {
		m1.insert(pair<int, int>(1, i));	// insert必须是pair类型
	}
	cout << "m1 = " << endl;
	printmultimap(m1);

	/* find(key) 返回迭代器*/
	multimap<int, int>::iterator pos1 = m1.find(1);	// 返回找到的第一个key值
	cout << "m1.find(1) = " << (*pos1).first << ": " << pos1->second << endl;
	multimap<int, int>::iterator pos2 = m1.find(11);	// 不存在返回.end()
	if (pos2 == m1.end()) {
		cout << "m1.find(11) = NULL" << endl;
	}

	/* count(key) */
	cout << "m1.count(1) = " << m1.count(1) << endl;
	cout << "m1.count(11) = " << m1.count(11) << endl;
}
/*
排序
*/
class MyCompare {
public:
	bool operator()(int v1, int v2) const {	// const,建议所有的operator都加const
		return v1 > v2;
	}
};
void test10_06() {
	cout << "----排序----" << endl;
	/* map<t,t> m */
	map<int, int, MyCompare> m1;
	for (int i = 1; i < 6; i++) {
		m1.insert(pair<int, int>(i, 10 * i));	// insert必须是pair类型
	}
	cout << "m1 = " << endl;

	/* 排序 */
	for (map<int, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
}
int main10() {
	/* 构造 */
	test10_01();
	cout << endl << endl;

	/* 大小和交换 */
	test10_02();
	cout << endl << endl;

	/* 插入和删除 */
	test10_03();
	cout << endl << endl;

	/* 查找和统计 */
	test10_04();
	cout << endl << endl;

	/* multimap */
	test10_05();
	cout << endl << endl;

	/* 排序 */
	test10_06();
	cout << endl << endl;
	return 0;
}