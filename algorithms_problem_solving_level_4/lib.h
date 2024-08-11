#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
namespace lib {
	struct sDate {
		short Day;
		short Month;
		short Year;
	};
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
	sDate ReadDate() {
		sDate Date;
		Date.Day = soln19::ReadNumberInRange(1, 31, "Please Enter a Day? ");
		Date.Month = soln19::ReadNumberInRange(1, 12, "Please Enter a Month? ");
		Date.Year = soln19::ReadNumber("Please Enter a Year? ");
		return Date;
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
	sDate AddingDaysToDate(short AddDays, sDate Date) {
		short NumOfDaysAfterAddingDays = AddDays + NumOfDaysFromBeginingOfYear(Date.Day, Date.Month, Date.Year);
		short RemainOfDays = NumOfDaysAfterAddingDays;
		while (true) {
			short NumOfDaysInAYear = NumOfDaysInYear(Date.Year);
			if (NumOfDaysAfterAddingDays > NumOfDaysInAYear) {
				RemainOfDays -= NumOfDaysInAYear;
				Date.Year++;
			}
			else { break; }
		}
		Date = GetDateByNumOfDaysInYear(RemainOfDays, Date.Year);
		return Date;
	}
	enum enComparing {
		bigger = 1,
		smaller = 0,
		equal = -1,
	};
	bool Date1IsMoreThanDate2(sDate Date1, sDate Date2) {
		return (Date1.Year != Date2.Year) ? (Date1.Year > Date2.Year) :
			(Date1.Month != Date2.Month) ? (Date1.Month > Date2.Month) :
			(Date1.Day != Date2.Day) ? (Date1.Day > Date2.Day) : false;
	}
	bool IsDate1EqualToDate2(sDate Date1, sDate Date2) {
		return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
	}
	string ResultOfComparing(enComparing Comparing, string Title) {
		switch (Comparing)
		{
		case enComparing::bigger:
			return Title + "1 is " + "more than " + Title + "2\n";
		case enComparing::smaller:
			return Title + "1 is " + "less than " + Title + "2\n";
		case enComparing::equal:
			return Title + "1 is " + "equal to " + Title + "2\n";
		default:
			return Title + "1 is " + "after " + Title + "2\n";
		}
	}
	bool IsLastDay(sDate Date) {
		return Date.Day == NumOfDaysInMonth(Date.Month, Date.Year);

	}
	bool IsLastMonth(sDate Date) {
		return Date.Month == 12;
	}
	sDate IncreaseDateByOneDay(sDate Date) {
		if (!IsLastDay(Date)) { Date.Day += 1; }
		else if (!IsLastMonth(Date)) {
			Date.Day = 1;
			Date.Month += 1;
		}
		else {
			Date.Day = 1;
			Date.Month = 1;
			Date.Year += 1;

		}
		return Date;
	}
	enComparing ComparingTwoDate(sDate Date1, sDate Date2) {
		return (Date1.Year != Date2.Year) ? (enComparing)(Date1.Year > Date2.Year) :
			(Date1.Month != Date2.Month) ? (enComparing)(Date1.Month > Date2.Month) :
			(Date1.Day != Date2.Day) ? (enComparing)(Date1.Day > Date2.Day) : enComparing::equal;
	}

	int Differance2Date(sDate Date1, sDate Date2) {
		int Year = 0;
		for (int i = Date2.Year; i < Date1.Year; i++) { Year += NumOfDaysInYear(i); }
		int NumOfDays1 = NumOfDaysFromBeginingOfYear(Date1.Day, Date1.Month, Date1.Year);
		int NumOfDays2 = NumOfDaysFromBeginingOfYear(Date2.Day, Date2.Month, Date2.Year);
		int del = Year + NumOfDays1 - NumOfDays2;


		return del;
	}

	int GetDifferance2Date(sDate Date1, sDate Date2, bool IncludingEndDay = false) {
		int Days = 0;
		enComparing result = ComparingTwoDate(Date1, Date2);
		int swapflap = 1;
		((bool)result) ? swapflap = -1 : swapflap = 1;
		while (ComparingTwoDate(Date1, Date2) != enComparing::equal)
		{
			Days++;
			result ?
				Date2 = IncreaseDateByOneDay(Date2) :
				Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludingEndDay ? (++Days * swapflap) : (Days * swapflap);
	}


	sDate IncreaseDateByXDays(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	sDate IncreaseDateByOneWeek(sDate Date) { return IncreaseDateByXDays(7, Date); }
	sDate IncreaseDateByXWeeks(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	sDate IncreaseDateByOneMonth(sDate Date) {
		short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);
		return IncreaseDateByXDays(NumOfDaysInAMonth, Date);
		//if (Date.Month == 12) {
		//	Date.Month = 1;
		//	Date.Year++;
		//}
		//else { Date.Month++; }
		//short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);

		//if (Date.Day > NumOfDaysInAMonth) {
		//	Date.Day = NumOfDaysInAMonth;
		//}
		//return Date;
	}
	sDate IncreaseDateByXMonths(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	sDate IncreaseDateByOneYear(sDate Date) {
		//return IncreaseDateByXMonths(12,Date);
		Date.Year++;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	sDate IncreaseDateByXYears(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	sDate IncreaseDateByXYearsFaster(int x, sDate Date) {
		Date.Year += x;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	sDate IncreaseDateByOneDecade(sDate Date) { return IncreaseDateByXYearsFaster(10, Date); }
	sDate IncreaseDateByXDecades(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = IncreaseDateByOneDecade(Date);

		}
		return Date;
	}
	sDate IncreaseDateByXDecadesFaster(int x, sDate Date) { return IncreaseDateByXYearsFaster(x * 10, Date); }
	sDate IncreaseDateByOneCentury(sDate Date) { return IncreaseDateByXYearsFaster(100, Date); }
	sDate IncreaseDateByOneMillennium(sDate Date) { return IncreaseDateByXYearsFaster(1000, Date); }

	bool IsFristDay(sDate Date) {
		return Date.Day == 1;

	}
	bool IsFristMonth(sDate Date) {
		return Date.Month == 1;
	}
	sDate DecreaseDateByOneDay(sDate Date) {
		if (!IsFristDay(Date)) { Date.Day -= 1; }
		else if (!IsFristMonth(Date)) {
			Date.Month -= 1;
			Date.Day = NumOfDaysInMonth(Date.Month, Date.Year);

		}
		else {
			Date.Year -= 1;
			Date.Month = 12;
			Date.Day = 31;
			//Date.Day = NumOfDaysInMonth(Date.Month, Date.Year);
		}
		return Date;
	}
	sDate DecreaseDateByXDays(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	sDate DecreaseDateByOneWeek(sDate Date) { return DecreaseDateByXDays(7, Date); }
	sDate DecreaseDateByXWeeks(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	sDate DecreaseDateByOneMonth(sDate Date) {
		short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);
		return DecreaseDateByXDays(NumOfDaysInAMonth, Date);
		//if (Date.Month == 1) {
		//	Date.Month = 12;
		//	Date.Year--;
		//}
		//else { Date.Month--; }
		//short NumOfDaysInAMonth = NumOfDaysInMonth(Date.Month, Date.Year);
		//if (Date.Day > NumOfDaysInAMonth) { Date.Day = NumOfDaysInAMonth; }
		//return Date;
	}
	sDate DecreaseDateByXMonths(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	sDate DecreaseDateByOneYear(sDate Date) {
		//return DecreaseDateByXMonths(12,Date);
		Date.Year--;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	sDate DecreaseDateByXYears(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}


}


