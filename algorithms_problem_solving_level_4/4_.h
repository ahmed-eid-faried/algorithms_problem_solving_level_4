#pragma once
#include <iostream>
using namespace std;
namespace soln4 {

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

	short NumOfDaysInYear(short year) {
		return IsleapYear(year) ? 366 : 365;
	}
	short NumOfHoursInYear(short year) {
		return NumOfDaysInYear(year) * 24;
	}
	int NumOfMinutesInYear(short year) {
		return NumOfHoursInYear(year) * 60;
	}
	int NumOfSecondsInYear(short year) {
		return NumOfMinutesInYear(year) * 60;
	}

}



void NumbersOfDaysInYearEx() {
	short year = soln4::ReadNumber("Please Enter a Year to check? ");
	cout << "Num Of Days    In Year : " << soln4::NumOfDaysInYear(year) << endl;
	cout << "Num Of Hours   In Year : " << soln4::NumOfHoursInYear(year) << endl;
	cout << "Num Of Minutes In Year : " << soln4::NumOfMinutesInYear(year) << endl;
	cout << "Num Of Seconds In Year : " << soln4::NumOfSecondsInYear(year) << endl;


}