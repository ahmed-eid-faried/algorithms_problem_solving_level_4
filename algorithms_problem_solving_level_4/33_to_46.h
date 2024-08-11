#pragma once
#include "lib.h"
void DecreaseDateEx() {
	lib::sDate Date1 = lib::ReadDate();
	cout << "\nDate After: \n";
	Date1 = lib::DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXDays(10, Date1);
	cout << "\n02-Subtracting 10 days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting one week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXWeeks(10, Date1);
	cout << "\n04-Subtracting 10 weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting one month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXMonths(5, Date1);
	cout << "\n06-Subtracting 5 months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting one year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXYears(10, Date1);
	cout << "\n08-Subtracting 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXYearsFaster(10, Date1);
	cout << "\n09-Subtracting 10 Years (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting one Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXDecades(10, Date1);
	cout << "\n11-Subtracting 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByXDecadesFaster(10, Date1);
	cout << "\n12-Subtracting 10 Decade (faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
	Date1 = lib::DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting One Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
}
