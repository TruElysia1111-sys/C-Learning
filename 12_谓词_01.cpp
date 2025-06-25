#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

/*
谓词：
	返回bool类型的仿函数成为谓词
	如果operator()接受一个参数	：	一元谓词
	如果operator()接受两个参数	：	二元谓词

*/

/*
一元谓词
*/
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void test12_01() {
	// 一元谓词
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// 查找有没有大于5的数字
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "Null" << endl;
	}
	else {
		cout << "*it = "<<*it << endl;
	}
}
/*
二元谓词
*/
class Mycompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};
void test12_02() {
	vector<int> v;
	v.push_back(8);
	v.push_back(4);
	v.push_back(9);
	v.push_back(7);
	v.push_back(5);

	cout << "升序" << endl;
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;

	cout << "降序" << endl;
	sort(v.begin(), v.end(), Mycompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
}
int main12() {
	test12_01();
	cout << endl << endl;
	test12_02();
	return 0;
}