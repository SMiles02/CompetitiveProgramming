#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,cur=1;
int a[100000];
vector<int> v;

void recurse(int l, int r)
{
    if (l==r)
    {
        a[l]=v.back();
        v.pop_back();
        return;
    }
    if (cur<k)
    {
        cur+=2;
        if ((r-l)%2)
        {
            recurse(l,l+(r-l)/2);
            recurse(l+(r-l)/2+1,r);
        }
        else
        {
            recurse(l,l+(r-l)/2-1);
            recurse(l+(r-l)/2,r);
        }
        return;
    }
    for (int i=r;i>=l;--i)
    {
        a[i]=v.back();
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        v.push_back(i);
    recurse(0,n-1);
    if (cur!=k)
    {
        cout<<-1;
        return 0;
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}