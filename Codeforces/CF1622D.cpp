#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 5001;
int f[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

int sub(int a, int b) { return add(a,MOD-b); }

int C(int n, int k) { return dv(f[n],mul(f[k],f[n-k])); }

void calc_factorials() {
    f[0]=1;
    for (int i=1;i<N;++i) f[i]=mul(f[i-1],i);
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n,k,m,ans=1,ct;
    cin>>n>>k;
    string s;
    cin>>s;
    if (k==0)
    {
        cout<<1;
        return 0;
    }
    if (k==1)
    {
        for (int i=0;i<n;++i)
            if (i==0||(i>0&&s[i-1]=='1'))
            {
                ct=0;
                for (int j=i;j<n;++j)
                    if (s[j]=='1')
                        if (ct++==k)
                            ans=add(ans,sub(C(j-i,k),1));
                if (ct==k)
                    ans=add(ans,sub(C(n-i,k),1));
            }
    }
    else
    {
        vector<array<int,3>> v;
        for (int i=0;i<n;++i)
            if (s[i]=='1')
            {
                if (v.empty())
                    v.push_back({0,i,n-1});
                else
                {
                    v.back()[2]=i-1;
                    v.push_back({v.back()[1]+1,i,n-1});
                }
            }
        m=v.size();
        if (m<k)
        {
            cout<<1;
            return 0;
        }
        ans=0;
        for (int i=k-1;i<m;++i)
            ans=add(ans,sub(C(v[i][2]-v[i-k+1][0]+1,k),0));
        for (int j=1;j<2;++j)
            for (int i=k-1+j;i<m;++i)
            {
                if (j&1)
                    ans=sub(ans,sub(C(v[i-j][2]-v[i-k+1][0]+1,k-j),0));
                else
                    ans=add(ans,sub(C(v[i-j][2]-v[i-k+1][0]+1,k-j),0));
            }
    }
    cout<<ans;
    return 0;
}