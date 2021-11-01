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
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double mn = 1e9;
    vector<double> ans;
    for (double x1=0;x1<=5;x1+=0.5)
        for (double x2=0;x2<=5;x2+=0.5)
            for (double x3=0;x3<=5;x3+=0.5)
                for (double x4=0;x4<=5;x4+=0.5)
                    for (double x5=-5;x5<=5;x5+=0.5)
                        for (double x6=0;x6<=5;x6+=0.5)
                            if (x1+x2+x3>=1&&-x1+x4+x5==0&&-x2-x4+x6==0&&x3-x5+x6<=1)
                                if (mn>x1+8*x2+9*x3+2*x4+7*x5+3*x6)
                                {
                                    mn=x1+8*x2+9*x3+2*x4+7*x5+3*x6;
                                    ans={x1,x2,x3,x4,x5,x6};
                                }
    cout<<mn<<"\n";
    for (auto i : ans)
        cout<<i<<" ";
    return 0;
}