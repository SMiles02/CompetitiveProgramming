#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
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
    string s(a+b,'0');
    for (int i=0;i<b;++i)
        s[i]='1';
    int cur=0;
    for (int i=b;i<a+b&&cur<k;++i,++cur)
        swap(s[i],s[i-1]);
    for (int i=b-1;i&&cur<k;--i,++cur)
        swap(s[i],s[i-1]);
    cout<<s;
    return 0;
}