#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int MAXN=1e6+1;
//int a[MAXN],inp[MAXN];
vector<int> factors[MAXN];

void PowerOn(int N, int on[], int button[])
{
    for (int i=1;i<=N;++i)
        for (int j=i;j<=N;j+=i)
            factors[j].push_back(i);
    for (int i=N;i;--i)
    {
        if (!on[i])
        {
            button[i]=1;
            for (int j : factors[i])
                on[j]^=1;
        }
        else
            button[i]=0;
    }
} 

/**int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>inp[i];
    PowerOn(n,inp,a);
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}**/