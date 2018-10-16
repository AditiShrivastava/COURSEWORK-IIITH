#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
 int arr[20][20];
int n;

using namespace std;
int futil(int r,int col,int sum)
{
    
    if(r+1<n)
    {
        sum=sum+arr[r+1][col];
        futil(r+1,col,sum);
    }
    if(r+1<n && col>0)
    {
         sum=sum+arr[r+1][col-1];
        futil(r+1,col-1,sum);
    }
    if(r+1<n && col+1<n)
    {
         sum=sum+arr[r+1][col-1];
        futil(r+1,col+1,sum);
    }
    return sum;
    
}


int f(int r,int col,int sum)
{
      sum+=arr[r][col];
      return futil(r,col,sum);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,max;
    int sum[n]={0};
    cin>>t;
    while(t--)
    {
        cin>>n;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        for(int col=0;col<n;col++)
        {
            
          sum[col]=f(0,col,0);
        }
        max=sum[0];
        for(int i=0;i<n;i++)
        {
            if(sum[0]>max)
                max=sum[0];
        }
        cout<<max;
        
    }
    
    
    return 0;
}
