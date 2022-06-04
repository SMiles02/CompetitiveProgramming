#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int n,o,p;
    cin>>n;
    int a[n];
    vector<int> x={-1};
    vector<int> y={-1};
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        if (x.back()==a[i])
        {
            if (y.back()==a[i])
            {
                cout<<"NO";
                return 0;
            }
            y.push_back(a[i]);
        }
        else
        {
            x.push_back(a[i]);
        }
    }
    o=sz(x);p=sz(y);
    cout<<"YES\n"<<o-1<<"\n";
    for (int i=1;i<o;++i)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n"<<p-1<<"\n";
    for (int i=p-1;i>0;--i)
    {
        cout<<y[i]<<" ";
    }
    return 0;
}