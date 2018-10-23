#include<bits/stdc++.h>
using namespace std;
map<int,int> mymap;
map<int,int>:: iterator itr1,itr2,itr3;
int n,t,test_num,count;
int main()
{
cin>>t;
while(t--)
{
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];

	}

	// 	for(int i=1;i<=n;i++)
	// {
	// 	cout<<arr[i];

	// }
	// mymap[key]=value;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		mymap[arr[i]]=i;

	}

	for(itr1=mymap.begin();itr1!=mymap.end();itr1++)
	{
		cout<<itr1->first<<" , "<<itr1->second<<endl;
	}
    
    

	mymap.clear();

cout<<"-------------------";


}
return 0;
}