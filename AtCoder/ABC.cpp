#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    swap(x,y);
    swap(x,z);
    cout<<x<<" "<<y<<" "<<z;
    return 0;
}