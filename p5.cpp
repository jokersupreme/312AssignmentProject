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
