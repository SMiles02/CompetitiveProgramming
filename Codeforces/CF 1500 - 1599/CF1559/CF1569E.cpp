#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int A;
map<int,vector<int>> m[2];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int sub(int a, int b)
{
    return add(a,MOD-b);
}

void solve(int n, vector<int> t, int id, int r1)
{
    vector<int> ans(n);
    for (int i=0;i<(1<<(n-1));++i)
    {
        int s = n, p = r1, cur = 0, x = i, y = n/2, z = n/2;
        vector<array<int,2>> v(n);
        for (int j=0;j<n;++j)
            v[j]={t[j],j};
        for (int j=1;j<s;j+=2)
        {
            if (x&1)
            {
                ans[v[j-1][1]]=p;
                cur=add(cur,mul(v[j-1][0],binpow(A,p)));
                v.push_back(v[j]);
            }
            else
            {
                ans[v[j][1]]=p;
                cur=add(cur,mul(v[j][0],binpow(A,p)));
                v.push_back(v[j-1]);
            }
            ++s;
            x>>=1;
            if (--y==0)
            {
                z/=2;
                y=z;
                p=p/2+1;
            }
        }
        if (r1==n/2+1)
            ans[v[s-1][1]]=1;
        else
            ans[v[s-1][1]]=2;
        cur=add(cur,mul(v[s-1][0],binpow(A,ans[v[s-1][1]])));
        m[id][cur]=ans;
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,h;
    cin>>k>>A>>h;
    vector<int> v;
    if (k<5)
    {
        v.resize(1<<k);
        iota(v.begin(), v.end(), 1);
        solve((1<<k), v, 0, (1<<(k-1))+1);
        if (!m[0][h].empty())
        {
            for (int i : m[0][h])
                cout<<i<<" ";
        }
        else
            cout<<-1;
        return 0;
    }
    v.resize(1<<(k-1));
    iota(v.begin(), v.end(), 1);
    solve((1<<(k-1)), v, 0, (1<<(k-1))+1);
    iota(v.begin(), v.end(), (1<<(k-1))+1);
    solve((1<<(k-1)), v, 1, (1<<(k-1))+1);
    for (auto i : m[1])
        for (int j=0;j<(1<<(k-1));++j)
            if (i.second[j]==2&&!m[0][sub(h,add(i.first,mul(j+1+(1<<(k-1)),sub(A,mul(A,A)))))].empty())
            {
                for (int x : m[0][sub(h,add(i.first,mul(j+1+(1<<(k-1)),sub(A,mul(A,A)))))])
                    cout<<x<<" ";
                for (int x=0;x<j;++x)
                    cout<<i.second[x]<<" ";
                cout<<"1 ";
                for (int x=j+1;x<(1<<(k-1));++x)
                    cout<<i.second[x]<<" ";
                return 0;
            }
    for (auto i : m[0])
        for (int j=0;j<(1<<(k-1));++j)
            if (i.second[j]==2&&!m[1][sub(h,add(i.first,mul(j+1,sub(A,mul(A,A)))))].empty())
            {
                for (int x=0;x<j;++x)
                    cout<<i.second[x]<<" ";
                cout<<"1 ";
                for (int x=j+1;x<(1<<(k-1));++x)
                    cout<<i.second[x]<<" ";
                for (int x : m[1][sub(h,add(i.first,mul(j+1,sub(A,mul(A,A)))))])
                    cout<<x<<" ";
                return 0;
            }
    cout<<-1;
    return 0;
}