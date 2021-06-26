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
    int n,m,cur1=0,cur2=0,x=0,y=0,ans=0;
    cin>>n>>m;
    int a[n];
    int b[m];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    while (x<n||y<m)
    {
        //cout<<x<<" "<<y<<" "<<cur1<<" "<<cur2<<"\n";
        if (cur2==cur1&&cur1>0)
        {
            ++ans;
            cur1=0;
            cur2=0;
        }
        else
        {
            if (cur1==cur2)
            {
                cur1+=a[x];
                cur2+=b[y];
                ++x;
                ++y;
            }
            else if (cur1>cur2)
            {
                cur2+=b[y];
                ++y;
            }
            else
            {
                cur1+=a[x];
                ++x;
            }
        }
    }
    if (cur2==cur1&&cur1>0)
    {
        ++ans;
    }
    cout<<ans;
    return 0;
}
