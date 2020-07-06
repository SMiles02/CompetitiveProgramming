#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int a,b,c,ans1=0,ans2=0,x,y,z,b2,b3;
    vector<int> v;
    cin>>a>>b>>c;
    b2=b;
    b3=b;
    if (a%2)
    {
        x=a/2+1;
        y=a/2;
        z=c;
    }
    else
    {
        x=a/2;
        y=a/2;
        z=c;
    }
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end());
    b2-=((v[2]-v[0])+(v[2]-v[1]));
    ans1=v[2];
    if (b2>0)
    {
        if (b2%3)
        {
            ans1+=b2/3+1;
        }
        else
        {
            ans1+=b2/3;
        }
    }
    v.clear();
    if (c%2)
    {
        x=c/2+1;
        y=c/2;
        z=a;
    }
    else
    {
        x=c/2;
        y=c/2;
        z=a;
    }
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(), v.end());
    b-=((v[2]-v[0])+(v[2]-v[1]));
    ans2=v[2];
    if (b>0)
    {
        if (b%3)
        {
            ans2+=b/3+1;
        }
        else
        {
            ans2+=b/3;
        }
    }
    v.clear();
    cout<<min({ans1,ans2,max({a,b3,c})})<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}