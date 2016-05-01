/* clarry@pdx.edu
 * CS163
 * Program 2 
 * April 28, 2016
 *
 * functions.cpp
 * This file holds 
 */
#include "functions.h"
using namespace std;

/* Constructor
 * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Nothing. 
 * Output: Nothing. */
Package::Package(void)
{
    sender = NULL;
    recipient = NULL;
    weight = 0;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
Package::~Package(void)
{
    if(sender)
        delete [] sender;
    if(recipient)
        delete [] recipient;
}

int Package::create_entry(char * SENDER, char * RECIPIENT, int WEIGHT)
{
    sender = new char[strlen(SENDER)+1];
    strcpy(sender, SENDER);
    recipient = new char[strlen(RECIPIENT)+1];
    strcpy(recipient, RECIPIENT);
    weight = WEIGHT;
    return 1;
}

int Package::copy_entry(const Package & new_package)
{
    if(sender) delete [] sender;
        sender = new char[strlen(new_package.sender)+1];
        strcpy(sender, new_package.sender);
    if(recipient) delete [] recipient;
        recipient = new char[strlen(new_package.recipient)+1];
        strcpy(recipient, new_package.recipient);
    weight = new_package.weight;
    return 1;
}

int Package::display(void)
{
    if(sender)
    {
        cout << "From:" << sender << endl;
        cout << "To:" << recipient << endl;
        cout << "Weight:" << weight << endl;
    }
    return 1;
}

/* Constructor
 * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Nothing. 
 * Output: Nothing. */
stack::stack(void)
{
    head = NULL;
    top_index = 0;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
stack::~stack(void)
{
    delete head;
}

int stack::isEmpty()
{
    if(!head)
        return 1;
    else
        return 0;
}

int stack::push(const Package & to_push)
{
   if(!head)
   {
       top_index = 0;
       node * temp = head;
       head = new node;
       head->a_package = new Package[SIZE_ARRAY];
       head->a_package[top_index].copy_entry(to_push);
       head->next = temp;
       ++top_index;
       return 1;
   }
    if(top_index == SIZE_ARRAY)
    {
        top_index = 0;
        node * temp = head;
        head = new node;
        head->next = temp;
        head->a_package = new Package[SIZE_ARRAY];
        head->a_package[top_index].copy_entry(to_push);
        ++top_index;
        return 1;
    }
   else
   {
       head->a_package[top_index].copy_entry(to_push);
       ++top_index;
   }
    return 1;
}

int stack::display(void)
{
/*    if(!head) return 0;
    node * current = head;
    while(current)
    {
        for(int i = 0; i < top_index;++i)
            current->a_package[top_index].display();
        current = current->next;
    }
    return 1;
    */
    return display_all(head);
}

int stack::display_all(node * head)
{    
    if(!head) return 0;
    display_all(head->next);
    for(int i = top_index; i >= 0; --i)
    {
        head->a_package[i].display();
    }
    return 1;
}
