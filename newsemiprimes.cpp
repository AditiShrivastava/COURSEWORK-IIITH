#include<bits/stdc++.h>
using namespace std;
int isSemiprime(int query)
{
	int flag;
	int arr[query];
	int j=0;
	for(int i=2;i<query;i++)
	{
		if(query%i==0)
		{	
			arr[j++]=i;
		}
	}
	
	int brr[query];
	int m=0;
	for(int k=0;k<j;k++)

	     {

	           flag=0;
	           for(int j=2;j<arr[k];j++)

	           {

	                 if(arr[k]%j==0)

	                 {

	                       flag=1;

	                       break;

	                 }

	           }

	           if(flag==0)

	     	      {

	                 brr[m++]=arr[k];
 
	              }

	     }


	int a,b;
	a=0;
	b=m-1;
	if(b==1)
	{
		if(arr[b]*arr[a]==query)
		{
			return 1;
		}
	}
	return 0;


}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {		
	int s;
	cin>>s;
	int arr[200];//To store the semiprimes between 1 and 200.
	int j=0;
	/*This loop prints the all subprimes between 1 and 200*/
	for(int i=0;i<=200;i++)
	{
		if(isSemiprime(i))
			arr[j++]=i;

	}

	/*To check whether sum of any two elements(same also possible) in the array of subprimes is equal to the input number.*/
	int a=0,b=j-1;
	while((arr[a]+arr[b]!=s)&&(a!=b))
	{
		if(arr[a]+arr[b]>s)
			b--;
		else
			a++;
	}
	if(arr[a]+arr[b]==s && (a==b))
		cout<<"YES"<<endl;
	else if(arr[a]+arr[b]==s)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
return 0;
}