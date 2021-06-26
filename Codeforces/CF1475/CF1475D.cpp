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

void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n][2];
    for (int j=0;j<2;++j)
        for (int i=0;i<n;++i)
            cin>>a[i][j];
    vector<int> one,two;
    for (int i=0;i<n;++i)
    {
        if (a[i][1]==1)
            one.push_back(a[i][0]);
        else
            two.push_back(a[i][0]);
    }
    int ans=1000000,l,r,mid,x=sz(one),y=sz(two);
    sort(one.rbegin(), one.rend());
    sort(two.rbegin(), two.rend());
    ll pre1[x+1],pre2[y+1];
    pre1[0]=pre2[0]=0;
    for (int i=0;i<x;++i)
        pre1[i+1]=pre1[i]+one[i];
    for (int i=0;i<y;++i)
        pre2[i+1]=pre2[i]+two[i];
    /**
    for (int i=0;i<=x;++i)
        cout<<pre1[i]<<" ";
    cout<<"\n";
    for (int i=0;i<=y;++i)
        cout<<pre2[i]<<" ";
    cout<<"\n";
    **/
    for (int i=0;i<=x;++i)
    {
        if (pre1[i]+pre2[y]<m)
            continue;
        l=0;r=y;
        while (l^r)
        {
            mid=l+(r-l)/2;
            //cout<<l<<" "<<r<<"!\n";
            //cout<<mid<<": "<<pre1[i]+pre2[mid]<<"\n";
            if (pre1[i]+pre2[mid]<m)
                l=mid+1;
            else
                r=mid;
            //cout<<l<<" "<<r<<"!\n";
        }
        ans=min(ans,i+2*l);
        //cout<<i<<" "<<mid<<"\n";
        //cout<<pre1[i]<<" "<<pre2[mid]<<"\n";
        //cout<<"\n";
    }
    if (ans==1000000)
        ans=-1;
    cout<<ans<<"\n";
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