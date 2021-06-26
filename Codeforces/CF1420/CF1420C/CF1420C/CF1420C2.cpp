#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,q,l,r,x=0,y=0;
    ll score=0;
    cin>>n>>q;
    int a[n+2];
    a[0]=0;a[n+1]=0;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=2;i<n;++i)
    {
        if (a[i-1]<a[i]&&a[i]>a[i+1])
            score+=a[i];
        else if (a[i-1]>a[i]&&a[i]<a[i+1])
            score-=a[i];
    }
    if (n>1)
    {
        if (a[1]>a[2])
            x=a[1];
        if (a[n]>a[n-1])
            y=a[n];
    }
    else
        score=1;
    cout<<score+x+y<<"\n";
    while (q--)
    {
        cin>>l>>r;
        if (n>1)
        {
            for (int i=max(2,l-1);i<=min(n-1,min(l+1,r-2));++i)
            {
                if (a[i-1]<a[i]&&a[i]>a[i+1])
                    score-=a[i];
                if (a[i-1]>a[i]&&a[i]<a[i+1])
                    score+=a[i];
            }
            for (int i=max(2,r-1);i<=min(n-1,r+1);++i)
            {
                if (a[i-1]<a[i]&&a[i]>a[i+1])
                    score-=a[i];
                if (a[i-1]>a[i]&&a[i]<a[i+1])
                    score+=a[i];
            }
            swap(a[l],a[r]);
            for (int i=max(2,l-1);i<=min(n-1,min(l+1,r-2));++i)
            {
                if (a[i-1]<a[i]&&a[i]>a[i+1])
                    score+=a[i];
                if (a[i-1]>a[i]&&a[i]<a[i+1])
                    score-=a[i];
            }
            for (int i=max(2,r-1);i<=min(n-1,r+1);++i)
            {
                if (a[i-1]<a[i]&&a[i]>a[i+1])
                    score+=a[i];
                if (a[i-1]>a[i]&&a[i]<a[i+1])
                    score-=a[i];
            }
            if (a[1]>a[2])
                x=a[1];
            else
                x=0;
            if (a[n]>a[n-1])
                y=a[n];
            else
                y=0;
        }
        cout<<score+x+y<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}