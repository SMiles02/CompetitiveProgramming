#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool inp[200000];

void solve()
{
    int n,T,a,b,k,ans=0,t=0,done=0,x,easy=0,hard=0;
    cin>>n>>T>>a>>b;
    multiset<pair<int,int>> s;
    multiset<pair<int,int>>::iterator it;
    for (int i=0;i<n;++i)
    {
        cin>>inp[i];
        if (inp[i]) ++hard;
        else ++easy;
    }
    for (int i=0;i<n;++i)
    {
        cin>>k;
        s.insert({k,inp[i]});
    }
    while (t<=T)
    {
        if (sz(s)==0)
        {
            cout<<n<<"\n";
            return;
        }
        it=s.begin();
        if ((*it).first>t)
        {
            k=(*it).first-t-1;
            x=min(easy,k/a);
            k-=(min(easy,k/a)*a);
            x+=min(hard,k/b);
            ans=max(ans,done+x);
        }
        if ((*it).second)
        {
            --hard;
            t+=b;
        }
        else
        {
            --easy;
            t+=a;
        }
        s.erase(it);
        ++done;
    }
    cout<<ans<<"\n";
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