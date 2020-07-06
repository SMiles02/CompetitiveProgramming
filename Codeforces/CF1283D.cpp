#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> v;
int m;

void printAll()
{
    for (int i=0;i<m;++i)
    {
        cout<<v[i]<<" ";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,done=0;
    ll ans=0;
    cin>>n>>m;
    int a[n];
    vector<pair<int,pair<int,int>>> possible;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    possible.push_back({100000,{a[0],-1}});
    possible.push_back({100000,{a[n-1],1}});
    for (int i=0;i<n-1;++i)
    {
        possible.push_back({(a[i+1]-a[i]-1)/2,{a[i],1}});
    }
    for (int i=1;i<n;++i)
    {
        possible.push_back({(a[i]-a[i-1]-1)-((a[i]-a[i-1]-1)/2),{a[i],-1}});
    }
    sort(possible.rbegin(), possible.rend());
    for (int i=1;1;++i)
    {
        while (possible.back().first-i<0)
        {
            possible.pop_back();
        }
        k=sz(possible);
        for (int j=0;j<k;++j)
        {
            ans+=i;
            v.push_back((possible[j].second).first+((possible[j].second).second*i));
            ++done;
            if (done==m)
            {
                cout<<ans<<"\n";
                printAll();
                return 0;
            }
        }
    }
    return 0;
}