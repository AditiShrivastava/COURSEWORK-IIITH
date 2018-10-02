 #include <bits/stdc++.h>
using namespace std;



  int maxnum(int max,int lmax,int rmax)
    {
        return((lmax>max)?((lmax>rmax)?lmax:rmax):((max>rmax)?max:rmax));
    }

  int minnum(int min,int lmin,int rmin)
    {
        return((lmin<min)?((lmin<rmin)?lmin:rmin):((min<rmin)?min:rmin));
    }



int main()
{
	int m1=30000,m2=900,m3=770;
	int max=maxnum(m1,m2,m3);
	int min=minnum(m1,m2,m3);
	cout<<max<<endl;
	cout<<min<<endl;


}