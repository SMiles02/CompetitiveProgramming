#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 5e5+1;
int f[N],g[N],h[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,k,n,s,x,u=0,ans;
    cin>>m>>k>>n>>s;
    vector<int> a(m);
    for (int i=0;i<m;++i)
        cin>>a[i];
    for (int i=0;i<s;++i)
    {
        cin>>x;
        if (++f[x]==1)
            ++u;
    }
    x=0;
    for (int i=0;i<m&&u>0;++i)
    {
        x=i;
        if (++g[a[i]]==f[a[i]])
            --u;
    }
    if (u==0&&n*k<=m-max(x+1-k,0))
    {
        //cout<<"yee\n";
        ans=max(x+1-k,0);
        cout<<ans<<"\n";
        for (int i=0;i<=x&&ans>0;++i)
            if (++h[a[i]]>f[a[i]])
            {
                cout<<i+1<<" ";
                --ans;
            }
        return 0;
    }
    for (int i=1;i<m;++i)
    {
        if (g[a[i-1]]--==f[a[i-1]])
            ++u;
        if (u>0)
            for (++x;x<m&&u>0;++x)
            {
                if (++g[a[x]]==f[a[x]])
                    --u;
                if (u==0)
                    break;
            }
        //cout<<i<<": "<<x<<" "<<u<<"\n";
        //cout<<m<<" "<<x-i+1-k<<" "<<(i%k)<<"\n";
        //cout<<m-max(x-i+1-k,0)-(i%k)<<"\n";
        if (u==0&&n*k<=m-max(x-i+1-k,0)-(i%k))
        {
            //cout<<i<<" "<<x<<"!\n";
            ans=max(x-i+1-k,0);
            cout<<ans+(i%k)<<"\n";
            for (int j=0;j<(i%k);++j)
                cout<<j+1<<" ";
            for (int j=i;j<=x&&ans>0;++j)
                if (++h[a[j]]>f[a[j]])
                {
                    cout<<j+1<<" ";
                    --ans;
                }
            return 0;
        }
    }
    cout<<-1;
    return 0;
}