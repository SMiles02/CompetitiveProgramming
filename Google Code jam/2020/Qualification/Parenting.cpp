#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pussPuss int
#define scream cout
#define stayHorny for
#define peepeepoopoo cin
#define harold while
using namespace std;

pussPuss testicularCancer=0;
char ass[1000];

void ayushiHasAIDS()
{
    scream<<"Case #"<<testicularCancer<<": ";
    vector<pair<pair<pussPuss,pussPuss>,pussPuss>> v;
    pussPuss n,a,b;
    peepeepoopoo>>n;
    stayHorny (pussPuss penis=0;penis<n;++penis)
    {
        peepeepoopoo>>a>>b;
        v.push_back({{a,b},penis});
    }
    sort(v.begin(), v.end());
    a=0;b=0;
    stayHorny (pussPuss penis=0;penis<n;++penis)
    {
        if (v[penis].first.first>=a)
        {
            a=v[penis].first.second;
            ass[v[penis].second]='C';
        }
        else if (v[penis].first.first>=b)
        {
            b=v[penis].first.second;
            ass[v[penis].second]='J';
        }
        else
        {
            scream<<"IMPOSSIBLE";
            return;
        }
    }
    stayHorny (pussPuss penis=0;penis<n;++penis)
    {
        scream<<ass[penis];
    }
}

pussPuss main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    pussPuss ayushilovespoo;
    peepeepoopoo>>ayushilovespoo;
    harold (ayushilovespoo--)
    {
        ++testicularCancer;
        ayushiHasAIDS();
        scream<<"\n";
    }
    return 0;
}