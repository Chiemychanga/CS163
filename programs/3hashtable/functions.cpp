/* Larry Chiem 
 * CS163 - Program 3: Hash Tables 
 * 05/3/2016
 * functions.cpp
 * This file holds all of the implemented functions.  
 */
#include "functions.h"
using namespace std;

/* Constructor
 * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Nothing. 
 * Output: Nothing. */
studyGuide::studyGuide(void)
{
    keyword = NULL;
    description = NULL;
    chapter = NULL;
    chapterSize = 0;
    page = NULL;
    pageSize = 0;
    important = false;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
studyGuide::~studyGuide(void)
{
    if(keyword)
    {
        delete [] keyword;
        keyword = NULL;
    }
    if(description)
    {
        delete [] description;
        description = NULL;
    }
    if(chapter)
    {
        delete [] chapter;
        chapter = NULL;
    }
    if(page)
    {
        delete [] page;
        page = NULL;
    }
    important = false;
}

/* copyEntry 
 * Task: This function deep copies whatever temporary object of studyGuide
 * gets passed in.
 * Input: object of studyGuide 
 * Output: Returns a 1 for success. */
int studyGuide::copyEntry(const studyGuide & newGuide)
{
    if(keyword) delete [] keyword;
    keyword = new char[strlen(newGuide.keyword)+1];
    strcpy(keyword, newGuide.keyword);

    if(description) delete [] description;
    description = new char[strlen(newGuide.description)+1];
    strcpy(description, newGuide.description);

    int * tempChapterIndex = newGuide.pointChapter();
    if(chapter) delete [] chapter;
    chapter = new int[newGuide.getChapterArray()];
    for(int i=0; i<newGuide.getChapterArray(); ++i)
    {
        *(chapter+i) = *(tempChapterIndex+i); 
    }
    chapterSize = newGuide.chapterSize;

    int * tempPageIndex = newGuide.pointPage();
    if(page) delete [] page;
    page = new int[newGuide.getPageArray()];
    for(int j=0; j<newGuide.getPageArray(); ++j)
        *(page+j) = *(tempPageIndex+j);

    pageSize = newGuide.pageSize;
    important = newGuide.important;
    return 1;
}

/* setKey 
 * Task: Takes the dynamic char array and deep copies the keyword. 
 * Input: A pointer to a char array. 
 * Output: Nothing. */
void studyGuide::setKey(char * key)
{
    keyword = new char[strlen(key)];
    strcpy(keyword, key);
}

/* getKey 
 * Task: Returns the keyword.  
 * Input: Nothing. 
 * Output: Returns a char *.  */
char * studyGuide::getKey()
{
    return keyword;
}

/* setDescription
 * Task: Takes the dynamic char array and deep copies the keyword. 
 * Input: A pointer to a char array. 
 * Output: Nothing. */
void studyGuide::setDescription(char * describe)
{
    description = new char[strlen(describe)];
    strcpy(description, describe);
}

/* editDescription
 * Task: This function will create a new array that will fit
 * the OLD DESCRIPTION + addDescription, then deallocates the OLD DESCRIPTION
 * and allocaates for the NEW DESCRIPTION. 
 * Input: A pointer to a char array. 
 * Output: Returns a 0 for fail and a 1 for success. */
int studyGuide::editDescription(char * addDescription)
{
    if(!addDescription) return 0;

    int newSizeArray = strlen(description) + strlen(addDescription);
    char * newDescription = new char[newSizeArray+3];
    newDescription[0] = '\0';
    strcat(newDescription, description);
    strcat(newDescription,". ");
    strcat(newDescription, addDescription);
    
    if(description) delete [] description;
    description = new char[strlen(newDescription)];
    strcpy(description, newDescription);

    delete [] newDescription;
    return 1;
}

/* setChapterArray 
 * Task: Allocates the array size of chapter and returns the chapterSize. 
 * Input: An int size. 
 * Output: Returns the chapterSize. */
int studyGuide::setChapterArray(int size)
{
    chapterSize = size;
    chapter = new int[chapterSize];
    return chapterSize;
}

/* getChapterArray 
 * Task: Gets the chapterSize. 
 * Input: Nothing. 
 * Output: Returns the chapterSize. */
int studyGuide::getChapterArray()const
{
    return chapterSize;
}

/* findChapter 
 * Task: Takes in an int to findChapter, and uses a for loop to
 * go through the chapter with pointer arithmetic until it finds a match.
 * Input: An int findChapter. 
 * Output: Returns a 0 for fail, returns a 1 for success.  */
int studyGuide::findChapter(int findChapter)
{
    int chapterSize = getChapterArray();
    for(int i=0; i<chapterSize; ++i)
    {
        if(*(chapter+i) == findChapter)
            return 1;
    }
    return 0;
}

/* pointChapter()
 * Task: Returns the int pointer chapter. 
 * Input: Nothing. 
 * Output: Returns the int pointer. */
int * studyGuide::pointChapter()const
{
    return chapter;
}

/* setChapter  
 * Task: Sets the chapter's element to the value passed in. 
 * Input: Two int values. 
 * Output: Nothing. */
void studyGuide::setChapter(int index, int value)
{
    chapter[index] = value;
}

/* setPageArray
 * Task: Dynamically allocates the page array to the pageSize,
 * then returns the pageSize.
 * Input: An int size. 
 * Output: Returns an int (pageSize). */
int studyGuide::setPageArray(int size)
{
    pageSize = size;
    page = new int[pageSize];
    return pageSize;
}

/* getPageArray
 * Task: Returns the pageSize from the private member.  
 * Input: Nothing. 
 * Output: Returns the pageSize. */
int studyGuide::getPageArray()const
{
    return pageSize;
}

/* pointPage 
 * Task: Returns the pointer to an int from private member.  
 * Input: Nothing. 
 * Output: Returns the page pointer to int.  */
int * studyGuide::pointPage()const
{
    return page;
}

/* setPage 
 * Task: Sets the private member page's element to the value passed in. 
 * Input: Two int values. 
 * Output: Nothing. */
void studyGuide::setPage(int index, int value)
{
    page[index] = value;
}

/* setImportant 
 * Task: Sets the private member important to the passed in bool flag. 
 * Input: A bool flag. 
 * Output: Nothing. */
void studyGuide::setImportant(bool flag)
{
    important = flag;
}

/* display 
 * Task: Displays all the private data members. 
 * Input: Nothing. 
 * Output: Returns a 0 for failure, Returns a 1 for success. */
int studyGuide::display()
{
    if(!keyword) return 0;
    cout << "\n\nKeyword:" << keyword
         << "\nDescription:" << description
         << "\nChapter(s):"; 
    for(int i=0; i<getChapterArray();++i)
    {
        cout << chapter[i];
        if(i != getChapterArray()-1)
            cout << ", ";
    }
    cout << "\nPage(s):";
    for(int j=0; j<getPageArray(); ++j)
    {
        cout << page[j];
        if(j != getPageArray()-1)
            cout << ", ";
    }
    if(important)
        cout << "\nIMPORTANT!\n";
    else
        cout << "\nNOT IMPORTANT!\n";
    return 1;
}

/* Constructor
 * Task: Initializes the members, and is implicitly
 * invoked whenver a client creates an object of the
 * class.
 * Input: Nothing. 
 * Output: Nothing. */
table::table()
{
    hashTableSize = 5;
    hashTableKey = new node *[hashTableSize]();
    hashTableChapter = new node *[hashTableSize]();
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
table::~table()
{
   node * current;
   node * head;
   if(hashTableKey)
   {
       for(int i=0; i<hashTableSize; ++i)
       {
           head = *(hashTableKey+i);
           current = *(hashTableKey+i);
           while(current)
           {
               current = current->next;
               delete head;
               head = current;
           }
       }
       delete [] hashTableKey;
       hashTableKey = NULL;
   }
   if(hashTableChapter)
   {
       for(int i=0; i<hashTableSize; ++i)
       {
           head = *(hashTableKey+i);
           current = *(hashTableKey+i);
           while(current)
           {
               current = current->next;
               delete head;
               head = current;
           }
       }
       delete [] hashTableChapter;
       hashTableChapter = NULL;
   }
}

/*  Read in 
 * Task:This function reads in from an external file "study.txt"
 * and stores in the data into a temporary object of struct airport,
 * and passes in that object to add to the LLL. 
 * Input: Nothing.
 * Output: A non-zero for success, a zero for fail, */
int table::readIn()
{
    studyGuide tempStudy;
    ifstream file;
    file.open("study.txt");
    if(file)
    {
        while(!file.eof())
        {
            char key[SIZE_CHAR];
            char desc[SIZE_CHAR];

            int chapterSize;
            int chapterValue;
            int pageSize;
            int pageValue;
            int flagger;
            bool flag;

            file.get(key,SIZE_CHAR,':'); file.ignore(100,':');
            tempStudy.setKey(key);

            file.get(desc,SIZE_CHAR,':'); file.ignore(100,':');
            tempStudy.setDescription(desc);

            //:n,1,2: n is the size of array
            file >> chapterSize; file.ignore(100,',');
            int * saveChapters = new int[chapterSize];
            tempStudy.setChapterArray(chapterSize);
            for(int i = 0; i<chapterSize; ++i)
            {
                file >> chapterValue;
                if(i<chapterSize-1)
                    file.ignore(100,',');
                else
                    file.ignore(100,':');
                saveChapters[i] = chapterValue;
                tempStudy.setChapter(i, chapterValue);
            }

            file >> pageSize; file.ignore(100,',');
            tempStudy.setPageArray(pageSize);
            for(int j = 0; j<pageSize; ++j)
            {
                file >> pageValue;
                if(j<pageSize-1)
                    file.ignore(100,',');
                else
                    file.ignore(100,':');
                tempStudy.setPage(j, pageValue);
            }
            file >> flagger; file.ignore(100,'\n');
            if(flagger == 0)
                flag = false;
            else
                flag = true;
            tempStudy.setImportant(flag);

            insertKey(key, tempStudy); 
            for(int k = 0; k<chapterSize; ++k)
            {
                insertChapter(saveChapters[k], tempStudy);
            }
            file.peek();
        }
    }
    file.close();
    return 1;
}

/* insertKey 
 * Task: Inserts a new node into the hashTableKey element. 
 * Input: A key pointer to char, and a const object to studyGuide.
 * Output: A non-zero for success, a zero for fail, */
int table::insertKey(char * key, const studyGuide & toAdd)
{
    if(!key) return 0;
    int index = hashFunction(key);
    node * temp = new node; 
    temp->studyThis.copyEntry(toAdd);
    temp->next = hashTableKey[index];
    hashTableKey[index] = temp;
    return 1;
}

/* insertNewKey 
 * Task: Gets the user to enter a new keyword with its information. 
 * Input: Nothing.
 * Output: A non-zero for success, a zero for fail, */
int table::insertNewKey()
{
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

    cin.get(desc,SIZE_CHAR,'\n'); cin.ignore(100,'\n');
    tempStudy.setDescription(desc);

    //:n,1,2: n is the size of array
    cout << "\nHow many chapters(Set the size of the array):";
    cin >> chapterSize; cin.ignore(100,'\n');
    int * saveChapters = new int[chapterSize];
    tempStudy.setChapterArray(chapterSize);
    for(int i = 0; i<chapterSize; ++i)
    {
        cout << "\nEnter a chapter:";
        cin >> chapterValue; cin.ignore(100,'\n');
        saveChapters[i] = chapterValue;
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
    cout << "\n0 = No additional study needed. \n1 = Additional study needed.";
    cin >> flagger; cin.ignore(100,'\n');
    if(flagger == 0)
        flag = false;
    else
        flag = true;
    tempStudy.setImportant(flag);

    insertKey(key, tempStudy); 
    for(int k = 0; k<chapterSize; ++k)
    {
        insertChapter(saveChapters[k], tempStudy);
    }
    return 1;
}

/* insertChapter
 * Task: Inserts by int chapter into the hashTableChapter! 
 * Input: An int chap, and a const object to studyGuide. 
 * Output: A non-zero for success, a zero for fail, */
int table::insertChapter(int chap, const studyGuide & toAdd)
{
    if(!chap) return 0;
    int index = hashFunctionChapter(chap);
    node * temp = new node;
    temp->studyThis.copyEntry(toAdd);
    temp->next = hashTableChapter[index];
    hashTableChapter[index] = temp;
    return 1;
}

/* toEditDescriptionKey 
 * Task: Edit the description to add more text as you study, given the keyword. 
 * Input: A pointer to a char. 
 * Output: A non-zero for success, a zero for fail, */
int table::toEditDescriptionKey(char * findKey)
{
    if(!findKey) return 0;

    char addDescription[SIZE_CHAR];
    int index = hashFunction(findKey);
    node * current = hashTableKey[index];
    while(current)
    {
        if(strcmp(current->studyThis.getKey(),findKey)==0)
        {
            cout << "\nAdditional description: "; 
            cin.get(addDescription,SIZE_CHAR,'\n'); cin.ignore(100,'\n');
            current->studyThis.editDescription(addDescription);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

/* retrieveKey 
 * Task: Retrieve the information about a particular keyword.   
 * Input: 
 * Output: A true for success, a false for fail, */
bool table::retrieveKey(char * key, studyGuide & toCopy)
{
    if(!key) return false;
    int index = hashFunction(key);
    node * current = hashTableKey[index];
    if(hashTableKey[index])
    {
        while(current)
        {
            if(strcmp(current->studyThis.getKey(), key)==0)
            {
                current->studyThis.copyEntry(current->studyThis); 
                return true;
            }
            else
                current = current->next;
        }
    }
    return false;
}

/* removeKey
 * Task: Removes a keyword with its information. 
 * Input: A pointer to a char.  
 * Output: A non-zero for success, a zero for fail, */
int table::removeKey(char * key)
{
    if(!key) return 0;
    int index = hashFunction(key);
    return recursiveRemoveKey(hashTableKey[index], key);
}

/* recursiveRemoveKey 
 * Task: Recursively removes the matched keyword and its information. 
 * Input: A head pointer passed by reference, and a pointer to char. 
 * Output: A non-zero for success, a zero for fail, */
int table::recursiveRemoveKey(node *& head, char * key)
{
    if(!head) return 0;
    if(strcmp(head->studyThis.getKey(), key)==0)
    {
        node * temp = head;
        head = head->next;
        delete temp;
        return 1;
    }
    return recursiveRemoveKey(head->next, key);
}

/* hashFunction 
 * Task: Takes a pointer to char and gets the total value, mods that sum 
 * by the hashTableSize and returns the index it belongs in. 
 * Input: A pointer to char.  
 * Output: Returns the index it belongs in. */
int table::hashFunction(char * key)
{
    int length = strlen(key);
    int value = 0; 
    for(int i=0; i<length; ++i)
        value += (*(key+i));
    return value % hashTableSize;
}

/* hashFunctionChapter 
 * Task: Returns the index it belongs in. 
 * Input: An int chap. 
 * Output: Returns the index it belongs in.*/ 
int table::hashFunctionChapter(int chap)
{
    return chap % hashTableSize;
}

/* displayAllKey 
 * Task: Displays all keywords from the hashTableKey. 
 * Input: Nothing. 
 * Output: A non-zero for success, a zero for fail, */
int table::displayAllKey()
{
    if(!hashTableKey) return 0;
    for(int i=0; i<hashTableSize; ++i)
    {
        if(hashTableKey[i])
        {
            node * current = hashTableKey[i];
            while(current)
            {
                current->studyThis.display();
                current = current->next;
            }
        }
    }
    return 1;
}

/* displayGivenChapter 
 * Task: Displays all for a given chapter from the hashTableChapter  
 * Input: An int chap. 
 * Output: A non-zero for success, a zero for fail, */
int table::displayGivenChapter(int chap)
{
    if(!hashTableChapter || chap == 0) return 0;
    int index = hashFunctionChapter(chap);
    {
        if(hashTableChapter[index])
        {
            node * current = hashTableChapter[index];
            while(current)
            {
                if(current->studyThis.findChapter(chap))
                {
                    current->studyThis.display();
                }
                current = current->next;
            }
        }
    }
    return 1;
}

/* again 
 * Task: Prompts the user to re-run the program. 
 * Input: Nothing. 
 * Output: Returns a true for 'Y' or 'y' and returns a false for 'N' or 'n'. */
bool again()
{
    char answer;
    cout << "\nAgain? (Y/N)";
    cin >> answer; cin.ignore(100,'\n');
    if(answer == 'Y' || 'y')
        return true;
    if(answer == 'N' || 'n')
        return false;
}
