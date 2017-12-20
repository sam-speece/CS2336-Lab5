/*Project 5
Sam Speece - sds160130
CS 2336.004
November 28, 2016*/

#include "Graph.h"

string findName(string&);
void getPath(int[], string);

int main()
{
    //open files and instantiate objects
    ifstream galaxy("galaxy.txt");
    ifstream routes("pilot_routes.txt");
    ofstream patrols("patrols.txt");
    Graph graph;
    graph.createGraph(galaxy);
    LinkedList *pilotList = new LinkedList;

    if(routes.is_open())
    {
        while(!routes.eof())
        {
            //create variables
            DoubleLinkNode *pilot = new DoubleLinkNode;
            string line;
            getline(routes, line);
            int psize = 0, weight = 0;
            for(unsigned int i = 0; i < line.size(); i++)
            {
                if(isspace(line[i]))
                    psize++;
            }
            int *path = new int[psize];

            //creates node and checks all info from graph and files
            pilot->pilotName = findName(line);
            getPath(path, line);
            pilot->valid = graph.validatePath(path, psize - 1, weight);
            pilot->weight = weight;
            pilotList->insertNode(pilot);
        }
        //sort list of pilots in descending order and output to file
        pilotList->sortLinkedList();
        patrols << pilotList;
    }else
        cout << "File not found";

    //clear graph, delete dynamic memory, close files
    graph.clearGraph();
    delete pilotList;
    galaxy.close();
    routes.close();

    return 0;
}

//takes in a string which should contain the line from the file.  It assumes the line is valid and keeps adding each character
//to the string name from the string line until it comes across a number, then it truncates the line so that the name is not part
//of the string line and returns the string name.
string findName(string& line)
{
    int i = 0;
    string name;

    while(isalpha(line[i + 1]) || isspace(line[i + 1]))
    {
        if(isspace(line[i]))
        {
            if(!isalpha(line[i + 1]))
                return name;
        }
        name += line[i];
        i++;
    }
    line = line.substr(i + 1);

    return name;
}

//void functions that takes in int array and the line from the file and uses a stringstream to separate out
//each vertex and inserts it into the path array
void getPath(int path[], string line)
{
    int index = 0;
    string vertex;
    stringstream ss(line);
    while(getline(ss, vertex, ' '))
    {
        path[index] = atoi(vertex.c_str());
        index++;
    }
}
