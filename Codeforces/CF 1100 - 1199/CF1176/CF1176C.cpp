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
    int n,m,k,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
    cin>>n;
    m=n;
    while (n--)
    {
        cin>>k;
        if (k==4)
        {
            ++c1;
        }
        else if (k==8)
        {
            if (c1)
            {
                --c1;
                ++c2;
            }
        }
        else if (k==15)
        {
            if (c2)
            {
                --c2;
                ++c3;
            }
        }
        else if (k==16)
        {
            if (c3)
            {
                --c3;
                ++c4;
            }
        }
        else if (k==23)
        {
            if (c4)
            {
                --c4;
                ++c5;
            }
        }
        else
        {
            if (c5)
            {
                --c5;
                ++c6;
            }
        }
        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<c5<<" "<<c6<<"\n";
    }
    cout<<m-(6*c6);
    return 0;
}