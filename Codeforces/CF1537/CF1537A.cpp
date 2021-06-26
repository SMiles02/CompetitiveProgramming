#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,s=0,x;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        s+=x;
    }
    if (s<n)
        cout<<"1\n";
    else if (s==n)
        cout<<"0\n";
    else
        cout<<s-n<<"\n";
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