#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int f[16];
int ans=0,checker=0;
map<int,int> done;

void works()
{
    for (int i=1;i<16;++i)
    {
        if (abs(f[f[i]]-2*(f[i])+i)%15)
        {
            return;
        }
    }
    ++ans;
    return;
}

void permutationGenerator(int cur)
{
    if (cur==16)
    {
        for (int i=1;i<16;++i)
        {
            cout<<f[i]<<" ";
        }
        cout<<"\n";
        ++checker;
        works();
        return;
    }
    for (int i=1;i<16;++i)
    {
        if (!f[i])
        {
            f[i]=cur;
            permutationGenerator(cur+1);
            f[i]=0;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    permutationGenerator(1);
    cout<<ans<<" "<<checker;
    return 0;
}