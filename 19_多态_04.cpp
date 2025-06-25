#include<iostream>
using namespace std;

/*
	虚析构和纯虚析构

	如果子类中的属性开辟到堆区，使用父类调用子类对象则：
		父类指针无法释放子类对象
	都需要具体的函数实现
*/
class Animals {
public:
	Animals() {
		cout << "Animals的构造函数调用" << endl;
	}
	// 纯虚函数
	virtual void speak() = 0;

	//~Animals() { // 析构
	//	cout << "Animals的析构函数调用" << endl;
	//}
	virtual ~Animals() { // 虚析构
		cout << "Animals的析构函数调用" << endl;
	}
	// virtual ~Animals() = 0 // 纯虚析构，需要代码实现，否则会报错，需要在外部有代码实现
};
Animals::~Animals() {
	cout << "Animals的纯析构函数调用" << endl;
};

class Cats : public Animals {
public:
	// 构造函数
	Cats(string name) {
		cout << "CATS的构造函数调用" << endl;
		m_Name = new string(name);
	}
	virtual void speak() {
		cout << *m_Name <<"Cat在说话" << endl;
	}
	~Cats() {
		if (m_Name != NULL) {
			delete m_Name; // 释放内存
		}
		cout << "CATS的析构函数调用" << endl;
	}
	string* m_Name;
};
int main19() {
	Animals* animals = new Cats("Tom");
	animals->speak();
	delete animals;		// 不加virtual，父类指针在析构的时候不会调用子类中的析构函数，
						// 导致子类中如果有堆区的数据，会导致内存的泄露
						// 加virtual，会调用子类的析构函数
	/*
	* 不加virtual
	Animals的构造函数调用
	CATS的构造函数调用

	Animals的析构函数调用
				没有执行CATS的析构函数，造成了内存泄漏
	*/
	/*
	* 加virtual 
	Animals的构造函数调用
	CATS的构造函数调用

	CATS的析构函数调用		执行CATS的析构函数
	Animals的析构函数调用
	*/
	

	return 0;
}