/* Larry Chiem 
 * Program 2 
 * April 28, 2016
 *
 * functions.cpp
 * This file holds all of the implemented functions
 * from functions.h.
 */
#include "functions.h"
using namespace std;


/* Constructor * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Nothing. 
 * Output: Nothing. */
queue::queue(void)
{
    rear = NULL;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
queue::~queue(void)
{
    if(rear)
    {
        qnode * temp = rear;
        while(temp->next != rear)
        {
            qnode * end = temp;
            temp = temp->next;
            delete end;
        }
        delete temp;
        rear = NULL;
    }
}

/* enqueue
 * Task: Adds a new node at the rear
 * Input: const Package & to_rear
 * Output: A non-zero for success, a zero for fail*/ 
int queue::enqueue(const Package & to_rear)
{
    if(!rear)
    {
        rear = new qnode;
        rear->next = rear;
        rear->delivery.copy_entry(to_rear);
        return 1;
    }
    else
    {
        qnode * temp = new qnode;
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
        rear->delivery.copy_entry(to_rear);
        temp = NULL;
    }
    return 1;
}

/* dequeue
 * Task: Dequeues at the front(rear->next) of the linked list.
 * Input:Nothing.
 * Output: A non-zero for success, a zero for fail*/ 
int queue::dequeue()
{
    if(!rear) return 0;
    if(rear->next == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    else
    {
        qnode * temp = rear->next;
        rear->next = temp->next;
        delete temp;
    }
    return 1;
}

/* display_all
 * Task: Turns the CLL into a LLL, and traverses and displays.
 * Input: void.
 * Output: A non-zero for success, a zero for fail*/ 
int queue::display_all(void)const
{
    if(!rear) return 0;
    qnode * current = rear->next;
    rear->next = NULL;
    while(current)
    {
        current->delivery.display();
        current = current->next;
    }
    return 1;
}

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

/* create_entry 
 * Task: creates the entry based of passed in arguments.
 * Input: char * SENDER, char * RECIPIENT, int WEIGHT.
 * Output: A non-zero for success, a zero for fail*/ 
int Package::create_entry(char * SENDER, char * RECIPIENT, int WEIGHT)
{
    sender = new char[strlen(SENDER)+1];
    strcpy(sender, SENDER);
    recipient = new char[strlen(RECIPIENT)+1];
    strcpy(recipient, RECIPIENT);
    weight = WEIGHT;
    return 1;
}

/* copy_entry 
 * Task: Deletes any arrays, then deep copies into those arrays
 * the argument's arrays passed in.
 * Input: const Package & new_package.
 * Output: A non-zero for success, a zero for fail*/ 
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

/* display 
 * Task: Displays the package info.
 * Input: Void.
 * Output: A non-zero for success, a zero for fail*/ 
int Package::display(void)
{
    if(sender)
    {
        cout << "\nFrom:" << sender << endl;
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

/* isEmpty 
 * Task:Checks if the stack is empty.
 * Input: nothing. 
 * Output: A non-zero for success, a zero for fail*/ 
int stack::isEmpty()
{
    if(!head)
        return 1;
    else
        return 0;
}

/* push 
 * Task: This function allocates the stack, adding a node
 * at head, then copying the entry into each top_index.
 * Input: const Package & to_push.
 * Output: A non-zero for success, a zero for fail*/ 
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


/* display 
 * Task: Function overload display_all (I think that's what
 * this is called).
 * Input:void.
 * Output: A non-zero for success, a zero for fail*/ 
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

/* display_all
 * Task: This function displays on the recursive return 
 * showing from the top_index down to index 0.
 * Input: node * head.
 * Output: A non-zero for success, a zero for fail*/ 
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
