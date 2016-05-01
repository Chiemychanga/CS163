/* clarry@pdx.edu
 * CS163
 * Program 1
 * April 4, 2016
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
    lll LLL;
    LLL.read_in();

    
    char response;
    bool retry = true;
    //The variable "trips" will determine the size of the array
    int trips;


    cout << "Is this a one-way trip? (Y/N)\n";
    cin >> response; cin.ignore(100,'\n');
    response = toupper(response);
    if(response == 'Y')
        trips = 1; 
    if(response == 'N')
    {
        cout << "How many trips will you be making?\n" ;
        cin >> trips; cin.ignore(100,'\n');
    }
//This will create the array by passing in "trips"
//into the constructor arraylll(int size).
    arraylll itinerary(trips);

//This for loop will ensure that we are building
//the linked list at the correct element array.
    for(int i = 0;i<trips;++i)
    {
/* Repeat this for each itinerary.array[i] in the arrays.*/ 
       
//Creating objects for the struct times(data in each a_node)
//and for the struct admin (info inside every element array).
        times TIMES;
        admin temp_admin;
        char temp[30];

        do
        {
//This section of the do while loop
//will read in all of the admininstrative
//information by passing in "temp_admin"
//into my "itinerary.copy_admin" function
//which deep copies the bools.
            cout << "\n******Trip/Array:" << i << "*********";
            cout << "\n\nAdministrative Information:\n";
            cout << "________________________________\n";
            cout << "\nDomestic or International? (D or I)\n";
            cin >> response; cin.ignore(100,'\n');
            response = toupper(response);
            if(response == 'D')
                temp_admin.dom_int = true;
            if(response == 'I')
                temp_admin.dom_int = false;
            cout << "\nCustoms? (Y/N)\n";
            cin >> response; cin.ignore(100,'\n');
            response = toupper(response);
            if(response == 'Y')
                temp_admin.customs = true;
            if(response == 'N')
                temp_admin.customs = false;
            cout << "Pre TSA approval? (Y/N)\n";
            cin >> response; cin.ignore(100,'\n');
            response = toupper(response);
            if(response == 'Y')
                temp_admin.pre_TSA = true;
            if(response == 'N')
                temp_admin.pre_TSA = false;
//Pass in temp_admin to deep copy in the function "copy_admin".
            itinerary.copy_admin(temp_admin,i);
            cout << "\nList of airports\n";
            LLL.display();
//Every time the user enters an airport,
//I pass in the "temp" into my "LLL.check" 
//function to make sure that it exists in the
//LLL first. If it doesn't, retry.
            cout << "\nStarting point:\n ";
            cin.get(temp,30,'\n'); cin.ignore(100,'\n');
            if(LLL.check(temp) == 0) 
            {
                cout << "\nInvalid entry. Please try again.\n";
                retry = false;
            }
        }while(retry == false);
        
/*Now I deep copy temporary TIMES into the insert function. */
        TIMES.name = new char[strlen(temp)+1];         
        strcpy(TIMES.name, temp);
        cout << "Departure time (ex.2459): ";
        cin >> TIMES.departure; cin.ignore(100,'\n');
        cout << "Arrival time (ex. 2459): ";
        cin >> TIMES.arrival; cin.ignore(100,'\n');
        
        itinerary.insert(TIMES,i);

/*This for loop will be responsible for inserting
 * any layover flights in between the starting
 * and destination points.*/        
        int layovers = 0;
        cout << "\nHow many layovers?\n";
        cin >> layovers; cin.ignore(100,'\n'); 

        for(int j = 0;j<layovers;++j)
        {
//Always changing int variable gate A based of the previous node's
//arrival time.
            int gateA = TIMES.arrival;
            do
            {
                retry = true;
                cout << "\nNext airport: ";
                char temp[30];
                cin.get(temp,30,'\n'); cin.ignore(100,'\n');
                if(LLL.check(temp)==0)
                {
                    cout << "\nInvalid entry. Please try again.\n";
                    retry = false;
                }
                TIMES.name = new char[strlen(temp)+1];         
                strcpy(TIMES.name, temp);
            }while(retry == false);
            
            do
            {
                retry = true;
                cout << "Departure time (ex.2459): ";
                cin >> TIMES.departure; cin.ignore(100,'\n');

/* This function checks if the client will have enough time to
 * get to the next airport's gate in time. If not, they will
 * have to insert a later time that will work.*/
                int gateBdeparture = TIMES.departure;
                int timetoB = gateA + LLL.sum(TIMES.name,temp_admin); 
                if(gateBdeparture < timetoB)
                {
                    cout << "\nTHERE IS NOT ENOUGH TIME TO MAKE IT TO THE NEXT GATE.\n";
                    retry = false;
                }
                else if(gateBdeparture > timetoB)
                {
                    cout << "\nYou will arrive approximately at: " << timetoB << ".\n";
                    cout << "\nYou have " << gateBdeparture - timetoB << "minutes til your flight at " << gateBdeparture << endl;
                }
            }while(retry == false); 

            cout << "\nArrival time (ex. 2459): ";
            cin >> TIMES.arrival; cin.ignore(100,'\n');
            itinerary.insert(TIMES,i); 
        }
        
        retry = true;
        do
        {
            cout << "\nDestination point:\n ";
            cin.get(temp,30,'\n'); cin.ignore(100,'\n');
            if(LLL.check(temp) == 0) 
            {
                cout << "\nInvalid entry. Please try again.\n";
                retry = false;
            }
            else
                retry = true;
        }while(retry == false);

        TIMES.name = new char[strlen(temp)+1];         
        strcpy(TIMES.name, temp);


/* For the destination airport, departure time does
 * not exist.*/
        int END = 0;
        TIMES.departure = END;
        cout << "Arrival time (ex. 2459): ";
        cin >> TIMES.arrival; cin.ignore(100,'\n');

        itinerary.insert(TIMES,i);
        cout << "\n******Trip/Array:" << i << "End.*********";
    }
/*End of the for loop above. */

/*This will be the last of the program, the do
 * while loop which will give the client the option of 
 * displaying their whole itinerary or
 * just one trip, or exiting the program. */
    do
    {
        retry = true;
        cout << "1. Display All \n"; 
        cout << "2.Display one trip \n";
        cout << "3.Exit" ;
        cin >> trips; 
        if(trips == 1)
            itinerary.display_all(trips);
        if(trips == 2)
        {
            cout << "\nWhich trip/array do you want displayed?(0,1,2,...etc)";
            cin >> trips; cin.ignore(100,'\n');
            itinerary.display(trips);
        }
        if(trips == 3)
            retry = false;
    }while(retry == true); 

    return 0;
}
