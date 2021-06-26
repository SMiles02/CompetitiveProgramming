#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a1=5e5,a2=0,b1=5e5,b2=0,x,y,c=0,d=1e6,e=0,f=1e6;
    cin>>n;
    string s;
    for (int i=0;i<n;++i)
    {
        cin>>s;
        x=0;y=0;
        for (auto c : s)
        {
            if (c=='B')
                ++x;
            else
                ++y;
        }
        a1=min(x,a1);
        a2=max(x,a2);
        b1=min(y,b1);
        b2=max(y,b2);
        cout<<x<<" "<<y<<"\n";
    }
    for (int i=0;i<500001;++i)
    {
        if (max(abs(a1-i),abs(a2-i))<=d)
        {
            d=max(abs(a1-i),abs(a2-i));
            c=i;
        }
        if (max(abs(b1-i),abs(b2-i))<=f)
        {
            f=max(abs(b1-i),abs(b2-i));
            e=i;
        }
    }
    cout<<c<<" "<<e<<"!!!\n";
    cout<<max(max(abs(b1-e),abs(b2-e)),max(abs(a1-c),abs(a2-c)))<<"\n";
    for (int i=0;i<e;++i)
        cout<<"N";
    for (int i=0;i<c;++i)
        cout<<"B";
    return 0;
}