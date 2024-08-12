#pragma once
#include "lib.h"
void CompareDatesEx() {
	cout << "\nEnter Date1:";
	lib::sDate Date1 = lib::ReadDate();
	cout << "\nEnter Date2:";
	lib::sDate Date2 = lib::ReadDate();
	cout << "\nCompare Result = " << lib::ComparingTwoDate(Date1, Date2);

}