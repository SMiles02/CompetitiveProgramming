#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,cur;
    cin>>n;
    cur=n;
    cout<<"2\n";
    for (int i=n-1;i;--i)
    {
        cout<<cur<<" "<<i<<"\n";
        cur=(cur+i+1)/2;
    }
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