#include <iostream>
#include <vector>

using namespace std;

vector <int> adj[10]; //vector of 10 integers which has the name adj. the number of elements is optional in a vector
bool visited[10]; // vector of boolean data type to keep track of the nodes we have visited

void dfs(int s)
{
  visited[s]=true; // making the boolean visited array true for the current node
  for(int i = 0 ; i < adj[s].size() ; ++i)
          {
             if(visited[adj[s][i]] == false) // how did we use a 2D array basically by declaring a 1D structure
             dfs(adj[s][i]); // if an adjacent node of the starting node hasnt been visited then the then DFS Is also called on that
          }

}


void initialize()
{

   for(int i=0 ; i<10 ; i++)
   visited[i]=false;
} //by default initialization is 0 only for global array


/* in this program we are basically iterating through all the nodes and keeping track of the number of times we have to apply DFS.
in applying DFS one time, we visit all nodes possible through a node and we do this recursively */

int main()
{
    int nodes, edges, x, y, ConnectedComponents = 0 ;
    /* edges and nodes represent the number of edges and nodes in the graph as is obvioius
    x and y are variables to represnet the vertex number where the edges are present */
    cout<<"Enter the number of nodes \n";
    cin >> nodes; // total nodes in the graph
    cout<<"Enter the number of edges \n";
    cin >> edges; // total edges in the graph
    for(int i =1; i<=edges ; i++) // iterating through all the edges
        {     cout<<"Enter the nodes to which the edge "<<i<<" is connected \n";
              cout<<"First node ";
              cin>>x;  // accepting the vertex values where the edges are present from the user
              cout<<"\n Second node ";
              cin>>y;
    adj[x].push_back(y); // adding the node y to the adjacency list of the node x
    adj[y].push_back(x); // adding the node x to the adjacency list of node y
} //therefore for all the edges we have added the adjacent nodes of all
    initialize(); // to initialize the boolean visited array to 0

    for(int i = 1 ; i<= nodes ; i++)
    {
         if(visited[i] == false )
           {
              dfs(i);
              ConnectedComponents++;


           }


    }
cout<<" Number of connected components"<<ConnectedComponents;
return 0;
}
