#include "p2.h"

//Variables
bool ADDU = new bool [00010000];
bool SUBU = new bool [00010001];
bool NEG = new bool [00000010];
bool EQ = new bool [00000011];
bool LT = new bool [00000100];
bool GT = new bool [00000101];
bool AND = new bool [00000110];
bool OR = new bool [00000111];
bool SLL = new bool [00001000];
bool SRL = new bool [00001001];


bool* alu(bool instruction[8], bool input1[8], bool input2[8])
{
	bool* output;
	bool temp = new bool [8];
	temp = instruction;
	if(temp == ADDU)
		addu(output,input1,input2);
	if(temp == SUBU)
		subu(output,input1,input1);
	if(temp == NEG)
	{
		negate(output,input1);
		negate(output,input2);
	}
	if(temp == EQ)
		equal(input1,input2);
	if(temp == LT)
		lessthan(input1,input2);
	if(temp == GT)
		greaterthan(input1,input2);
	if(temp == AND)
		and(output,input1,input2);
	if(temp == OR)
		or(output,input1,input2);
	if(temp == SLL)
		shiftLeft(input1,input2);
	if(temp == SRL)
		shiftRight(input1,input2);
}
