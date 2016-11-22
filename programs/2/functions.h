/* Larry Chiem 
 * CS163
 * Program 2 
 * April 28, 2016
 *
 * functions.h
 * This file holds all of the classes, structs, and
 * prototypes that will be used in the main.cpp.
 */

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE_ARRAY = 5;



/* Struct packageinfo 
 * Task: Keeps track of the data being entered between the client
 * and ADTs. In the private, it holds a
 * two dynamically allocated char arrays, and an int.*/
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

/* struct qnode 
 * Task: qnode(Queue's node) holds an object(delivery) to Package
 * and a next pointer to qnode.*/
struct qnode
{
    Package delivery; 
    qnode * next;
};

/* class queue 
 * Task: This Queue ADT holds operations and a rear
 * pointer to qnode.*/
class queue
{
    public:
        queue(void);
        ~queue(void);
        int enqueue(const Package & to_rear);//Enqueue to the rear.
        int dequeue();//Dequeue from the front.
        int display_all(void)const;//Displays the CLL.

    private:
        qnode * rear;
};

/* struct node 
 * Task: LLL of Array: Holds a_package pointer to Package, 
 * an int position (position array) and a next pointer to node. */
struct node
{
    Package * a_package;
    int position;
    node * next;
};

/* class stack 
 * Task: This stack ADT manages the LLL of arrays
 * with functions. In the private, it  holds the 
 * head pointer to struct node.*/
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
