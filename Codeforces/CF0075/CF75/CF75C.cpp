#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

vector<int> v;
int x,y,low,high,mid;

void solveBinSearch()
{
    cin>>x>>y;
    low=0;high=sz(v)-1;
    while (low<high)
    {
        mid=low+((high-low)/2);
        if (v[mid]>y)
        {
            low=mid+1;
        }
        else if (v[mid]<x)
        {
            high=mid-1;
        }
        else
        {
            high=mid;
        }
    }
    if (high==low&&x<=v[low]&&v[low]<=y)
    {
        cout<<v[low]<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,x,s,n;
    cin>>a>>b;
    x=gcd(a,b);
    s=sqrt(x);
    for (int i=1;i<=s;++i)
    {
        if (!(x%i))
        {
            if (i*i!=x)
            {
                v.push_back(x/i);
            }
            v.push_back(i);
        }
    }
    sort(v.rbegin(),v.rend());
    cin>>n;
    while (n--)
    {
        solveBinSearch();
    }
    return 0;
}