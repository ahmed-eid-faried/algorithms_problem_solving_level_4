#pragma once
#include <iostream>
#include "lib.h"
using namespace std;


void CalculateVacationReturnDateEX() {
	cout << "\nVacation Starts: ";
	lib::sDate DateFrom = lib::ReadDate();

	short VacationDays = lib::ReadNumber("\nPlease enter vacation days? ", true);

	lib::sDate ReturnDate = lib::CalculateVacationReturnDate(DateFrom, VacationDays);

	cout << "\n\nReturn Date: " << lib::DayShortName(lib::DayOfWeekOrderByGergorianCalender(ReturnDate)) << " , "
		<< ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << endl;

}