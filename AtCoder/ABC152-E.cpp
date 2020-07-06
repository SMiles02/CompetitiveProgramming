#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll MOD=1000000007;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    int res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}


pair<vector<int>,map<int,int>> primeFactorisation(int n)
{
    vector<int> v;
    map<int,int> m;
    int cur;
    if (!(n%2))
    {
        cur=2;
        n/=2;
        v.push_back(2);
        while (!(n%2))
        {
            n/=2;
            cur*=2;
        }
        m[2]=cur;
        //cout<<"m["<<2<<"] = "<<cur<<"\n";
    }
    for (int i=3;i*i<=n;i+=2)
    {
        if (!(n%i))
        {
            cur=i;
            n/=i;
            v.push_back(i);
            while (!(n%i))
            {
                n/=i;
                cur*=i;
            }
            m[i]=cur;
            //cout<<"m["<<i<<"] = "<<cur<<"\n";
        }
    }
    if (n!=1)
    {
        v.push_back(n);
        m[n]=n;
    }
    return {v,m};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    ll ans=0,cur;
    vector<pair<vector<int>,map<int,int>>> v;
    vector<int> lcmFactors;
    map<int,int> lcmPowers;
    cin>>n;
    for (int j=0;j<n;++j)
    {
        cin>>x;
        v.push_back(primeFactorisation(x));
        k=sz(v.back().first);
        for (int i=0;i<k;++i)
        {
            if (!lcmPowers[v.back().first[i]])
            {
                lcmFactors.push_back(v.back().first[i]);
            }
            lcmPowers[v.back().first[i]]=max(lcmPowers[v.back().first[i]],v.back().second[v.back().first[i]]);
            //cout<<lcmPowers[v.back().first[i]]<<" "<<v.back().second[v.back().first[i]]<<"\n";
            //cout<<v.back().first[i]<<" "<<lcmPowers[v.back().first[i]]<<"?\n";
        }
    }
    k=sz(lcmFactors);
    for (int i=0;i<n;++i)
    {
        cur=1;
        for (int j=0;j<k;++j)
        {
            cur*=lcmPowers[lcmFactors[j]]/max(v[i].second[lcmFactors[j]],1);
            //cout<<binpow(lcmFactors[j],lcmPowers[lcmFactors[j]]-v[i].second[lcmFactors[j]])<<"\n";
            //cout<<lcmFactors[j]<<" ^ "<<lcmPowers[lcmFactors[j]]-v[i].second[lcmFactors[j]]<<", cur = "<<cur<<" !\n";
            cur%=MOD;
        }
        ans+=cur;
    }
    cout<<ans%MOD;
    return 0;
}