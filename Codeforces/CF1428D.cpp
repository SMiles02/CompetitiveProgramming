#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    set<int> threes,twos,threesOnly;
    vector<pair<int,int>> ans;
    for (int i=n;i;--i)
    {
        if (a[i]==0)
            continue;            
        if (a[i]==1)
        {
            twos.insert(i);
            threes.insert(i);
            ans.push_back({i,i});
        }
        else if (a[i]==2)
        {
            if (twos.empty())
            {
                cout<<"-1\n";
                return 0;
            }
            x=*(--twos.end());
            twos.erase(twos.lower_bound(x));
            if (threes.find(x)!=threes.end())
                threes.erase(threes.lower_bound(x));
            threesOnly.insert(i);
            ans.push_back({x,i});
        }
        else
        {
            if (!threesOnly.empty())
            {
                x=*(--threesOnly.end());
                threesOnly.erase(threesOnly.lower_bound(x));
            }
            else if (!threes.empty())
            {
                x=*(--threes.end());
                threes.erase(threes.lower_bound(x));
                if (twos.find(x)!=twos.end())
                    twos.erase(twos.lower_bound(x));
            }
            else
            {
                cout<<"-1\n";
                return 0;
            }
            threesOnly.insert(i);
            ans.push_back({i,i});
            ans.push_back({i,x});
        }
    }
    cout<<ans.size()<<"\n";
    for (auto i : ans)
        cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}