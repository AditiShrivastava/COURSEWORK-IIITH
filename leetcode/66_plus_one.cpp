class Solution 
{
    public:
        vector<int> plusOne(vector<int>& digits)
        {
            cout<<"here1"<<endl;
            vector<int>::iterator it=digits.end()-1;
            cout<<"here5"<<endl;
            if(it==digits.begin())
            {
                if(*it!=9)
                {
                    cout<<"here7"<<endl;
                    digits[it-digits.begin()]++;
                    return digits;
                }
                else
                {
                     cout<<"here8"<<endl;
                    //digits.clear();
                    digits[0]=1;
                    digits.push_back(0);
                    for(auto itr=digits.begin();itr!=digits.end();itr++)
                    {
                        cout<<*itr<<" , ";
                    }
                    return digits;
                }
                    
            }
            while(it!=digits.begin())
            {
                cout<<"value of *it is"<<*it<<endl;
                if(*it!=9)
                {
                    cout<<"here2"<<endl;
                    //*it++;
                    cout<<it-digits.begin()<<endl;
                    digits[it-digits.begin()]++;
                    cout<<digits[2]<<endl;
                    return digits;
                }
                
                else
                {
                    cout<<"here3"<<endl;
                    //*it==0;
                    digits[it-digits.begin()]==0;
                    it--;
                }
            }
            if(it==digits.begin())
            {
              //digits.insert ( it,0 , 1 ); 
              cout<<"here4"<<endl;
              it = digits.insert(digits.begin(), 1);   
                
            }
                // digits.push_front(1);
            
            return digits;
        }
};
