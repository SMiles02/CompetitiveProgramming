#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,x=0,y=0;
    cin>>n;
    map<pair<int,int>,pair<int,int>> m;
    int a[3];
    for (int i=1;i<=n;++i)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if (a[0]>ans)
        {
            ans=a[0];
            x=i;y=0;
        }
        for (int p=0;p<3;++p)
            for (int q=0;q<3;++q)
                for (int r=0;r<3;++r)
                    if (p!=q&&q!=r&&r!=p&&p<q)
                    {
                        //cout<<i<<" "<<p<<" "<<q<<" "<<r<<": "<<min(m[{min(a[p],a[q]),max(a[p],a[q])}].first+a[r],min(a[p],a[q]))<<"\n";
                        if (min(m[{min(a[p],a[q]),max(a[p],a[q])}].first+a[r],min(a[p],a[q]))>ans)
                        {
                            ans=min(m[{min(a[p],a[q]),max(a[p],a[q])}].first+a[r],min(a[p],a[q]));
                            x=i;y=m[{a[p],a[q]}].second;
                        }
                        if (a[r]>m[{min(a[p],a[q]),max(a[p],a[q])}].first)
                            m[{min(a[p],a[q]),max(a[p],a[q])}]={a[r],i};
                    }
    }
    //cout<<"ans="<<ans<<"\n";
    if (y==0)
        cout<<"1\n"<<x;
    else
        cout<<"2\n"<<x<<" "<<y;
    return 0;
}