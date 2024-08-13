#pragma once
#include "lib.h"
void FormateDateEx() {
	string DateString = lib::ReadStringDate();
	lib::sDate Date = lib::StringToDate(DateString);
	cout << "\n" << lib::FormateDate(Date) << "\n";
	cout << "\n" << lib::FormateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << lib::FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << lib::FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << lib::FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << lib::FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
}