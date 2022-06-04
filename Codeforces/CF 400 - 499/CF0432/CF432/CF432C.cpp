#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int sieve[100001];

void sieveBuild()
{
    for (int i=2;i<100001;++i)
    {
        if (!sieve[i])
        {
            for (int j=i*2;j<=100001;j+=i)
                sieve[j]=1;
            sieve[i]=i;
        }
        else sieve[i]=sieve[i-1];
    }
}

int numToIndex[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieveBuild();
    int n,k,p;
    cin>>n;
    vector<pair<int,int>> ans;
    int sorted[n];
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        sorted[i]=a[i];
        numToIndex[a[i]]=i;
    }
    sort(sorted,sorted+n);
    for (int i=0;i<n;++i)
    {
        while (a[i]!=sorted[i])
        {
            p=numToIndex[sorted[i]];
            k=sieve[p-i+1];
            swap(a[p],a[p-k+1]);
            numToIndex[a[p]]=p;
            numToIndex[a[p-k+1]]=p-k+1;
            ans.push_back({p+1,p-k+2});
        }
    }
    n=sz(ans);
    cout<<n<<"\n";
    for (int i=0;i<n;++i) cout<<min(ans[i].first,ans[i].second)<<" "<<max(ans[i].first,ans[i].second)<<"\n";
    return 0;
}