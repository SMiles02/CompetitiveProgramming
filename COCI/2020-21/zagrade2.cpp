#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool dp[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    bool b;
    cin>>n>>q;
    string s, t(n/2,')'),u(n/2,'(');
    s=t+u;
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;j+=2)
        {
            cout<<"? "<<i+1<<" "<<j+1<<endl;
            cin>>b;
            dp[i][j]=b;
        }
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;j+=2)
            if (dp[i][j])
            {
                s[i]='(';
                s[j]=')';
            }
    cout<<"! "<<s<<endl;
    return 0;
}