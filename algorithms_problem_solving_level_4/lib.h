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
	short ReadNumber(string Message, bool shortNum)
	{
		short Num;
		cout << Message;
		cin >> Num;
		return Num;
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
	short DayOfWeekOrderByGergorianCalender(short Day, short Month, short Year) {
		int a = (14 - Month) / 12;
		int y = Year - a;
		int m = Month + 12 * a - 2;
		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
	short DayOfWeekOrderByGergorianCalender(sDate Date) {
		return DayOfWeekOrderByGergorianCalender(Date.Day, Date.Month, Date.Year);
	}
	string DayShortName(enDaysOfWeek day) {
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
	string DayShortName(short Num) {
		return DaysOfWeek[Num];
	}
	string MonthsShortName(short Month) {
		string MonthsOfYear[12] = { "Jan" ,"Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return MonthsOfYear[Month - 1];
	}
	void BodyMonthCalender(short Month, short Year) {

		short NumOfDaysInAMonth = NumOfDaysInMonth(Month, Year);
		short OrderOfFristDay = DayOfWeekOrderByGergorianCalender(1, Month, Year);
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

	short NumOfDaysFromBeginingOfYear(sDate Date) {
		return  NumOfDaysFromBeginingOfYear(Date.Day, Date.Month, Date.Year);
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
		Before = -1,
		Equal = 0,
		After = 1
	};
	enComparing ReturnComparingDateValue(bool state) {
		return state ? enComparing::After : enComparing::Before;
	}
	bool IsDate1EqualToDate2(sDate Date1, sDate Date2) {
		return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
	}
	enComparing ComparingTwoDate(sDate Date1, sDate Date2) {
		return (Date1.Year != Date2.Year) ? ReturnComparingDateValue(Date1.Year > Date2.Year) :
			(Date1.Month != Date2.Month) ? ReturnComparingDateValue(Date1.Month > Date2.Month) :
			(Date1.Day != Date2.Day) ? ReturnComparingDateValue(Date1.Day > Date2.Day) : enComparing::Equal;
	}

	bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
		return ComparingTwoDate(Date1, Date2) == enComparing::Before;
	}
	bool IsDate1AfterDate2(sDate Date1, sDate Date2) {
		return ComparingTwoDate(Date1, Date2) == enComparing::After;
	}
	bool IsDate1EqualDate2(sDate Date1, sDate Date2) {
		return ComparingTwoDate(Date1, Date2) == enComparing::Equal;
	}

	string ResultOfComparing(enComparing Comparing, string Title) {
		switch (Comparing)
		{
		case enComparing::After:
			return Title + "1 is " + "After " + Title + "2\n";
		case enComparing::Before:
			return Title + "1 is " + "before " + Title + "2\n";
		case enComparing::Equal:
			return Title + "1 is " + "Equal to " + Title + "2\n";
		default:
			return Title + "1 is " + "After " + Title + "2\n";
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


	int Differance2Date(sDate Date1, sDate Date2, bool IncludingEndDay = false) {
		int Year = 0;
		for (int i = Date2.Year; i < Date1.Year; i++) { Year += NumOfDaysInYear(i); }
		int NumOfDays1 = NumOfDaysFromBeginingOfYear(Date1.Day, Date1.Month, Date1.Year);
		int NumOfDays2 = NumOfDaysFromBeginingOfYear(Date2.Day, Date2.Month, Date2.Year);
		int del = Year + NumOfDays1 - NumOfDays2;


		return IncludingEndDay ? ++del : del;
	}

	//int GetDifferance2Date(sDate Date1, sDate Date2, bool IncludingEndDay = false) {
	//	int Days = 0;
	//	enComparing result = ComparingTwoDate(Date1, Date2);
	//	int swapflap = 1;
	//	((bool)result) ? swapflap = -1 : swapflap = 1;
	//	while (ComparingTwoDate(Date1, Date2) != enComparing::Equal)
	//	{
	//		Days++;
	//		result ?
	//			Date2 = IncreaseDateByOneDay(Date2) :
	//			Date1 = IncreaseDateByOneDay(Date1);
	//	}
	//	return IncludingEndDay ? (++Days * swapflap) : (Days * swapflap);
	//}

	int GetDifferance2Date(sDate Date1, sDate Date2, bool IncludingEndDay = false) {
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludingEndDay ? ++Days : Days;
	}
	struct stPeriod {
		sDate From;
		sDate To;
	};
	stPeriod ReadPeriod() {
		stPeriod P;
		cout << "\n Start Date: "<<endl;
		P.From = ReadDate();
		cout << "\n End Date: " << endl;
		P.To = ReadDate();
		return P;
	};
	bool IsOverlapPeriods(stPeriod P1, stPeriod P2) {
		enComparing ComparingP1FromWithP2From = ComparingTwoDate(P1.From, P2.From);
		enComparing ComparingP1ToWithP2To = ComparingTwoDate(P1.To, P2.To);
		enComparing ComparingP1FromWithP2To = ComparingTwoDate(P1.From, P2.To);
		enComparing ComparingP1ToWithP2From = ComparingTwoDate(P1.To, P2.From);
		//short
	/*	if (ComparingP1ToWithP2From == enComparing::Before || ComparingP1FromWithP2To == enComparing::After) { return true; }
		else { return false; }*/
		if (ComparingP1FromWithP2From == enComparing::Before
			&& ComparingP1ToWithP2To == enComparing::Before
			&& ComparingP1FromWithP2To == enComparing::Before
			&& ComparingP1ToWithP2From == enComparing::Before) {
			return false;
		}
		else if (
			ComparingP1FromWithP2From == enComparing::After
			&& ComparingP1ToWithP2To == enComparing::After
			&& ComparingP1FromWithP2To == enComparing::After
			&& ComparingP1ToWithP2From == enComparing::After) {
			return false;
		}
		else {
			return true;
		}
	}

	int PeriodLengthInDays(stPeriod P1, bool IncludingEndDate = false) {
		return GetDifferance2Date(P1.From, P1.To, IncludingEndDate);
	}
	bool IsDateInPeriod(sDate Date, stPeriod P) {
		return ((IsDate1BeforeDate2(P.From, Date) || IsDate1EqualDate2(P.From, Date))
			&& (IsDate1EqualDate2(P.To, Date) || IsDate1AfterDate2(P.To, Date)));
	}
	tm* GetNowDate() {
		// current date/time based on current system
		time_t now = time(0);
		// Create a tm structure to hold the result
		static tm localTime;
		// Use localtime_s to safely convert the time
		localtime_s(&localTime, &now);
		return &localTime;
	}
	sDate GetSystemDate() {
		sDate Date;
		Date.Year = GetNowDate()->tm_year + 1900;
		Date.Month = GetNowDate()->tm_mon + 1;
		Date.Day = GetNowDate()->tm_mday;
		return Date;
	}

	int CalculateYourAgeInDay(sDate Date) {
		sDate DateNow = GetSystemDate();
		int NumOfDays = GetDifferance2Date(DateNow, Date);
		return NumOfDays;
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
	sDate DecreaseDateByXYearsFaster(int x, sDate Date) {
		Date.Year -= x;
		if (!isLeapYear(Date.Year))
		{
			if (Date.Month == 2 && Date.Day == 29)Date.Day == 28;
		}
		return Date;
	}
	sDate DecreaseDateByOneDecade(sDate Date) { return DecreaseDateByXYearsFaster(10, Date); }
	sDate DecreaseDateByXDecades(int x, sDate Date) {
		for (int i = 0; i < x; i++)
		{
			Date = DecreaseDateByOneDecade(Date);

		}
		return Date;
	}
	sDate DecreaseDateByXDecadesFaster(int x, sDate Date) {
		return DecreaseDateByXYearsFaster(x * 10, Date);
	}
	sDate DecreaseDateByOneCentury(sDate Date) { return DecreaseDateByXYearsFaster(100, Date); }
	sDate DecreaseDateByOneMillennium(sDate Date) { return DecreaseDateByXYearsFaster(1000, Date); }

	bool IsEndOfWeek(sDate Date) {
		//6=>saturday and 0=>sunday
		return DayOfWeekOrderByGergorianCalender(Date) == 6;
	}
	bool IsWeekEnd(sDate Date) {
		//6=>saturday , 5=>friday and 0=>sunday
		short DayIndex = DayOfWeekOrderByGergorianCalender(Date);
		return DayIndex == 6 || DayIndex == 5;
	}
	bool IsBusinessDay(sDate Date) {
		return !IsWeekEnd(Date);
	}

	short DaysUntilTheEndOfWeek(sDate Date) {
		return 6 - DayOfWeekOrderByGergorianCalender(Date);
	}

	short DaysUntilTheEndOfMonth(sDate Date) {
		return  NumOfDaysInMonth(Date.Month, Date.Year) - Date.Day;
	}

	short DaysUntilTheEndOfYear(sDate Date) {
		return  NumOfDaysInYear(Date.Year) - NumOfDaysFromBeginingOfYear(Date);
	}
	short CalculateVacationDays(sDate FromDate, sDate ToDate) {
		short VacationDays = 0;
		if (ComparingTwoDate(FromDate, ToDate) == enComparing::After)return 0;
		while (ComparingTwoDate(FromDate, ToDate) != enComparing::Equal)
		{
			if (IsBusinessDay(FromDate)) 				VacationDays++;
			FromDate = IncreaseDateByOneDay(FromDate);

		}
		return VacationDays;
	}

	sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays) {
		int counter = 0;
		while (VacationDays >= counter)
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
			if (IsBusinessDay(DateFrom)) {
				counter++;
			}

		}
		return DateFrom;
	}

	sDate CalculateVacationReturnDate2(sDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
}


