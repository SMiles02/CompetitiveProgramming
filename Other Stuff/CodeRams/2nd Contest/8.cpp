#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 800, ed = 9602443;
array<int,2> pt[mn][mn];
int n,rk[mn][mn],primes[640001];
ll pre[640001];
string s[800];
bitset<ed> sieve;
bitset<mn> isLead[mn];

array<int,2> find_set(int x, int y) {
    if (pt[x][y][0]==x&&pt[x][y][1]==y)
        return {x,y};
    return pt[x][y] = find_set(pt[x][y][0],pt[x][y][1]);
}
 
void make_set(int v) {
    for (int i=0;i<v;++i)
        for (int j=0;j<v;++j)
        {
            pt[i][j] = {i,j};
            rk[i][j] = 1;
            isLead[i][j]=1;
        }
}
 
void unite(int a, int b, int c, int d) {
    array<int,2> x = find_set(a,b), y = find_set(c,d);
    if (x != y) {
        if (rk[x[0]][x[1]] < rk[y[0]][y[1]])
            swap(x, y);
        pt[y[0]][y[1]] = x;
        isLead[y[0]][y[1]]=0;
        rk[x[0]][x[1]] += rk[y[0]][y[1]];
    }
}

void genPrime()
{
    int c=0;
    primes[++c]=1;
    pre[c]=pre[c-1]+primes[c];
    primes[++c]=2;
    pre[c]=pre[c-1]+primes[c];
    for (int i=3;i<ed;i+=2)
        if (!sieve[i])
        {
            primes[++c]=i;
            pre[c]=pre[c-1]+primes[c];
            for (int j=i*3;j<ed;j+=i*2)
                sieve[j]=1;
        }
}

bool ok(int x, int y)
{
    if (0<=x&&0<=y&&x<n&&y<n&&s[x][y]=='.')
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    ll ans=0;
    genPrime();
    for (int i=0;i<n;++i)
        cin>>s[i];
    make_set(n);
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (ok(i,j))
            {
                if (ok(i-1,j))
                    unite(i,j,i-1,j);
                if (ok(i,j-1))
                    unite(i,j,i,j-1);
            }
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            if (ok(i,j)&&isLead[i][j])
                ans+=pre[rk[i][j]];
    cout<<ans;
    return 0;
}