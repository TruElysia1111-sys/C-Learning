# include<iostream>
using namespace std;
# include<string>
// 类模板：
/*
	类模板没有自动类型推导的使用方式
	类模板在参数列表中可以有默认参数
*/

//template<class NameType, class AgeType>	// 默认无数据类型，模板
template<class NameType = string, class AgeType = int>	// 给NameType和AgeType设置默认数据类型
class Person {
public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << "Name是 " << this->m_Name << endl;
		cout << "Age是  " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test04_01() {	// 类模板无法使用自动类型推导
	//Person p("Elysia",16) // 报错，因为无法进行自动类型推导
	Person <string, int> p("Elysia", 16);	// 只能用显示指定数据类型

	p.showPerson();
}

void test04_02() {	// 类模板在模板参数列表中可以有默认参数列表
	Person<> p("Kevien", 17);	// 可以使用默认参数列表，但是一定要写<>
	p.showPerson();
}

int main04() {

	test04_01();
	test04_02();
	return 0;
}


