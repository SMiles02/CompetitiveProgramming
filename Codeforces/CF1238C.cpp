#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int h,n;
vector<int> p;

void solve()
{
    int ans=0;
    int cur=h;
    for (int i=1;i<n;++i)
    {
        //cout<<"cur="<<cur<<"\n";
        if (cur<3)
        {
            cout<<ans<<"\n";
            return;
        }
        if (cur>p[i])
        {
            if (cur-p[i]==1)
            {
                if (i==n-1)
                {
                    ++ans;
                    //cout<<"plussed at i="<<i<<"\n";
                    cout<<ans<<"\n";
                    return;
                }
                if (cur-p[i+1]>2)
                {
                    ++ans;
                    cur=p[i]-1;
                    //cout<<"plussed at i="<<i<<"\n";
                }
                else
                {
                    cur=p[i+1];
                }
            }
            else
            {
                if (i==n-1)
                {
                    ++ans;
                    cout<<ans<<"\n";
                    return;
                }
                if (p[i]-p[i+1]==1)
                {
                    cur=p[i+1];
                }
                else
                {
                    ++ans;
                    cur=p[i];
                }
            }
        }
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,k;
    cin>>q;
    while (q--)
    {
        cin>>h>>n;
        for (int i=0;i<n;++i)
        {
            cin>>k;
            p.push_back(k);
        }
        solve();
        p.clear();
    }
    return 0;
}