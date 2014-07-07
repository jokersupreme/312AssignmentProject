#include <iostream>
#include "basic_functions.h"

using namespace std;

static int FunctionCount = 0;
bool AND(bool a, bool b)
{
	if (a && b)
	{
		FunctionCount++;
		return true;
	}
	else
	{
		FunctionCount++;
		return false;
	}	
}
bool OR(bool a, bool b)
{
	if(a || b)
	{
		FunctionCount++;
		return true;
	}
	else
	{
		FunctionCount++;
		return false;
	}
}
bool NOT(bool a)
{
	if(a)
	{
		FunctionCount++;
		return false;
	}
	else
	{
		FunctionCount++;
		return true;
	}
}
void printFunctioncount()
{
	cout << FunctionCount << endl;
}
void print(bool a)
{
	cout << a << endl;
}
void resetFunctionCount()
{
	FunctionCount = 0;
}
bool getValue(bool byte[8], int offset)
{
	return byte[offset];
}
void writeValue(bool* byte, int offset, bool value)
{
	//////
}
void printValue(bool byte[8])
{
	cout << byte[0];
	cout << byte[1];
	cout << byte[2];
	cout << byte[3];
	cout << byte[4];
	cout << byte[5];
	cout << byte[6];
	cout << byte[7] << endl;
}
void printValueInDecimal(bool byte[8])
{
	int total = 0;
	if(byte[0])
		total = 1;
	else
		total = 0;
	if(byte[1])
		total = total + 2;
	else
		total = total;
	if(byte[2])
		total = total + 4;
	else
		total = total;
	if(byte[3])
		total = total + 8;
	else
		total = total;
	if(byte[4])
		total = total + 16;
	else
		total = total;
	if(byte[5])
		total = total + 32;
	else
		total = total;
	if(byte[6])
		total = total + 64;
	else
		total = total;
	if(byte[7])
		total = total + 128;
	else
		total = total;

	cout << "This is the number in decimal: " << total << endl;
}
