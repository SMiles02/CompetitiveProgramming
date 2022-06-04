#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,maxLength=0,ending,j;
    cin>>n;
    map<int,int> m;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        m[a[i]]=max(m[a[i]],m[a[i]-1]+1);
        if (m[a[i]]>maxLength)
        {
            maxLength=m[a[i]];
            ending=a[i];
        }
    }
    cout<<maxLength<<"\n";
    j=ending+1-maxLength;
    for (int i=0;i<n;++i)
    {
        if (a[i]==j)
        {
            cout<<i+1<<" ";
            ++j;
        }
    }
    return 0;
}