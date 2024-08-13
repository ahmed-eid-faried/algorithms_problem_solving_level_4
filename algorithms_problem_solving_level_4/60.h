#pragma once
#include "lib.h"
void IsDateInPeriodEx() {
	cout << "\nEnter Period :"<<endl;
	lib::stPeriod Period = lib::ReadPeriod();
	cout << "\nEnter Date to check:\n";
	lib::sDate Date = lib::ReadDate(); if (lib::IsDateInPeriod(Date, Period))
		cout << "\nYes, Date is within period\n"; else
		cout << "\nNo, Date is NOT within period\n";
}