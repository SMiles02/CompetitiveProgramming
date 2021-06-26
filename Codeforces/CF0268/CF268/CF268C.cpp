#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,y;
    cin>>n>>m;
    y=min(n,m);
    cout<<y+1<<"\n";
    for (int i=0;i<=y;++i)
    {
    	cout<<i<<" "<<y-i<<"\n";
    }
    return 0;
}