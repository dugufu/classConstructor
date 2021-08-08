#include <iostream>
#include <string>
using namespace std;
// 
// class CPU {
// public:
// 	virtual void calculate() = 0;
// 	virtual ~CPU() {};
// };
// 
// class GPU {
// public:
// 	virtual void GraphicOutput() = 0;
// 	virtual ~GPU() {};
// };
// 
// class Memory {
// public:
// 	virtual void storage() = 0;
// 	virtual ~Memory() {};
// };
// 
// class execute {
// public:
// 	virtual void doTask() = 0 ;
// 	virtual ~execute() {};
// };
// 
// 
// class IntelComputer :public CPU, public GPU, public Memory,public execute {
// public:
// 	IntelComputer() {
// 		cout << "INtelComputer Constructor" << endl;
// 	}
// 
// 	void calculate()
// 	{
// 		cout << "Intel : Calculating cpu" << endl;
// 	};
// 	void GraphicOutput()
// 	{
// 		cout << "Intel : Displaying ultra graphic" << endl;
// 	};
// 	void storage()
// 	{
// 		cout << "Intel : Memory is running" << endl;
// 	};
// 
// 	void doTask() {
// 		calculate();
// 		GraphicOutput();
// 		storage();
// 	}
// 
// 	~IntelComputer() {
// 		cout << "Intel Deconstructor" << endl;
// 	}
// };
// 
// class LenovoComputer :public CPU, public GPU, public Memory,public execute {
// public:
// 	LenovoComputer() {
// 		cout << "Lenovo Constructor" << endl;
// 	}
// 
// 	void calculate()
// 	{
// 		cout << "Lenovo : Calculating cpu" << endl;
// 	};
// 	void GraphicOutput()
// 	{
// 		cout << "Lenovo : Displaying ultra graphic" << endl;
// 	};
// 	void storage()
// 	{
// 		cout << "Lenovo : Memory is running" << endl;
// 	};
// 
// 	void doTask() {
// 		calculate();
// 		GraphicOutput();
// 		storage();
// 	}
// 	~LenovoComputer() {
// 		cout << "Lenovo Deconstructor" << endl;
// 	}
// };
// 
// class MSIComputer :public CPU, public GPU, public Memory,public execute {
// public:
// 	MSIComputer() {
// 		cout << "MSI Constructor" << endl;
// 	}
// 	void calculate()
// 	{
// 		cout << "MSI : Calculating cpu" << endl;
// 	};
// 	void GraphicOutput()
// 	{
// 		cout << "MSI : Displaying ultra graphic" << endl;
// 	};
// 	void storage()
// 	{
// 		cout << "MSI : Memory is running" << endl;
// 	};
// 	void doTask() {
// 		calculate();
// 		GraphicOutput();
// 		storage();
// 	}
// 
// 	~MSIComputer() {
// 		cout << "MSI Deconstructor" << endl;
// 	}
// 	
// };
// 
// class Computer
// {
// public:
// 
// 	Computer() {
// 		cout << "Computer Constructor" << endl;
// 	}
// 	Computer(IntelComputer * intel, LenovoComputer * lenovo, MSIComputer * msi) {
// 		cout << "Computer Parametrized Constructor" << endl;
// 		cout << endl;
// 		intel->doTask();
// 		cout << endl;
// 		lenovo->doTask();
// 		cout << endl;
// 		msi->doTask();
// 		cout << endl;
// 
// 		if (intel != NULL)
// 		{
// 			deleteUsage(intel, lenovo, msi, this);
// 		}
// 	}
// 
// 	void deleteUsage(IntelComputer* intel, LenovoComputer* lenovo, MSIComputer* msi, Computer* computer) {
// 		delete intel;
// 		intel = NULL;
// 		delete lenovo;
// 		lenovo = NULL;
// 		delete msi;
// 		msi = NULL;
// 		delete computer;
// 		computer = NULL;
// 	}
// 
// 	~Computer() {
// 		cout << "computer deconstructor" << endl;
// 	}
// protected:
// private:
// };
// 
// 
// 
// void test01() {
// 	IntelComputer* intel = new IntelComputer;
// 	LenovoComputer* lenovo = new LenovoComputer;
// 	MSIComputer* msi = new MSIComputer;
// 
// 	Computer* buildPC = new Computer(intel, lenovo, msi);
// 
// 	//deleteUsage(intel, lenovo, msi, buildPC);
// }
// 
// int main() {
// 	test01();
// }