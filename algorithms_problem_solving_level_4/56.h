#pragma once
#include <iostream>
#include "lib.h"
using namespace std;
void IsDate1AfterDate2Ex() {
	cout << "\nEnter Date1:" << endl;
	lib::sDate Date1 = lib::ReadDate();
	cout << "\nEnter Date2:" << endl;
	lib::sDate Date2 = lib::ReadDate();
	if (IsDate1AfterDate2(Date1, Date2))
		cout << "\nYes, Date1 is After Date2."; else
		cout << "\nNo, Date1 is NOT After Date2.";
}