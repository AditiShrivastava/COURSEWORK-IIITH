#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of integers you want to insert";
  cin>>n;

  int arr[n];
  for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
  int current_sum[n], max_sum;
  max_sum = current_sum[0] = arr[0]; //Initialising the current_sum[0] with arr[0]
  for(int i=1;i<n;i++)
    {
      if(current_sum[i-1]<0)
        {
          current_sum[i]=arr[i];
        }
      else
        {
          current_sum[i]=arr[i]+current_sum[i-1];
        }
      if(current_sum[i] > max_sum)
      {
        max_sum = current_sum[i];
       // cout<<"max_sum updated with"<<max_sum;
      }

    }

    cout<<"The max sum is"<<max_sum;

    return 0;

}


