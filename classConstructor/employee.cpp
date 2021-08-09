#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "employee.h"
using namespace std;


void showMenu() {
	cout << "************************************" << endl;
	cout << "*** 0. Exit Program \t\t ***" << endl;
	cout << "*** 1. Add New Employee \t ***" << endl;
	cout << "*** 2. Display Employee Details  ***" << endl;
	cout << "*** 3. Delete Employee \t\t ***" << endl;
	cout << "*** 4. Edit Employee \t\t ***" << endl;
	cout << "*** 5. Search Employee \t\t ***" << endl;
	cout << "*** 6. ReOrdering Employee \t ***" << endl;
	cout << "*** 7. Delete All Data \t\t ***" << endl;
}


int main() {
	int num = -1;
	int program = -1;
	int checkIntType; // return 1 = true 0 = false
	while (program != 0)
	{
		jump_to_showMenu:
		system("CLS");
		showMenu();
		cout << "\nEnter Number here" << endl;
		cin >> num;
		checkIntType = checkVarIsInt(&num); // return 1 = true 0 = false
		if (checkIntType != 1)
		{
			goto jump_to_showMenu;
		}
		switch (num)
		{
		case 0:
			ExitProgram(&program);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}
}

//function 0 
void ExitProgram(int * num) {
	*num = 0;
}


//checking num 
int checkVarIsInt(int* numInt) {

	if (*numInt != -1)
	{
		return 1;
	}
	else {
		return 0;
	}
}