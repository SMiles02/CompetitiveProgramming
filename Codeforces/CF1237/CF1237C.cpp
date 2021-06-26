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
    int n,ind,x,y,z,a;
    vector<vector<int>> v;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y>>z;
        v.push_back({x,y,z,i+1});
    }
    while (n)
    {
        x=v[n-1][0];
        y=v[n-1][1];
        z=v[n-1][2];
        a=v[n-1][3];
        v.pop_back();
        ind=n-2;
        for (int i=n-3;i>-1;--i)
        {
            if ((min(x,v[ind][0])<=v[i][0]&&v[i][0]<=max(x,v[ind][0]))&&(min(y,v[ind][1])<=v[i][1]&&v[i][1]<=max(y,v[ind][1]))&&(min(z,v[ind][2])<=v[i][2]&&v[i][2]<=max(z,v[ind][2])))
            {
                ind=i;
            }
        }
        cout<<a<<" "<<v[ind][3]<<"\n";
        v.erase(v.begin()+ind);
        n-=2;
    }
    return 0;
}