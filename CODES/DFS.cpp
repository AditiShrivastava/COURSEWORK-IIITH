#include <iostream>
#include <list>
//#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list<int> *l;
	public:
			Graph(int v)
			{
				V=v;
				//Array of linked lists
				l=new list<int>[v];
			}
		    void addEdge(int u,int v,bool bidir=true)
		    {
		    	l[u].push_back(v);
		    
		    	if(bidir)
		    	{
		    		l[v].push_back(u);
		    	}

		    }

		    void printAdjList()
		    {
		    	for(int i=0;i<V;i++)
		    	{
		    		cout<<i<<"->";
		    		//l[i] is a linked list
		    		for(int vertex: l[i])
		    		{
		    			cout<<vertex<<",";
		    		}
		    		cout<<endl;
		    	}
		    }



		   void DFSutil(int v,bool visited[])
			{
				visited[v]=true;
				cout<<v<<" ,";
				for(auto itr=l[v].begin();itr!=l[v].end();++itr)
				{
					if(visited[*itr]==false)
					{
						DFSutil(*itr,visited);

					}
				}
			}

			void DFS(int u)
			{
				bool* visited=new bool[V];
				for(int i=0;i<V;++i)
				{
					visited[i]=false;
				}
				DFSutil(u,visited);


			}



};

int main()
{
	// Graph g(5);
	// g.addEdge(0,1);
	// g.addEdge(0,4);
	// g.addEdge(4,3);
	// g.addEdge(1,4);
	// g.addEdge(1,2);
	// g.addEdge(2,3);
	// g.addEdge(1,3);
	// g.printAdjList();
	// cout<<"*************Printing DFS Traversal**************";
	// g.DFS(3);


	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout<<"*************Printing DFS Traversal**************";
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 
  
	return 0;
}

