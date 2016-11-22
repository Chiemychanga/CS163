/* Larry Chiem 
 * CS163 - Program 4: BST 
 * 05/25/2016
 * functions.cpp
 * This file holds all of the implemented functions.  
 */
#include "functions.h"
using namespace std;

/* Constructor * Task: Initializes the members, and is implicitly
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

    delete [] tempChapterIndex;
    tempChapterIndex = NULL;
    delete [] tempPageIndex;
    tempPageIndex = NULL;
    return 1;
}

/* setKey 
 * Task: Takes the dynamic char array and deep copies the keyword. 
 * Input: A pointer to a char array. 
 * Output: Nothing. */
void studyGuide::setKey(char * key)
{
    if(keyword) delete [] keyword;
    keyword = new char[strlen(key)+1];
    strcpy(keyword, key);
}

/* getKey 
 * Task: Returns the keyword.  
 * Input: Nothing. 
 * Output: Returns a char *.  */
char * studyGuide::getKey()const
{
    return keyword;
}

/* setDescription
 * Task: Takes the dynamic char array and deep copies the keyword. 
 * Input: A pointer to a char array. 
 * Output: Nothing. */
void studyGuide::setDescription(char * describe)
{
    if(description) delete [] description;
    description = new char[strlen(describe)+1];
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
    description = new char[strlen(newDescription)+1];
    strcpy(description, newDescription);

    delete [] newDescription;
    newDescription = NULL;
    return 1;
}

/* setChapterArray 
 * Task: Allocates the array size of chapter and returns the chapterSize. 
 * Input: An int size. 
 * Output: Returns the chapterSize. */
int studyGuide::setChapterArray(int size)
{
    //if(chapter) delete [] chapter;
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
    root = NULL;
}

/* Destructor
 * Task: Implicitly deallocates the memory when the 
 * lifetime of a class object is over(end of block
 * in which it is defined).
 * Input: Nothing.
 * Output: Nothing. */
table::~table()
{
    removeAll(root);
}

/* removeAll
 * Task: Function overload's the private removeAll function.
 * Input: Nothing.
 * Output: Returns a 0 for failure, Returns a 1 for success. */
int table::removeAll()
{
    return removeAll(root);
}

/* removeAll
 * Task: Deallocates all of the nodes in the tree, startign with leafs first.
 * Input: A root pointer by reference to node.
 * Output: Returns a 0 for failure, Returns a 1 for success. */
int table::removeAll(node *& root)
{
    if(!root) return 0;
    int remove = 1 + removeAll(root->left) + removeAll(root->right);
    delete root; root = NULL;
    return remove;
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

            tempStudy.setChapterArray(chapterSize);
            for(int i = 0; i<chapterSize; ++i)
            {
                file >> chapterValue;
                if(i<chapterSize-1)
                    file.ignore(100,',');
                else
                    file.ignore(100,':');
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

            insertKey(tempStudy); 
            file.peek();
        }
    }
    file.close();
    return 1;
}

/* insertKey 
 * Task: Calls the insertKey function from private. 
 * Input: A const object to studyGuide.
 * Output: A non-zero for success, a zero for fail, */
int table::insertKey(const studyGuide & toAdd)
{
    return insertKey(root, toAdd); 
}

/* insertKey
 * Task: Inserts the node into the sorted spot in the BST.
 * Input: A root pointer by reference to node, and a const object to studyGuide.
 * Output: A non-zero for success, a zero for fail, */
int table::insertKey(node *& root, const studyGuide & toAdd)
{
    if(!root)
    {
        root = new node;
        root->data.copyEntry(toAdd);
        root->left = root->right = NULL;
        return 1;
    }
    if(strcmp(toAdd.getKey(), root->data.getKey()) < 0)
        return insertKey(root->left, toAdd);
    if(strcmp(toAdd.getKey(), root->data.getKey()) >= 0)
        return insertKey(root->right, toAdd);
    return insertKey(root->left, toAdd) + insertKey(root->right, toAdd);
}

/* removeKey
 * Task: Removes a keyword with its information. 
 * Input: A pointer to a char.  
 * Output: A non-zero for success, a zero for fail, */
int table::removeKey(char * key)
{
    return removeKey(root, key);
}

/* recursiveRemoveKey 
 * Task: Recursively removes the matched keyword and its information. 
 * Input: A head pointer passed by reference, and a pointer to char. 
 * Output: A non-zero for success, a zero for fail, */
