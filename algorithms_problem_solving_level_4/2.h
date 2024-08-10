#pragma once
#include <iostream>
using namespace std;
namespace soln2 {

	int ReadNumber(string Message)
	{
		int Number;
		bool IsFinsh = false;
		while (!IsFinsh)
		{
			cout << Message;
			cin >> Number;
			if (Number > 0)IsFinsh = true;
		}
		return Number;


	}
	bool IsleapYear(short year) {
		if (year % 400 == 0)return true;
		if (year % 4 == 0 && year % 100 != 0)return true;
		return false;
	}
}


void CheckLeapYear() {
	short year = soln2::ReadNumber("nEnter a Year ? ");
	cout << "this year is : ";
	soln2::IsleapYear(year) ?
		cout << "Leap Year" << endl :
		cout << "Common Year" << endl;

}