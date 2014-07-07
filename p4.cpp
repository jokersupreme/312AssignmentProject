#include "p1.h"
#include "p2.h"
#include "p3.h"
bool* add(bool* output, bool input1[8], bool input2[8])
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
	bool sum1 = SUM3(i11,i21,CarryOut2);
	bool CarryOut1 = CarryOut(i11,i21,CarryOut2);
	output[7] = sum7;

	bool i10 = input1[0];
	bool i20 = input2[7];
	bool sum0 = SUM3(i17,i27,CarryOut1);
	bool CarryOut0 = CarryOut(i10,i20,CarryOut1);
	output[0] = sum0;

	if(CarryOut0)
	{
		throw invalid_argument("Overflow");
		return output;
	}
	
	else
		return output;
}

bool* sub(bool* output, bool input1[8], bool input2[8])
{
	bool* neg = new bool [8];

	neg = negate(neg,input2);
	output = add(output,input1,neg);


	return output;
}
