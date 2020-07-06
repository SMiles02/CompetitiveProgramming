#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,obstacles=0,r,c;
    cin>>n>>q;
    map<pair<int,int>,int> states;
    map<pair<pair<int,int>,pair<int,int>>,int> blockedPaths;
    while (q--)
    {
        cin>>r>>c;
        if (r==2&&c==1)
        {
            if (states[{2,1}])
            {
                if (blockedPaths[{{1,2},{2,1}}])
                {
                    blockedPaths[{{1,2},{2,1}}]=0;
                    --obstacles;
                }
                states[{r,c}]=0;
            }
            else
            {
                if (states[{1,2}])
                {
                    blockedPaths[{{1,2},{2,1}}]=1;
                    ++obstacles;
                }
                states[{r,c}]=1;
            }
        }
        else if (r==1&&c==n)
        {
            if (states[{1,n}])
            {
                if (blockedPaths[{{1,n},{2,n-1}}])
                {
                    blockedPaths[{{1,n},{2,n-1}}]=0;
                    --obstacles;
                }
                states[{r,c}]=0;
            }
            else
            {
                if (states[{2,n-1}])
                {
                    blockedPaths[{{1,n},{2,n-1}}]=1;
                    ++obstacles;
                }
                states[{r,c}]=1;
            }
        }
        else if (r==1)
        {
            if (states[{1,c}])
            {
                if (blockedPaths[{{1,c},{2,c-1}}])
                {
                    blockedPaths[{{1,c},{2,c-1}}]=0;
                    --obstacles;
                }
                if (blockedPaths[{{1,c},{2,c+1}}])
                {
                    blockedPaths[{{1,c},{2,c+1}}]=0;
                    --obstacles;
                }
                if (blockedPaths[{{1,c},{2,c}}])
                {
                    blockedPaths[{{1,c},{2,c}}]=0;
                    --obstacles;
                }
                states[{r,c}]=0;
            }
            else
            {
                if (states[{2,c-1}])
                {
                    blockedPaths[{{1,c},{2,c-1}}]=1;
                    ++obstacles;
                }
                if (states[{2,c+1}])
                {
                    blockedPaths[{{1,c},{2,c+1}}]=1;
                    ++obstacles;
                }
                if (states[{2,c}])
                {
                    blockedPaths[{{1,c},{2,c}}]=1;
                    ++obstacles;
                }
                states[{r,c}]=1;
            }
        }
        else
        {
            if (states[{2,c}])
            {
                if (blockedPaths[{{1,c+1},{2,c}}])
                {
                    blockedPaths[{{1,c+1},{2,c}}]=0;
                    --obstacles;
                }
                if (blockedPaths[{{1,c-1},{2,c}}])
                {
                    blockedPaths[{{1,c-1},{2,c}}]=0;
                    --obstacles;
                }
                if (blockedPaths[{{1,c},{2,c}}])
                {
                    blockedPaths[{{1,c},{2,c}}]=0;
                    --obstacles;
                }
                states[{r,c}]=0;
            }
            else
            {
                if (states[{1,c-1}])
                {
                    blockedPaths[{{1,c-1},{2,c}}]=1;
                    ++obstacles;
                }
                if (states[{1,c+1}])
                {
                    blockedPaths[{{1,c+1},{2,c}}]=1;
                    ++obstacles;
                }
                if (states[{1,c}])
                {
                    blockedPaths[{{1,c},{2,c}}]=1;
                    ++obstacles;
                }
                states[{r,c}]=1;
            }
        }
        if (obstacles==0)
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}