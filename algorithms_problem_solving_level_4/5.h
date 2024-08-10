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
	bool isLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}
	short NumOfDaysInYear(short Year) {
		return isLeapYear(Year) ? 366 : 365;
	}
	short NumOfDaysInMonth(short Month, short Year) {
		switch ((enMonths)Month) {
		case enMonths::January: return 31;
		case enMonths::February: return isLeapYear(Year) ? 29 : 28;
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
	short NumOfHoursInMonth(short Month, short Year) {
		return  NumOfDaysInMonth(Month, Year) * 24;
	}
	int NumOfMinutesInMonth(short Month, short Year) {
		return NumOfHoursInMonth(Month, Year) * 60;
	}
	int NumOfSecondsInMonth(short Month, short Year) {
		return NumOfMinutesInMonth(Month, Year) * 60;
	}


	//other method
	short NumberOfDaysInAMonth2(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		if (Month == 2)
		{
			return isLeapYear(Year) ? 29 : 28;
		}
		short arr31Days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 1; i <= 7; i++)
		{
			if (arr31Days[i - 1] == Month)
				return 31;
		}
		//if you reach here then its 30 days.
		return 30;
	}

}



void NumbersOfDaysInMonthEx() {
	short Year = soln5::ReadNumber("Please Enter a Year to check? ");
	short Month = soln5::ReadNumber("Please Enter a Month to check? ");
	cout << "Num Of Days    In Month : " << soln5::NumOfDaysInMonth(Month, Year) << endl;
	cout << "Num Of Hours   In Month : " << soln5::NumOfHoursInMonth(Month, Year) << endl;
	cout << "Num Of Minutes In Month : " << soln5::NumOfMinutesInMonth(Month, Year) << endl;
	cout << "Num Of Seconds In Month : " << soln5::NumOfSecondsInMonth(Month, Year) << endl;


}