#pragma once
#include "lib.h"
void StringToDateAndDateToStringEx() {
	string DateString = lib::ReadStringDate();
	lib::sDate Date = lib::StringToDate(DateString);
	cout << "\nDay:" << Date.Day << endl;
	cout << "Month:" << Date.Month << endl;
	cout << "Year:" << Date.Year << endl;
	cout << "\nYou Entered: " << lib::DateToString(Date) << "\n";
}