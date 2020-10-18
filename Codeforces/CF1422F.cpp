#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7;

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
    return res;
}

struct node()
{
    node *l,*r;
    ll val;
    node(node *l, node *r) : l(l) r(r) 
    {
        val=lcm(l->)
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    return 0;
}