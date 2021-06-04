#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+3;
int seg[N<<2],x;

int query(int l, int r)
{
    int k;
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>k;
    return k;
}

bool walk(int i, int l, int r)
{
    if (seg[i]==-1)
    {
        if (i&1)
            seg[i]=r-l+1-query(l,r);
        else
            seg[i]=seg[(i-1)/2]-seg[i-1];
    }
    if (seg[i]<x)
    {
        x-=seg[i];
        return 0;
    }
    if (l==r)
        cout<<"! "<<l<<endl;
    else if (!walk(i*2+1,l,l+(r-l)/2))
        walk(i*2+2,l+(r-l)/2+1,r);
    --seg[i];
    return 1;
}

int main()
{
    for (int i=0;i<N*4;++i)
        seg[i]=-1;
    int n,t;
    cin>>n>>t;
    while (t--)
    {
        cin>>x;
        walk(1,1,n);
    }
    return 0;
}