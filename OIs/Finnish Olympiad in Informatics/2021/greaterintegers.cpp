#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll n;
set<int> s;

bool allSame(ll k)
{
    s.clear();
    while (k)
    {
        s.insert(k%10);
        k/=10;
    }
    if (sz(s)==1)
        return 1;
    return 0;
}

int findLen(ll k)
{
    int r=0;
    while (k)
    {
        ++r;
        k/=10;
    }
    return r;
}

int firstDigit(ll k)
{
    while (k>9)
        k/=10;
    return k;
}

void solve()
{
    cin>>n;
    int l = findLen(n), f = firstDigit(n);
    if (!allSame(n)&&f==*(--s.end()))
    {
        while (l--)
            cout<<f;
        cout<<"\n";
        return;
    }
    if (f==9)
    {
        f=0;
        ++l;
    }
    while (l--)
        cout<<(f+1);
    cout<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}