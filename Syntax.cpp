
#include "Syntax.h"
//method will check for file name then it will check for the syntax of file
string Syntax::SytnaxTest(string check)
{
     Genstack<char> myArr;
    char charCheck;
    notAComment= false;
    cout<<" enter the file name or path"<<endl;
    cin>>name;
    ifstream inFile;
    if (inFile.fail())
    {
        cout<<"improper name for file";
    }
    if(name.at(name.length()-4) == '.' && name.at(name.length()-3) =='c' && name.at(name.length()-2) =='p' && name.at(name.length()-1) =='p')
    {
        cout<<"file will be used"<<endl;
    }
    else
    {
        cout<<"must be a .cpp file"<<endl;
        welcomeFstream();
    }
    inFile.open(check);
    while(getline(inFile,currLine))
    {
        for(int i =0; i <currLine.length(); i++)
        {
            temp = currLine[i];
                if(temp == '"')
                {
                    stringCounter++;
                    if(stringCounter % 2 ==0)
                    {
                        isAString=true;
                    }
                }
                //if there is a " in another context besides the front then it will become not a string
                else
                {
                    {
                        isAString= false;
                    }
                }
                //will see if it begins with / meaning it is a comment
                if(temp == '/')
                {
                    notAComment= false;
                }

                if( temp == '(' || temp == '[' || temp == '{')
                {
                    posOfBracket= lineNum;
                    myArr.insert(temp);

                }
                else if(temp == '}')
                {
                tTemp = peekingTheStack('}') ;
                    if(isStackEmpty() != "0")
                    {
                        return isStackEmpty();
                    }
                    if(tTemp == "0")
                    {
                        return tTemp;
                    }
                    myArr.pop();
                    
                }
                else if(temp == ']')
                {
                    tTemp = peekingTheStack(']') ;
                    if(isStackEmpty()!="0")
                    {
                        return isStackEmpty();
                    }
                    if(tTemp == "0")
                    {
                        return tTemp;
                    }
                    myArr.pop();
                    
                    
                }
                else if(temp == ')')
                {
                    tTemp = peekingTheStack(')') ;
                    if(isStackEmpty()!= "0")
                    {
                        return isStackEmpty();
                    }
                    if(tTemp == "0")
                    {
                        return tTemp;
                    }
                    myArr.pop();
                    
                }
        }
    }
    inFile.close();

}
//this checks the file and introduces them to the program.
void Syntax::welcomeFstream()
{
    cout<<" enter the file name or path"<<endl;
    cin>>name;
    ifstream inFile;
    if (inFile.fail())
    {
        cout<<"improper name for file";
    }
    if(name.at(name.length()-4) =='.' && name.at(name.length()-3) =='c' && name.at(name.length()-2) =='p' && name.at(name.length()-1) =='p' )
    {
        cout<<"file will be used"<<endl;

    }
    else
    {
        cout<<"must be a .cpp file"<<endl;
        welcomeFstream();
    }
    
}
//checks if stack is empty and returns that
 string Syntax::isStackEmpty()
{
    if(myArr.isEmpty())
    {
        pair = false;
        return lineNum + " ";
    }
    return "0";
}
//checks if stack is empty and returns that
string Syntax::peekingTheStack(char t)
{
  
    if(myArr.peek() != t)
    {
            if(t == '}')
        {
            otherPair= '{';
        }
        else if(t == ')')
        {
            otherPair= '(';
        }
        else if(t == ']')
        {
            otherPair= '[';
        }
        else if(t == '[')
        {
            otherPair= ']';
        }
        else if(t == '{')
        {
            otherPair= '}';
        }
        else if(t == '(')
        {
            otherPair= ')';
        }
        return lineNum +" ";
    }
        return "0";
   
}
//this is the main check syntax for the program when it is run it will be the main funciton for the program
void Syntax::checkEntireFile(string check)
{
    if(myArr.isEmpty() ==-1)
    {
        cout<<"Syntax is right. you can enter another file"<<endl;
        welcomeFstream();
    }
    else if(myArr.peek() == '{')
    {
        cout<<"the file is missing a }"<<endl;
    }
    else if(myArr.peek() == '(')
    {
        cout<<"the file is missing a )"<<endl;
    }
    else if(myArr.peek() == '[')
    {
        cout<<"the file is missing a ]"<<endl;
    }
    else
    {
        {
            cout<<"on line "<< SytnaxTest(name)<< tTemp<< "was located and " << otherPair<< "was expect" <<endl;
        }
    }
    
}