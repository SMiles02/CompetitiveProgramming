#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int cycle(int k, int n)
{
    int ans=1;
    for (int i=k;i%n;i+=k)
        ++ans;
    return ans;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int amount[26];

int score(int n)
{
    int ans=0;
    for (int i=0;i<26;++i)
        ans+=amount[i]/n;
    return ans;
}

void solve()
{
    for (int i=0;i<26;++i)
        amount[i]=0;
    int n,k,maxi=0;
    cin>>n>>k;
    string s;
    cin>>s;
    for (auto c : s)
        ++amount[c-'a'];
    for (int i=0;i<26;++i)
        maxi=max(maxi,amount[i]);
    for (int i=n;i>0;--i)
    {
        if (k%i==0)
        {
            cout<<i<<"\n";
            return;
        }
        if (score(cycle(k,i))>=(i/(cycle(k,i))))
        {
            cout<<i<<"\n";
            return;
        }
    }
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