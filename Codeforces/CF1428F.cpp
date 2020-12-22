#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=(1<<19);
int bit[maxn];

void update(int i, int x)
{
    while (i<maxn)
    {
        bit[i]+=x;
        i+=(i&(-i));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k=0,x,y,z=-1;
    ll ans=0,cur=0;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (__builtin_popcount(i+1)==1)
            ++z;
        if (s[i]=='0')
        {
            k=0;
            ans+=cur;
            continue;
        }
        ++k;
        x=0;y=0;
        for (int i=z;i>=0;--i)
            if (x+bit[y+(1<<i)]>=k)
            {
                y+=(1<<i);
                x+=bit[y];
            }
        cur+=i+1-y;
        ans+=cur;
        update(y+1,1);
        update(i+2,-1);
    }
    cout<<ans;
    return 0;
}