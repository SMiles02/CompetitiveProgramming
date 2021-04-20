#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool btwn(ll a, ll b, ll c)
{
    return (min({a,b})<c&&c<max({a,b}));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll x[n],y[n];
    ll A1,A2,B1,B2,C1,C2,D,X,Y;
    for (int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    ll ans=0;
    bool ok;
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
            {
                ok=1;
                for (int k=0;k<n;++k)
                    for (int l=0;l<n;++l)
                        if (k!=l)
                        {
                            A1=y[i]-y[j];
                            B1=x[j]-x[i];
                            C1=A1*x[i]+B1*y[i];
                            A2=y[k]-y[l];
                            B2=x[l]-x[k];
                            C2=A2*x[l]+B2*y[k];
                            D=A1*B2-A2*B1;
                            if (D!=0)
                            {
                                X=B2*C1-B1*C2;
                                Y=A1*C2-A2*C1;
                                if (btwn(x[i]*D,x[j]*D,X)&&btwn(y[i]*D,y[j]*D,Y)&&btwn(x[k]*D,x[l]*D,X)&&btwn(y[k]*D,y[l]*D,Y))
                                    ok=0;
                            }
                        }
                ans+=ok;
                if (ok)
                    cout<<i<<" "<<j<<"\n";
            }
    cout<<ans;
    return 0;
}