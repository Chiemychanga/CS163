/* clarry@pdx.edu
 * CS163
 * Program 1
 * April 4, 2016
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
lll::lll(void)
{
    head = NULL;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
lll::~lll(void)
{
    node * current = head;
    while(current)
    {
        head = head->next;
        delete current;
        current = head;
    }
    head = NULL;
}

/*  Read in 
 * Task:This function reads in from an external file "airport.txt"
 * and stores in the data into a temporary object of struct airport,
 * and passes in that object to add to the LLL. 
 * Input: Nothing.
 * Output: A non-zero for success, a zero for fail, */
int lll::read_in()
{
    int counter = 0;
    airport temp;
    ifstream file;
    file.open("airport.txt");
    if(file)
    {
        while(!file.eof())
        {
            char tempp[SIZE_NAME];
            file.get(tempp,SIZE_NAME,':');
            file.ignore(100,':');
            temp.name = new char[strlen(tempp)+1];
            strcpy(temp.name, tempp);
            file >> temp.customs;
            file.ignore(100,':');
            file >> temp.immigration;
            file.ignore(100,':');
            file >> temp.checkpoints;
            file.ignore(100,':');
            file >> temp.processtime;
            file.ignore(100,':');
            file >> temp.traveltime;
            file.ignore(100,'\n');
            add(temp);
            file.peek();
        }
    }
    file.close();
    return counter;
}

/* Add
 * Task: This function inserts a new node before head(UNSORTED).
 * Input: Reference to struct airport.
 * Output: A non-zero for success, a zero for fail, */
int lll::add(airport & a)
{
    node * temp = new node;
    temp->next = head;
    head = temp;
    head->data1.name = new char[strlen(a.name)+1];
    strcpy(head->data1.name, a.name);
    head->data1.customs = a.customs;
    head->data1.immigration = a.immigration;
    head->data1.checkpoints = a.checkpoints;
    head->data1.processtime = a.processtime;
    head->data1.traveltime = a.traveltime;
    return 1;
}

/* Sum 
 * Task: Finds the sum of commute time for the argument's airport based
 * off of the administrative info.
 * Input: A character pointer and a struct admin passed by reference.
 * Output: A non-zero for success, a zero for fail, */
int lll::sum(char * name, struct admin & to_sum)
{
    int total = 0;
    if(!head)
        return -1;
    node * current = head;
    while(current)
    {
        if(strcmp(current->data1.name, name) == 0)
        {
            if(to_sum.customs)
                total += current->data1.customs;
            if(to_sum.immigration)
                total += current->data1.immigration;
            if(!to_sum.pre_TSA)
                total += (current->data1.checkpoints * current->data1.processtime);
            total += current->data1.traveltime;
            return total;
        }
        current = current->next; 
    }
    return -1;
}

/* Check 
 * Task: This function just checks the LLL for the matched airport.
 * Input: A character pointer.
 * Output: A non-zero for success, a zero for fail, */
int lll::check(char * match)
{
    if(!head)
        return 0;
    node * current = head;
    while(current)
    {
        if(strcmp(current->data1.name, match) == 0)
            return 1;
        else 
            current = current->next;
    }
    return 0;
}

/*Display 
 * Task: This function just displays the airports from the LLL so 
 * the user can see what airport choices they have. 
 * Input: Nothing.
 * Output: A non-zero for success, a zero for fail, */
int lll::display()
{
    int counter = 0;
    if(!head)
        return 0;
    node * current = head;
    while(current)
    {
        cout << counter << ". ";
        cout << current->data1.name;
        if(current->next)
            cout << "\n";
        current = current->next;
        ++counter;
    }
    cout << endl;
    return 1;
}


/* Constructor
 * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Nothing. 
 * Output: Nothing. */
a_lll::a_lll(void)
{
    head = NULL;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
a_lll::~a_lll(void)
{
    a_node * current = head;
    while(current)
    {
        head = head->next;
        delete current;
        current = head;
    }
    head = NULL;
}

/* Insert 
 * Task: This function inserts a_node at the end of each array and 
 * deep copies the name, departure and arrival times.
 * Input: Pass by reference to the struct times const. 
 * Output: A non-zero for success, a zero for fail, */
int a_lll::insert(const times & to_add)
{
    a_node * current = head;
    if(!head)
    {
        head = new a_node;
        head->next = NULL;
        current = head;
    }
    else
    {
        while(current->next)
            current = current->next;
        a_node * temp = new a_node;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    current->data2.name = new char[strlen(to_add.name)+1];
    strcpy(current->data2.name, to_add.name);
    current->data2.departure = to_add.departure;
    current->data2.arrival = to_add.arrival;
    return 1;
}


/* 
 * Task:
 * Input:
 * Output: A non-zero for success, a zero for fail, */
int a_lll::display_all()
{
    a_node * current = head;
    if(!head)
        return 0;
    while(current)
    {
        cout << current->data2.name << ".\n";
        if(current->data2.departure == 0)
            cout << "TRIP ENDED.\n";
        else
            cout << "Time of departure: " << current->data2.departure << ".\n";
        cout << "Time of arrival: " << current->data2.arrival << ".\n\n";
        current = current->next;
    }
    return 1;
}


/* Constructor
 * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Int size
 * Output: Nothing. */
arraylll::arraylll(int size)
{
    array = new admin [size];
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
arraylll::~arraylll()
{
    if(array)
    {
        delete [] array;
        array = NULL;
    }
}

/* arraylll insert  
 * Task: This function takes in a const reference to 
 * struct times and an int index and passes both arguments
 * into a_lll's insert function. This will create the 
 * linked list in the correct array element.
 * Input:Const reference of struct times and an int index.
 * Output: A non-zero for success, a zero for fail, */
int arraylll::insert(const times & to_add, int index)
{
    array[index].object.insert(to_add);
    return 0;
}


/* arraylll copy_admin 
 * Task: Deep copies the argument's const reference to struct admin
 * to the correct index's struct admin members.
 * Input:A const reference to struct admin and an int index.
 * Output: A non-zero for success, a zero for fail, */
int arraylll::copy_admin(const admin & to_copy, int index)
{
    array[index].dom_int = to_copy.dom_int;
    array[index].customs = to_copy.customs;
    array[index].immigration = to_copy.immigration;
    array[index].pre_TSA = to_copy.pre_TSA;
    return 1;
}

/* arraylll's display 
 * Task: Displays the array element's administrative info
 * and then calls a_lll's display_all function which 
 * displays each nodes's name, departure and arrival times
 * till the end of the list.
 * Input:An int index.
 * Output: A non-zero for success, a zero for fail, */
int arraylll::display(int index)
{
    cout << "TRIP# " << index << endl;
    cout << "Administrative Information:" << endl;
    if(array[index].dom_int == true) 
        cout << "\nDomesetic.\n";
    else 
        cout << "\nInternational.\n";
    if(array[index].customs == true)
        cout << "\nCustoms.\n";
    else 
        cout << "\nNo Customs.\n";
    if(array[index].pre_TSA == true)
        cout << "\nPre TSA approval.\n";
    else 
        cout << "\nNo Pre TSA.\n";
    cout << "__________________\n"; 
    array[index].object.display_all();

    return 0;
}

/* arraylll display_all
 * Task: This function takes in int size so that it 
 * gets the size of the array and displays everything through 
 * each element.
 * Input: An int size.
 * Output: A non-zero for success, a zero for fail, */
int arraylll::display_all(int size)
{
   for(int i = 0; i<size; ++i)
   {
       cout << "\n\nHere is the complete itinerary:\n";
       display(i);
   }
   return 1;
}
