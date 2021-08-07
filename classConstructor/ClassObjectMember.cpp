#include <iostream>
#include <string>
using namespace std;

// 
// class Phone
// {
// public:
// 	Phone(string phone_name) : phoneName(phone_name) {
// 
// 	}
// 
// 	string getPhoneName() const{
// 		return phoneName;
// 	}
// 	string phoneName;
// 
// 	~Phone() {
// 		cout << "deconstruction" << endl;
// 	}
// };
// 
// class Person
// {
// public:
// 	Person(string user_name, string phone_name) : Name(user_name), pName(phone_name)
// 	{
// 
// 	}
// 	;
// 
// 
// 	void getInformation() const{
// 		cout << getName() << endl;
// 		cout << pName.getPhoneName() << endl;
// 
// 	}
// 
// 	static int function() {
// 		s_personNum = 100;
// 	}
// 
// 
// 	static int s_personNum;
// private:
// 	string getName() const {
// 		return Name;
// 	}
// 
// 
// 	Phone pName;
// 	string Name;
// 
// };
// 
// void test01() {
// 	Person p("ccr","samsung");
// 	Person p2("ccx", "apple");
// 
// 	p.getInformation();
// 	p2.getInformation();
// 	
// }
// 
// int  Person::s_personNum = 0;
// 
// int main() {
// 	test01();
// };