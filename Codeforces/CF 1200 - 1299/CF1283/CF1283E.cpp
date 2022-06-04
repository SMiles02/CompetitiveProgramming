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
    int n,x=0,y=0;
    cin>>n;
    map<int,int> occupied1;
    map<int,int> occupied2;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        if (!occupied1[a[i]-1]&&!occupied1[a[i]]&&!occupied1[a[i]+1])
        {
            occupied1[a[i]+1]=1;
            ++x;
        }
        if (!occupied2[a[i]-1])
        {
            occupied2[a[i]-1]=1;
            ++y;
        }
        else
        {
            if (!occupied2[a[i]])
            {
                occupied2[a[i]]=1;
                ++y;
            }
            else if (!occupied2[a[i]+1])
            {
                occupied2[a[i]+1]=1;
                ++y;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}