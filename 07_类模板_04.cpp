# include<iostream>
using namespace std;

/*
当子类继承的父类是类模板时，子类在声明的时候，需要指定出父类中T的类型
如果不指定，编译器无法给子类分配内存
如果想让T的类型更加灵活，子类也可变为类模板
*/
template<class T>
class Base {
	T m;
};
//class Son :public Base {}// 错误
class Son1:public Base<int> { // 继承
	
};

template<class T>
class Son2 :public Base<int> {	// 类模板继承类模板

};


int main07() {

	return 0;
}