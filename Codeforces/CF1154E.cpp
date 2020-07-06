#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans[200000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,done=0;
    cin>>n>>k;
    vector<pair<int,int>> v;
    multiset<int> m;
    multiset<int>::iterator it;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v.push_back({x,i});
        m.insert(i);
    }
    sort(v.begin(), v.end());
    for (int turn=0;done<n;++turn)
    {
        while (ans[v.back().second])
            v.pop_back();
        ++done;
        if (turn%2)
            x=2;
        else
            x=1;
        ans[v.back().second]=x;
        for (int check=0;*m.begin()<v.back().second&&check<k;++check)
        {
            it=m.find(v.back().second);
            --it;
            ans[*it]=x;
            m.erase(it);
            ++done;
        }
        for (int check=0;m.upper_bound(v.back().second)!=m.end()&&check<k;++check)
        {
            it=m.upper_bound(v.back().second);
            ans[*it]=x;
            m.erase(it);
            ++done;
        }
        it=m.find(v.back().second);
        m.erase(it);
    }
    for (int i=0;i<n;++i)
        cout<<ans[i];
    return 0;
}