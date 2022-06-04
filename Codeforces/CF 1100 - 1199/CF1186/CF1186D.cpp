#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll x=0;
    cin>>n;
    double a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        x+=floor(a[i]);
    }
    for (int i=0;i<n;++i)
    {
        if ((int)a[i]==a[i]||x==0)
        {
            if (floor(a[i])==0)
                cout<<"0\n";
            else
                cout<<floor(a[i])<<"\n";
        }
        else
        {
            if (ceil(a[i])==0)
                cout<<"0\n";
            else
                cout<<ceil(a[i])<<"\n";
            ++x;
        }
    }
    return 0;
}