#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> m;

void solve()
{
    m.clear();
    int n,x;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        ++m[((x%n)+n+i)%n];
        //cout<<((x%n)+n+i)%n<<" ";
    }
    //cout<<"\n";
    for (int i=0;i<n;++i)
        if (m[i]>1)
        {
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}