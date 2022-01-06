// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int n,m;
vector<int> dx = {0,0,-1,1}, dy = {-1,1,0,0};

bool ok(int x, int y)
{
    return (0<=x&&x<n&&0<=y&&y<m);
}

void solve() {
    int x,y,tX,tY,ct;
    cin>>n>>m;
    vector<string> s(n);
    vector<vector<bool>> f(n, vector<bool>(m));
    queue<array<int,2>> q;
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='L')
                q.push({i,j});
    while (!q.empty())
    {
        x=q.front()[0];
        y=q.front()[1];
        q.pop();
        ct=0;
        for (int i=0;i<4;++i)
        {
            tX=x+dx[i];
            tY=y+dy[i];
            if (ok(tX,tY)&&s[tX][tY]!='#'&&s[tX][tY]!='L'&&!f[tX][tY])
                ++ct;
        }
        if (ct<2||s[x][y]=='L')
            f[x][y]=1;
        else
            continue;
        for (int i=0;i<4;++i)
        {
            tX=x+dx[i];
            tY=y+dy[i];
            if (ok(tX,tY)&&s[tX][tY]=='.'&&!f[tX][tY])
            {
                q.push({tX,tY});
                // cerr<<tX<<" "<<tY<<" "<<x<<" "<<y<<"\n";
            }
        }
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
        {
            if (s[i][j]=='.'&&f[i][j])
                cout<<"+";
            else
                cout<<s[i][j];
        }
        cout<<"\n";
    }
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}