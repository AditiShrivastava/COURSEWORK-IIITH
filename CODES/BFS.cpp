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
		    void addEdge(int u,int v,bool bidir=false)
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



		   void BFS(int s)
			{
				bool * visited = new bool[V];
				for(int i=0;i<V;i++)
					visited[i]=false;
				list<int> queue;
				visited[s]=true;
				queue.push_back(s);
				list<int>::iterator i;
				while(!queue.empty())
				{
					s=queue.front();
					cout<<s<<" , ";
					queue.pop_front();
					for(i=l[s].begin();i!=l[s].end();++i)
					{
						if(!visited[*i])
						{
							visited[*i]=true;
							queue.push_back(*i);
						}
					}
				}
				

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
	// cout<<"*************Printing BFS Traversal**************";
	// g.BFS(3);


	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.printAdjList();
    cout<<"*************Printing BFS Traversal**************";
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n"; 
    g.BFS(2); 
  
	return 0;
}

