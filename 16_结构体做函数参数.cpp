#include <iostream>
using namespace std;

// 定义结构体
struct Student_ {
    string name;
    int age;
    float score;
};
// 定义打印函数 值传递
void printStudent_(struct Student_ s) {
    cout << "\tStudent_ s = {" << s.name << ", " << s.age << ", " << s.score << "}" << endl;
}
// 定义打印函数 地址传递
void printStudent_A(struct Student_ *s) {
    cout << "\tStudent_ s = {" << s->name << ", " << s->age << ", " << s->score << "}" << endl;
}

// 测试值传递
void testValue(struct Student_ s) {
    // 修改年龄
    s.age = 100;
    cout << "\t修改后年龄：" << s.age << endl;
}

// 测试地址传递
void testAddress(struct Student_ *s) {
    // 修改年龄
    s->age = 100;
    cout << "\t修改后年龄：" << s->age << endl;
}

// 测试const地址传递
void testConstAddress(const struct Student_ *s) {
    // 修改年龄
    // s->age = 100; // 报错，不可修改
    // cout << "\t修改后年龄：" << s->age << endl;
}



// conse 修饰结构中的某些数据
// 创建结构体
struct Student_ConstName {
    const string name;          // 名字不可修改
    int age;
    float score;
};
// 测试Const修改部分变量
void testConst(struct Student_ConstName *s) {
    // 修改年龄
     s->age = 100; // 可以修改
     cout << "\t修改后年龄：" << s->age << endl;
     //s->name = "小刚"; // 不可修改
     //cout << "\t修改后名字：" << s->name << endl; 
}


int main16() {
    cout<<"------------------------------------------------------值传递："<<endl;
    // 值传递
    struct Student_ s1 = {"小明", 18, 100};
    // 打印结构体变量
    printStudent_(s1);
    cout << endl << endl;

    cout<<"------------------------------------------------------地址传递："<<endl;
    // 地址传递
    struct Student_ s2 = {"小红", 19, 99};
    // 指针
    Student_ *p = &s2;
    printStudent_A(p);
    cout << endl << endl;

    cout<<"------------------------------------------------------值传递和地址传递："<<endl;
    cout << "值传递" << endl;
    struct Student_ s3 = {"小刚", 20, 98};
    testValue(s3);      // 在函数中值改变
    printStudent_(s3);  // 值传递，在函数外不会改变
    cout << "地址传递" << endl;
    struct Student_ s4 = {"小刚", 20, 98};
    testAddress(&s4);   // 在函数中改变值
    printStudent_(s4);  // 地址传递，在函数外也会改变
    cout << endl << endl;

    cout<<"------------------------------------------------------结构体中const使用"<<endl;
    // const 修饰结构体中的数据
    // 设置只读，不可修改，可以有效的减少内存开销
    // 创建结构体变量
    struct Student_ const s5 = {"李华", 20, 98};
    testConstAddress(&s5);          // 可以节省内存空间，因为编译器可以知道这个变量是只读的，所以可以省去内存空间


    // const 修饰结构体中的部分数据
    struct Student_ConstName s6 = {"李华", 20, 98};   // 名字不可修改
    testConst(&s6);
    cout << endl << endl;

    return 0;
}