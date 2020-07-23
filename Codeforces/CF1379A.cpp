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
    int n,cur=0;
    bool ok=0;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i+6<n;++i)
        if (s[i]=='a')
            if (s[i+1]=='b')
                if (s[i+2]=='a')
                    if (s[i+3]=='c')
                        if (s[i+4]=='a')
                            if (s[i+5]=='b')
                                if (s[i+6]=='a')
                                    ok=1;
    for (int i=0;i+6<n&&ok==0;++i)
        if (s[i]=='a'||s[i]=='?')
            if (s[i+1]=='b'||s[i+1]=='?')
                if (s[i+2]=='a'||s[i+2]=='?')
                    if (s[i+3]=='c'||s[i+3]=='?')
                        if (s[i+4]=='a'||s[i+4]=='?')
                            if (s[i+5]=='b'||s[i+5]=='?')
                                if (s[i+6]=='a'||s[i+6]=='?')
                                {
                                    //cout<<i<<" in\n";
                                    if (i+10<n)
                                        if (s[i+7]=='c'&&s[i+8]=='a'&&s[i+9]=='b'&&s[i+10]=='a')
                                            continue;
                                    if (i-4>=0)
                                        if (s[i-4]=='a'&&s[i-3]=='b'&&s[i-2]=='a'&&s[i-1]=='c')
                                            continue;
                                    //cout<<"stayed\n";
                                    s[i]='a';
                                    s[i+1]='b';
                                    s[i+2]='a';
                                    s[i+3]='c';
                                    s[i+4]='a';
                                    s[i+5]='b';
                                    s[i+6]='a';
                                    ok=1;
                                }
    for (int i=0;i<n;++i)
        if (s[i]=='?')
            s[i]='z';
    for (int i=0;i+6<n;++i)
        if (s[i]=='a')
            if (s[i+1]=='b')
                if (s[i+2]=='a')
                    if (s[i+3]=='c')
                        if (s[i+4]=='a')
                            if (s[i+5]=='b')
                                if (s[i+6]=='a')
                                    ++cur;
    if (cur==1)
        cout<<"Yes\n"<<s<<"\n";
    else
        cout<<"No\n";
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