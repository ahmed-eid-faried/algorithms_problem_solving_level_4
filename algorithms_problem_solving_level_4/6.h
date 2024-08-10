#pragma once
#include <iostream>
using namespace std;
namespace soln6 {
#include <iostream>


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
	bool isLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}
	short NumOfDaysInYear(short Year) {
		return isLeapYear(Year) ? 366 : 365;
	}

	short NumOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)return 0;
		int Days[12] = { 31, 28,  31,  30,  31,  30, 31,  31,  30,  31,  30,  31 };

		return	(Month == 2) ? (isLeapYear(Year) ? 29 : 28) : Days[Month - 1];
	}
	//other method
	short NumOfDaysInMonth2(short Month, short Year)
	{
		if (Month < 1 || Month>12)return 0;
		return	(Month == 2) ? (isLeapYear(Year) ? 29 : 28) : ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
	}


	short NumOfHoursInMonth(short Month, short Year) {
		return  NumOfDaysInMonth(Month, Year) * 24;
	}
	int NumOfMinutesInMonth(short Month, short Year) {
		return NumOfHoursInMonth(Month, Year) * 60;
	}
	int NumOfSecondsInMonth(short Month, short Year) {
		return NumOfMinutesInMonth(Month, Year) * 60;
	}



}



void NumbersOfDaysInMonthEx2() {
	short Year = soln6::ReadNumber("Please Enter a Year to check? ");
	short Month = soln6::ReadNumber("Please Enter a Month to check? ");
	cout << "Num Of Days    In Month : " << soln6::NumOfDaysInMonth(Month, Year) << endl;
	cout << "Num Of Hours   In Month : " << soln6::NumOfHoursInMonth(Month, Year) << endl;
	cout << "Num Of Minutes In Month : " << soln6::NumOfMinutesInMonth(Month, Year) << endl;
	cout << "Num Of Seconds In Month : " << soln6::NumOfSecondsInMonth(Month, Year) << endl;


}