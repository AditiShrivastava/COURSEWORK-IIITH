#include<iostream>
#include<list>

using namespace std;

class Graph
{
    int V;
    list<int> *a; // pointer array to lists

    void helper(int, int, bool[], int[], int &);

public :
    Graph(int V);
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);

};

Graph::Graph(int V)
{
    this->V = V; // this refers to the current instance of the class
    a = new list<int>[V];
}

void Graph::addEdge(int u, int v) // unidirectional edges. from u to v.
{
    a[u].push_back(v); // v needs to be added in u's adjacency list
}

void Graph::printAllPaths(int s, int d)
{
    bool *visited = new bool[V]; // creates a boolean array of the number of vertices in the graph

    int *path = new int[V];
    int path_index = 0;

    for (int i = 0; i < V; i++)
            visited[i] = false;
    helper(s,d,visited,path,path_index);
}

void Graph::helper(int u, int d, bool visited[], int path[], int &path_index)
{
    visited[u] = true;
    path[path_index]=u;
    path_index++;
if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
        {

            list<int>::iterator i;
            for (i = a[u].begin(); i != a[u].end(); ++i)
                if (!visited[*i])
                    helper(*i, d, visited, path, path_index);
        }
        path_index--;
            visited[u] = false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);

    return 0;
}
