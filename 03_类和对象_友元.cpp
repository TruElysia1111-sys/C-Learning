#include <iostream>
using namespace std;
// 友元：关键字 friend
//      * 全局函数做友元
//      * 类做友元
//      * 类成员函数做友元

// 类外的特殊函数访问类成员


/*
全局函数做友元
*/
class Building {
    // 友元函数
    friend void visit(Building* building); // 全局函数做友元
public:
    Building() {
        /* 赋值操作 */
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
public:
        string m_SittingRoom; // 客厅,公共属性
private:
        string m_BedRoom; // 卧室，私有属性
};

// 全局函数 
void visit(Building *building) {
    cout << "访问sittingroom" << building->m_SittingRoom << endl;  // 访问sittingroom客厅，公共属性

    //cout << "访问bedroom" << building->m_BedRoom << endl;  // 报错，不允许访问
    cout << "访问bedroom" << building->m_BedRoom << endl;  // 在类中添加  friend void visit(Building* building); 做友元
}

void test05() {
    Building building;
    visit(&building);
}

/*
类做友元
*/
class Building1 {
    // 类做友元
    friend class GoodGay;
public:
    Building1() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; // 客厅
private:
    string m_BedRoom; // 卧室
};

class GoodGay {
public:
    GoodGay() {
        building = new Building1;
    }
public:
    void visit00(); // 成员函数

public:
    Building1 *building;
};
// 类外写函数
void GoodGay::visit00() {
    cout << "正在访问：" << building->m_SittingRoom << endl;
    cout << "正在访问：" << building->m_BedRoom << endl;
}

void test06() {
    GoodGay gg;
    gg.visit00();
}

/*
成员函数做友元
*/
class Building2;

class A1 {
public:
    A1();

    void visit01();   // 可以访问Building2的私有属性

    void visit02();     // 不可以访问Building2的私有属性

    Building2* building2;
};

class Building2 {
    friend void A1::visit01(); // 告诉编译器，visit01函数是A类的友元函数
public:
    Building2() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};

// 类外成员函数
A1::A1() {
    building2 = new Building2();
}
void A1::visit01() {
    cout << "visit01() 访问: " << building2->m_SittingRoom << endl;
    cout << "visit01() 访问: " << building2->m_BedRoom << endl; // 合法，因为是友元
};     // 可以访问Building2的私有属性

void A1::visit02() {
    cout << "visit02() 访问: " << building2->m_SittingRoom << endl;
    // cout << building2->m_BedRoom << endl; // 非法，未被声明为友元
};


void test07() {
    A1 a2;
    a2.visit01();
    a2.visit02();
}

int main03() {
    test05(); // 全局函数做友元

    test06(); // 友元类

    test07(); // 友元函数
    system("pause");
    return 0;
}