#include <iostream>
using namespace std;

/*
    Class和Struct的区别：（唯一区别就是默认访问权限）
        ·struct默认权限为公共
        ·class默认权限为私有

*/


/*
    类和对象：
        封装、继承、多态
        封装：
            封装就是将数据成员和成员函数封装在一起，
            通过类的访问权限控制成员变量和成员函数的访问权限，
            从而达到保护数据、隐藏细节、提高安全性的目的。
        继承：
            继承就是子类可以继承父类的属性和方法。
        多态：
            父类对象可以转换为子类对象。
            子类对象可以转换为父类对象。
*/

/*
    对象：
        属性，行为
    具有相同性质的对象，抽象为类。

    封装：
        将属性和行为作为一个整体
        将属性和行为加以权限控制
*/


// -------------------------------------------------------------------定义
/*
    设计一个圆，求周长
*/
const double PI = 3.1415926;
// class 类名{
// 访问权限： （public，private，protected）
//      属性
//      行为
// }
class Circle {
public:   // 公共权限
    double r;       // 属性：半径
    double getPerimeter() {     // 行为：求周长，一般以函数形式表示
        return 2 * PI * r;
    }
};

// ----------------------------------------------------------------封装的访问权限:
// 公共： public
//      类内可以访问，类外也可以访问
// 私有： private
//      类内可以访问，类外不可以访问
// 保护： protected
//      类内可以访问，类外不可以访问
//      子类可以访问
class Student {
public: // 公共权限
    string name;
    int age;
protected:  // 保护权限
    int ID;
private:  // 私有权限
    int score;

public:
    void printinfo() {
        cout << "name:" << name << endl;   // 类内可以访问
        cout << "age:" << age << endl;     // 类内可以访问
        cout << "ID:" << ID << endl;       // 保护权限类内可以访问
        cout << "score:" << score << endl; // 私有权限类内可以访问
    }
};

//------------------------------------------------------------------------- Class和Struct区别
class A {
    int a = 0;  // 默认私有
};
struct B {
    int b = 0;  // 默认公有
};

// ---------------------------------------------------------成员属性设置为私有
// 1. 可以自己控制读写权限
// 2. 对于写可以检测数据的有效性
class Person {
private:    // 私有属性
    string Name; // 姓名 可读可写
    int Age; // 只读
    string Id; // 只写
//  提供共有的方法，来设置私有属性
public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }
    // 通过写来验证数据有效性
    void setAge(int age) {
        if (age > 0 && age < 100) {
            Age = age;
        }
        else {
            cout<< "年龄不合法" << endl;
        }
    }
};

// --------------------------------------------------------构造函数和析构函数

class creat {
    // 构造函数：在创建对象时调用
    //      类名（）{}
    //      没有返回值，不写void
    //      函数名称与类名相同
    //      自动调用，且只调用一次
    //      可以有参数，允许重载
public:
    creat(int a = 0) {   // 函数名与类名相同
        cout<< "a = " << a << endl; // 可以有参数
        cout<< "构造函数" << endl;  // 自动调用
    }
};
// 析构函数：在销毁对象时调用
class cancel {
    //      ~类名（）{}
    //      没有返回值，不写void
    //      函数名称与类名相同，前面加~
    //      自动调用，且只调用一次
    //      没有参数，不能重载
public:
    ~cancel() {     // 析构函数 不可以有参数
        cout<< "析构函数" << endl;
    }
};
void test() {
    cancel c;
}

// ----------------------------------------------------------------------------------------分类
class cls {
    // 分类: 无参构造，有参构造
public:
    cls() {
        cout << "无参构造" << endl;
    }
    cls(int a) {
        cout << "有参构造" << endl;
    }
    // 分类：拷贝构造
    cls(const cls &cls) {
        cout << "拷贝构造" << endl;
    }
};


// -----------------------------------------------------------------------------------------深拷贝与浅拷贝
class func {
public:
    int f_age;
    int* f_height;

    func() {
        cout << "无参构造" << endl;
    }
    func(int age, int height) {
        f_age = age;
        f_height = new int(height); // 堆区的数据需要手动释放
        cout << "有参构造" << endl; 
    }
    func(const func& f1) {
        f_age = f1.f_age;
        f_height = f1.f_height;
        cout << "拷贝构造" << endl; // 浅拷贝构造
    }
    ~func() {
        if (f_height) {
            delete f_height; // 手动删除堆区数据
        }
        cout << "析构函数" << endl;
    }
};
class func1 {
public:
    int f_age;
    int* f_height;

