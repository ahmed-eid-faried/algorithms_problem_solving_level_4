#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
namespace soln11 {

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
	string DaysOfWeek[7] = { "Sun" ,"Mon","Tue","Wed","Thu","Fri","Sat" };
	string MonthsShortName(short Month) {
		string MonthsOfYear[12] = { "Jan" ,"Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return MonthsOfYear[Month - 1];
	}

	void BodyMonthCalender(short Month, short Year) {

		short NumOfDaysInAMonth = NumOfDaysInMonth(Month, Year);
		short OrderOfFristDay = FindDayNameOfWeekByDateGergorianCalender(1, Month, Year);
		int CurrentDay = 1;
		for (int i = 0; i < NumOfDaysInAMonth + OrderOfFristDay; i++)
		{

			if (i >= OrderOfFristDay) {
				cout << right << setw(3) << CurrentDay;
				CurrentDay++;
				cout << " ";
				if ((i + 1) % 7 == 0)cout << endl;
			}
			else {
				cout << right << setw(3) << " ";
				cout << " ";
			}


		}
		cout << endl;
	}

	void PrintMonthCalender(short Month, short Year) {
		cout << "------------" << MonthsShortName(Month) << "------------" << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << DaysOfWeek[i];
			cout << " ";

		}
		cout << endl;

		BodyMonthCalender(Month, Year);
		cout << "---------------------------" << endl;
	}
	void PrintMonthYearCalender(short Year) {
		cout << "---------------------------" << endl;

		cout << "     Calender " << Year << "      " << endl;
		cout << "---------------------------" << endl << endl;

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, Year);
			cout << endl;
		}
		cout << "---------------------------" << endl;

	}
	short NumOfDaysFromBeginingOfYear(short Day, short Month, short Year) {
		short NumOfDays = Day;
		for (short i = 1; i < Month; i++)
		{
			NumOfDays += NumOfDaysInMonth(i, Year);
		}
		return NumOfDays;
	}
	struct sDate {
		short Day;
		short Month;
		short Year;
	};
	sDate GetDateByNumOfDaysInYear(short NumOfDays, short Year) {
		sDate Date;
		for (short i = 1; i <= 12; i++)
		{
			short NumOfDaysInAMonth = NumOfDaysInMonth(i, Year);
			if (NumOfDays > NumOfDaysInAMonth) {
				NumOfDays -= NumOfDaysInMonth(i, Year);
				Date.Month = i + 1;
			}
			else { break; }
		}
		Date.Day = NumOfDays;
		Date.Year = Year;
		return Date;
	}
}



void PrintDateByNumOfDaysInYearEX() {
	short Day = soln11::ReadNumberInRange(1,31,"Please Enter a Day? ");
	short Month = soln11::ReadNumberInRange(1,12,"Please Enter a Month? ");
	short Year = soln11::ReadNumber("Please Enter a Year? ");
	cout << endl;
	short NumOfDays = soln11::NumOfDaysFromBeginingOfYear(Day, Month, Year);
	cout << "Numbers Of Days From Begining Of Year: " << NumOfDays << endl;
	cout << "Date for [" << NumOfDays << "]: ";
	soln11::sDate Date = soln11::GetDateByNumOfDaysInYear(NumOfDays, Year);
	printf("%5d/%5d/%5d", Date.Day, Date.Month, Date.Year);
	cout << endl;
}