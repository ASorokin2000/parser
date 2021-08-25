
//-------------------------------------------------------------------------
// AUTHOR:                  Aleksei Sorokin
// FILENAME:                transition.h
// SPECIFICATION:           Header file
// FOR:                     CS 3361 Programming Languages Project1
//-------------------------------------------------------------------------

#include"string.h"
using namespace std;

#if !defined (TRANSITION_H_INCL)
 #define TRANSITION_H_INCL
 


 // structure for cells of the transition table
struct transition
{
	int action; // 0 - move, 1 - assign 
	int type;
};


extern void fill();
extern int tt_action(int a, int b);
extern int tt_type(int a, int b);
extern int translate(char c);
extern string int_to_token(int n);

#endif

