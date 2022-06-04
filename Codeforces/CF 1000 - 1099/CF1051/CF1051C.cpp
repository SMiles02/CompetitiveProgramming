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
    int n,c=0,extra=0,k,found=0;
    cin>>n;
    int a[n];
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++m[a[i]];
    }
    for (int i=1;i<101;++i)
    {
        if (m[i]==1)
        {
            //cout<<i<<"\n";
            ++c;
        }
        else if (m[i]>2)
        {
            extra=1;
            k=i;
        }
    }
    if (c%2)
    {
        if (extra)
        {
            cout<<"YES\n";
            for (int i=0;i<n;++i)
            {
                if (m[a[i]]==1)
                {
                    if (c%2)
                    {
                        cout<<"A";
                    }
                    else
                    {
                        cout<<"B";
                    }
                    --c;
                }
                else if (a[i]==k)
                {
                    if (found)
                    {
                        cout<<"A";
                    }
                    else
                    {
                        cout<<"B";
                        found=1;
                    }
                }
                else
                {
                    cout<<"A";
                }
            }
        }
        else
        {
            cout<<"NO";
        }
        return 0;
    }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
    {
        if (m[a[i]]==1)
        {
            if (c%2)
            {
                cout<<"A";
            }
            else
            {
                cout<<"B";
            }
            --c;
        }
        else
        {
            cout<<"A";
        }
    }
    return 0;
}