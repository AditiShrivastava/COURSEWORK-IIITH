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

	// For reverse graph
/*
	void showGraphReverse()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<"->";
		
		for(auto itr=m[i].begin();itr!=m[i].end();++itr)
		{
			cout<<*itr<<",";
		}
		cout<<endl;
		}
	}*/
	void DFSutilReverse(int v,bool visited[])
	{
		visited[v]=true;
		cout<<v<<" ,";
		for(auto itr=m[v].begin();itr!=m[v].end();++itr)
		{
			if(visited[*itr]==false)
			{
				DFSutilReverse(*itr,visited);

			}
		}
	}

	/*void DFSReverse(int u)
	{
		bool* visited=new bool[V];
		for(int i=0;i<V;++i)
		{
			visited[i]=false;
		}
		DFSutilReverse(u,visited);


	}*/
	void fillOrder(int v,bool visited[],stack<int> &Stack)
	{
		visited[v]=true;
		list<int>::iterator i;
		for(i=l[v].begin();i!=l[v].end();++i)
			if(visited[*i]==false)
				fillOrder(*i,visited,Stack);
		Stack.push(v);
	}
	void printSCC()
	{
		stack<int> Stack;
		bool *visited=new bool[V];
		for(int i=0;i<V;++i)
		{
			visited[i]=false;
		}
		for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
        for(int i = 0; i < V; i++) 
        	visited[i] = false;
    	 while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            DFSutilReverse(v, visited); 
            cout << endl; 
        } 
    } 




	}



};
int main()
{
	int v;
	v=11;
	Graph g(v);
	g.addEdge(0,1); 
	g.addEdge(1,2); 
	g.addEdge(2,0); 
	g.addEdge(1,3); 
	g.addEdge(3, 4); 
	g.addEdge(5,3); 
	g.addEdge(4,5);
	g.addEdge(6,5);
	g.addEdge(6,7);
	g.addEdge(9,6);
	g.addEdge(7,8); 
	g.addEdge(8,9);
	g.addEdge(9,10);      
	g.showGraph();
	cout<<"****************************";
	//g.showGraphReverse();
	cout<<" "<<"\n";
	//g.printSCC();
	g.DFS(9);
	return 0;


}
