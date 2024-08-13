#pragma once
#include "lib.h"
void CalCulatePeriodLength() {
	cout << "\nEnter Period 1:";
	lib::stPeriod Period1 = lib::ReadPeriod();
	cout << "\nPeriod Length is: " << lib::PeriodLengthInDays(Period1);
	cout << "\nPeriod Length (Including End Date) is: " << lib::PeriodLengthInDays(Period1, true);
}