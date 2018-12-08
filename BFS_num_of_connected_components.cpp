#include <iostream>
#include <list>
//#include<bits/stdc++.h>
using namespace std;
static int count;
class Graph
{
	int V;
	list<int> *l;
	bool * visited = new bool[V];

	public:


			Graph(int v)
			{
				V=v;
				//Array of linked lists
				l=new list<int>[v];
				visited = new bool[V];

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


			int num_connected_components()
			{
				BFS(0);
				count++;

				for(int i=0;i<V;i++)
				{
					if(visited[i]=false)
					{
						BFS(i);
						count++;
					}
				}
				return count;
			}



};

int main()
{

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
    g.num_connected_components(); 
  
	return 0;
}

