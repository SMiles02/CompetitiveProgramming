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
    int n,k;
    cin>>n;
    string s;
    cin>>s;
    map<int,vector<int>> notSame;
    int a[n];
    map<int,int> ans;
    for (int i=0;i<n;++i)
    {
        a[i]=i;
    }
    for (int i=1;i<n;++i)
    {
        for (int j=i;j&&s[j]<s[j-1];--j)
        {
            //cout<<"swap "<<j<<" "<<j+1<<"\n";
            //cout<<s[j]<<" > "<<s[j-1]<<"\n";
            notSame[a[j]].push_back(a[j-1]);
            notSame[a[j-1]].push_back(a[j]);
            swap(s[j],s[j-1]);
            swap(a[j],a[j-1]);
        }
    }
    for (int i=0;i<n;++i)
    {
        k=sz(notSame[i]);
        if (k)
        {
            sort(notSame[i].begin(), notSame[i].end());
            if (notSame[i][0]<i)
            {
                ans[i]=3-ans[notSame[i][0]];
                for (int j=1;j<k&&notSame[i][j]<i;++j)
                {
                    if (ans[i]==ans[notSame[i][j]])
                    {
                        cout<<"NO\n";
                        return 0;
                    }
                }
            }
            else
            {
                ans[i]=1;
            }
        }
        else
        {
            ans[i]=1;
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;++i)
    {
        cout<<ans[i]-1;
    }
    return 0;
}