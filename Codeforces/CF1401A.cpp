#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n,k;
    cin>>n>>k;
    if (n<k)
        return k-n;
    return ((n^k)&1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        cout<<solve()<<"\n";
    return 0;
}