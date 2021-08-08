#include <iostream>
#include <string>
using namespace std;

// 
// class Animal 
// {
// public:
// 	Animal() {
// 		cout << "Animal constructor Called" << endl;
// 	}
// 	virtual void speak() = 0;
// 
// 	virtual ~Animal() = 0;
// 	virtual ~Animal() {
// 		cout << "Animal deconstructor called" << endl;
// 	}
// 
// protected:
// private:
// };
// 
// class Cat : public Animal {
// public:
// 
// 	Cat(string name_cat) {
// 		m_name = new string(name_cat); 
// 	};
// 
// 	void speak() {
// 		cout << *m_name << "is Meow~ ing ..." << endl;
// 	}
// 
// 	string *m_name;
// 
// 	~Cat() {
// 		cout << "Cat deconstructor called" << endl;
// 		if (m_name != NULL)
// 		{
// 			delete m_name;
// 			m_name = NULL;
// 		}
// 	}
// 
// };
// 
// Animal::~Animal() {
// 	cout << "Animal deconstructor called" << endl;
// }
// 
// void test01() {
// 	Animal* animal = new Cat("XiaoMiao");
// 	animal->speak();
// 
// 	delete animal;
// }
// 
// int main() {
// 	test01();
// }