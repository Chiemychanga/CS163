/* clarry@pdx.edu
 * CS163
 * Program 1
 * April 4, 2016
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

const int SIZE_NAME = 50;

/* Struct airport
 * Task: This struct holds the members that will
 * be saved from reading in the external data file.*/
struct airport
{
    char * name;
    int customs;
    int immigration;
    int checkpoints;
    int processtime;
    int traveltime;
};

/* struct node
 * Task: This is the struct used for the LLL
 * holding the information of all major airports
 * from the external file. */
struct node
{
    airport data1;
    node * next;
};

/* class lll
 * Task: This class manages the LLL with functions and
 * holds the head pointer to struct node.*/
class lll
{
    public:
        lll(void);
        ~lll(void);
        int read_in();//Reads in from external file and stores.
        int add(airport &);//Adds into the beginning of the LLL.
        int sum(char * name, struct admin & to_sum);//Checks the admin bools and returns the time.
        int check(char * match);//Checks for the match in the LLL.
        int display();//Displays only the names from the LLL.
    private:
        node * head;
};

/* struct times
 * Task: This is the struct used for the linked list
 * in the itinerary's arrays. It holds the name of
 * airports along with their departure and arrival time. */
struct times
{
    char * name;
    int departure;
    int arrival;
};

/* struct a_node
 * Task: This is the struct used for the class a_lll 
 * which has an object of struct times and a next
 * pointer to struct a_node. */
struct a_node
{
    times data2;
    a_node * next;
};

/* class a_lll
 * Task: This class is responsible for the linked list
 * in the arrays. It holds a head pointer to struct a_node.
 */
class a_lll
{
    public:
        a_lll(void);
        ~a_lll(void);
        int insert(const times & to_add);//Creates the linked list from the array. 
        int display_all();//displays the list with name and times of departure and arrival.
    private:
        a_node * head;
};

/* struct admin
 * Task: This struct holds the administrative info
 * and an object to the class a_lll so that it 
 * has it's head pointer to a_node. This will be the 
 * same in every array element */
struct admin
{
    bool dom_int;
    bool customs;
    bool immigration;
    bool pre_TSA;
    a_lll object;
};

/* class arraylll
 * This class is responsible for creating the array,
 * which is a pointer to admin.   */
class arraylll
{
    public:
        arraylll(int size);                
        ~arraylll();
        int insert(const times & to_add, int index);//Calls the insert function from the specified array element.
        int copy_admin(const admin & to_copy, int index);//Deep copies the admin info
        int display(int index);//Displays the admin info and calls the display_all for the linked list in the specified array element. 
        int display_all(int size);//Displays the whole itinerary starting from the first trip.
    private:        
        admin * array;    
};
