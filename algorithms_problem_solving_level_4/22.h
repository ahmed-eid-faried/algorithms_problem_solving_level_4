#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "lib.h"
using namespace std;

void IncreaseDateByXWeeksEX() {
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
 
}