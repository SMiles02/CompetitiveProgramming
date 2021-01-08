#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s;
int n;

bool ok(int a, int b)
{
    int x=0,y=0,X,Y;
    //cout<<"obstacle at "<<a<<" "<<b<<"\n";
    for (int i=0;i<n;++i)
    {
        //cout<<x<<" "<<y<<"\n";
        if (s[i]=='L')
        {
            X=x-1;
            Y=y;
        }
        if (s[i]=='R')
        {
            X=x+1;
            Y=y;
        }
        if (s[i]=='U')
        {
            X=x;
            Y=y+1;
        }
        if (s[i]=='D')
        {
            X=x;
            Y=y-1;
        }
        if (X==a&&Y==b)
        {
            X=x;
            Y=y;
        }
        x=X;
        y=Y;
    }
    //cout<<x<<" "<<y<<" is final\n";
    if (x==0&&y==0)
        return 1;
    return 0;
}

void solve()
{
    cin>>s;
    n=sz(s);
    int x=0,y=0,X,Y;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='L')
        {
            X=x-1;
            Y=y;
        }
        if (s[i]=='R')
        {
            X=x+1;
            Y=y;
        }
        if (s[i]=='U')
        {
            X=x;
            Y=y+1;
        }
        if (s[i]=='D')
        {
            X=x;
            Y=y-1;
        }
        if ((!(X==0&&Y==0))&&ok(X,Y))
        {
            cout<<X<<" "<<Y<<"\n";
            return;
        }
        x=X;y=Y;
    }
    cout<<"0 0\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}