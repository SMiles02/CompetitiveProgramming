#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[100000];
int ideal[100001];
int ans[100001];

void solve()
{
    int n,cur=1;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ideal[a[i]]=i;
        ans[i]=0;
    }
    while (cur<=n)
    {
        if (ans[ideal[cur]])
        {
            cout<<"No\n";
            return;
        }
        ans[ideal[cur]]=cur;
        ++cur;
        for (int i=ideal[cur-1]+1;i+1<n&&ans[i]==0;++i)
        {
            if (ideal[cur]!=i)
            {
                cout<<"No\n";
                return;
            }
            ans[i]=cur;
            ++cur;
        }
    }
    cout<<"Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--) solve();
    return 0;
}