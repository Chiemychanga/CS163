/* Larry Chiem 
 * CS163
 * Program 2 
 * April 28, 2016
 *
 * main.cpp
 * This file holds the client program and passes 
 * in objects and variables into the stack and queue
 * ADT operations.
 */

#include "functions.h"
using namespace std;

int main()
{
    Package add_package;     
    stack Stack;   
    queue Queue;

    for(int i = 0; i<10; ++i)
    {
        char * number = new char[2];
        number[0] = i + '0';
        number[1] = '\0';
       add_package.create_entry(number,number,i);
       Stack.push(add_package);
        Queue.enqueue(add_package);
    }
    cout << "\nQueue Display all *******************\n";
    Queue.display_all();
    cout << "\nStakc Display all *******************\n";
    Stack.display();

    return 0;    
}
