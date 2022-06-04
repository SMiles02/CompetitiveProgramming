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
    int n,k,a,b,c;
    cin>>n;
    map<int,int> m;
    while (n--)
    {
        cin>>k;
        ++m[k];
    }
    a=m[4];
    if (m[1]>0&&m[2]>0&&m[4]>0)
    {
        m[1]-=m[4];
        m[2]-=m[4];
        m[4]=0;
    }
    b=m[3];
    if (m[1]>0&&m[3]>0&&m[6]>0)
    {
        m[6]-=m[3];
        m[1]-=m[3];
        m[3]=0;
    }
    c=m[2];
    if (m[1]>0&&m[2]>0&&m[6]>0)
    {
        m[1]-=m[2];
        m[6]-=m[2];
        m[2]=0;
    }
    for (int i=1;i<8;++i)
    {
        if (m[i]!=0)
        {
            cout<<-1;
            return 0;
        }
    }
    for (int i=0;i<a;++i)
    {
        cout<<"1 2 4\n";
    }
    for (int i=0;i<b;++i)
    {
        cout<<"1 3 6\n";
    }
    for (int i=0;i<c;++i)
    {
        cout<<"1 2 6\n";
    }
    return 0;
}