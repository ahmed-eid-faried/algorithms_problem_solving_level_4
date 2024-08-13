#pragma once
#include "lib.h"
void xx() {
	lib::sDate Date1 = lib::ReadDate();
	if (lib::IsValidDate(Date1))
		cout << "\nYes, Date is a valide date.\n";
	else
		cout << "\nNo, Date is a NOT valide date\n";
}