#include <iostream>
using namespace std;

/* 关系运算符重载 */
/*
	== 
	!=
	>
	<
	>=
	<=
*/
class Grades {
public:
	Grades(int a) {
		grade = a;
	}

	/* 重写关系运算符 */
	string operator> (Grades& g) {
		if (this->grade > g.grade) {
			return "true";
		}
		else {
			return "false";
		}
	}


private:
	int grade;
};



int main08() {

	Grades g1(20);
	Grades g2(30);

	cout << "g1 > g2 ?" << (g1>g2) << endl;

	return 0;
}