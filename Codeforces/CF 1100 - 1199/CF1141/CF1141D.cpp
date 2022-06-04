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
    int n,k;
    string s,t,alpha="abcdefghijklmnopqrstuvwxyz";
    map<char,vector<int>> M1;
    map<char,vector<int>> M2;
    vector<pair<int,int>> ans;
    vector<int> v;
    vector<int> w;
    cin>>n;
    cin>>s;
    cin>>t;
    for (int i=0;i<n;++i)
    {
        M1[s[i]].push_back(i+1);
        M2[t[i]].push_back(i+1);
    }
    for (int i=0;i<26;++i)
    {
        while (sz(M1[alpha[i]])&&sz(M2[alpha[i]]))
        {
            ans.push_back({M1[alpha[i]].back(),M2[alpha[i]].back()});
            M1[alpha[i]].pop_back();
            M2[alpha[i]].pop_back();
        }
        while (sz(M1[alpha[i]])&&sz(M2['?']))
        {
            ans.push_back({M1[alpha[i]].back(),M2['?'].back()});
            M1[alpha[i]].pop_back();
            M2['?'].pop_back();
        }
        while (sz(M2[alpha[i]])&&sz(M1['?']))
        {
            ans.push_back({M1['?'].back(),M2[alpha[i]].back()});
            M2[alpha[i]].pop_back();
            M1['?'].pop_back();
        }
    }
    while (sz(M2['?'])&&sz(M1['?']))
    {
        ans.push_back({M1['?'].back(),M2['?'].back()});
        M2['?'].pop_back();
        M1['?'].pop_back();
    }
    k=sz(ans);
    cout<<k<<"\n";
    for (int i=0;i<k;++i)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
    return 0;
}