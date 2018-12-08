#include<vector>
#include<iostream>
using namespace std;
int main()
{
  vector<int> v;
  for(int i=0;i<10;i++)
  {
    int a;
    cin>>a;
    v.push_back(a);
  }
  for(auto itr=v.begin();itr!=v.end();itr++)
  {
    cout<<*itr<<" ";
  }
  cout<<"the size of vector is"<<v.size();
}
