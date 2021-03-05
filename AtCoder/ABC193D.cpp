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

int calc(vector<int> v)
{
    int rtn=0;
    for (int i=1;i<10;++i)
        rtn+=i*binpow(10,v[i]);
    return rtn;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,c[10],A;
    vector<int> v(10,0),w(10,0);
    cin>>k;
    string s,t;
    cin>>s;
    cin>>t;
    for (int i=1;i<10;++i)
        c[i]=k;
    for (int i=0;i<4;++i)
    {
        --c[s[i]-'0'];
        ++v[s[i]-'0'];
    }
    for (int i=0;i<4;++i)
    {
        --c[t[i]-'0'];
        ++w[t[i]-'0'];
    }
    double ans=0,cur;
    for (int i=1;i<10;++i)
        if (c[i]>0)
        {
            cur=(double)c[i]/(k*9-8);
            --c[i];
            ++w[i];
            A=calc(w);
            //cout<<i<<": "<<calc(w)<<"\n";
            for (int j=1;j<10;++j)
            {
                ++v[j];
                //cout<<"j"<<j<<": "<<calc(v)<<"\n";
                if (calc(v)>A)
                    ans+=cur*((double)c[j]/(k*9-9));
                --v[j];
            }
            ++c[i];
            --w[i];
        }
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}