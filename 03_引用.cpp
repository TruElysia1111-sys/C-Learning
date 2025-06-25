#include <iostream>
using namespace std;

void swap(int& a, int& b);
int& getNum0(); // 返回局部变量
int& getNum1();  // 
int& getNum2(); // 引用函数作为左值
void showValue(const int& val);

int main3() {
    //std::cout << "Hello, World!" << std::endl;
    /*
        引用：
            给变量起别名
        语法：
            数据类型 &别名 = 变量;
    */

    int a = 10;
    int &b = a; // b是a的别名
    cout <<"a = " << a << endl;
    cout <<"a的地址是"<< &a << endl;
    cout <<"b = " << b << endl;
    cout <<"b的地址是"<< &b << endl;  // 相同

    // 如果修改b？？
    b = 20;
    cout <<"a = " << a << endl;
    cout <<"b = " << b << endl;  // 相同

    // 类似深拷贝

    /*
        注意事项：
            引用必须初始化，即必须有一个变量
            引用不能改变，即该引用不可以改变指向
            引用不能为空
    */

    // 引用做函数参数
    // 类似指针，但是更简化
    cout << endl << endl << "----------引用做函数参数，传递" << endl;
    int m = 10;
    int n = 20;

    cout << "交换前：" << endl;
    cout<<"m = "<< m<<endl;
    cout<<"n = "<< n<<endl;

    swap(m, n);
    cout << "交换后：" << endl;
    cout<<"m = " << m << endl;
    cout<<"n = " << n << endl;


    // 引用做函数返回值
    // 不要返回局部变量
    // 函数调用作为左值
    cout << endl << endl << "----------引用做函数返回值，返回" << endl;
    int &ref0 = getNum0();
    int &ref1 = getNum1();

    cout<<"返回局部变量 第一次：ref0 = " << ref0 << endl;
    cout << "返回局部变量 第二次：ref0 = " << ref0 << endl;   // 乱码，因为局部变量用完之后就会释放内存

    cout<<"返回全局引用 第一次：ref1 = " << ref1 << endl;
    cout << "返回全局引用 第二次：ref1 = " << ref1 << endl;   // 不会乱码


    // 引用函数可以作为左值
    cout << endl << endl << "-----------引用函数可以作为左值" << endl;

    int& ref2 = getNum2();      // 函数的返回值引用ref2，ref2是函数的引用
    cout<<"ref2 = "<< ref2 << endl;
    cout << "getNum2() = " << getNum2() << endl;
    getNum2() = 1;           // 对函数进行改值,ref2也会修改
    cout<<"ref2 = "<< ref2 << endl;
    cout << "getNum2() = " << getNum2() << endl;


    // 常量引用
    cout << endl << endl << "-----------常量引用" << endl;
    // 在形参列表中加const，防止形参改变实参，防止误操作
    const int& ref3 = 10;   // 加上const之后，可以引用常数，编译器创建了一个临时空间
    cout << "ref3 = " << ref3 << endl;
    //ref3 = 20;  // 加上const，变为只读，编译器会报错
    //cout << "ref3 = " << ref3 << endl;
   
    // 修饰形参防止误操作
    int val = 10;
    showValue(val);


    /*
        引用的本质：
            内部实现：指针常量，方向不可变，值可变
    */

    system("pause");
    return 0;
}


// 引用传递
void swap(int &a, int &b) {
    // a,b是m,n的引用，所以a，b相当于m,n
    int temp = a;
    a = b;
    b = temp;
}

// 引用返回函数值
int &getNum0() {
    int n = 10;   // 局部变量，存放在栈中，用完即释放
    return n;
}
int &getNum1() {
    static int n = 100;   // 静态变量，存放在全局区域，程序运行期间一直存在
    return n;
}

// 引用函数作为左值
int& getNum2() {        // 函数相当于1000： getNums() = 1000
    static int n = 1000;
    return n;
}

void showValue(const int &val) {        // 加上const之后，val是常量，不能修改
    // 误操作：
    //    val = 1000;
    cout <<"val = " << val << endl;
}
