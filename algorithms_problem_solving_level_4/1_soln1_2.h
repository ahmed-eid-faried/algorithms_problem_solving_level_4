#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace soln1_2 {

	string NumberToTEXt(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "",
		   "One","Two","Three","Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = {
		   "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
		   ,"Ninety" };

			return arr[Number / 10] + " " + NumberToTEXt(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToTEXt(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToTEXt(Number / 100) + "Hundreds " +
				NumberToTEXt(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToTEXt(Number % 1000);
		}


		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToTEXt(Number / 1000) + "Thousands " +
				NumberToTEXt(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToTEXt(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToTEXt(Number / 1000000) + "Millions " +
				NumberToTEXt(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToTEXt(Number %
				1000000000);
		}
		else
		{
			return NumberToTEXt(Number / 1000000000) + "Billions " +
				NumberToTEXt(Number % 1000000000);
		}
	}
	int ReadNumber()
	{
		int Number;
		cout << "\nEnter a Number? ";
		cin >> Number;
		return Number;
	}
}




void ConvertNumbersToStringEX2() {
	int Number = soln1_2::ReadNumber();
	cout << soln1_2::NumberToTEXt(Number);

}
