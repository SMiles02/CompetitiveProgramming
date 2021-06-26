#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,ans=0,done=0,adder;
    ll n,k,mini=1,maxi;
    cin>>n>>m>>k;
    ll p[m];
    for (int i=0;i<m;++i)
    {
        cin>>p[i];
    }
    maxi=mini+k-1;
    while (done<m)
    {
        //cout<<"mini = "<<mini<<", maxi = "<<maxi<<"\n";
        if (p[done]>maxi)
        {
            mini=maxi+1+((p[done]-maxi-1)/k)*k;
            maxi=mini+k-1;
        }
        else
        {
            adder=0;
            while (done<m&&p[done]<=maxi)
            {
                ++done;
                ++adder;
            }
            ++ans;
            maxi+=adder;
            //cout<<"maxi increased to "<<maxi<<"\n";
        }
    }
    cout<<ans;
    return 0;
}