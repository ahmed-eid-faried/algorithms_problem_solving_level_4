#pragma once
#include <iostream>
#include "lib.h"
using namespace std;


void CalculateVacationDaysEx() {
	cout << "Vacation Date: \n" << endl;
	cout << "Vacation Starts: " << endl;
	lib::sDate From = lib::ReadDate();
	cout << "\nVacation End: " << endl;
	lib::sDate To = lib::ReadDate();
	cout << "\nVacation Starts: " << lib::DayShortName(lib::DayOfWeekOrderByGergorianCalender(From))
		<< " , "
		<< From.Day << "/" << From.Month << "/" << From.Year <<
		endl;
	cout << "\nVacation End: " << lib::DayShortName(lib::DayOfWeekOrderByGergorianCalender(To))
		<< " , "
		<< To.Day << "/" << To.Month << "/" << To.Year <<
		endl;
	cout << "\nActual Vacatin Days is: " << lib::CalculateVacationDays(From, To);
}