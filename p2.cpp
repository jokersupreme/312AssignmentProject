//Problem 2
#include <iostream>
#include "p1.h"
#include "p2.h"

using namespace std;
int ValueInDecimal(bool byte[8]);

bool* mux(bool* output, bool operation, bool input1[8], bool input2[8])
{
	bool ns = NOT(operation);
	bool nsa = AND(ns,input1);
	bool sb = AND(operation,input2[0]);
	bool ans = OR(nsa,sb);
	return 0;
}
bool* addu(bool* output, bool input1[8], bool input2[8])
{
	bool i17 = input1[7];
	bool i27 = input2[7];
	bool sum7 = SUM(i17,i27);
	bool CarryOut7 = CarryOut(i17,i27,0);
	output[7] = sum7;

	bool i16 = input1[6];
	bool i26 = input2[6];
	bool sum6 = SUM3(i16,i26,CarryOut7);
	bool CarryOut6 = CarryOut(i16,i26,CarryOut7);
	output[6] = sum6;

	bool i15 = input1[5];
	bool i25 = input2[5];
	bool sum5 = SUM3(i15,i25,CarryOut6);
	bool CarryOut5 = CarryOut(i15,i25,CarryOut6);
	output[5] = sum5;

	bool i14 = input1[4];
	bool i24 = input2[4];
	bool sum4 = SUM3(i14,i24,CarryOut5);
	bool CarryOut4 = CarryOut(i15,i25,CarryOut5);
	output[4] = sum4;

	bool i13 = input1[3];
	bool i23 = input2[3];
	bool sum3 = SUM3(i13,i23,CarryOut4);
	bool CarryOut3 = CarryOut(i13,i23,CarryOut4);
	output[3] = sum3;

	bool i12 = input1[2];
	bool i22 = input2[2];
	bool sum2 = SUM3(i12,i22,CarryOut3);
	bool CarryOut2 = CarryOut(i12,i22,CarryOut3);
	output[2] = sum2;

	bool i11 = input1[1];
	bool i21 = input2[1];
	bool sum1 = SUM(i11,i21);
	bool CarryOut1 = CarryOut(i11,i21,CarryOut2);
	output[7] = sum7;

	bool i10 = input1[0];
	bool i20 = input2[7];
	bool sum0 = SUM3(i17,i27,CarryOut1);
	bool CarryOut0 = CarryOut(i10,i20,CarryOut1);
	output[0] = sum0;

	return output;
}
bool* negate(bool* output, bool input[8]) //(create the 2's complement version of this number - make sure that a value negated twice is itself)
{
	bool* temp = new bool [8];
	temp[0] = NOT(input[0]);
	temp[1] = NOT(input[1]);
	temp[2] = NOT(input[2]);
	temp[3] = NOT(input[3]);
	temp[4] = NOT(input[4]);
	temp[5] = NOT(input[5]);
	temp[6] = NOT(input[6]);
	temp[7] = NOT(input[7]);
	bool one[8] = {"00000001"};

	output = addu(output,temp,one);

	return output;
}
bool* subu(bool* output, bool input1[8], bool input2[8])
{
	//a-b
	bool* negb = new bool [8];
	negb = negate(negb,input2);
	output = addu(output,input1,negb);

	return output;
}
bool equal(bool input1[8], bool input2[8]) //(return 0 if two values are different)
{
	if(input1[0],input2[0])
		if(input1[1],input2[2])
			if(input1[2],input2[2])
				if(input1[3],input2[3])
					if(input1[4],input2[4])
						if(input1[5],input2[5])
							if(input1[6],input2[6])
								if(input1[7],input2[7])
									return 1;
	else 
		return 0;

}
bool lessthan(bool input1[8], bool input2[8]) //(return 0 if false)
{
	int n1 = ValueInDecimal(input1);
	int n2 = ValueInDecimal(input2);

	if (input1 < input2)
		return true;
	else
		return false;
}
int ValueInDecimal(bool byte[8])
{
	int total = 0;
	if (byte[0])
		total = 1;
	else
		total = 0;
	if (byte[1])
		total = total + 2;
	else
		total = total;
	if (byte[2])
		total = total + 4;
	else
		total = total;
	if (byte[3])
		total = total + 8;
	else
		total = total;
	if (byte[4])
		total = total + 16;
	else
		total = total;
	if (byte[5])
		total = total + 32;
	else
		total = total;
	if (byte[6])
		total = total + 64;
	else
		total = total;
	if (byte[7])
		total = total + 128;
	else
		total = total;

	return total;
}
bool greaterthan(bool input1[8], bool input2[8]) //(return 0 if false)
{
	int n1 = ValueInDecimal(input1);
	int n2 = ValueInDecimal(input2);

	if (input1 > input2)
		return true;
	else
		return false;
}
bool* equal(bool* output, bool input1[8], bool input2[8]) //(return 00000000 if two values are different)
{
	if (equal(input1[0],input2[0]))
		output[0] = 1;
	if (equal(input1[1],input2[1]))
		output[1] = 1;
	if (equal(input1[2],input2[2]))
		output[2] = 1;
	if (equal(input1[3],input2[3]))
		output[3] = 1;
	if (equal(input1[4],input2[4]))
		output[4] = 1;
	if (equal(input1[5],input2[5]))
		output[5] = 1;
	if (equal(input1[6],input2[6]))
		output[6] = 1;
	if (equal(input1[7],input2[7]))
		output[7] = 1;
	else
		return 0;
}
bool* and(bool* output, bool input1[8], bool input2[8]) //(bitwise and)
{
	output[0] = AND(input1[0],input2[0]);
	output[1] = AND(input1[1],input2[1]);
	output[2] = AND(input1[2],input2[2]);
	output[3] = AND(input1[3],input2[3]);
	output[4] = AND(input1[4],input2[4]);
	output[5] = AND(input1[5],input2[5]);
	output[6] = AND(input1[6],input2[6]);
	output[7] = AND(input1[7],input2[7]);

	return output;
}
bool* or(bool* output, bool input1[8], bool input2[8]) //(bitwise or)
{
	output[0] = OR(input1[0],input2[0]);
	output[1] = OR(input1[1],input2[1]);
	output[2] = OR(input1[2],input2[2]);
	output[3] = OR(input1[3],input2[3]);
	output[4] = OR(input1[4],input2[4]);
	output[5] = OR(input1[5],input2[5]);
	output[6] = OR(input1[6],input2[6]);
	output[7] = OR(input1[7],input2[7]);

	return output; 
}
bool* shiftLeft(bool* output, bool input[8]) //(shift left all bits, equivalent to multiplication with 2)
{
	bool* temp = new bool [8];

	temp[7] = input[6];
	temp[6] = input[5];
	temp[5] = input[4];
	temp[4] = input[3];
	temp[3] = input[2];
	temp[2] = input[1];
	temp[1] = input[0];
	temp[0] = 0;

	output = temp;

	return output;
}
bool* shiftRight(bool* output, bool input[8]) //(shift right all bits including the sign bit)(shift in same value as MSB)
{
	bool* temp = new bool [8];

	temp[7] = 0;
	temp[6] = input[7];
	temp[5] = input[6];
	temp[4] = input[5];
	temp[3] = input[4];
	temp[2] = input[3];
	temp[1] = input[2];
	temp[0] = input[1];

	output = temp;
}
