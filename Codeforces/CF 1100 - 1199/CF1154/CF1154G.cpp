#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e7+1;
int x[N][2], min_prime[N];
vector<array<int, 2>> factorisation;
  
void build_sieve()
{
    vector<int> pr;
    for (int i=2; i<N; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j<sz(pr) && pr[j] <= min_prime[i] && i * pr[j] < N; ++j)
            min_prime[i * pr[j]] = pr[j];
    }
}

void rec(int pos, int cur, int org) {
    if (pos == sz(factorisation)) {
        if (x[cur][0] == 0 || org < x[cur][0])
        {
            x[cur][1] = x[cur][0];
            x[cur][0] = org;
        }
        else if (x[cur][1] == 0 || org < x[cur][1])
            x[cur][1] = org;
        return;
    }
    int cur_mul = 1;
    for (int i = 0; i <= factorisation[pos][1]; ++i) {
        rec(pos + 1, cur * cur_mul, org);
        cur_mul *= factorisation[pos][0];
    }
}

void get_factors(int num) {
    factorisation.clear();
    int org = num;
    while (num > 1) {
        if (!factorisation.empty() && min_prime[num] == factorisation.back()[0])
            ++factorisation.back()[1];
        else
            factorisation.push_back({min_prime[num], 1});
        num /= min_prime[num];
    }
    rec(0, 1, org);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    build_sieve();
    int n,id;
    long long ans=1e18;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        get_factors(a[i]);
    }
    for (int i=1;i<N;++i)
        if (x[i][1]>0&&(1LL*x[i][0]*x[i][1])/i<ans)
        {
            ans=(1LL*x[i][0]*x[i][1])/i;
            id=i;
        }
    for (int i=0;i<n;++i)
        if (a[i]==x[id][0])
            for (int j=n-1;j>=0;--j)
                if (a[j]==x[id][1])
                {
                    cout<<min(i,j)+1<<" "<<max(i,j)+1<<"\n";
                    return 0;
                }
    return 0;
}