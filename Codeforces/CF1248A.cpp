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
    int t,n,m,k;
    ll odds1,evens1,odds2,evens2;
    cin>>t;
    while (t--)
    {
        odds1=0;odds2=0;evens1=0;evens2=0;
        cin>>n;
        while (n--)
        {
            cin>>k;
            if (k%2)
            {
                ++odds1;
            }
            else
            {
                ++evens1;
            }
        }
        cin>>m;
        while (m--)
        {
            cin>>k;
            if (k%2)
            {
                ++odds2;
            }
            else
            {
                ++evens2;
            }
        }
        cout<<odds1*odds2+evens1*evens2<<"\n";
    }
    return 0;
}