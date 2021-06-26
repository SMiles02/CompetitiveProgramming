#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,v;
    cin>>n>>v;
    if (n-1<=v)
    {
        cout<<n-1;
        return 0;
    }
    //cout<<v-1<<" "<<(((n-v)*(n-v+1))/2)<<"\n";
    cout<<v-1+(((n-v)*(n-v+1))/2);
    return 0;
}