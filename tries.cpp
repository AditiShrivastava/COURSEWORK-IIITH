//QUESTION ON TRIES



// You have an array A of N strings and Q queries. In each query you are provided with a string again. You need to print the number of strings which contains the query string as a prefix in array A.

// Input Format

// first line contains two integers N and Q respectively

// following N lines contains N strings represting array A

// followwing Q lines contains Q query strings.

// Constraints

// 1 <= N, Q <= 10^5

// String lengths <= 30

// Output Format

// Q integers on newline contains the results of Q queries

// Sample Input 0

// 5 3
// xkeilwef
// zxhkn
// vjavemcbsi
// bbnuvp
// rwqnie
// bbn
// qqb
// wce

// Sample Output 0

// 1
// 0
// 0






#include<bits/stdc++.h>
#include<string>
using namespace std;


struct node
{
    node * alpha[26];
    bool isAWord;
    int count;
    node(): isAWord(false),count(0)
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
                    (n->alpha[s[i]-'a']->count)++;
                }
            else
                (n->alpha[s[i]-'a']->count)++;
            insertutil(n->alpha[s[i]-'a'],s, i+1);
        }
        else
        n->isAWord=true;
    }
    void insert(string str)
    {    
        if(str.empty())
        {
            return;
        }
        insertutil(&root, str, 0);
    }

      int prefixutil(node * n, string s, int i)
    {
        if(i!=s.length())
        {
            if(n->alpha[s[i]-'a']==NULL)
                {    
                    return 0;
                }
            return(prefixutil(n->alpha[s[i]-'a'],s, i+1));
        }
        return n->count;
    }
    int prefix(string str)
    {    
        if(str.empty())
        {
            return 0;
        }
        return prefixutil(&root, str, 0);
    }  
    
    
    
    

};



Trie t;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    cin>>n>>q;
    string arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        t.insert(arr[i]);
        
        
    }
    while(q--)
    {
        string s;
        cin>>s;
        
        int c;
        c=t.prefix(s);
        cout<<c<<endl;
    }
   
    
    return 0;
}