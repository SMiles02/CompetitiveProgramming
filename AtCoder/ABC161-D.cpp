#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans=0,s=8;

void permutations(vector<int> v, int cur)
{
    if (cur==s)
    {
        v.push_back(9);
        for (int i=0;i<s;++i)
        {
            if (abs(v[i]-v[i+1])>1)
            {
                return;
            }
        }
        ++ans;
        return;
    }
    for (int i=10-s-1;i<10;++i)
    {
        v.push_back(i);
        permutations(v,cur+1);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> v;
    permutations(v,0);
    cout<<ans;
    return 0;
}