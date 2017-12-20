#include "Graph.h"

//default constructor that finds the size of the Graph from the file and creates dynamic array
//of LinkedList objects
Graph::Graph()
{
    graphSize = findSize();
    graphList = new LinkedList[graphSize];
}

//destructor that calls clearGraph to delete dynamic memory
Graph::~Graph()
{
    clearGraph();
}

//function that takes in the file and checks to see if findSize() worked.  If so then it uses a string stream to
//separate out the different vertices and insert the vertex and weight into the graph
void Graph::createGraph(ifstream &galaxy)
{
    DoubleLinkNode *node;
    int vertex;
    string line, adjVertex;

    if(!galaxy.is_open())
    {
        cout << "File not found";
        return;
    }

    while(!galaxy.eof())
    {
        galaxy >> vertex;
        if(vertex > graphSize)
        {
            cout << "Did not change galaxy.txt in findSize() method";
            return;
        }
        getline(galaxy, line);
        stringstream ss(line);
        while(getline(ss, adjVertex, ' '))
        {
            if(adjVertex.size() > 0)
            {
                int i = 0;
                while(adjVertex[i] != ',')
                    i++;
                int x = atoi(adjVertex.substr(0, i).c_str());
                int y = atoi(adjVertex.substr(i + 1).c_str());
                node = new DoubleLinkNode(x, y);
                graphList[vertex].insertNode(node);
            }
        }
    }

    galaxy.close();
}

//iterates through each LinkedList and calls the destructor for each one
void Graph::clearGraph()
{
    for(int i = 0; i < graphSize; i++)
        graphList[i].destroy(graphList[i].getHead());

    graphSize = 0;
}

//iterates through graph if it is not empty and prints out each LinkedList
void Graph::printGraph()
{
    for(int i = 0; i < graphSize; i++)
    {
        if(!graphList[i].isEmpty())
        {
            cout << i << " ";
            graphList[i].printList();
        }
    }
}

//opens file and finds the highest vertex in the graph and makes that the graph size
int Graph::findSize()
{
    ifstream galaxy("galaxy.txt");
    int gsize, check;

    if(!galaxy.is_open())
    {
        cout << "File not found";
        return -1;
    }

    galaxy >> gsize;
    while(!galaxy.eof())
    {
        string blank;
        getline(galaxy, blank);
        galaxy >> check;
        if(check > gsize)
            gsize = check;
    }

    galaxy.close();
    return gsize;
}

//does a depth first traversal and traverses each vertex's adjacent vertices and adds the weight of the current vertex
//to the reference parameter weight, then it goes to the next vertex and checks its adjacent vertices
bool Graph::validatePath(int path[], int length, int& weight)
{
    static int i = 0;
    if(i == length - 1)
    {
        if(i == 0)
        {
            if(graphList[path[i]].getHead())
                return true;
            return false;
        }
        i = 0;
        return true;
    }

    DoubleLinkNode *current = graphList[path[i]].getHead();

    while(current)
    {
        if(current->vertex == path[i + 1])
        {
            weight += current->weight;
            i++;
            return validatePath(path, length, weight);
        }
        current = current->getNextPtr();
    }
    return false;
}

bool Graph::checkConnected(int vertex, bool visited[])
{
    static int vsize;
    if(vertex > vsize)
        vsize = vertex;

    visited[vertex] = true;

    DoubleLinkNode *current = graphList[vertex].getHead();

    while(current)
    {
        int v = current->vertex;
        if(!visited[v])
            checkConnected(v, visited);
    }

    for(int i = 0; i < vsize; i++)
    {
        if(!visited[i])
            return false;
    }
    vsize = 0;
    return true;
}
