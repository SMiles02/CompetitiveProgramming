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
    int d,sumTime,minTime=0,maxTime=0,a,b;
    cin>>d>>sumTime;
    vector<pair<int,int>> v;
    for (int i=0;i<d;++i)
    {
        cin>>a>>b;
        minTime+=a;
        maxTime+=b;
        v.push_back({a,b-a});
    }
    if (!(minTime<=sumTime&&sumTime<=maxTime))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (int i=0;i<d;++i)
    {
        if (minTime+v[i].second>sumTime)
        {
            cout<<v[i].first+sumTime-minTime<<" ";
            minTime=sumTime;
        }
        else
        {
            cout<<v[i].second+v[i].first<<" ";
            minTime+=v[i].second;
        }
    }
    return 0;
}