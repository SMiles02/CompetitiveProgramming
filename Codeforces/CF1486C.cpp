#include <bits/stdc++.h>
using namespace std;

int n,k,l,r,m,x;

int query(int l, int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void before()
{
    l=1;r=k-1;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        x=query(m,k);
        if (x==k)
            l=m;
        else
            r=m-1;
    }
}

void after()
{
    l=k+1;r=n;
    while (l<r)
    {
        m=l+(r-l)/2;
        x=query(k,m);
        if (x==k)
            r=m;
        else
            l=m+1;
    }
}

int main()
{
    cin>>n;
    k=query(1,n);
    if (k==1)
        after();
    else if (k==n)
        before();
    else
    {
        x=query(1,k);
        if (x==k)
            before();
        else
            after();
    }
    cout<<"! "<<l<<endl;
    return 0;
}