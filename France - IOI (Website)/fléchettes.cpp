#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans[51][51];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r;
    cin>>n;
    char c='a';
    for (int i=0;i<n;++i)
    {
        l=i;
        r=(2*n)-2-i;
        for (int j=l;j<=r;++j)
        {
            ans[l][j]=i;
            ans[j][l]=i;
            ans[r][j]=i;
            ans[j][r]=i;
        }
    }
    for (int i=0;i<2*n-1;++i)
    {
        for (int j=0;j<2*n-1;++j)
        {
            c='a';
            for (int k=0;k<ans[i][j];++k) ++c;
            cout<<c;
        }
        cout<<"\n";
    }
    return 0;
}