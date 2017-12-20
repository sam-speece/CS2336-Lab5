#include "DoubleLinkNode.h"

//default constructor that sets the pointers equal to nullptr
DoubleLinkNode::DoubleLinkNode()
{
    vertex = 0;
    weight = 0;
    pilotName = "";
    valid = false;
    nextPtr = nullptr;
    prevPtr = nullptr;
}

DoubleLinkNode::DoubleLinkNode(int v, int w)
{
    vertex = v;
    weight = w;
    pilotName = "";
    valid = false;
    nextPtr = nullptr;
    prevPtr = nullptr;
}

//copy constructor that copies name, area, next and previous pointer
DoubleLinkNode::DoubleLinkNode(const DoubleLinkNode& other)
{
    nextPtr = other.nextPtr;
    prevPtr = other.prevPtr;
    vertex = other.vertex;
}

//destructor for DoubleLinkNode
DoubleLinkNode::~DoubleLinkNode()
{
    delete nextPtr;
    delete prevPtr;
}
