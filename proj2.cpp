#include"iostream"
#include"fstream"
#include"string.h"
#include"transition.h"
#include"setjmp.h"

using namespace std;

struct ret{
	int type;
	string context;
};

// global variables

ret token;
FILE *FP;
int error = 0;
int level = 0;
int num_tokens = 0;
ret tokens[300];

void expr();


ret scan()
{
	ret t;
	char ch ; // current character
	int chType; // type of ch
	int cs; // the current state of the automata
	t.context = "";
	cs = 1;
	ch = getc(FP);
	ungetc(ch, FP);
	chType = translate(ch);
	
	while (tt_action(cs, chType) == 0)
	{
		cs = tt_type(cs,chType);
		ch = getc(FP);
		t.context += ch;
		ch = getc(FP);
		ungetc(ch, FP);
		chType = translate(ch);
	}
	t.type = tt_type(cs,chType);
	if (t.type == 9)
	{
		if (t.context == "write")
			t.type = 11;
		else if (t.context == "read")
			t.type = 10;
	}
	return (t);
}

void add_terminal()
{
	tokens[num_tokens].context = "<" + int_to_token(token.type) + ">";
	tokens[num_tokens].type = level;
	num_tokens++;
	
	level++;
	tokens[num_tokens].context = token.context;
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
	
	tokens[num_tokens].context = "</" + int_to_token(token.type) + ">";
	tokens[num_tokens].type = level;
	num_tokens++;
}

void match (int expected)
{
	level++;
	if (expected == token.type)
	{
		if (token.type != 0)
			add_terminal();
		int get_new = 0;
		while (!get_new && feof(FP) == 0)
		{
			if (feof(FP) == 1)
			{
				token.type = 0;
				get_new = 1;
			}
			else 
			{
				token = scan();
				if (token.type <= 12 || token.type == 0)
					get_new = 1;
			}
		}
	}
	else
		error = 1;
	level--;
}

void mult_op()
{
	level++;
	tokens[num_tokens].context = "<mult_op>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 1)
		match(1);
	else if (token.type == 2)
		match(2);
	else error = 1;
	tokens[num_tokens].context = "</mult_op>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
}

void add_op()
{
	level++;
	tokens[num_tokens].context = "<add_op>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 4)
		match(4);
	else if (token.type == 3)
		match(3);
	else error = 1;
	tokens[num_tokens].context = "</add_op>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
	
}

void factor()
{
	level++;
	tokens[num_tokens].context = "<factor>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 9)
		match(9);
	else if (token.type == 8)
		match(8);
	else if (token.type == 5)
	{
		match(5);
		expr();
		match(6);
	}
	else error = 1;
	tokens[num_tokens].context = "</factor>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
}

void factor_tail()
{
	level++;
	tokens[num_tokens].context = "<factor_tail>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 1 || token.type == 2)
	{
		mult_op();
		factor();
		factor_tail();
	}
	else if (token.type == 3 || token.type == 4 || token.type == 6 || token.type == 9 || token.type == 10 || token.type == 11 || token.type == 0 )
	{}
	else error = 1;
	tokens[num_tokens].context = "</factor_tail>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
}

void term()
{
	level++;
	tokens[num_tokens].context = "<term>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 5 || token.type == 8 || token.type == 9)
	{
		factor();
		factor_tail();
	}
	else error = 1;
	tokens[num_tokens].context = "</term>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
}

void term_tail()
{
	level++;
	tokens[num_tokens].context = "<term_tail>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 3 || token.type == 4)
	{
		add_op();
		term();
		term_tail();
	}
	else if (token.type == 6 || token.type == 9 || token.type == 10 || token.type == 11 || token.type == 0)
	{
	}
	else error = 1;
	tokens[num_tokens].context = "</term_tail>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
}

void expr()
{
	level++;
	tokens[num_tokens].context = "<expr>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 5 || token.type == 8 || token.type == 9)
	{
		term();
		term_tail();
	}
	else
		error = 1;
	tokens[num_tokens].context = "</expr>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;

}

void stmt()
{
	level++;
	tokens[num_tokens].context = "<stmt>";
	tokens[num_tokens].type = level;
	num_tokens++;
	switch (token.type)
	{
		case 9:
			{
				match(9);
				match(7);
				expr();
				break;
			}
		case 10:
			{
				match(10);
				match(9);
				break;
			}
		case 11:
			{
				match(11);
				expr();
				break;
			}
		default:
				error = 1;
	}
	tokens[num_tokens].context = "</stmt>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;
			
}

void stmt_list()
{
	level++;
	tokens[num_tokens].context = "<stmt_list>";
	tokens[num_tokens].type = level;
	num_tokens++;
	if (token.type == 9 || token.type == 10 || token.type == 11)
	{
		stmt();
		stmt_list();
	}
	else if (token.type == 0)
	{
	}
		else 
	{
			error = 1;
			
	}
	tokens[num_tokens].context = "</stmt_list>";
	tokens[num_tokens].type = level;
	num_tokens++;
	level--;

}


int main()
{
	string file_name;
	// file_name = "inp.txt";
	cout << "Enter the name of the file: ";
	cin >> file_name;
	fill(); // fill the transition table according to the given rules
	FP = fopen(file_name.c_str(), "r");
	if (FP)
	{
		tokens[num_tokens].context = "<Program>";
		tokens[num_tokens].type = level;
		num_tokens++;
		if (feof(FP) == 1)
			token.type = 0;
		else
		{
			token = scan();
		}
		if (token.type == 12)
			error = 1;
		if (token.type == 0 || token.type == 9 || token.type == 10 || token.type == 11)
		{
			stmt_list();
			match(0);
		}
		else 
				error = 1;
			
		//
		tokens[num_tokens].context = "</Program>";
		tokens[num_tokens].type = level;
		num_tokens++;
		fclose(FP);
		if (error == 1)
			cout << "error.";
		else 
		{	for (int i = 0; i < num_tokens; i++)
			{
				for (int j = 0; j < tokens[i].type; j++)
					cout << "  ";
				cout <<  tokens[i].context << "\n";
			}
		}
	}
	else
		cout << "File opening failed";
	
	return(0);
}
