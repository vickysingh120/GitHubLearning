#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int largest_f(int n)
{
   for(int i=n/2;i>=1;i--)
   {
       if(n%i==0)
        return i;
   }
}
int my_search(vector<int> v,int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(v[i]==x)
            return 1;
    }
    return 0;
}
int main()
{
   int m,n,count=1;
   vector<int> v;
   cin>>m>>n;

    v.push_back(m);
    v.push_back(n);

    

   while(1)
   {
       int present;
       if(m>n)
       {
           m=largest_f(m);
           present=my_search(v,v.size(),m);
           if(present)
           {
             cout<<v.size()-1;
             break;
           }
           v.push_back(m);

       }
       else
       {
          n=largest_f(n);
          present=my_search(v,v.size(),n);
           if(present)
           {
             cout<<v.size()-1;
             break;
           }
           v.push_back(n);
       }

   }


  return 0;
}