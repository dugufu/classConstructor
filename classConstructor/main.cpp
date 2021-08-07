#include <iostream>
#include <string>
using namespace std;

class Person10 {
public:
	Person10() {
		cout << "Run Constructor" << endl;
	}
	//Parametrized Constructor 
	Person10(int a) {
		age = a;
		cout << "Run Constructor with param" << endl;
	}
	//copy constructor
	Person10(const Person10& p) {
		age = p.age;
		cout << "Run Constructor with copy construc" << endl;
	};

	~Person10() {
		cout << "End Constructor" << endl;
	};

private:
	int age;
private:

};

void test1() {
	//默认法
	// 	Person p;//default
// 	Person p2(10);//parametrized
// 	Person p3(p2);
	//显示法
	Person10 p2 = Person10(10);
	Person10 p3 = Person10(p2);
	//
	
	Person10(10);//匿名对象， after这个line 就会执行deconstructor
	cout << "end line" << endl;

/*	隐式写法*/
	Person10 p4 = 10; // Person p4 = Person(10) 所以这里调用的是 有参数的constructor
	Person10 p5 = p4; // Person p5 = Person(p5) 所以这里调用的是 copy constructor

}

int main1() {
	test1();//default constrc
	

	return 0;
};