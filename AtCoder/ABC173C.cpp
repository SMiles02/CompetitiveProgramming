#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int h,w,k;
string s[6];
vector<set<int>> rows;
vector<set<int>> cols;

void permGen(int cur, set<int> se, bool b)
{
    if (b)
    {
        if (cur==h)
        {
            rows.push_back(se);
            return;
        }
    }
    else
    {
        if (cur==w)
        {
            cols.push_back(se);
            return;
        }
    }
    permGen(cur+1,se,b);
    se.insert(cur);
    permGen(cur+1,se,b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>h>>w>>k;
    for (int i=0;i<h;++i)
        cin>>s[i];
    set<int> se;
    int ans=0,cur;
    permGen(0,se,1);
    permGen(0,se,0);
    for (auto i : rows)
        for (auto j : cols)
        {
            cur=0;
            for (int x=0;x<h;++x)
                for (int y=0;y<w;++y)
                    if (i.find(x)==i.end())
                        if (j.find(y)==j.end())
                            if (s[x][y]=='#')
                                ++cur;
            if (cur==k)
                ++ans;
        }
    cout<<ans;
    return 0;
}