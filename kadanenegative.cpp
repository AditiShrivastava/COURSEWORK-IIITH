#include <stdio.h>
#include<iostream>
#include <limits.h>
using namespace std;

int main() 
{
    int t,n;
    cin>>t>>n;
    while(t--)
    {
        
        int max_final=INT_MIN;
        int maxsofar=0;
        int maxifallnegative;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        maxifallnegative=arr[0];
        int j=0;
            for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
             if(arr[i]>maxifallnegative)
             maxifallnegative=arr[i];
             j++;
            }   
            
        }
        
        if(n==j)
        {
          cout<<"All are negative";
          cout<<maxifallnegative<<endl;
        }
        else
        {
            cout<<"Normal starts";      
            max_final=0;
            maxsofar=0;
            for(int i=0;i<n;i++)
            {
                maxsofar=maxsofar+arr[i];
                if(maxsofar>max_final)
                max_final=maxsofar;
                if(maxsofar<0)
                maxsofar=0;
                
            }
            cout<<max_final<<endl;
            cout<<"Normal ends";
        }
        
    }
	return 0;
}
