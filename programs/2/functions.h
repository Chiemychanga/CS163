/* clarry@pdx.edu
 * CS163
 * Program 2 
 * April 28, 2016
 *
 * functions.h
 * This file holds 
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE_ARRAY = 5;

/* Struct packageinfo 
 * Task:
 * */
class Package
{
    public:
        Package(void);
        ~Package(void);
        int create_entry(char * SENDER, char * RECIPIENT, int WEIGHT);
        int copy_entry(const Package & new_package);
        int display(void);

private:
    char * sender;
    char * recipient;
    int weight;
};

bool again();
/* struct node
 * Task: This is the struct used for the LLL
 *. */
struct node
{
    Package * a_package;
    node * next;
};

/* class stack 
 * Task: This class manages the LLL with functions and
 * holds the head pointer to struct node.*/
class stack 
{
    public:
        stack(void);
        ~stack(void);
        int isEmpty();
        int isFull();
        int push(const Package & to_push);
        int pop(Package & to_pop);
        int peek(Package & to_peek);
        int display_all(node * head);
        int display(void);
    private:
        node * head;
        int top_index;
};
