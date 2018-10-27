/* PROBLEM:Given an array containing both negative and positive integers. Find the contiguous sub-array with maximum sum.
 
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
 
Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.
 
Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 1000
-100 ≤ A[i] <= 100
 
Example:
Input
2
3
1 2 3
4
-1 -2 -3 -4
Output
6
-1

*/

#include <stdio.h>
#include<iostream>
#include <limits.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
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
          //cout<<"All are negative";
          cout<<maxifallnegative<<endl;
        }
 else
        {
            //cout<<"Normal starts";
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
            //cout<<"Normal ends";
        }

    }
        return 0;
}

