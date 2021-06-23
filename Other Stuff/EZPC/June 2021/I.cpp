#include <bits/stdc++.h>
using namespace std;

long long solve()
{
    long long a, b, c=0;
    cin>>a>>b;
    for (int i=0;i<60;++i)
    {
        if ((1LL<<i)&a)
            c^=(1LL<<i)*(1-(((1LL<<i)&b)!=0));
        else if ((1LL<<i)&b)
            return -1;
    }
    return c;
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