#include <iostream>
using namespace std;

/*
继承方式：
	public 公共继承
	protected 保护继承
	private 私有继承
*/
class Father {
public:
	string a = "public";
	void pub() {
		cout << "public" << endl;
	}
protected:
	string b = "protected";
	void prot() {
		cout << "protected" << endl;
	}
private:
	string c = "private";
	void priv() {
		cout << "private" << endl;  /* 子类无法访问私有内容 */
	}
};
class Offspr_Public:public Father {
	// 公有继承
	// 可以访问public和protected权限内容
public:
	void func() {
		cout << "public继承，类内访问" << endl;
		cout << "a = " << a << endl;	// 依然是共有权限
		cout << "b = " << b << endl;	// 依然是保护权限
		cout << endl;
	}
};
class Offspr_Protected :protected Father {
	// 保护继承
	// 继承共有和保护权限，但都设置为保护权限
public:
	void func() {
		cout << "protected继承，类内访问" << endl;
		cout << "a = " << a << endl;	// 修改为保护权限
		cout << "b = " << b << endl;	// 依然是保护权限
		cout << endl;
	}
};
class Offspr_Private :private Father {
	// 私有继承
	// 继承共有和保护权限，但都设置为私有权限
public:
	void func() {
		cout << "protected继承，类内访问" << endl;
		cout << "a = " << a << endl;	// 修改为私有权限
		cout << "b = " << b << endl;	// 修改为私有权限
		cout << endl;
	}
};



/*
继承的类占用的内存空间
继承的类中有哪些对象模型
*/
class Base {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son1:public Base{};
class Son2 :protected Base {};
class Son3 :protected Base {};

int main11() {
	cout << "公共继承-------------------" << endl;
	Offspr_Public offspr_public; // 公共继承
	offspr_public.func();
	cout << "类外访问a = " << offspr_public.a << endl << endl;
	//cout << "类外访问b = " << offspr_public.b << endl; // 依然为保护权限，无法访问

	cout << "保护继承-------------------" << endl;
	Offspr_Protected offspr_protected; // 公共继承
	offspr_protected.func();
	//cout << "类外访问a = " << offspr_protected.a << endl; // 修改为保护权限，类外无法访问
	//cout << "类外访问b = " << offspr_protected.b << endl; // 依然为保护权限，类外无法访问

	cout << "私有继承-------------------" << endl;
	Offspr_Private offspr_private; // 公共继承
	offspr_private.func();
	//cout << "类外访问a = " << offspr_private.a << endl; // 修改为保护权限，类外无法访问
	//cout << "类外访问b = " << offspr_private.b << endl; // 依然为保护权限，类外无法访问


	cout << endl << endl << endl << endl;
	cout << "父类的内存空间" << sizeof(Base) << endl;		// 12
	cout << "public继承子类内存空间" << sizeof(Son1) << endl;	// 12
	cout << "protected继承子类内存空间" << sizeof(Son2) << endl;// 12
	cout << "private继承子类内存空间" << sizeof(Son3) << endl;	// 12
	// 说明父类中的所有的非静态成员属性都会被继承下去，但是会隐藏私有属性成员
	return 0;
}