#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int r=0,g=0,b=0;
    ll ans=0;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='R')
        {
            ++r;
        }
        else if (s[i]=='G')
        {
            ++g;
        }
        else
        {
            ++b;
        }
    }
    int rComing[n];
    int gComing[n];
    int bComing[n];
    for (int i=0;i<n;++i)
    {
        if (s[i]=='R')
        {
            --r;
        }
        else if (s[i]=='G')
        {
            --g;
        }
        else
        {
            --b;
        }
        rComing[i]=r;
        bComing[i]=b;
        gComing[i]=g;
    }
    for (int i=0;i<n;++i)
    {
        for (int j=i+1;j<n;++j)
        {
            if (s[i]!=s[j])
            {
                if (s[i]=='R')
                {
                    if (s[j]=='G')
                    {
                        if (s[j+(j-i)]=='B')
                        {
                            ans+=(bComing[j]-1);
                        }
                        else
                        {
                            ans+=(bComing[j]);
                        }
                    }
                    else //B
                    {
                        if (s[j+(j-i)]=='G')
                        {
                            ans+=(gComing[j]-1);
                        }
                        else
                        {
                            ans+=(gComing[j]);
                        }
                    }
                }
                if (s[i]=='G')
                {
                    if (s[j]=='R')
                    {
                        if (s[j+(j-i)]=='B')
                        {
                            ans+=(bComing[j]-1);
                        }
                        else
                        {
                            ans+=(bComing[j]);
                        }
                    }
                    else //B
                    {
                        if (s[j+(j-i)]=='R')
                        {
                            ans+=(rComing[j]-1);
                        }
                        else
                        {
                            ans+=(rComing[j]);
                        }
                    }
                }
                if (s[i]=='B')
                {
                    if (s[j]=='G')
                    {
                        if (s[j+(j-i)]=='R')
                        {
                            ans+=(rComing[j]-1);
                        }
                        else
                        {
                            ans+=(rComing[j]);
                        }
                    }
                    else //R
                    {
                        if (s[j+(j-i)]=='G')
                        {
                            ans+=(gComing[j]-1);
                        }
                        else
                        {
                            ans+=(gComing[j]);
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}