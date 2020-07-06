#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,k,ans=0,l,r,mid;
vector<int> sum;

void binsearch(int cur)
{
    l=1;r=cur;
    while (l!=r)
    {
        mid=l+(r-l)/2;
        if (min(sum[cur]-sum[mid-1],cur-mid+1-sum[cur]+sum[mid-1])<=k)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    //cout<<l<<" "<<cur<<"\n";
    ans=max(ans,cur-l+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>n>>k;
    cin>>s;
    sum.push_back(0);
    for (int i=0;i<n;++i)
    {
        if (s[i]=='a')
        {
            sum.push_back(sum.back()+1);
        }
        else
        {
            sum.push_back(sum.back());
        }
    }
    for (int i=n;i;--i)
    {
        binsearch(i);
    }
    cout<<ans;
    return 0;
}