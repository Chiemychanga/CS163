/* Larry Chiem 
 * CS163 - Program 4: BST.
 * 05/25/2016 
 * main.cpp
 * Task: In this program, we will use an 
 * Table to represent the hash table and
 * chaining as the collision resolution
 * technique.  
 *                          Root
 *                          /   \
 *                      Less    Greater or equal to.
 * */
#include "functions.h"
using namespace std;

const int KEYWORD = 20;
const int DESCRIPTION = 100;

int main()
{
    table Table;
    Table.readIn();

    cout << "\n\nHere's what is initially from the external data file: \n\n";
    Table.displayTreeInOrder();
    
    char findKey[KEYWORD];
    int option;
    do
    {
        cout << "\n1. Insert a new keyword with its information.EXTRA CREDIT DOESN'T WORK, WORKS FROM READIN.\n"
             << "2. Search for keyword and remove the notes\n"
             << "3. Search for keyword and edit description\n"
             << "4. Retrieve a keyword.\n"
             << "5. Display all keywords within a given range:\n" 
             << "6. Display all keywords in sorted order.\n"
             << "7. Quit. \n"
             << "8. Remove All\n";

        cout << "Enter the option:";
        cin >> option; cin.ignore(100,'\n');
        if(option == 1)
        {
            /* This section gave me a seg fault. If you can figure it out, 
             * you're smart.
            studyGuide tempStudy;
            char key[SIZE_CHAR];
            char desc[SIZE_CHAR];
            int chapterSize;
            int chapterValue;
            int pageSize;
            int pageValue;
            int flagger;
            bool flag;

            cout << "\nENTER A NEW KEYWORD WITH IT'S INFORMATION:\n";
            cout << "\nKeyword:";
            cin.get(key,SIZE_CHAR,'\n'); cin.ignore(100,'\n');
            tempStudy.setKey(key);

            cout << "\nDescription:";
            cin.get(desc,SIZE_CHAR,'\n'); cin.ignore(100,'\n');
            tempStudy.setDescription(desc);

            //:n,1,2: n is the size of array
            cout << "\nHow many chapters(Set the size of the array):";
            cin >> chapterSize; cin.ignore(100,'\n');
            tempStudy.setChapterArray(chapterSize);
            for(int i = 0; i<chapterSize; ++i)
            {
                cout << "\nEnter a chapter:";
                cin >> chapterValue; cin.ignore(100,'\n');
                tempStudy.setChapter(i, chapterValue);
            }
            cout << "\nHow many pages(Set the size of the array):";
            cin >> pageSize; cin.ignore(100,'\n');
            tempStudy.setPageArray(pageSize);
            for(int j = 0; j<pageSize; ++j)
            {
                cout << "\nEnter a page:";
                cin >> pageValue; cin.ignore(100,'\n');
                tempStudy.setPage(j, pageValue);
            }
            cout << "\n Flag for importance of this Keyword:\n" 
                << "0 = No additional study needed. \n1 = Additional study needed.";
            cin >> flagger; cin.ignore(100,'\n');
            if(flagger == 0)
                flag = false;
            else
                flag = true;
            tempStudy.setImportant(flag);

            Table.insertKey(tempStudy);
            */

        }
        if(option == 2)
        {
            cout << "\nSearch for keyword and remove:";
            cin.get(findKey,100,'\n'); cin.ignore(100,'\n');
            if(Table.removeKey(findKey)==1)
            {
                cout << "\nAfter Remove\n\n";
                Table.displayTreeInOrder();
            }
            else
            {
                cout << "\nRemove did not occur.\n\n";
            }
        }
        if(option == 3)
        {
            cout << "\nSearch for keyword and edit description:";
            cin.get(findKey, 100,'\n'); cin.ignore(100,'\n');

            char addDescription[SIZE_CHAR];
            cout << "\nAdditional description: "; 
            cin.get(addDescription,SIZE_CHAR,'\n'); cin.ignore(100,'\n');

            Table.toEditDescriptionKey(findKey, addDescription);
            cout << "\nAfter edit\n\n";
            Table.displayTreeInOrder();
        }
        if(option == 4)
        {
            cout << "\nRetrieve a keyword.";
            cin.get(findKey,100,'\n'); cin.ignore(100,'\n');
            
            if(Table.retrieveKey(findKey))
                cout << "\nRetrieve success!\n\n";
            else
                cout << "\nRetrieve fail!\n\n";
        }
        if(option == 5)
        {
            char min[SIZE_CHAR];
            char max[SIZE_CHAR];
            cout << "\nDisplay all keywords within a range:\n";
            cout << "\nMin:";
            cin.get(min,100,'\n'); cin.ignore(100,'\n');
            cout << "\nMax:";
            cin.get(max,100,'\n'); cin.ignore(100,'\n');
            Table.displayRange(min, max);
        }
        if(option == 6)
        {
            cout << "\nDisplay all keywords (in sorted order): \n"; Table.displayTreeInOrder(); } if(option == 7)
        {
            return 1;
        }
        if(option == 8)
        {
            Table.removeAll();
            cout << "\nEmpty Tree after Removal:\n";
            Table.displayTreeInOrder();
        }
    }while(again());
    return 0;
}
