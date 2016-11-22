/* Larry Chiem
 * CS163 - Program 3: Hash Tables.
 * 05/3/2016 
 *
 * functions.h
 * This file holds the classes, #includes, and prototype functions. 
 */
#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE_CHAR = 50;

/* This studyGuide class holds the private data members
 * and functions to access and edit those data members.
 * */
class studyGuide
{
    public:
        studyGuide(void);
        ~studyGuide(void);
        int copyEntry(const studyGuide & newGuide); 
        void setKey(char * key);
        char * getKey();
        void setDescription(char * describe);
        int editDescription(char * addDescription);
        int setChapterArray(int size); 
        int getChapterArray()const;
        int findChapter(int findChapter);
        int * pointChapter()const;
        void setChapter(int index, int value);
        int setPageArray(int size);
        int getPageArray()const;
        int * pointPage()const;
        void setPage(int index, int value);
        void setImportant(bool flag);
        int display();
    private:
        char * keyword;
        char * description;
        int * chapter;
        int chapterSize;
        int * page;
        int pageSize;
        bool important;
};

/* This struct node holds an object to the class studyGuide
 * and holds a next pointer to itself. */
struct node 
{
    studyGuide studyThis;
    node * next;
};

/*This class table manages the hash tables and holds the
 * prototype functions that were required for our program
 * by Karla. */
class table
{
    public:
        table();
        ~table();
        int readIn();
        int searchKey(char * key);
        int insertKey(char * key, const studyGuide & toAdd);
        int insertNewKey();
        int insertChapter(int chap, const studyGuide & toAdd);
        int toEditDescriptionKey(char * findKey);
        bool retrieveKey(char * key, studyGuide & toCopy);
        int removeKey(char * key);
        int recursiveRemoveKey(node *& head, char * key);
        int displayChapters(int * chaptersToFind, studyGuide & foundChapters);
        int hashFunction(char * key);
        int hashFunctionChapter(int chap);
        int displayAllKey();
        int displayGivenChapter(int chap);
    private:
        node ** hashTableKey;
        node ** hashTableChapter;
        int hashTableSize;
};

bool again();
