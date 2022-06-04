//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

const int N = 101;
int n, a[N], b[N], q[N], x, y;
int inp[N];
bool local = 0;

void query()
{
    cout<<"?";
    for (int i=1;i<=n;++i)
        cout<<" "<<q[i];
    cout<<endl;
    if (!local)
        cin>>x;
    else
    {
        map<int,int> m;
        x=0;
        for (int i=1;i<=n;++i)
            ++m[q[i]+inp[i]];
        for (int i=n;i>=1;--i)
            if (m[q[i]+inp[i]]>1)
                x=i;
        cout<<x<<endl;
    }
}
  
int main()
{
    cin>>n;
    if (local)
        for (int i=1;i<=n;++i)
            cin>>inp[i];
    for (int i=1;i<=n;++i)
        a[i]=b[i]=-1;
    for (int i=n;i>=1;--i)
    {
        if (a[i]==-1)
        {
            for (int j=1;j<i;++j)
                q[j]=1;
            for (int j=i+1;j<=n;++j)
                q[j]=1;
            q[i]=2;
            query();
            if (x<i)
            {
                a[i]=x;
                b[x]=i;
            }
            else
                a[i]=0;
        }
        if (b[i]==-1)
        {
            for (int j=1;j<i;++j)
                q[j]=2;
            for (int j=i+1;j<=n;++j)
                q[j]=2;
            q[i]=1;
            query();
            if (x<i)
            {
                b[i]=x;
                a[x]=i;
            }
            else
                b[i]=0;
        }
    }
    // for (int i=1;i<=n;++i)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for (int i=1;i<=n;++i)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for (int i=1;i<=n;++i)
        if (b[i]==0)
        {
            x=i;
            y=1;
            //cerr<<x<<" "<<y<<"\n";
            q[x]=y++;
            while (a[x]>0)
            {
                x=a[x];
                //cerr<<x<<" "<<y<<"\n";
                q[x]=y++;
            }
            cout<<"!";
            for (int i=1;i<=n;++i)
                cout<<" "<<q[i];
            cout<<endl;
            return 0;
        }
    return 0;
}