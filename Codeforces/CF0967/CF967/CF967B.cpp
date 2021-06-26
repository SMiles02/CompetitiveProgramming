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
    int n,A,B,sum,ans=0;
    double o;
    cin>>n>>A>>B;
    cin>>o;
    sum=o;
    vector<int> a(n-1);
    for (int i=0;i<n-1;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(), a.end());
    for (int i=0;i<n;++i)
    {
        //cout<<sum<<"\n";
        if ((o*A)/sum>=B)
        {
            cout<<ans;
            return 0;
        }
        ++ans;
        sum-=a.back();
        a.pop_back();
    }
    cout<<"tes";
    return 0;
}