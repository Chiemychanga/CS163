/* clarry@pdx.edu
 * CS163
 * Program 2 
 * April 28, 2016
 *
 * main.cpp
 * This file holds the client program and passes 
 * in objects and variables into the user program
 * functions.
 */

#include "functions.h"
using namespace std;

int main()
{
//    node * head = NULL;
    Package add_package;     
    stack Stack;   

    
    for(int i = 0; i<4; ++i)
    {
        char * number = new char[2];
        number[0] = i + '0';
        number[1] = '\0';
       add_package.create_entry(number,number,i);
       Stack.push(add_package);
    }
    Stack.display();

    return 0;    
}
