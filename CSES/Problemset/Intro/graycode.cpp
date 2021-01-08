#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> v = {0};
    for (int i=0;i<n;++i)
        for (int j=(1<<i)-1;~j;--j)
            v.push_back(v[j]^1<<i);
    for (int i : v)
    {
        for (int j=(n-1);~j;--j)
            cout<<(i>>j&1);
        cout<<"\n";
    }
    return 0;
}   