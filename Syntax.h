#ifndef _SYNTAX_H_
#define _SYNTAX_H_
#include <string>
#include <fstream>
#include <iostream>

#include <array>
#include "Genstack.h"
using namespace std;

class Syntax {
   public:
   string currLine;
   bool keepGoing = true;
   bool testFail = false;
   int number = 0;
   string name;
   int posOfBracket = 0;
   int size = 0;
   string SytnaxTest(string check);
   void welcomeFstream();
   int lineNum=0;
   bool notAComment;
   int stringCounter =0;
   char temp;
   bool pair;
   char otherPair;
   bool isAString;
   string tTemp;
   Syntax();
   string peekingTheStack(char t);
   string isStackEmpty();
   Genstack<char> myArr;
   void checkEntireFile(string check);
   private:
};
#endif