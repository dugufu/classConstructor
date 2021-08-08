#include <iostream>
#include <string>
using namespace std;


// class Base{
// public:
// 	virtual int test01() = 0;
// 
// };
// //son must be re-initialize the pure virtual
// class Son : public Base {
// public:
// 	virtual int test01() {
// 		cout << "out son" << endl;
// 		return 0;
// 	}
// };
// void test() {
// 	Base* base = new Son;
// 	base->test01();
// 
// }
// 
// class AbstractDrinks {
// public:
// 	virtual void Boil() = 0;
// 	virtual void Stir() = 0;
// 	virtual void Pour() = 0;
// 	virtual void Topping() = 0;
// 
// 	void makeDrink()
// 	{
// 		Boil();
// 		Stir();
// 		Pour();
// 		Topping();
// 	}
// };
// 
// class Coffee :public AbstractDrinks{
// public:
// 	virtual void Boil() {
// 		cout << "Boiling Water" << endl;
// 	}; //??This is because we turn it to non-abstract member
// 	virtual void Stir() {
// 		cout << "Stirring water with coffee" << endl;
// 	};
// 	virtual void Pour() {
// 		cout << "Pouring coffee into cup" << endl;
// 	};
// 	virtual void Topping() {
// 		cout << "Adding some toppings" << endl << endl;
// 	};
// };
// 
// 
// class LemonTea :public AbstractDrinks {
// public:
// 	virtual void Boil() {
// 		cout << "Boiling Water" << endl;
// 	}; //??This is because we turn it to non-abstract member
// 	virtual void Stir() {
// 		cout << "Stirring water with Lemon Tea" << endl;
// 	};
// 	virtual void Pour() {
// 		cout << "Pouring Lemon Tea into cup" << endl;
// 	};
// 	virtual void Topping() {
// 		cout << "Adding some toppings" << endl << endl;
// 	};
// };
// 
// void func_makeDrink(AbstractDrinks * drinks) {
// 	drinks->makeDrink();
// 	delete drinks;
// }
// 
// void test01() {
// 	func_makeDrink(new Coffee);
// 	func_makeDrink(new LemonTea);
// }
// 
// int main() {
// 
// 	test01();

//	test();
//}