int table::removeKey(node *& root, char * key)
{
    if(!root) return 0; 
    if(strcmp(root->data.getKey(), key) == 0)
    {
        if(!root->left && !root->right)
        {
            delete root;
            root = NULL;
            return 1;
        }
        else if(!root->left && root->right)
        {
            node * remove = root;
            root = root->right;
            delete remove;
            remove = NULL;
            return 1;
        }
        else if(root->left && !root->right)
        {
            node * remove = root;
            root = root->left;
            delete remove;
            remove = NULL;
            return 1;
        }
        else if(root->left && root->right)
        {
            node * successor = pluckInOrderSuccessor(root->right);
            root->data.copyEntry(successor->data);
            delete successor;
            successor = NULL;
            return 1;
        }
    }
    return removeKey(root->left, key) + removeKey(root->right, key);
}


/* pluckInOrderSuccessor 
 * Task: This node will return a pointer to the in order successor
 * and traverse root to the root's right. 
 * Input: node *& root
 * Output: A pointer to a node. */
node * table::pluckInOrderSuccessor(node *& root)
{
    if(!root) return 0;
    if(!root->left)
    {
        node * hold = root;
        root = root->right;
        return hold;
    }
    if(root->left)
    {
        return pluckInOrderSuccessor(root->left);
    }
    return NULL;
}

/* toEditDescriptionKey 
 * Task: Edit the description to add more text as you study, given the keyword. 
 * Input: A pointer to a char. 
 * Output: A non-zero for success, a zero for fail, */
int table::toEditDescriptionKey(char * findKey, char * addDescription)
{
    if(!findKey) return 0;
    return editDescriptionKey(root, findKey, addDescription);
}

/* toEditDescriptionKey 
 * Task: Edit's the description of the specific root.
 * Input: A pointer passed by reference to node, and a pointer to a char.
 * Output: A non-zero for success, a zero for fail, */
int table::editDescriptionKey(node *& root, char * findKey, char * addDescription)
{
    if(!root) return 0;
    node * toEdit = retrieveKey(root, findKey);
    toEdit->data.editDescription(addDescription);
    return 1;
}
/*
 * retrieveKey 
 * Task: Retrieve the information about a particular keyword.   
 * Input: 
 * Output: A true for success, a false for fail,*/ 
int table::retrieveKey(char * key)
{
    //Function overload
    node * retrieve = retrieveKey(root, key);
    if(!retrieve) return 0;
    else 
        return 1;
    //return retrieve->data.display();
} 


/* retrieveKey 
 * Task: Returns the matching pointer to the node back to the calling routine.
 * Input: A root pointer to node, a key pointer to char.
 * Output:  */
node * table::retrieveKey(node * root, char * key)
{
    if(!root) return 0;
    if(strcmp(root->data.getKey(), key) == 0)
    {
        node * hold = root;
        return hold;
    }
    if(strcmp(root->data.getKey(), key) > 0)
    {
        return retrieveKey(root->left, key);
    }
    if(strcmp(root->data.getKey(), key) <= 0)
    {
        return retrieveKey(root->right, key);
    }
    return NULL;
}

/* displayTreeInOrder
 * Task: Function overload calls displayTreeInOrder from private.
 * Input: Nothing.
 * Output: A non-zero for success, a zero for fail, */
int table::displayTreeInOrder()
{
    return displayTreeInOrder(root);
}

/* displayAllKey 
 * Task: Displays all keywords in order from the Tree. 
 * Input: Nothing. 
 * Output: A non-zero for success, a zero for fail, */
int table::displayTreeInOrder(node * root)
{
    if(root)
    {
        displayTreeInOrder(root->left);
        root->data.display();
        displayTreeInOrder(root->right);
    }
    return 1;
}

/* displayRange
 * Task: Calls the private displayRange function.
 * Input: Two pointers to char to determine the range.
 * Output: A non-zero for success, a zero for fail, */
int table::displayRange(char * min, char * max)
{
    return displayRange(root, min, max);
}

/* displayRange
 * Task: Display's the root's info if it's keyword is within
 * the range of the argument.
 * Input: A root pointer to node, and two char pointers.
 * Output: A non-zero for success, a zero for fail, */
int table::displayRange(node * root, char * min, char * max)
{
    if(!root) return 0;
        displayRange(root->left, min, max);
    //if the root is within the range, display
    if(*(root->data.getKey()) >= *min && *(root->data.getKey()) <= *max)
    {
        root->data.display();
    }
    displayRange(root->right, min, max);
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
