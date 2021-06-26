#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int n,k,m;

int num(int x, int y)
{
    return y+abs(x-k);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,tot=0,big=0;
    cin>>n>>k>>m;
    multiset<int,greater<int>> s;
    set<pair<int,int>> exists;
    s.insert(0);
    for (int i=0;i<m;++i)
    {
        cin>>x>>y;
        //cout<<num(x,y)<<"\n";
        if (exists.find({x,y})!=exists.end())
        {
            exists.erase(exists.lower_bound({x,y}));
            s.erase(s.lower_bound(num(x,y)));
            --tot;
            if (num(x,y)>n)
                --big;
        }
        else
        {
            exists.insert({x,y});
            s.insert(num(x,y));
            ++tot;
            if (num(x,y)>n)
                ++big;
        }
        cout<<*(s.begin())<<" "<<tot<<" "<<n+big<<"\n";
        cout<<max(*(s.begin()),max(tot,n+big))-n<<"\n";
    }
    return 0;
}