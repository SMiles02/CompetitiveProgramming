#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7;
int n, bit[N], A, B, C, D;
long long ans;
string s, t="ANOT";
vector<int> v[4];

void update(int i, int d)
{
    while (i<=n)
    {
        bit[i]+=d;
        i+=i&-i;
    }
}

int query(int i)
{
    int ret=0;
    while (i)
    {
        ret+=bit[i];
        i-=i&-i;
    }
    return ret;
}

void test(int a, int b, int c, int d)
{
    int tmp=0;
    long long cur=0;
    for (int i=1;i<=n;++i)
        bit[i]=0;
    for (int j : v[a])
    {
        ++tmp;
        cur+=j+query(j)-tmp;
        update(1,1);
        update(j,-1);
    }
    for (int j : v[b])
    {
        ++tmp;
        cur+=j+query(j)-tmp;
        update(1,1);
        update(j,-1);
    }
    for (int j : v[c])
    {
        ++tmp;
        cur+=j+query(j)-tmp;
        update(1,1);
        update(j,-1);
    }
    for (int j : v[d])
    {
        ++tmp;
        cur+=j+query(j)-tmp;
        update(1,1);
        update(j,-1);
    }
    if (cur>=ans)
    {
        A=a;
        B=b;
        C=c;
        D=d;
        ans=cur;
    }
}

void solve()
{
    cin>>s;
    n=s.size();
    ans=0;
    for (int i=0;i<4;++i)
        v[i].clear();
    for (int i=0;i<n;++i)
    {
        if (s[i]=='A')
            v[0].push_back(i+1);
        else if (s[i]=='N')
            v[1].push_back(i+1);
        else if (s[i]=='O')
            v[2].push_back(i+1);
        else
            v[3].push_back(i+1);
    }
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            if (j!=i)
                for (int k=0;k<4;++k)
                    if (k!=i&&k!=j)
                        for (int l=0;l<4;++l)
                            if (l!=i&&l!=j&&l!=k)
                                test(i,j,k,l);
    int e=sz(v[A]),f=sz(v[B]),g=sz(v[C]),h=sz(v[D]);
    while (e--)
        cout<<t[A];
    while (f--)
        cout<<t[B];
    while (g--)
        cout<<t[C];
    while (h--)
        cout<<t[D];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}