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

int a[500];
int b[500];

void solve()
{
    int n,x;
    cin>>n;
    vector<int> ans;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    for (int i=n-1;i>1;--i)
    {
        for (int j=i;j+1;--j)
            if (a[j]==b[i])
            {
                x=j;
                break;
            }
        //cout<<b[i]<<"\n";
        while (x<=i-2)
        {
            //cout<<x<<" "<<i<<"\n";
            ans.push_back(x+1);
            swap(a[x],a[x+1]);
            swap(a[x],a[x+2]);
            x+=1;
            //for (int j=0;j<n;++j)
                //cout<<a[j]<<" ";
            //cout<<"!\n";
        }
        if (x<i)
        {
            ans.push_back(x);
            swap(a[x-1],a[x]);
            swap(a[x-1],a[x+1]);
            //for (int j=0;j<n;++j)
                //cout<<a[j]<<" ";
            //cout<<"!!\n";
        }
    }
    if (a[0]!=b[0]||a[1]!=b[1])
    {
        cout<<"-1\n";
        return;
    }
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    cout<<"\n";
    return;
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