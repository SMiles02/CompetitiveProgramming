#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,a[200000];
    cin>>n;
    char c;
    stack<int> s;
    for (int i=0;i<2*n;++i)
    {
        cin>>c;
        if (c=='+')
            s.push(i);
        else
        {
            if (s.empty())
            {
                cout<<"NO\n";
                return 0;
            }
            cin>>k;
            a[s.top()]=k;
            s.pop();
            a[i]=-k;
        }
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for (int i=0;i<2*n;++i)
    {
        if (a[i]<0)
        {
            if (q.top()!=-a[i])
            {
                cout<<"NO";
                return 0;
            }
            q.pop();
        }
        else
        {
            q.push(a[i]);
        }
    }
    cout<<"YES\n";
    for (int i=0;i<2*n;++i)
        if (a[i]>0)
            cout<<a[i]<<" ";
    return 0;
}