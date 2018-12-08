#include <iostream>
#include <string>
using namespace std;

struct Node
{
    Node* arr[26];
    int leaf_count, prefix_count;

    Node(): leaf_count(0), prefix_count(0) 
    {
        for(int i = 0; i < 26; ++i)
            arr[i] = NULL;
    }
};

struct Trie
{
    Node root;

    void insert(string str);
    void insertUtil(Node* node, string &str, int i);
    void remove(string str);
    void removeUtil(Node* node, string &str, int i);
    bool find(string str);
    bool findUtil(Node* node, string &str, int i);
};

Trie mytrie;

inline int char_to_index(char ch)
{
    return ch - 'a';
}

void Trie::insertUtil(Node* node, string &str, int i)
{
    if(i == str.length())
    {
        ++node->leaf_count;
        ++node->prefix_count;
        return;
    }
    int idx = char_to_index(str[i]);

    if(!node->arr[idx])
    {
        node->arr[idx] = new Node;
    }
    ++node->prefix_count;
    insertUtil(node->arr[idx], str, i + 1);
}

void Trie::insert(string str)
{
    if(str.empty())
        return;

    insertUtil(&root, str, 0);
}

void Trie::removeUtil(Node* node, string &str, int i)
{
    if(i == str.length())
    {
        --node->leaf_count;
        --node->prefix_count;
        return;
    }

    int idx = char_to_index(str[i]);
    if(!node->arr[idx]) return;

    removeUtil(node->arr[idx], str, i+1);
    if(node->arr[idx]->prefix_count == 0)
    {
        delete node->arr[idx];
        node->arr[idx] = NULL;
    }
    --node->prefix_count;
}

void Trie::remove(string str)
{
    if(str.empty())
        return;

    removeUtil(&root, str, 0);
}

bool Trie::findUtil(Node* node, string &str, int i)
{
    if(i == str.length())
    {
        if(node->leaf_count > 0)
            return true;
        return false;
    }
    int idx = char_to_index(str[i]);
    if(!node->arr[idx])
        return false;

    return findUtil(node->arr[idx], str, i+1);
}

bool Trie::find(string str)
{
    if(str.empty())
        return false;

    findUtil(&root, str, 0);
}


int main()
{
    string str_arr[] = {"hello", "helloworld", "hellobhavi", "bhavi", "bhavidhingra"};

    for(int i = 0; i < 5; ++i)
    {
        mytrie.insert(str_arr[i]);
    }

    cout << mytrie.find("bhavi") << endl;
    mytrie.remove("bhavi");
    cout << mytrie.find("bhavidhingra") << endl;
    cout << mytrie.find("bhavi") << endl;

    return 0;
}
