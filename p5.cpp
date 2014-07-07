bool* mul(bool* output, bool input1[4], bool input2[4])
{
	bool sum[8] = {00000000};
	bool temp[8] = {00000000};
	bool temp2[8] = {00000000};
	bool temp3[8] = {00000000};
	bool temp4[8] = {00000000};

	if(input2[0])
	{
		temp == input1;
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}
	else
	{
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}

	if(input2[0])
	{
		temp2 == input1;
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}
	else
	{
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}

	if(input2[0])
	{
		temp3 == input1;
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}
	else
	{
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}

	if(input2[0])
	{
		temp4 == input1;
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}
	else
	{
		input1 = shiftLeft(output,input1);
		input2 = shiftRight(output,input2);
	}

	sum == addu(output,temp,temp2);
	
	return sum;
}
bool* div(bool* output, bool input1[8], bool input2[8])
{
	bool* temp1 = new bool[8];
	bool* temp2 = new bool[8];
	bool* temp3 = new bool[8];

	for (int i = 0; i < 8; i++)
	{
		temp1[i] = 0;
		temp2[i] = 0;
	}

	for (int i = 0; i < 8; i++)
	{
		shiftRight(temp1, input2);
		if (lessthan(input1, temp1));
		{
			sub(input1, temp1);
			temp2 = temp2 + 1;
		}

		shiftLeft(temp3,temp2);
	}
	
	output[0] = temp3[0];
	output[1] = temp3[1];
	output[2] = temp3[2];
	output[3] = temp3[3];
	output[4] = temp3[4];
	output[5] = temp3[5];
	output[6] = temp3[6];
	output[7] = temp3[7];

	return output;
	
}
