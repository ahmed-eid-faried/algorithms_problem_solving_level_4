#pragma once
#include "lib.h"
void IsOverlapPeriodsEX() {
	cout << "\nEnter Period 1:";
	lib::stPeriod Period1 = lib::ReadPeriod();
	cout << "\nEnter Period 2:";
	lib::stPeriod Period2 = lib::ReadPeriod();
	if (lib::IsOverlapPeriods(Period1, Period2))
		cout << "\nYes, Periods Overlap\n"; else   
		cout << "\nNo, Periods do not Overlap\n";
}