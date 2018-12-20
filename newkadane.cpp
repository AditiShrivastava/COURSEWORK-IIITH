#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of integers you want to insert";
  cin>>n;
  int start,end;
  int final_start,final_end;
  //We are creating two arrays:arr for storing input and current_sum to store the current_sum.If the previous current_sum is negative,
  //we will not add it in the next current_sum.Take some set of inputs and you will understand the code.
  int arr[n];
  for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
  int current_sum[n], max_sum;

  max_sum = current_sum[0] = arr[0];
  //Initialising the current_sum[0] with arr[0]
  //We are taking start and end variables that stores indices to keep track of the elements for which the current_sum is being evaluated.
  start=0;
  end=0;
  for(int i=1;i<n;i++)
    {
      if(current_sum[i-1]<0)
        {
          current_sum[i]=arr[i];
          //As the previous current_sum is negative , we will not take the elements < i'th position.
          //So this is our new start and end point.
          start=i;
          end=i;
        }
      else
        {
          current_sum[i]=arr[i]+current_sum[i-1];
          end++;
          //As we are including previous elements as well,we are just incrementing the end index.
        }
      if(current_sum[i] > max_sum)
      {
        max_sum = current_sum[i];
        //As max_sum is updated,we will also update the final_end index.
        final_end=end;
       // cout<<"max_sum updated with"<<max_sum;
      }

    }

    cout<<"The max sum is"<<max_sum;
    cout<<"Starting index is:"<<start<<", Ending Index is :"<<final_end;

    return 0;

}
