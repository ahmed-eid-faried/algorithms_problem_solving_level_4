#pragma once
#include "lib.h"

void DateProblemsEx()
{
	lib::sDate Date1 = lib::GetSystemDate();
	cout << "\nToday is " << lib::DayShortName(lib::DayOfWeekOrderByGergorianCalender(Date1))
		<< " , "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year <<
		endl;
	//---------------------
	cout << "\nIs it End of Week?\n";
	if (lib::IsEndOfWeek(Date1))
		cout << "Yes it is Saturday, it's of Week.";
	else
		cout << "No it's Not end of week.";
	//---------------------
	cout << "\n\nIs it Weekend?\n";
	if (lib::IsWeekEnd(Date1))
		cout << "Yes it is a week end.";
	else
		cout << "No today is " <<
		lib::DayShortName(lib::DayOfWeekOrderByGergorianCalender(Date1)) << ", Not a weekend.";
	//---------------------
	cout << "\n\nIs it Business Day?\n";
	if (lib::IsBusinessDay(Date1))
		cout << "Yes it is a business day.";
	else
		cout << "No it is NOT a business day.";
	//---------------------
	cout << "\n\nDays until end of week : "
		<< lib::DaysUntilTheEndOfWeek(Date1) << " Day(s).";
	//---------------------
	cout << "\nDays until end of month : "
		<< lib::DaysUntilTheEndOfMonth(Date1) << " Day(s).";
	//---------------------
	cout << "\nDays until end of year : "
		<< lib::DaysUntilTheEndOfYear(Date1) << " Day(s).";

}