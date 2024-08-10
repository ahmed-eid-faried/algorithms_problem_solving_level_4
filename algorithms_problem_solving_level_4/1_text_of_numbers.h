#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace soln1 {
	int ReadNumber()
	{
		int Number;
		cout << "\nEnter a Number? ";
		cin >> Number;
		return Number;
	}
	enum enOnesPlace {
		Zero = 0,
		One = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
	};
	enum enTeenNumbers {
		Ten = 10,
		Eleven,
		Twelve,
		Thirteen,
		Fourteen,
		Fifteen,
		Sixteen,
		Seventeen,
		Eighteen,
		Nineteen,
	};
	enum enTensPlace {
		Twenty = 20,
		Thirty = 30,
		Forty = 40,
		Fifty = 50,
		Sixty = 60,
		Seventy = 70,
		Eighty = 80,
		Ninety = 90,
	};
	enum enPlaces {
		Ones = 0,
		Thousand = 1,
		Million = 2,
		Billion = 3,
		Trillion = 4,
	};
	string OnesPlace(enOnesPlace OnesPlace) {
		switch (OnesPlace)
		{
		case enOnesPlace::Zero:
			return "";
		case enOnesPlace::One:
			return "One";
		case enOnesPlace::Two:
			return "Two";
		case enOnesPlace::Three:
			return "Three";
		case enOnesPlace::Four:
			return "Four";
		case enOnesPlace::Five:
			return "Five";
		case enOnesPlace::Six:
			return "Six";
		case enOnesPlace::Seven:
			return "Seven";
		case enOnesPlace::Eight:
			return "Eight";
		case enOnesPlace::Nine:
			return "Nine";
		default:
			return "";
		}
	}
	string TeenNumbers(enTeenNumbers TeenNumbers) {
		switch (TeenNumbers)
		{
		case enTeenNumbers::Ten:
			return "Ten";
		case enTeenNumbers::Eleven:
			return "Eleven";
		case enTeenNumbers::Twelve:
			return "Twelve";
		case enTeenNumbers::Thirteen:
			return "Thirteen";
		case enTeenNumbers::Fourteen:
			return "Fourteen";
		case enTeenNumbers::Fifteen:
			return "Fifteen";
		case enTeenNumbers::Sixteen:
			return "Sixteen";
		case enTeenNumbers::Seventeen:
			return "Seventeen";
		case enTeenNumbers::Eighteen:
			return "Eighteen";
		case enTeenNumbers::Nineteen:
			return "Nineteen";
		default:
			return "";
		}
	}
	string TensPlace(enTensPlace TensPlace) {
		switch (TensPlace)
		{
		case enTensPlace::Twenty:
			return "Twenty";
		case enTensPlace::Thirty:
			return "Thirty";
		case enTensPlace::Forty:
			return "Forty";
		case enTensPlace::Fifty:
			return "Fifty";
		case enTensPlace::Sixty:
			return "Sixty";
		case enTensPlace::Seventy:
			return "Seventy";
		case enTensPlace::Eighty:
			return "Eighty";
		case enTensPlace::Ninety:
			return "Ninety";
		default:
			return "";
		}
	}
	//enum enOneOrNo {
	//	One = true, No = false,
	//};
	vector<int> numberToDigits(int number) {
		vector<int> digits;

		// Handle the case where the number is 0
		if (number == 0) {
			digits.push_back(0);
			return digits;
		}

		// Handle negative numbers
		if (number < 0) {
			number = -number;
		}

		// Extract digits and store them in the vector
		while (number > 0) {
			int digit = number % 10;
			digits.insert(digits.begin(), digit); // Insert at the beginning to maintain order
			number /= 10;
		}

		return digits;
	}
	vector<int> numberToThreeDigitChunks(int number) {
		vector<int> chunks;

		// Handle the case where the number is 0
		if (number == 0) {
			chunks.push_back(0);
			return chunks;
		}

		// Handle negative numbers
		if (number < 0) {
			number = -number;
		}

		// Extract 3-digit chunks and store them in the vector
		while (number > 0) {
			int chunk = number % 1000;
			chunks.insert(chunks.begin(), chunk); // Insert at the beginning to maintain order
			number /= 1000;
		}

	}

	string ConvertThreeDigitChunkToString(int LastThreeDigitChunk) {
		if (LastThreeDigitChunk < 10) {
			return	OnesPlace((enOnesPlace)LastThreeDigitChunk);
		}
		else if (LastThreeDigitChunk < 20) {
			return	TeenNumbers((enTeenNumbers)LastThreeDigitChunk);
		}
		else if (LastThreeDigitChunk < 100) {
			vector<int> DigitsList = numberToDigits(LastThreeDigitChunk);
			string Separator = "";
			if (DigitsList[1] != 0)Separator = "-";
			return	TensPlace((enTensPlace)(DigitsList[0] * 10)) + Separator + OnesPlace((enOnesPlace)DigitsList[1]);
		}
		else if (LastThreeDigitChunk < 1000) {
			//cout << "====>>>> " << LastThreeDigitChunk << endl;
			vector<int> DigitsList = numberToDigits(LastThreeDigitChunk);
			string Separator1 = "";
			if (DigitsList[0] != 0) {
				(DigitsList[0] == 1) ? (Separator1 = " hundred ") : (Separator1 = " hundreds ");
			}
			string Separator2 = "";
			if (DigitsList[1] != 0 && DigitsList[2] != 0)Separator2 = "-";
			return OnesPlace((enOnesPlace)DigitsList[0]) +
				Separator1 +
				ConvertThreeDigitChunkToString((DigitsList[1] * 10) + (DigitsList[2]));
		}
	}
	string Places(enPlaces Place) {
		switch (Place)
		{
		case enPlaces::Ones:
			return "";
		case enPlaces::Thousand:
			return " Thousand";
		case enPlaces::Million:
			return " Million";
		case enPlaces::Billion:
			return " Billion";
		case soln1::Trillion:
			return " Trillion";
		default:
			return "";
		}
	}
	string ConvertNumbersToString(int  Num) {
		vector<int> ThreeDigitChunks = numberToThreeDigitChunks(Num);
   		string str = "";
		for (int i = 0; i < ThreeDigitChunks.size(); i++)
		{
			str += ConvertThreeDigitChunkToString(ThreeDigitChunks[i]);
			if (ThreeDigitChunks[i] != 0) { str += Places((enPlaces)(ThreeDigitChunks.size() - 1 - i)); }
			if (i != ThreeDigitChunks.size() - 1) {
				if (ThreeDigitChunks[i] != 1 && ThreeDigitChunks[i] != 0 && i > 0) { str += "s"; }
				if (ThreeDigitChunks[i + 1] != 0)str += " and ";

			}

		}
		return str;
	}






}
void ExampleConvertNumbersToString() {
	cout << soln1::ConvertNumbersToString(0) << endl;
	cout << soln1::ConvertNumbersToString(1) << endl;
	cout << soln1::ConvertNumbersToString(6) << endl;
	cout << soln1::ConvertNumbersToString(11) << endl;
	cout << soln1::ConvertNumbersToString(16) << endl;
	cout << soln1::ConvertNumbersToString(19) << endl;
	cout << soln1::ConvertNumbersToString(20) << endl;
	cout << soln1::ConvertNumbersToString(21) << endl;
	cout << soln1::ConvertNumbersToString(55) << endl;
	cout << soln1::ConvertNumbersToString(80) << endl;
	cout << soln1::ConvertNumbersToString(99) << endl;
	cout << soln1::ConvertNumbersToString(100) << endl;
	cout << soln1::ConvertNumbersToString(101) << endl;
	cout << soln1::ConvertNumbersToString(222) << endl;
	cout << soln1::ConvertNumbersToString(1111) << endl;
	cout << soln1::ConvertNumbersToString(1234) << endl;
	cout << soln1::ConvertNumbersToString(1234567890) << endl;
	cout << soln1::ConvertNumbersToString(1257899999) << endl;
}
void ConvertNumbersToStringEx() {
	//ExampleConvertNumbersToString();
	int Number = soln1::ReadNumber();
	cout << soln1::ConvertNumbersToString(Number);
}
