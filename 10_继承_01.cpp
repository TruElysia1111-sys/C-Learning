#include<iostream>
using namespace std;

/* 下级别的成员具有上一级的共性 */

// 继承：
class BasePage {
	// 公共页面的内容
public:
	void header() {
		cout << "Header: 公开课、登录、注册...." << endl;
	}

	void footer() {
		cout << "Footer: 帮助中心、交流合作...." << endl;
	}
};

/*
class 子类: 继承方式 父类{

};

子类也成为：派生类
父类也成为：基类
*/
// Java页面
class Java : public BasePage {
	// 继承BasePage的公共内容
public:
	void content() {
		cout << "Java内容" << endl;
	}
};
// C++页面
class CPP : public BasePage {
public:
	void content() {
		cout << "Cpp内容" << endl;
	}
};


int main10() {
	cout << "Java页面-------------------------" << endl;
	Java ja;
	ja.header();	// 可以调用父类的public内容
	ja.content();
	ja.footer();
	cout << "Cpp页面-------------------------" << endl;
	CPP cpp;
	cpp.header();
	cpp.content();
	cpp.footer();

	return 0;
}