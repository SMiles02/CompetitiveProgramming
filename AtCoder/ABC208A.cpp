#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin>>a>>b;
    if (a<=b&&b<=a*6)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}