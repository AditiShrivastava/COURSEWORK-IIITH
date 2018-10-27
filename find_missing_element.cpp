/*      PROBLEM:Missing number in array 
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases.
For each test case first line contains N, size of array. The ssubsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 107

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9

Explanation:
Testcase 1: Given array : 1 2 3 5. Missing element is 4.
*/

#include <iostream>
using namespace std;

int main()
{
	int t,n,x;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    //cout<<" n is"<<n;
	    int arr[n+1]={0};
	    for(int i=1;i<n;i++)
	    {
	        cin>>x;
	        arr[x]=1;

	    }

	    int i;
	    for(i=1;i<=n;i++)
	    {
	        if(arr[i]==0)
	        break;
	    }
	    cout<<i<<endl;
	    //cout<<"test "<<t<<"ends"<<endl;
	}
	return 0;
}
