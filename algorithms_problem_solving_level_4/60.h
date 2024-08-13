#pragma once
#include "lib.h"
void xx() {
	cout << "\nEnter Period :";
	lib::stPeriod Period = lib::ReadPeriod();
	cout << "\nEnter Date to check:\n";
	lib::stDate Date = lib::ReadDate(); if (lib::IsDateInPeriod(Date, Period))
		cout << "\nYes, Date is within period\n"; else
		cout << "\nNo, Date is NOT within period\n";
}