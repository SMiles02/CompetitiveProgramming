#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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

void solve()
{
    int n;
    cin>>n;
    string s,t,temp;
    cin>>s;
    cin>>t;
    vector<int> ans;
    for (int i=n-1;i;--i)
    {
        if (s[i]!=t[i])
        {
            if (s[0]==t[i])
            {
                ans.push_back(1);
                if (s[0]=='0')
                    s[0]='1';
                else
                    s[0]='0';
            }
            ans.push_back(i+1);
            temp.clear();
            for (int j=0;j<=i;++j)
            {
                if (s[i-j]=='0')
                    temp+='1';
                else
                    temp+='0';
            }
            for (int j=i+1;j<n;++j)
                temp+=s[j];
            s=temp;
        }
    }
    if (s[0]!=t[0])
        ans.push_back(1);
    cout<<sz(ans)<<" ";
    for (int i : ans)
        cout<<i<<" ";
    cout<<"\n";
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