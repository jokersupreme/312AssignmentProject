#include "basic_functions.h"
#include "basic_functions.h"
#include "p1.h"
#include "p2.h"
#include "p6.h"

bool registry[16][8];
bool instructionMemory[256][8];
bool dataMemory[16][8];
bool PC[8];
bool IR[32];

void initialize() {
  // TODO
  int n1 = 8;
  int n2 = 16;
  int n3 = 32;
  int n4 = 256;
  
  for(int i = 0; i < n2; i++)
	{
		for(int j = 0; j < n1; j++)
		{
			registry[i][j] = 0;
		}
	}
	for(int i = 0; i < n4; i++)
	{
		for(int j = 0; j < n1; j++)
		{
			instructionMemory[i][j] = 0;
		}
	}
	for(int i = 0; i < n2; i++)
	{
		for(int j = 0; j < n1; j++)
		{
			dataMemory[i][j] = 0;
		}
	}
	for(int j = 0; j < n1; j++)
	{
		PC[j] = 0;
	}
	for(int j = 0; j < n3; j++)
	{
		IR[j] = 0;
	}
	
}

bool* getRegistryValue(bool* output, bool registerNum[8]) 
{
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		output[0] = registry[0][0];
		output[1] = registry[0][1];
		output[2] = registry[0][2];
		output[3] = registry[0][3];
		output[4] = registry[0][4];
		output[5] = registry[0][5];
		output[6] = registry[0][6];
		output[7] = registry[0][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && !registerNum[6] && registerNum[7])
	{
		output[0] = registry[1][0];
		output[1] = registry[1][1];
		output[2] = registry[1][2];
		output[3] = registry[1][3];
		output[4] = registry[1][4];
		output[5] = registry[1][5];
		output[6] = registry[1][6];
		output[7] = registry[1][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && registerNum[6] && !registerNum[7])
	{
		output[0] = registry[2][0];
		output[1] = registry[2][1];
		output[2] = registry[2][2];
		output[3] = registry[2][3];
		output[4] = registry[2][4];
		output[5] = registry[2][5];
		output[6] = registry[2][6];
		output[7] = registry[2][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && registerNum[6] && registerNum[7])
	{
		output[0] = registry[3][0];
		output[1] = registry[3][1];
		output[2] = registry[3][2];
		output[3] = registry[3][3];
		output[4] = registry[3][4];
		output[5] = registry[3][5];
		output[6] = registry[3][6];
		output[7] = registry[3][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		output[0] = registry[4][0];
		output[1] = registry[4][1];
		output[2] = registry[4][2];
		output[3] = registry[4][3];
		output[4] = registry[4][4];
		output[5] = registry[4][5];
		output[6] = registry[4][6];
		output[7] = registry[4][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && !registerNum[6] && registerNum[7])
	{
		output[0] = registry[5][0];
		output[1] = registry[5][1];
		output[2] = registry[5][2];
		output[3] = registry[5][3];
		output[4] = registry[5][4];
		output[5] = registry[5][5];
		output[6] = registry[5][6];
		output[7] = registry[5][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && registerNum[6] && !registerNum[7])
	{
		output[0] = registry[6][0];
		output[1] = registry[6][1];
		output[2] = registry[6][2];
		output[3] = registry[6][3];
		output[4] = registry[6][4];
		output[5] = registry[6][5];
		output[6] = registry[6][6];
		output[7] = registry[6][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && registerNum[6] && registerNum[7])
	{
		output[0] = registry[7][0];
		output[1] = registry[7][1];
		output[2] = registry[7][2];
		output[3] = registry[7][3];
		output[4] = registry[7][4];
		output[5] = registry[7][5];
		output[6] = registry[7][6];
		output[7] = registry[7][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		output[0] = registry[8][0];
		output[1] = registry[8][1];
		output[2] = registry[8][2];
		output[3] = registry[8][3];
		output[4] = registry[8][4];
		output[5] = registry[8][5];
		output[6] = registry[8][6];
		output[7] = registry[8][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && !registerNum[6] && registerNum[7])
	{
		output[0] = registry[9][0];
		output[1] = registry[9][1];
		output[2] = registry[9][2];
		output[3] = registry[9][3];
		output[4] = registry[9][4];
		output[5] = registry[9][5];
		output[6] = registry[9][6];
		output[7] = registry[9][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && registerNum[6] && !registerNum[7])
	{
		output[0] = registry[10][0];
		output[1] = registry[10][1];
		output[2] = registry[10][2];
		output[3] = registry[10][3];
		output[4] = registry[10][4];
		output[5] = registry[10][5];
		output[6] = registry[10][6];
		output[7] = registry[10][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && registerNum[6] && registerNum[7])
	{
		output[0] = registry[11][0];
		output[1] = registry[11][1];
		output[2] = registry[11][2];
		output[3] = registry[11][3];
		output[4] = registry[11][4];
		output[5] = registry[11][5];
		output[6] = registry[11][6];
		output[7] = registry[11][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		output[0] = registry[12][0];
		output[1] = registry[12][1];
		output[2] = registry[12][2];
		output[3] = registry[12][3];
		output[4] = registry[12][4];
		output[5] = registry[12][5];
		output[6] = registry[12][6];
		output[7] = registry[12][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && !registerNum[6] && registerNum[7])
	{
		output[0] = registry[13][0];
		output[1] = registry[13][1];
		output[2] = registry[13][2];
		output[3] = registry[13][3];
		output[4] = registry[13][4];
		output[5] = registry[13][5];
		output[6] = registry[13][6];
		output[7] = registry[13][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && registerNum[6] && !registerNum[7])
	{
		output[0] = registry[14][0];
		output[1] = registry[14][1];
		output[2] = registry[14][2];
		output[3] = registry[14][3];
		output[4] = registry[14][4];
		output[5] = registry[14][5];
		output[6] = registry[14][6];
		output[7] = registry[14][7];
		return output;
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && registerNum[6] && registerNum[7])
	{
		output[0] = registry[15][0];
		output[1] = registry[15][1];
		output[2] = registry[15][2];
		output[3] = registry[15][3];
		output[4] = registry[15][4];
		output[5] = registry[15][5];
		output[6] = registry[15][6];
		output[7] = registry[15][7];
		return output;
	}
  // TODO
  
}

void setRegistryValue(bool registerNum[8], bool value[8]) 
{
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		registry[0][0] = value[0];
		registry[0][1] = value[1];
		registry[0][2] = value[2];
		registry[0][3] = value[3];
		registry[0][4] = value[4];
		registry[0][5] = value[5];
		registry[0][6] = value[6];
		registry[0][7] = value[7];
	}
	
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && !registerNum[6] && registerNum[7])
	{
		registry[1][0] = value[0];
		registry[1][1] = value[1];
		registry[1][2] = value[2];
		registry[1][3] = value[3];
		registry[1][4] = value[4];
		registry[1][5] = value[5];
		registry[1][6] = value[6];
		registry[1][7] = value[7];
	}
	
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && registerNum[6] && !registerNum[7])
	{
		registry[2][0] = value[0];
		registry[2][1] = value[1];
		registry[2][2] = value[2];
		registry[2][3] = value[3];
		registry[2][4] = value[4];
		registry[2][5] = value[5];
		registry[2][6] = value[6];
		registry[2][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && !registerNum[5] && registerNum[6] && registerNum[7])
	{
		registry[3][0] = value[0];
		registry[3][1] = value[1];
		registry[3][2] = value[2];
		registry[3][3] = value[3];
		registry[3][4] = value[4];
		registry[3][5] = value[5];
		registry[3][6] = value[6];
		registry[3][7] = value[7];
	}
	
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		registry[4][0] = value[0];
		registry[4][1] = value[1];
		registry[4][2] = value[2];
		registry[4][3] = value[3];
		registry[4][4] = value[4];
		registry[4][5] = value[5];
		registry[4][6] = value[6];
		registry[4][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && !registerNum[6] && registerNum[7])
	{
		registry[5][0] = value[0];
		registry[5][1] = value[1];
		registry[5][2] = value[2];
		registry[5][3] = value[3];
		registry[5][4] = value[4];
		registry[5][5] = value[5];
		registry[5][6] = value[6];
		registry[5][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && registerNum[6] && !registerNum[7])
	{
		registry[6][0] = value[0];
		registry[6][1] = value[1];
		registry[6][2] = value[2];
		registry[6][3] = value[3];
		registry[6][4] = value[4];
		registry[6][5] = value[5];
		registry[6][6] = value[6];
		registry[6][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && !registerNum[4] && registerNum[5] && registerNum[6] && registerNum[7])
	{
		registry[7][0] = value[0];
		registry[7][1] = value[1];
		registry[7][2] = value[2];
		registry[7][3] = value[3];
		registry[7][4] = value[4];
		registry[7][5] = value[5];
		registry[7][6] = value[6];
		registry[7][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		registry[8][0] = value[0];
		registry[8][1] = value[1];
		registry[8][2] = value[2];
		registry[8][3] = value[3];
		registry[8][4] = value[4];
		registry[8][5] = value[5];
		registry[8][6] = value[6];
		registry[8][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && !registerNum[6] && registerNum[7])
	{
		registry[9][0] = value[0];
		registry[9][1] = value[1];
		registry[9][2] = value[2];
		registry[9][3] = value[3];
		registry[9][4] = value[4];
		registry[9][5] = value[5];
		registry[9][6] = value[6];
		registry[9][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && registerNum[6] && !registerNum[7])
	{
		registry[10][0] = value[0];
		registry[10][1] = value[1];
		registry[10][2] = value[2];
		registry[10][3] = value[3];
		registry[10][4] = value[4];
		registry[10][5] = value[5];
		registry[10][6] = value[6];
		registry[10][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && !registerNum[5] && registerNum[6] && registerNum[7])
	{
		registry[11][0] = value[0];
		registry[11][1] = value[1];
		registry[11][2] = value[2];
		registry[11][3] = value[3];
		registry[11][4] = value[4];
		registry[11][5] = value[5];
		registry[11][6] = value[6];
		registry[11][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && !registerNum[6] && !registerNum[7])
	{
		registry[12][0] = value[0];
		registry[12][1] = value[1];
		registry[12][2] = value[2];
		registry[12][3] = value[3];
		registry[12][4] = value[4];
		registry[12][5] = value[5];
		registry[12][6] = value[6];
		registry[12][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && !registerNum[6] && registerNum[7])
	{
		registry[13][0] = value[0];
		registry[13][1] = value[1];
		registry[13][2] = value[2];
		registry[13][3] = value[3];
		registry[13][4] = value[4];
		registry[13][5] = value[5];
		registry[13][6] = value[6];
		registry[13][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && registerNum[6] && !registerNum[7])
	{
		registry[14][0] = value[0];
		registry[14][1] = value[1];
		registry[14][2] = value[2];
		registry[14][3] = value[3];
		registry[14][4] = value[4];
		registry[14][5] = value[5];
		registry[14][6] = value[6];
		registry[14][7] = value[7];
	}
	if(!registerNum[0] && !registerNum[1] && !registerNum[2] && !registerNum[3] && registerNum[4] && registerNum[5] && registerNum[6] && registerNum[7])
	{
		registry[15][0] = value[0];
		registry[15][1] = value[1];
		registry[15][2] = value[2];
		registry[15][3] = value[3];
		registry[15][4] = value[4];
		registry[15][5] = value[5];
		registry[15][6] = value[6];
		registry[15][7] = value[7];
	}
  // TODO
}

int toDecimal(bool registerNum[8]) 
{
	int total = 0;
	if(registerNum[0])
		total = 1;
	else
		total = 0;
	if(registerNum[1])
		total = total + 2;
	else
		total = total;
	if(registerNum[2])
		total = total + 4;
	else
		total = total;
	if(registerNum[3])
		total = total + 8;
	else
		total = total;
	if(registerNum[4])
		total = total + 16;
	else
		total = total;
	if(registerNum[5])
		total = total + 32;
	else
		total = total;
	if(registerNum[6])
		total = total + 64;
	else
		total = total;
	if(registerNum[7])
		total = total + 128;
	else
		total = total;
  // TODO
  return total;
}

void incrementPC() 
{
bool ne[8];
	ne[0] = 0;
	ne[1] = 0;
	ne[2] = 0;
	ne[3] = 0;
	ne[4] = 0;
	ne[5] = 1;
	ne[6] = 0;
	ne[7] = 0;
	bool* output = new bool [8];
	output = addu(output,PC,ne);
	
	PC[0] = output[0];
	PC[1] = output[1];
	PC[2] = output[2];
	PC[3] = output[3];
	PC[4] = output[4];
	PC[5] = output[5];
	PC[6] = output[6];
	PC[7] = output[7];
  // TODO
}

void addPC(bool addressOffset[8]) 
{
	bool* output = new bool[8];
	output = addu(output,PC,addressOffset);
	
	PC[0] = output[0];
	PC[1] = output[1];
	PC[2] = output[2];
	PC[3] = output[3];
	PC[4] = output[4];
	PC[5] = output[5];
	PC[6] = output[6];
	PC[7] = output[7];
  // TODO
}

void instructionFetch() 
{
	int n1 = 8;
	int t = 0;
	
	toDecimal(PC)
	
	for(int t = 0; t < 8;t++)
	{
		IR[t] = instructionMemory[toDecimal(PC)][t];
	}
	for(int t = 8; t < 16;t++)
	{
		IR[t] = instructionMemory[toDecimal(PC)+1][t];
	}
	for(int t = 16; t < 24;t++)
	{
		IR[t] = instructionMemory[toDecimal(PC)+2][t];
	}
	for(int t = 24; t < 32;t++)
	{
		IR[t] = instructionMemory[toDecimal(PC)+3][t];
	}
  // TODO
}

void parseInstructionInIR(bool* name,
                          bool* reg_out,
                          bool* reg_in1,
                          bool* reg_in2,
                          bool* imm16) {
	
	//If R-format
	if(!IR[0] && !IR[1] && !IR[2] && !IR[3] && !IR[4] && !IR[5])
	{
		name[0] = IR[0];
		name[1] = IR[1];
		name[2] = IR[2];
		name[3] = IR[3];
		name[4] = IR[4];
		name[5] = IR[5];
		
		reg_in1[0] = IR[6];
		reg_in1[1] = IR[7];
		reg_in1[2] = IR[8];
		reg_in1[3] = IR[9];
		reg_in1[4] = IR[10];
		
		reg_in2[0] = IR[11];
		reg_in2[1] = IR[12];
		reg_in2[2] = IR[13];
		reg_in2[3] = IR[14];
		reg_in2[4] = IR[15];
		
		reg_out[0] = IR[16];
		reg_out[1] = IR[17];
		reg_out[2] = IR[18];
		reg_out[3] = IR[19];
		reg_out[4] = IR[20];
	}
	
	else
	{
		name[0] = IR[0];
		name[1] = IR[1];
		name[2] = IR[2];
		name[3] = IR[3];
		name[4] = IR[4];
		name[5] = IR[5];
		
		reg_out[0] = IR[6];
		reg_out[1] = IR[7];
		reg_out[2] = IR[8];
		reg_out[3] = IR[9];
		reg_out[4] = IR[10];
		
		imm16[0] = IR[11];
		imm16[1] = IR[12];
		imm16[2] = IR[13];
		imm16[3] = IR[14];
		imm16[4] = IR[15];
		imm16[5] = IR[16];
		imm16[6] = IR[17];
		imm16[7] = IR[18];
		imm16[8] = IR[19];
		imm16[9] = IR[20];
		imm16[10] = IR[21];
		imm16[11] = IR[22];
		imm16[12] = IR[23];
		imm16[13] = IR[24];
		imm16[14] = IR[25];
		imm16[15] = IR[26];
	}
	
  // TODO
}

void initializeInstructionMemory(std::ifstream& fp) 
{
	char c;
	int n = 8;
	int m = 256;
	if(fp.good())
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				c = fp.get();
				if(c == '1')
					instructionMemory[i][j] = true;
				else
					instructionMemory[i][j] = false;
			}
		}	
	}
	
  // TODO
}

bool* getInstructionValue(bool* output, const std::string& instructionName) 
{
	if(instructionName == "ADDU")
	{
	//return op code
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 1;
		output[4] = 0;
		output[5] = 0;
		output[6] = 0;
		output[7] = 0;
		return output;
	}
	if(instructionName == "SUBU")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 1;
		output[4] = 0;
		output[5] = 0;
		output[6] = 0;
		output[7] = 1;
		return output;
	}
	if(instructionName == "NEG")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 0;
		output[4] = 0;
		output[5] = 0;
		output[6] = 1;
		output[7] = 0;
		return output;
	}
	if(instructionName == "EQ")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 0;
		output[4] = 0;
		output[5] = 0;
		output[6] = 1;
		output[7] = 1;
		return output;
	}
	if(instructionName == "LT")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 1;
		output[4] = 0;
		output[5] = 1;
		output[6] = 0;
		output[7] = 0;
		return output;
	}
	if(instructionName == "GT")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 1;
		output[4] = 0;
		output[5] = 1;
		output[6] = 0;
		output[7] = 1;
		return output;
	}
	if(instructionName == "AND")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 1;
		output[4] = 0;
		output[5] = 1;
		output[6] = 1;
		output[7] = 0;
		return output;
	}
	if(instructionName == "OR")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 1;
		output[4] = 0;
		output[5] = 1;
		output[6] = 1;
		output[7] = 1;
		return output;
	}
	if(instructionName == "SLL")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 0;
		output[4] = 1;
		output[5] = 0;
		output[6] = 0;
		output[7] = 0;
		return output;
	}
	if(instructionName == "SRL")
	{
		output[0] = 0;
		output[1] = 0;
		output[2] = 0;
		output[3] = 0;
		output[4] = 1;
		output[5] = 0;
		output[6] = 0;
		output[7] = 1;
		return output;
	}
	//keep going
  // TODO
  return 0;
}

void mem(bool registerNum[8], bool memlocation[16], bool read, bool write) 
{
	bool* output = new bool[8];
	if(read)
		setRegistryNumber(registerNumber,dataMemory(toDecimal(memLocation)));
	if(write)
	{
		getRegistryValue(output,registerNum)
		dataMemory[toDecimal(memLocation))][0] = output[0];
		dataMemory[toDecimal(memLocation))][1] = output[1];
		dataMemory[toDecimal(memLocation))][2] = output[2];
		dataMemory[toDecimal(memLocation))][3] = output[3];
		dataMemory[toDecimal(memLocation))][4] = output[4];
		dataMemory[toDecimal(memLocation))][5] = output[5];
		dataMemory[toDecimal(memLocation))][6] = output[6];
		dataMemory[toDecimal(memLocation))][7] = output[7];
	}
  // TODO
}

void lw(bool registerNum[8], bool memlocation[16]) 
{
	mem(registerNum,memLocation,1,0);
  // TODO
}

void sw(bool registerNum[8], bool memlocation[16]) 
{
	mem(registerNum,memLocation,0,1);
  // TODO
}

void readOrWriteMem(bool value[8], bool memlocation[8], bool read, bool write) 
{
	if(write)
		dataMemory[toDecimal(memLocation))][0] = value[0];
		//go down to 8
	if(read)
	{
	}
  // TODO
}

void readMem(bool value[8], bool memlocation[16]) {
  // TODO
}

void writeMem(bool value[8], bool memlocation[16]) {
  // TODO
}
