#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int isInt(double a)
{
    if ((int)a==a)
        return 1;
    return 0;
}

const ll INF = 1e18, mn = 1e9;
int p[4][2];
ll ans;

ll dist(double a, double b, double c, double d)
{
    return abs(a-c) + abs(b-d);
}

ll attempt(double x, double y, double z)
{
    ll cur=INF;
    vector<int> v = {0,1,2,3};
    sort(v.begin(), v.end());
    do {
        cur=min(dist(x-z,y-z,p[v[0]][0],p[v[0]][1])+dist(x-z,y+z,p[v[1]][0],p[v[1]][1])+dist(x+z,y-z,p[v[2]][0],p[v[2]][1])+dist(x+z,y+z,p[v[3]][0],p[v[3]][1]),cur);
    } while (next_permutation(v.begin(), v.end()));
    //cout<<x<<" "<<y<<" "<<z<<": "<<cur<<"\n";
    //cout<<ans<<"\n";
    return cur;
}

bool tryCmp(double x, double y, double z)
{
    ll a=attempt(x,y,z-1),b=attempt(x,y,z);
    ans=min(ans,min(a,b));
    //cout<<"ans is now "<<ans<<"\n";
    if (a<b)
        return 1;
    return 0;
}

void solve(double x, double y)
{
    ll l=1,r=mn,m;
    if (isInt(x))
    {
        if (tryCmp(x,y,l))
            return;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (tryCmp(x,y,m))
                r=m-1;
            else
                l=m;
        }
        tryCmp(x,y,l);
    }
    else
    {
        if (tryCmp(x,y,0.5+l))
            return;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (tryCmp(x,y,0.5+m))
                r=m-1;
            else
                l=m;
        }
        tryCmp(x,y,0.5+l);
    }
}

void tc()
{
    ll x=0,y=0;
    ans=INF;
    for (int i=0;i<4;++i)
    {
        cin>>p[i][0]>>p[i][1];
        x+=p[i][0];
        y+=p[i][1];
    }
    x/=4;
    y/=4;
    //cout<<x<<" "<<y<<"\n";
    for (double i=-20;i<21;i+=1)
        for (double j=-20;j<21;j+=1)
            solve(i+x,j+y);
    for (double i=-19.5;i<20;i+=1)
        for (double j=-19.5;j<20;j+=1)
            solve(i+x,j+y);
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        tc();
    return 0;
}