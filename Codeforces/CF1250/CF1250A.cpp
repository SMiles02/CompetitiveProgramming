#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m;
    int a[n];
    map<int,int> mini;
    map<int,int> maxi;
    map<int,int> curPos;
    for (int i=0;i<n;++i)
    {
        a[i]=i+1;
        curPos[i+1]=i;
        mini[i+1]=i;
        maxi[i+1]=i;
    }
    while (m--)
    {
        cin>>k;
        if (curPos[k]!=0)
        {
            --curPos[k];
            mini[k]=min(mini[k],curPos[k]);
            maxi[a[curPos[k]]]=max(maxi[a[curPos[k]]],curPos[a[curPos[k]]]+1);
            ++curPos[a[curPos[k]]];
            swap(a[curPos[k]],a[curPos[k]+1]);
        }
    }
    for (int i=1;i<=n;++i)
    {
        cout<<mini[i]+1<<" "<<maxi[i]+1<<"\n";
    }
    return 0;
}