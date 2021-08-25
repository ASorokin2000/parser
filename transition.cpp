//-------------------------------------------------------------------------
// AUTHOR:                  Aleksei Sorokin
// FILENAME:                transition.h
// SPECIFICATION:           Implementation file
// FOR:                     CS 3361 Programming Languages Project1
//-------------------------------------------------------------------------

#include"iostream"
#include"string.h"
#include"transition.h"

using namespace std;



transition transition_table[18][14];

int tt_action(int a, int b)
{
	return(transition_table[a][b].action);
}

int tt_type(int a, int b)
{
	return(transition_table[a][b].type);
}

void fill()
{
	// to deal with problem of index starting from 0, I will move 18th column to 0th column;
	transition_table[1][0].action = 0;
	transition_table[1][0].type = 17;
	transition_table[1][1].action = 0;
	transition_table[1][1].type = 17;
	transition_table[1][2].action = 0;
	transition_table[1][2].type = 2;
	transition_table[1][3].action = 0;
	transition_table[1][3].type = 10;
	transition_table[1][4].action = 0;
	transition_table[1][4].type = 6;
	transition_table[1][5].action = 0;
	transition_table[1][5].type = 7;
	transition_table[1][6].action = 0;
	transition_table[1][6].type = 8;
	transition_table[1][7].action = 0;
	transition_table[1][7].type = 9;
	transition_table[1][8].action = 0;
	transition_table[1][8].type = 11;
	transition_table[1][9].action = 1;
	transition_table[1][9].type = 12;
	transition_table[1][10].action = 0;
	transition_table[1][10].type = 13;
	transition_table[1][11].action = 0;
	transition_table[1][11].type = 14;
	transition_table[1][12].action = 0;
	transition_table[1][12].type = 16;
	transition_table[1][13].action = 1;
	transition_table[1][13].type = 12;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[2][i].action = 1;
		transition_table[2][i].type = 1;
	}
	transition_table[2][2].action = 0;
	transition_table[2][2].type = 3;
	transition_table[2][3].action = 0;
	transition_table[2][3].type = 4;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[3][i].action = 0;
		transition_table[3][i].type = 3;
	}
	transition_table[3][1].action = 0;
	transition_table[3][1].type = 0;
	transition_table[3][13].action = 1;
	transition_table[3][13].type = 14;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[4][i].action = 0;
		transition_table[4][i].type = 4;
	}
	transition_table[4][3].action = 0;
	transition_table[4][3].type = 5;
	transition_table[4][13].action = 1;
	transition_table[4][13].type = 14;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[5][i].action = 0;
		transition_table[5][i].type = 4;
	}
	transition_table[5][2].action = 0;
	transition_table[5][2].type = 0;
	transition_table[5][3].action = 0;
	transition_table[5][3].type = 5;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[6][i].action = 1;
		transition_table[6][i].type = 5;
	}
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[7][i].action = 1;
		transition_table[7][i].type = 6;
	}
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[8][i].action = 1;
		transition_table[8][i].type = 4;
	}
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[9][i].action = 1;
		transition_table[9][i].type = 3;
	}
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[10][i].action = 1;
		transition_table[10][i].type = 2;
	}
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[11][i].action = 1;
		transition_table[11][i].type = 12;
	}
	
	transition_table[11][9].action = 0;
	transition_table[11][9].type = 12;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[12][i].action = 1;
		transition_table[12][i].type = 7;
	}
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[13][i].action = 1;
		transition_table[13][i].type = 12;
	}
	
	transition_table[13][11].action = 0;
	transition_table[13][11].type = 15;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[14][i].action = 1;
		transition_table[14][i].type = 8;
	}
	
	transition_table[14][10].action = 0;
	transition_table[14][10].type = 15;
	transition_table[14][11].action = 0;
	transition_table[14][11].type = 14;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[15][i].action = 1;
		transition_table[15][i].type = 8;
	}
	
	transition_table[15][11].action = 0;
	transition_table[15][11].type = 15;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[16][i].action = 1;
		transition_table[16][i].type = 9;
	}
	
	transition_table[16][11].action = 0;
	transition_table[16][11].type = 16;
	transition_table[16][12].action = 0;
	transition_table[16][12].type = 16;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[17][i].action = 1;
		transition_table[17][i].type = 13;
	}
	
	transition_table[17][13].action = 1;
	transition_table[17][13].type = 0;
	
	transition_table[17][0].action = 0;
	transition_table[17][0].type = 17;
	transition_table[17][1].action = 0;
	transition_table[17][1].type = 17;
	
	for (int i = 0; i < 14; i++)
	{
		transition_table[0][i].action = 1;
		transition_table[0][i].type = 14;
	}
}

int translate (char c)
{
	int ret;
	if (c == '\t' || c == ' ')
		ret = 0;
	else if (c == '\n')
		ret = 1;
	else if (c == '/')
		ret = 2;
	else if (c == '*')
		ret = 3;
	else if (c == '(')
		ret = 4;
	else if (c == ')')
		ret = 5;
	else if (c == '+')
		ret = 6;
	else if (c == '-')
		ret = 7;
	else if (c == ':')
		ret = 8;
	else if (c == '=')
		ret = 9;
	else if (c == '.')
		ret = 10;
	else if (c >= '0' && c <= '9')
		ret = 11;
	else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		ret = 12;
	else ret = 13; // presumably EOF
	return (ret);
}

string int_to_token(int n)
{
	string ret;
	if (n == 1)
		ret = "division";
	if (n == 2)
		ret = "times";
	if (n == 3)
		ret = "minus";
	if (n == 4)
		ret = "plus";
	if (n == 5)
		ret = "lparen";
	if (n == 6)
		ret = "rparen";
	if (n == 7)
		ret = "assign";
	if (n == 8)
		ret = "number";
	if (n == 9)
		ret = "id";
	if (n == 10)
		ret = "read";
	if (n == 11)
		ret = "write";
	return (ret);
}
