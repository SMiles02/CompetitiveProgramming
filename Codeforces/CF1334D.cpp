#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    ll n,l,r,done=0,cur=1,partner,first;
    int total;
    cin>>n>>l>>r;
    total=r-l+1;
    if (l==n*(n-1)+1)
    {
        cout<<1<<"\n";
        return;
    }
    while (l>done)
    {
        done+=((n-cur)*2);
        ++cur;
    }
    --cur;
    done-=((n-cur)*2);
    first=l-done;
    partner=cur+((first+1)/2);
    if (first%2==0)
    {
        cout<<partner<<" ";
        ++partner;
        --total;
    }
    for (;partner<=n&&total;++partner)
    {
        if (total==1)
        {
            cout<<cur<<"\n";
            return;
        }
        cout<<cur<<" "<<partner<<" ";
        total-=2;
    }
    for (++cur;cur<=n&&total;++cur)
    {
        for (partner=cur+1;partner<=n&&total;++partner)
        {
            if (total==1)
            {
                cout<<cur<<"\n";
                return;
            }
            cout<<cur<<" "<<partner<<" ";
            total-=2;
        }
    }
    if (total==1)
    {
        cout<<1;
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}