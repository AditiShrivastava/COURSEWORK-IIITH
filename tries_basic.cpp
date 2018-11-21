#include<bits/stdc++.h>
#include<string>
using namespace std;


struct node
{
	node * alpha[26];
	bool isAWord;
	node(): isAWord(false)
	{
		for(int i=0;i<26;i++)
		{
			alpha[i]=0;
		}
	}

};

struct Trie
{
	node root;
	void insertutil(node * n, string s, int i)
	{
		if(i!=s.length())
		{
			if(n->alpha[s[i]-'a']==NULL)
				{	
					n->alpha[s[i]-'a']= new node;
				}
			insertutil(n->alpha[s[i]-'a'],s, i+1);
		}
		else
		n->isAWord==true;
	}
	void insert(string str)
	{	
		if(str.empty())
		{
			return;
		}
		insertutil(&root, str, 0);
	}

	bool searchutil(node * n, string s, int i)
	{
		if(i!=s.length())
		{
			if(n->alpha[s[i]-'a']==NULL)
				{	
					return false;
				}
			return searchutil(n->alpha[s[i]-'a'],s, i+1);
		}
		else
		{
			if(n->isAWord==true)
			return true;
			else
			return false;
		}
		
	}
	bool search(string str)
	{	
		if(str.empty())
		{
			return false;
		}

		searchutil(&root, str, 0);
	}	

};



Trie t;

int main()
{
	string str[]={"abc","aditi","aditya","bhavi","bhavin"};
	for(int i=0;i!=5;++i)
	{
		t.insert(str[i]);
	}
	cout<<t.search("aditi");
	cout<<t.search("xyz");


}