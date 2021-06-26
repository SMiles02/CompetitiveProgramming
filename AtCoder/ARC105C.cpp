#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int INF = 1e8;
int n,m,a[8];
pii bridges[100000];

bool check(int k)
{
    int l=0,r=m-1,mid;
    ll s=0;
    //cout<<"k="<<k<<"\n";
    while (l<r)
    {
        mid=l+(r-l)/2+1;
        if (k<=bridges[mid].f)
            l=mid;
        else
            r=mid-1;
    }
    //cout<<"segLength = "<<bridges[l].f<<"\n";
    l=0;r=-1;
    for (int i=0;i<n;++i)
    {
        s+=a[i];
        while ((r-l)*k>=bridges[l].f)
        {
            s-=a[l];
            ++l;
        }
        if (s>bridges[l].s)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int maxi=0,ans=INF,l,r,mid,R=0;
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    for (int i=0;i<m;++i)
    {
        cin>>bridges[i].f>>bridges[i].s;
        if (bridges[i].s<maxi)
        {
            cout<<-1;
            return 0;
        }
        R=max(R,bridges[i].s);
    }
    sort(bridges,bridges+m);
    for (int i=m-2;i>=0;--i)
        bridges[i].s=max(bridges[i].s,bridges[i+1].s);
    sort(a,a+n);
    do
    {
        /**for (int i=0;i<n;++i)
            cout<<a[i]<<" ";
        cout<<"\n";**/
        l=0;r=bridges[m-1].f;
        while (l<r)
        {
            mid=l+(r-l)/2;
            if (check(mid))
                r=mid;
            else
                l=mid+1;
        }
        ans=min(ans,l);
    } while (next_permutation(a, a + n));
    cout<<ans;
    return 0;
}