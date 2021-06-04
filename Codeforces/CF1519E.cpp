#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

const int N = 1e6;
int t,p[N];
map<array<int,2>,int> m;
vector<int> w={0},b={0};

int val(int a, int b)
{
    int x=gcd(a,b);
    a/=x;b/=x;
    if (m[{a,b}])
        return m[{a,b}];
    m[{a,b}]=++t;

    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,c,d;
    cin>>n;
    for (int i=1;i<=n;++i)
    {

    }
    return 0;
}