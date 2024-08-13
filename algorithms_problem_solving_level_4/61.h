#pragma once
#include "lib.h"
void CountOverlapDaysEx() {
	cout << "\nEnter Period 1 :";
	lib::stPeriod Period1 = lib::ReadPeriod();
	cout << "\nEnter Period 2 :";
	lib::stPeriod Period2 = lib::ReadPeriod();
	cout << "\nOverlap Days Count Is: " << lib::CountOverlapDays(Period1, Period2);
}