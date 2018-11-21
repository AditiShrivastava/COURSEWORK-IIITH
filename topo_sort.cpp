#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
	int V;
	list<int> *l;
	list<int> *m;//storing reverse graph


	Graph(int v)
	{
		V=v;
		l=new list<int>[v];
		m=new list<int>[v];

	}
	void addEdge(int u,int v)
	{
		l[u].push_back(v);
		m[v].push_back(u);
	}
	void showGraph()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"->";
		
		for(auto itr=l[i].begin();itr!=l[i].end();++itr)
		{
			cout<<*itr<<",";
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



	void Topo_sort_util(int v,bool visited[],stack<int> &Stack)
	{
		visited[v]=true;
		list<int>::iterator i;
		for(i=l[v].begin();i!=l[v].end();++i)
			if(visited[*i]==false)
				Topo_sort_util(*i,visited,Stack);
		Stack.push(v);
	}
	void Topo_sort()
	{
		stack<int> Stack;
		// Mark all the vertices as not visited
		bool *visited=new bool[V];
		for(int i=0;i<V;++i)
		{
			visited[i]=false;
		}

		// Call the recursive helper function to store Topological 
    	// Sort starting from all vertices one by one 


		for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            Topo_sort_util(i, visited, Stack); 


        // Print contents of stack 

    	while (Stack.empty() == false) 
	    { 
	        cout << Stack.top() << " "; 
	        Stack.pop(); 
	    } 
    	
	}

};
int main()
{
	// Create a graph given in the above diagram 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.Topo_sort(); 
  
    return 0; 


}
