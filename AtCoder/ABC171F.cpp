#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

int n,ans=0;
string a="abcdefghijklmnopqrstuvwxyz";

void perms(string s)
{
    if (sz(s)==n)
    {
        for (auto c : s)
            if (c=='a')
            {
                ++ans;
                break;
            }
        return;
    }
    for (char c : a)
        perms(s+c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    perms("");
    cout<<ans;
    return 0;
}