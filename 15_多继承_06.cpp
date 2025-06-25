# include<iostream>
using namespace std;


class Base1 {
public:
	int b = 10;
};
class Base2 {
public:
	int b = 20;
};
class Base3 {
public:
	int b = 30;
};

class Son_ : public Base1, public Base2, public Base3 {
public:
	void printinfo(){
		cout << "第一个父类的b值   " << Base1::b << endl;
		cout << "第二个父类的b值   " << Base2::b << endl;
		cout << "第三个父类的b值   " << Base3::b << endl;
	}
};
int main15() {
	Son_ s;
	s.printinfo();

	return 0;
}