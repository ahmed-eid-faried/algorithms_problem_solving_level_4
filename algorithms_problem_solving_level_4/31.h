#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "lib.h"
using namespace std;

void IncreaseDateByOneCenturyEX() {
	lib::sDate Date1 = lib::ReadDate();
	cout << "\nDate After: \n";
	Date1 = lib::IncreaseDateByOneDay(Date1);
	cout << "\n01-Adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;


	Date1 = lib::IncreaseDateByXDays(10, Date1);
	cout << "\n02-Adding 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByXWeeks(10, Date1);
	cout << "\n04-Adding 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByXMonths(5, Date1);

	cout << "\n06-Adding 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByXYears(10, Date1);
	cout << "\n08-Adding 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Adding 10 Years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = lib::IncreaseDateByXDecades(10, Date1);
	cout << "\n11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Adding 10 Decade (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
 
}