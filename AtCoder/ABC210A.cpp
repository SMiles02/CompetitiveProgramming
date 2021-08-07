#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,x,y;
    cin>>n>>a>>x>>y;
    cout<<min(a,n)*x+max(n-a,0LL)*y;
    return 0;
}