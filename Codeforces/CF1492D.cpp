#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    // int n,m;
    // cin>>n>>m;
    // vector<int> v;
    // for (int i=(1<<(n+m-1));i<(1<<(n+m));++i)
    //     if (__builtin_popcount(i)==n)
    //         v.push_back(i);
    // for (int i=sz(v)-1;i<sz(v);++i)
    //     for (int j=0;j<=i;++j)
    //     {
    //         ok[__builtin_popcount(v[i]-v[j])]=1;
    //         cout<<__builtin_popcount(v[i]-v[j])<<" "<<v[j]<<"\n";
    //     }
    // for (int i=0;i<=n+m;++i)
    //     cout<<ok[i]<<" ";
    int a,b,k;
    cin>>a>>b>>k;
    if (b==1||a==0)
    {
        if (k==0)
        {
            cout<<"Yes\n";
            for (int i=0;i<b;++i)
                cout<<1;
            for (int i=0;i<a;++i)
                cout<<0;
            cout<<"\n";
            for (int i=0;i<b;++i)
                cout<<1;
            for (int i=0;i<a;++i)
                cout<<0;
            cout<<"\n";
        }
        else
            cout<<"No";
        return 0;
    }
    if (k>=a+b-1)
    {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    for (int i=0;i<b;++i)
        cout<<1;
    for (int i=0;i<a;++i)
        cout<<0;
    cout<<"\n";
    if (a+b-2-min(a-1,b-2)<=k)
    {
        int cur=0;
        string s(a+b,'1');
        for (int i=1;k<=a+b-1-i;++i)
        {
            ++cur;
            s[i]='0';
        }
        for (int i=a+b-2;cur<a;--i,++cur)
            s[i]='0';
        cout<<s;
        return 0;
    }
    if (b-1+k<a+b)
    {
        string s(a+b,'0');
        for (int i=0;i+1<b;++i)
            s[i]='1';
        s[b-1+k]='1';
    }
    return 0;
}