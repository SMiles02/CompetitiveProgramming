#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
int largestDivisor[500001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=2;i<=n;++i)
    {
        for (int j=i*2;j<=n;j+=i)
        {
            largestDivisor[j]=i;
        }
        v.push_back(max(1,largestDivisor[i]));
    }
    sort(v.begin(), v.end());
    for (int i=0;i<n-1;++i)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}