#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z,k,a,b;
    cin>>n>>m>>x>>y>>z>>k;
    int p[k][2];
    for (int i=0;i<k;++i)
    {
        cin>>p[i][0]>>p[i][1];
    }
    if (x%4==1)
    {
        swap(n,m);
        for (int i=0;i<k;++i)
        {
            a=p[i][1];
            b=m+1-p[i][0];
            p[i][0]=a;
            p[i][1]=b;
        }        
    }
    if (x%4==2)
    {
        for (int i=0;i<k;++i)
        {
            p[i][0]=n-p[i][0]+1;
            p[i][1]=m-p[i][1]+1;
        }     
    }
    if (x%4==3)
    {
        swap(n,m);
        for (int i=0;i<k;++i)
        {
            b=p[i][0];
            a=n+1-p[i][1];
            p[i][0]=a;
            p[i][1]=b;
        }        
    }
    if (y%2)
    {
        for (int i=0;i<k;++i)
        {
            p[i][1]=m+1-p[i][1];
        }    
    }
    if (z%4==3)
    {
        swap(n,m);
        for (int i=0;i<k;++i)
        {
            a=p[i][1];
            b=m+1-p[i][0];
            p[i][0]=a;
            p[i][1]=b;
        }        
    }
    if (z%4==2)
    {
        for (int i=0;i<k;++i)
        {
            p[i][0]=n-p[i][0]+1;
            p[i][1]=m-p[i][1]+1;
        }     
    }
    if (z%4==1)
    {
        swap(n,m);
        for (int i=0;i<k;++i)
        {
            b=p[i][0];
            a=n+1-p[i][1];
            p[i][0]=a;
            p[i][1]=b;
        }        
    }
    for (int i=0;i<k;++i)
    {
        cout<<p[i][0]<<" "<<p[i][1]<<"\n";
    }
    return 0;
}