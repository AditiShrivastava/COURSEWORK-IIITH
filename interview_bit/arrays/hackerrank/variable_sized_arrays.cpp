/* Problem statement can be found variable-sized-arrays-English.pdf

*/

/* My Method */

#include <iostream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q,k;
    cin>>n>>q;
    int** arr = new int* [n];
    for(int i=0;i<n;i++)
    {
        cin>>k;
        arr[i] = new int[k];
        for(int j=0;j<k;j++)
        {
            cin>>arr[i][j];
        }

    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<k;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int u,v;
    for(int i=0;i<q;i++)
    {
        cin>>u>>v;
        cout<<arr[u][v]<<endl;
    }



    return 0;
}





