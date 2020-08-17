#include<iostream>
#include<string>
#include<vector>

using namespace std;

int* my_seperate(string str)
{
   static int arr[5];
   int n=0,pos=0;
   int len=str.length();
   for(int i=0;i<len;i++)
   {
       char ch=str.at(i);
       //cout<<ch<<endl;
      if(ch!='.' && ch!='/')
          n=n*10+(ch-48);
      if(ch=='.' || ch=='/')
       {
           arr[pos++]=n;
           n=0;
       }
   }
   arr[pos]=n;
   return arr;
}

int check(int lower, int x, int upper)
{
    if(lower==x && x==upper)
        return 0;
    if(lower==x)
        return 1;
    if(upper==x)
        return 2;
    if(lower< x && x<upper)
        return 3;
    return 4;
}
int lower_checker(int lower, int x)
{
    if(lower==x)
        return 1;
    if(lower>x)
        return 4;
    if(lower<x)
        return 3;
  return 4;
}
int upper_checker(int upper, int x)
{
    if(upper==x)
        return 2;
    if(upper<x)
        return 4;
    if(upper>x)
        return 3;
  return 4;
}
int power(int a, int b)
{
    int f=1;
    for(int i=1;i<=b;i++)
        f=f*a;
    return f;
}
int main()
{
    int **from,**to,*arr;
    string *country,str1,str2,str3;
    int R,N;
    int num[]={128,192,224,240,248,252,254,255};
    cin>>R>>N;
    vector<string> v;
    from=new int*[R];
    to=new int*[R];
    country=new string[R];
    for(int i=0;i<R;i++)
    {
      from[i]=new int[5];
      to[i]=new int[5];
    }
   for(int i=0;i<R;i++)
   {
     cin>>str1>>str2>>str3;
     //cout<<"\n--------------\n";
     //cout<<str1<<endl;
     //cout<<str2<<endl;
     //cout<<str3<<endl;
     arr=my_seperate(str1);

        from[i][0]=arr[0];
        from[i][1]=arr[1];
        from[i][2]=arr[2];
        from[i][3]=arr[3];
        from[i][4]=arr[4];

        arr=my_seperate(str2);

        to[i][0]=arr[0];
        to[i][1]=arr[1];
        to[i][2]=arr[2];
        to[i][3]=arr[3];
        to[i][4]=arr[4];

       country[i]=str3;

   }
  /* for(int i=0;i<R;i++)
   {
       cout<<"\n-----------------------\n";
       cout<<from[i][0]<<" "<<from[i][1]<<" "<<from[i][2]<<" "<<from[i][3]<<" "<<from[i][4]<<" ";
       cout<<to[i][0]<<" "<<to[i][1]<<" "<<to[i][2]<<" "<<to[i][3]<<" "<<to[i][4]<<" ";
       cout<<country[i]<<endl;
   }*/

 for(int i=0;i<R;i++)
   {
      int f=from[i][4];
     f=32-f;
     int t=to[i][4];
     t=32-t;

     //for to
     if(t<=8)
      to[i][3]= power(2,t) -1;
     else if(t<=16)
     {
         to[i][3]=255;
         t=t-8;
         to[i][2]=power(2,t) -1;
     }
     else if(t<=24)
     {
          to[i][3]=255;
          to[i][2]=255;
         t=t-16;
         to[i][2]=power(2,t) -1;
     }
     else
     {
         to[i][3]=255;
          to[i][2]=255;
          to[i][1]=255;
         t=t-24;
         to[i][2]=power(2,t) -1;
     }

     //for from
      if(f<8)
      from[i][3]=num[f-1] ;
     else if(f<16)
     {
         from[i][3]=0;
         f=f-8;
         from[i][2]=num[7-f];
     }
     else if(f<24)
     {   from[i][3]=0;
         from[i][2]=0;
         f=f-16;
         from[i][1]=num[7-f];
     }
     else
     {
        from[i][3]=0;
         from[i][2]=0;
         from[i][1]=0;
         f=f-24;
         from[i][0]=num[7-f];
     }
   }
  /*for(int i=0;i<R;i++)
   {
       cout<<"\n-----------------------\n";
       cout<<from[i][0]<<" "<<from[i][1]<<" "<<from[i][2]<<" "<<from[i][3]<<" "<<from[i][4]<<" ";
       cout<<to[i][0]<<" "<<to[i][1]<<" "<<to[i][2]<<" "<<to[i][3]<<" "<<to[i][4]<<" ";
       cout<<country[i]<<endl;
   }*/
for(int j=1;j<=N;j++)
{
        cin>>str1;
       arr=my_seperate(str1);
       int flag=0;

   for(int i=0;i<R;i++)
   {  int abc=5;
     for(int k=0;k<4;k++)
     {

        if(k==0 || abc==0)
        {
          abc=check(from[i][k],arr[k],to[i][k]);
          continue;
        }


        //cout<<"From="<<from[i][k]<<"To="<<to[i][k]<<"x="<<arr[k]<<endl;
        //cout<<"abc="<<abc<<endl;

        if(abc==1 && k!=0)
        {
            // cout<<"abc="<<abc<<endl;
            abc=lower_checker(from[i][k],arr[k]);

             if(abc==3)
            {
            flag=1;
            v.push_back(country[i]);
            //cout<<country[i];
            break;
            }
            if(abc==4)
            {
            break;
            }
           //abc=1;
        }
        else if(abc==2)
        {
             //cout<<"abc="<<abc<<endl;
            abc=upper_checker(to[i][k],arr[k]);
            //cout<<"Upper_checker="<<abc<<endl;
             if(abc==3)
            {
            flag=1;
            v.push_back(country[i]);
            //cout<<country[i]<<endl;
            break;
            }
            if(abc==4)
            {
            break;
            }
        }
        if(abc==3)
        {
            flag=1;
            v.push_back(country[i]);
            //cout<<country[i]<<endl;
            break;
        }
        if(abc==4)
          {
            break;
          }
       if(k==3)
       {
           flag=1;
            v.push_back(country[i]);
            //cout<<country[i]<<endl;
            break;
       }
     }




   }//inner for
   if(flag==0)
    v.push_back("None");

}//outer for
  int vs=v.size();
  for(int i=0;i<vs;i++)
    {
     if(i<vs-1)
    cout<<v[i]<<endl;
    else
      cout<<v[i];
  }
    return 0;
}
