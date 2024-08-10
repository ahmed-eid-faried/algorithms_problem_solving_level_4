#pragma once
#include <iostream>
using namespace std;
namespace soln3 {

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
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
}


void CheckLeapYear2() {
	short year = soln3::ReadNumber("nEnter a Year ? ");
	cout << "this year is : ";
	soln3::IsleapYear(year) ?
		cout << "Leap Year" << endl :
		cout << "Common Year" << endl;

}