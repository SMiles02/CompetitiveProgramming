#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,ans=0;

int prod(int x)
{
    int k=1;
    while (x)
    {
        k*=(x%10);
        x/=10;
    }
    return k;
}

void check(vector<int> v)
{
    int x=0;
    for (int i=sz(v)-1;i>=0;--i)
    {
        x*=10;
        x+=v[i];
    }
    if (x<=n)
        ans=max(ans,prod(x));
}

vector<int> uni;

void perm(vector<int> v)
{
    if (sz(v)==sz(uni))
    {
        check(v);
        return;
    }
    vector<int> w={uni[sz(v)],9,8};
    if (uni[sz(v)]>0)
        w.push_back(uni[sz(v)]-1);
    for (int i : w)
    {
        v.push_back(i);
        perm(v);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int k=n;
    while (k)
    {
        uni.push_back(k%10);
        k/=10;
    }
    perm({});
    cout<<ans;
    return 0;
}