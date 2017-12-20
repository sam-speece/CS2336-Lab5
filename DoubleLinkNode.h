#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <ctype.h>

using namespace std;

class DoubleLinkNode
{
    public:
        DoubleLinkNode();
        DoubleLinkNode(int, int);
        DoubleLinkNode(const DoubleLinkNode&);
        ~DoubleLinkNode();

        void setNextPtr(DoubleLinkNode *ptr) {nextPtr = ptr;};
        DoubleLinkNode* getNextPtr() {return nextPtr;};
        void setPrevPtr(DoubleLinkNode *ptr) {prevPtr = ptr;};
        DoubleLinkNode* getPrevPtr() {return prevPtr;};

        int vertex;
        int weight;
        bool valid;
        string pilotName;

    protected:

    private:
        DoubleLinkNode *nextPtr;
        DoubleLinkNode *prevPtr;
};

#endif // DOUBLELINKNODE_H
