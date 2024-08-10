#pragma once
#include <iostream>
using namespace std;
namespace soln5 {
#include <iostream>

	enum enMonths {
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};

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
	bool isLeapYear(short year) {
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	short NumOfDaysInYear(short year) {
		return isLeapYear(year) ? 366 : 365;
	}
	short NumOfDaysInMonth(short year, short month) {
		switch ((enMonths)month) {
		case enMonths::January: return 31;
		case enMonths::February: return isLeapYear(year) ? 29 : 28;
		case enMonths::March: return 31;
		case enMonths::April: return 30;
		case enMonths::May: return 31;
		case enMonths::June: return 30;
		case enMonths::July: return 31;
		case enMonths::August: return 31;
		case enMonths::September: return 30;
		case enMonths::October: return 31;
		case enMonths::November: return 30;
		case enMonths::December: return 31;
		default: return 0;
		}
	}
	short NumOfHoursInMonth(short year, short month) {
		return  NumOfDaysInMonth(year, month) * 24;
	}
	int NumOfMinutesInMonth(short year, short month) {
		return NumOfHoursInMonth(year, month) * 60;
	}
	int NumOfSecondsInMonth(short year, short month) {
		return NumOfMinutesInMonth(year, month) * 60;
	}

}



void NumbersOfDaysInMonthEx() {
	short year = soln5::ReadNumber("Please Enter a Year to check? ");
	short month = soln5::ReadNumber("Please Enter a Month to check? ");
	cout << "Num Of Days    In Month : " << soln5::NumOfDaysInMonth(year, month) << endl;
	cout << "Num Of Hours   In Month : " << soln5::NumOfHoursInMonth(year, month) << endl;
	cout << "Num Of Minutes In Month : " << soln5::NumOfMinutesInMonth(year, month) << endl;
	cout << "Num Of Seconds In Month : " << soln5::NumOfSecondsInMonth(year, month) << endl;


}