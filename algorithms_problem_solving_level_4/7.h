#pragma once
#include <iostream>
using namespace std;
namespace soln7 {
#include <iostream>

	int ReadNumberInRange(int From, int To, string Message = "ENTER NUMBER") {
		int NUM;
		do {
			cout << Message << " FROM " << to_string(From) << " TO " << to_string(To) << ": ";
			cin >> NUM;
		} while (NUM < From || NUM > To);
		return NUM;
	}

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
	enum enDaysOfWeek {
		Sunday = 0,
		Monday = 1,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};
	short FindDayNameOfWeekByDateGergorianCalender(short Day, short Month, short Year) {
		int a = (14 - Month) / 12;
		int y = Year - a;
		int m = Month + 12 * a - 2;
		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
	string GetNameOfDayByOrder(enDaysOfWeek day) {
		switch (day)
		{
		case enDaysOfWeek::Sunday:
			return "Sunday";
		case enDaysOfWeek::Monday:
			return "Monday";
		case enDaysOfWeek::Tuesday:
			return "Tuesday";
		case enDaysOfWeek::Wednesday:
			return "Wednesday";
		case enDaysOfWeek::Thursday:
			return "Thursday";
		case enDaysOfWeek::Friday:
			return "Friday";
		case enDaysOfWeek::Saturday:
			return "Saturday";
		default:
			return "Sunday";
		}
	}
	string DaysOfWeek[7] = { "Sunday" ,"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

}



void FindDayNameOfWeekByDateEX() {
	short Year = soln7::ReadNumber("Please Enter a Year? ");
	short Month = soln7::ReadNumberInRange(1,12,"Please Enter a Month? ");
	short Day = soln7::ReadNumberInRange(1,31,"Please Enter a Day? ");
	cout << "Date      : " << Day << '/' << Month << '/' << Year << endl;
	short OrderedDay = soln7::FindDayNameOfWeekByDateGergorianCalender(Day, Month, Year);
	cout << "Day Order : " << OrderedDay << endl;
	cout << "Day Name  : " << soln7::DaysOfWeek[OrderedDay] << endl;
}