#include <iostream>
using namespace std;

/*
    对象模型和this指针
        类内的成员变量和成员函数分开存储
        只有非静态成员变量才属于对象
*/
class c1 {}; // 空对象
class c2 {
public:
    int c2_a;
    int static c2_b;    // 静态成员变量不占类的内存
    void func() {       // 函数不属于类对象上
        cout << "func()" << endl;
    }
}; // 非空对象
int c2::c2_b = 100;     // 类外初始化

void test01() {

    cout << sizeof(c1) << endl; // 类所占的内存

    cout << sizeof(c2) << endl; // 类所占的内存 
    
}


// this指针
// this 指针指向被调用的成员函数所属的对象
// this指针不用定义，直接使用
// this指针在成员函数中，指向当前对象

/*
    当形参和成员变量同名时，，this指针可以解决冲突
    在类的非静态成员函数中返回对象本身，可以使用 return *this
*/
class Person {
public:
    int age;

    Person(int age) {
       this->age = age; // this指针解决冲突
    }

    void PersonAddAge(Person& p) {
        this->age += p.age;
    }

    Person& PersonAddAge1(Person& p) {
        this->age += p.age;
        return *this;
    }

    Person PersonAddAge2(Person p) {        // 返回值
        this->age += p.age;
        return this->age;
    }
};
void test02() {
    Person p1(10);
    cout <<"p1.age = " << p1.age << endl;

    Person p2(20);
    p2.PersonAddAge(p1);  // 30
    cout <<"p2.age = " << p2.age << endl;

    // 链式编程思想
    // p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1); // 连续调用,报错，因为PersonAddAge 返回的是void，不能连续调用
    p2.PersonAddAge1(p1).PersonAddAge1(p1).PersonAddAge1(p1); // 连续调用，返回对象本身，可以连续调用
    cout <<"p2.age = " << p2.age << endl; // 60

    // 值返回，不能连续调用，创建新的对象
    // Person p3(30);
    // p3.PersonAddAge2(p1).PersonAddAge2(p1);
    // cout <<"p3.age = " << p3.age << endl;  // 40
}

/*
    空指针访问成员函数
*/
class Person01 {
public:
    void showClassName() {
        cout<<"Person01"<<endl;
    }
    void showPersonAge() {
        //if (this == NULL) {
        //    cout<<"this = NULL"<<endl;
        //    return;
        //}                     // 提高代码的健壮性
        cout<<"m_age = "<<m_age<<endl;
    }
    int m_age;
};
void test03() {
    Person01 *p = NULL;  // 指针指向空
    p->showClassName();  // 可以正常运行
    // p->showPersonAge();  // 访问空指针，程序崩溃
    // 原因：  属性的调用默认其实有一个this指针， this指针指向对象本身，空指针无法调用成员函数，程序崩溃
    //         即： cout<<"m_age = "<<m_age<<endl; 其实相当于 cout<<"m_age = "<<this->m_age<<endl;
    //         当this指针为空，则this指针无法访问对象本身，程序崩溃
}
/*
    const修饰成员函数
        const修饰成员函数
        1. 常函数：
        成员函数后加const称为常函数
        常函数内不可以修改成员属性
        成员属性声明时加关键字mutable，在常函数中依然可以修改
        2. 常对象：
        声明对象前加const
        常函数只能调用常对象
*/
class Person02 {
public:
    void showPersonInfo() const {  
        // 常函数---》 加const，即 this const， 指针变为常量指针，指针朝向的值也不可以修改了
        
        // this指针的本质是指针常量，指针的朝向是不可以修改的，指针修改的值可以修改
        // age = 10;  // 常函数内不可以修改成员属性,报错

        m_age = 20;       // 常函数内可以修改成员属性，因为成员属性声明时加了mutable
        cout << "m_age = " << m_age << endl;
    }
    void func() {
        cout << "func()" << endl;
    }
    int age;
    mutable int m_age; // 特殊变量，即使在常函数中，也可以修改
};
void test04() {
    Person02 p;
    p.showPersonInfo();

    // 常对象
    const Person02 p1; // 常对象，声明对象前加const
    //p1.age = 10;   // 报错，无法修改
    //p1.func(); // 常对象只能调用常函数
    p1.m_age = 10;  // 可以修改 mutable 特殊修饰
    p1.showPersonInfo();
}

int main2() {
    //std::cout << "Hello, World!" << std::endl;

    test01(); // 空对象占内存 1 字节， 非空对象占内存 所有非静态成员变量的内存和
    cout<< endl;

    cout<< "--------------------------------------------this 指针"<< endl;
    /* this 指针 */
    test02();
    
    cout << "----------空指针访问成员函数" << endl;
    /* 空指针访问成员函数 */
    test03();

    cout << "----------const修饰成员函数" << endl;
    /* const修饰成员函数
        1. 常函数：
        成员函数后加const称为常函数
        常函数内不可以修改成员属性
        成员属性声明时加关键字mutable，在常函数中依然可以修改
        2. 常对象：
        声明对象前加const
        常函数只能调用常对象
    */
    test04();


    system("pause");
    return 0;
}