#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define N 10000
#define K 100
using namespace std;
int n,k;
int store[N];
int arr[N][K]={-1};
int county=0;

     int futil(int i,int val)
    {
         int add=0,sub=0;
         if(i==n)
         {
             if(val==0)
                 return 1;
             else 
                 return 0;
         }
         if(i!=n) 
         {  county++;
            //cout<<endl<<" "<<county<<") I'm inside futil("<<i<<","<<val<<") called."<<endl;
            
          
          if(arr[i][val]==1)
                return 1;
         
          else if(arr[i][val]==0)
              return 0;
          
          
          
            else
            {
                
                int y=store[i]%k;
                //cout<<" y is "<<y;
                
                int z=((val+y)+k)%k;
                //cout<<" z is "<<z;  
                
                add=futil(i+1,z);
                
                
                
                int w=((val-y)+k)%k;
                //cout<<" w is "<<w;    
                
                sub=futil(i+1,w);
                 
                
                
                if(add==1)
                {   arr[i][val]=1;
                    
                }
            
                if(sub==1)
                    {
                        arr[i][val]=1;
                        
                    }
                
                if(add==0 && sub==0)
                {
                    arr[i][val]=0;
                }
               
            }
      
          
            
            
            
            
         }
         return(add||sub);
      
               
   
    }
    

        




    int main()
    { 
       int result;
       
       int t,x;
       cin>>t;
       while(t--)
       {    result=0;
            county=0;
            cin>>n>>k;   
            memset(arr,-1,sizeof(arr));
            for(int i=0;i<n;i++)
            {
                cin>>store[i];
            }
            x=store[0]%k;
            result=futil(0,0);
           if(result==1)
               cout<<"YES"<<endl;
           else
               cout<<"NO"<<endl;
     
      
      }
      return 0;
    }
 