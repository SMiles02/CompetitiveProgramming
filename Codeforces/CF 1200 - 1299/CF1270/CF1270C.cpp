#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,sum,bitwiseXOR,k;
    cin>>n;
    cin>>sum;
    bitwiseXOR=sum;
    for (int i=1;i<n;++i)
    {
        cin>>k;
        sum+=k;
        bitwiseXOR^=k;
    }
    cout<<"2\n"<<bitwiseXOR<<" "<<sum+bitwiseXOR<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}