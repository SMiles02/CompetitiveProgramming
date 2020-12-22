#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min(min(a,b),min(c,d));
    return 0;
}