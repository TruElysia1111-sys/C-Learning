# include<iostream>
using namespace std;
# include<string>
// 需要包含头文件<fstream>
# include<fstream>

/*
二进制的方式读写文件
主要调用成员函数write
*/
class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test03() { // 二进制写
	// 2. 创建流对象
	ofstream ofs;
	//ofsteram ofs("person.txt", ios::out | ios::binary)
	// 3. 打开文件
	ofs.open("02_test03.txt", ios::out | ios::binary);
	//ofs.open()
	// 4. 写文件
	Person p = { "Elysia",16 };
	ofs.write((const char*)&p, sizeof(Person)); 
	// 5. 关闭文件
	ofs.close();
}

void test04() { // 二进制读
	// 2. 创建流对象
	ifstream ifs;
	// 3. 打开文件
	ifs.open("02_test03.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "打开文件失败" << endl;
		return;
	}
	// 4. 读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名:	" << p.m_Name << endl;
	cout << "年龄:	" << p.m_Age << endl;
	// 5. 关闭文件
	ifs.close();
}
int main() {
	test03();
	test04();
	return 0;
}