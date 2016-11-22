/* Larry Chiem 
 * CS163 - Program 4: BST 
 * 05/25/2016
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
        char * getKey()const;
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
    studyGuide data; 
    node * left;
    node * right;
};

/*This class table manages the hash tables and holds the
 * prototype functions that were required for our program
 * by Karla. */
class table
{
    public:
        table();
        ~table();
        int removeAll();
        int readIn();
        int searchKey(char * key);
        int insertKey(const studyGuide & toAdd);
        int removeKey(char * key);
        int toEditDescriptionKey(char * findKey, char * addDescription);
        int retrieveKey(char * key);
        int displayTreeInOrder();
        int displayRange(char * min, char * max);
    private:
        int insertKey(node *& root, const studyGuide & toAdd);
        int displayTreeInOrder(node * root);
        int removeKey(node *& root, char * key);
        int editDescriptionKey(node *& root, char * findKey, char * addDescription);
        int displayRange(node * root, char * min, char * max);
        int removeAll(node *& root);
        node * retrieveKey(node * root, char * key);
        node * pluckInOrderSuccessor(node *& root);
        node * root;
};

bool again();
