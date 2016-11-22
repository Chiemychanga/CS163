/* Larry Chiem
 * CS163 - Program 3: Hash Tables.
 * 05/3/2016 
 * main.cpp
 * Task: In this program, we will use an 
 * array to represent the hash table and
 * chaining as the collision resolution
 * technique.  
                  ______    _    _
                 |______|->|_|->|_|->|NULL|
 key     hash    |______|->|_|->|NULL|
        function |______|->|NULL|
                 hash table 
 *
 *
 * */
#include "functions.h"
using namespace std;

const int KEYWORD = 20;

int main()
{
    table array;
    studyGuide study;
    
    array.readIn();

    cout << "\n\nHere's what is initially from the external data file: \n\n";
    array.displayAllKey();
    char findKey[KEYWORD];
    int givenChapter;
    int option;
    do
    {
        cout << "1. \n\nInsert a new keyword with its information.\n"
             << "2. Search for keyword and remove the notes\n"
             << "3. Search for keyword and edit description\n"
             << "4. Retrieve a keyword.\n"
             << "5. Display for a given chapter, all keywords:\n" 
             << "6. Display all keywords.\n"
             << "7. Given a keyword, return the index.\n\n\n";

        cout << "Enter the option:";
        cin >> option; cin.ignore(100,'\n');
        if(option == 1)
        {
            array.insertNewKey();
            array.displayAllKey();
        }
        if(option == 2)
        {
            cout << "\nSearch for keyword and remove:";
            cin.get(findKey,100,'\n'); cin.ignore(100,'\n');
            if(array.removeKey(findKey)==1)
            {
                cout << "\nAfter Remove\n\n";
                array.displayAllKey();
            }
            else
            {
                cout << "\nRemove did not occur.\n\n";
                array.displayAllKey();
            }
        }
        if(option == 3)
        {
            cout << "\nSearch for keyword and edit description:";
            cin.get(findKey, 100,'\n'); cin.ignore(100,'\n');
            array.toEditDescriptionKey(findKey);
            cout << "\nAfter edit\n\n";
            array.displayAllKey();
        }
        if(option == 4)
        {
            cout << "\nRetrieve a keyword.";
            cin.get(findKey,100,'\n'); cin.ignore(100,'\n');
            if(array.retrieveKey(findKey, study)==true)
                cout << "\nRetrieve success!\n\n";
            else
                cout << "\nRetrieve fail!\n\n";
        }
        if(option == 5)
        {
            cout << "\nDisplay for a given chapter, all keywords:\n";
            cin >> givenChapter; cin.ignore(100,'\n');
            array.displayGivenChapter(givenChapter);
        }
        if(option == 6)
        {
            array.displayAllKey();
        }
        if(option == 7)
        {
            cout << "\nGiven a keyword, return the index:";
            cin.get(findKey,100,'\n'); cin.ignore(100,'\n');
            cout << findKey << " goes to index: " << array.hashFunction(findKey);
        }
    }while(again());
    return 0;
}
