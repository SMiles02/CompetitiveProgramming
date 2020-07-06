#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<pair<int,ll>> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,d,m,s,i,j,k;
    ll ans,cur;
    map<int,int> a;
    cin>>n>>d;
    for (i=0;i<n;++i)
    {
        cin>>m>>s;
        if (a[m])
        {
            v[a[m]-1].second+=s;
        }
        else
        {
            v.push_back(make_pair(m,s));
            a[m]=sz(v);
        }
    }
    k=v.size();
    sort(v.begin(), v.end());
    ans=v[0].second;
    for (j=1;j<k;++j)
    {
        //cout<<"here, j: "<<j<<"\n";
        if (v[j].first<v[0].first+d)
        {
            ans+=v[j].second;
        }
        else
        {
            break;
        }
    }
    cur=ans;
    for (i=1;i<k;++i)
    {
        cur-=v[i-1].second;
        for (j=j;j<k;++j)
        {
            //cout<<"j: "<<j<<"\n";
            if (v[j].first<v[i].first+d)
            {
                cur+=v[j].second;
            }
            else
            {
                break;
            }
        }
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}