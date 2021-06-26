#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,j;
    ll k,c;
    cin>>n;
    vector<pair<int,ll>> v;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        c=1;
        for (j=1;j<39;++j)
        {
            c*=3;
            if (k%c)
            {
                break;
            }
        }
        v.push_back(make_pair(40-(j-1),k));
        //cout<<j-1<<" "<<k<<"\n";
    }
    sort(v.begin(), v.end());
    for (int i=0;i<n;++i)
    {
        cout<<v[i].second<<" ";
    }
    return 0;
}