    func1() {
        cout << "无参构造" << endl;
    }

    func1(int age, int height) {
        f_age = age;
        f_height = new int(height); // 堆区的数据需要手动释放
        cout << "有参构造" << endl; // 浅拷贝构造
    }

    func1(const func1 &p) {
        //f_age = age;
        //f_height = new int(height); // 堆区的数据需要手动释放
        f_age = p.f_age;

        f_height = new int(*p.f_height);  // 深拷贝，解引用p的值，然后在内存空间在开辟一个新的地址，储存相同的值
        cout << "拷贝构造" << endl; 
    }
    ~func1() {
        if (f_height) {
            delete f_height; // 手动删除堆区数据
        }
        cout << "析构函数" << endl;
    }
};


//-------------------------------------------------------------------------------------------- 类对象作为类成员
class Phone {
public:
    string phone_name;
    int phone_size;

    Phone(string name, int size) {
        cout << "构造函数Phone类" << endl;
        phone_name = name;
        phone_size = size;
    }

    ~Phone() {
        cout << "析构函数Phone类" << endl;
    }
};
class N {
public:

    // n_name = name , Phone phone = Phone(pname, 6.5);
    N(string name, string pname, int size): n_name(name), phone(pname, size) {
        cout<< "构造函数N类" << endl;
    }  // 
    
    ~N() {
        cout<< "析构函数N类" << endl;
    }
    string n_name;
    // 类对象作为类成员
    Phone phone;
};

void test_() {
    // 研究类对象作为类成员时，构造和析构函数的调用顺序
    N n1("张三", "华为", 6.5);
    cout << "n1.n_name的值是：" << n1.n_name << endl;
    cout << "n1.phone.phone_name的值是：" << n1.phone.phone_name << endl;
    cout << "n1.phone.phone_size的值是：" << n1.phone.phone_size << endl;
}


//-------------------------------------------------------------------------------------------- 静态成员
class Static {
public:
    // 静态成员： 所有对象共享同一份数据，在编译阶段分配内存，类内声明，类外初始化
    static int a; // 静态成员变量
    int b;

    // 访问方式： 通过对象访问，通过类名进行访问， 静态成员也可以设置访问权限

    // 静态成员函数，所有对象共享同一份函
    static void print() {
        cout << "静态成员函数" << endl;
        //cout << "普通成员变量的值是：" << b << endl;  // 静态成员函数中不可以访问普通成员变量
    }
};
int Static:: a = 10; // 类外初始化


// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
int main1() {
    //std::cout << "Hello, World!" << std::endl;

    // 通过圆类，创建具体的圆，（实例化）
    Circle c1;
    // 访问属性，赋值
    c1.r = 10.0;
    // 访问行为，求周长
    cout << "周长为: " << c1.getPerimeter() << endl;

    cout << "------------------------权限" << endl;
    Student s1;
    s1.name = "张三";
    s1.age = 20;
    //s1.id = 1001;   // 类外不可以访问
    //s1.score = 100;  // 类外不可以访问
    cout << endl << endl;


    cout << "------------------------Class和Struct" << endl;
    A a1;
    B b1;
    //cout <<a1.a<< endl;   不可访问
    cout << "Class默认私有" << "a1的值不可访问" << endl;
    cout << "Struct默认公有" << "b1的值可访问" << endl;
    cout << "b1.b的值是：" << b1.b << endl;
    cout << endl << endl;


    cout << "------------------------成员属性设置为私有" << endl;
    Person p1;
    p1.setName("Elysia");   // 通过公共方法来设置私有属性
    cout <<"通过公共方法来访问私有属性，Name = " << p1.getName() << endl;
    // 通过写来验证有效性
    p1.setAge(16);
    p1.setAge(150);
    cout << endl << endl;


    cout << "--------------------------对象的初始化和清理" << endl;
    // 对象的初始化和清理
    // 构造函数：
    //      主要用于创建对象时给成员属性赋值操作，无须手动调用
    creat g1;       // 自动调用构造函数
    // 析构函数：
    //      主要用于清理对象时释放资源操作，无须手动调用
    test();      // 自动调用析构函数, 释放g1对象
    cout << endl << endl;


    cout << "--------------------------构造函数的分类及调用" << endl;
    /*
        有参构造，无参构造
        默认构造，拷贝构造
        只要创建一个类： 编译器会给每个类添加至少三个函数：  默认构造（空实现），默认析构（空实现），默认拷贝构造（复制）
    */
    /*
        调用方式：
        1. 括号法：
        2. 显示法
        3. 隐式法
    */
    // 分类
    cout << "分类: 无参构造，有参构造" << endl;
    cls cls1;
    cls cls2(10);
    cout << "分类: 拷贝构造" << endl;
    cls cls3(cls1);  // cls3 == cls1

    cout << endl;
    // 调用方式
    cout << "调用方式: 括号法" << endl;
    cls cls4;       // 调用无参构造
    cls cls5(10);   // 调用有参构造
    cls cls6(cls5); // 调用拷贝构造

    cout << "调用方式: 显示法" << endl;
    cls cls7;           // 调用无参构造
    cls cls8 = cls(10); // 调用有参构造
    cls cls9 = cls5;    // 调用拷贝构造 

    cout << "调用方式: 隐式法" << endl;
    cls cls10 = cls();  // 调用无参构造 
    cls cls11 = cls(10);// 调用有参构造 cls cls11 = 10
    cls cls12 = cls5;   // 调用拷贝构造

    /*
        拷贝构造函数的构造时机：
            使用一个已经构造完毕的对象来初始化一个新对象
            值传递的方式给函数参数传值
            以值方式返回局部对象
    */
    cout << endl << endl;

    cout << "---------------------------------------------------------------深拷贝与浅拷贝" << endl;
    /*
        简单的赋值操作-----浅拷贝
        在堆区重新申请空间，进行拷贝操作-----深拷贝
    */
    func f1(19,177);

    func f2(f1);
    cout << "f1.age = " << f1.f_age << endl;
    cout << "f2.age = " << f2.f_age << endl; // 浅拷贝，f2.age = 19
    cout << "f1.height = " << f1.f_height << endl; 
    cout << "f2.height = " << f2.f_height << endl; // 浅拷贝，f2.height = f1.height, 地址相同,可能会产生堆区内存重复释放的问题
    cout << "f1.height = " << *f1.f_height << endl;
    cout << "f2.height = " << *f2.f_height << endl; // 浅拷贝，f2.height = f1.height，值相同

    // 深拷贝
    func1 f3(18,171);
    func1 f4(f3);
    cout << "f3.age = " << f3.f_age << endl;
    cout << "f4.age = " << f4.f_age << endl;
    cout << "f3.height = " << f3.f_height << endl;
    cout << "f4.height = " << f4.f_height << endl;
    cout << "f3.height = " << *f3.f_height << endl;
    cout << "f4.height = " << *f4.f_height << endl;     // 深拷贝，f4.height = f3.height, 地址不同，不会出现堆区内存重复释放的问题

    cout << endl << endl;

    cout << "------------------------------------------------------------初始化列表" << endl;
    /*
    class Person {
    public:
        string name;
        int age;
        int id;
        int score;
        Person(): name('name'),age(13),id(id),score(score) {        // 无参构造，默认值
            cout << "无参构造" << endl;
        }
        Person(string name, int age, int id, int score) : name(name), age(age), id(id), score(score) {
            cout << "有参构造" << endl;
        }
    };

    Person p;   // 无参构造, name = 'name', age = 13, id = id, score = score 默认值
    Person p1("张三", 18, 1001, 100);  // 在构造函数时就设置了初值
    Person p2("李四", 19, 1002, 90);
    */

    cout << "-----------------------------类对象作为类成员" << endl;
    // 先构造类成员，再构造类对象
    // 先析构类对象，再析构类成员
    test_();
    cout << endl << endl;


    cout << "--------------------------------静态成员" << endl;
    // 在成员变量或成员函数之前加上关键字 static
    Static st1;
    cout << "s1.a = " << st1.a << endl;   // 静态成员变量，所有对象共享一个变量
    Static st2;
    cout << "s2.a = " << st2.a << endl;

    // 静态成员变量，所有对象共享一个变量, 修改一个对象，其他对象也会改变
    st2.a = 100;
    cout << "s1.a = " << st1.a << endl;
    cout << "s2.a = " << st2.a << endl;

    // 访问方式： 通过对象访问，通过类名进行访问
    // 类名::静态变量
    cout << "通过类名来访问, Static::a = " << Static::a << endl;

    // 静态成员函数，所有对象共享一个函数，修改一个对象，其他对象也会改变
    st1.print();
    st2.print();

    // 访问方式： 通过对象访问，通过类名进行访问
    // 类名::静态函数
    Static::print();

    system("pause");
    return 0;
}