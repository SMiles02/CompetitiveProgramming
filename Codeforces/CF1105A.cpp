#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t=1,mini=1000000000,cur=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=1;i<101;++i)
    {
        cur=0;
        for (int j=0;j<n;++j)
        {
            cur+=min(abs(i-a[j]),min(abs(i+1-a[j]),abs(i-1-a[j])));
        }
        if (cur<=mini)
        {
            mini=cur;
            t=i;
        }
    }
    cout<<t<<" "<<mini;
    return 0;
}