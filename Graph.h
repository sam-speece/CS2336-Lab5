#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"

class Graph
{
    public:
        Graph();
        Graph(ifstream&);
        ~Graph();

        void setGraphSize(int s) {graphSize = s;};
        int getGraphSize() {return graphSize;};

        void createGraph(ifstream&);
        void clearGraph();
        void printGraph();
        int findSize();
        bool validatePath(int[], int, int&);
        bool checkConnected(int, bool[]);

        LinkedList *graphList;

    protected:

    private:
        int graphSize;
};

#endif // GRAPH_H
