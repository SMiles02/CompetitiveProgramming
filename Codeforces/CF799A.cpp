#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,t,k,d;

int with()
{
    int m=0,c1=t,c2=d,c3=t;
    for (int i=1;;++i)
    {
        if (--c1==0)
        {
            m+=k;
            c1=t;
        }
        if (--c2<0)
            --c3;
        if (c3==0)
        {
            m+=k;
            c3=t;
        }
        //cout<<i<<": "<<m<<"\n";
        //cout<<c3<<"\n";
        if (m>=n)
            return i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>t>>k>>d;
    //cout<<with()<<"\n";
    if (((n+k-1)/k)*t==with())
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}