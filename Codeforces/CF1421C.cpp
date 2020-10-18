#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int n=sz(s);
    cout<<"4\n";
    cout<<"R 2\n";
    n+=(n-2);
    cout<<"L 2\n";
    ++n;
    cout<<"R 2\n";
    n+=(n-2);
    cout<<"R "<<n-1<<"\n";
    return 0;
}