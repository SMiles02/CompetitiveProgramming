#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,a[8];
string s;
bool ok=0;
vector<int> ans;

void check(vector<int> v)
{
    if (ok)
        return;
    vector<array<int,3>> hori;
    //small x, big x, y
    vector<array<int,3>> verti;
    //small y, big y, x
    hori.push_back({0,a[0],0});
    for (int i=1;i<n;++i)
    {
        if (s[i]=='U')
        {
            if (i&1)
            {
                verti.push_back({hori.back()[2],hori.back()[2]+v[i-1],hori.back()[1]});
                hori.push_back({hori.back()[1]-a[i],hori.back()[1],hori.back()[2]+v[i-1]});
            }
            else
            {
                verti.push_back({hori.back()[2],hori.back()[2]+v[i-1],hori.back()[0]});
                hori.push_back({hori.back()[0],hori.back()[0]+a[i],hori.back()[2]+v[i-1]});
            }
        }
        else
        {
            if (i&1)
            {
                verti.push_back({hori.back()[2]-v[i-1],hori.back()[2],hori.back()[1]});
                hori.push_back({hori.back()[1]-a[i],hori.back()[1],hori.back()[2]-v[i-1]});
            }
            else
            {
                verti.push_back({hori.back()[2]-v[i-1],hori.back()[2],hori.back()[0]});
                hori.push_back({hori.back()[0],hori.back()[0]+a[i],hori.back()[2]-v[i-1]});
            }
        }
    } 
    for (int i=0;i<n;++i)
        for (int j=0;j+1<n;++j)
            if (i!=j&&i!=j+1)
                if (verti[j][0]<=hori[i][2]&&hori[i][2]<=verti[j][1])
                    if (hori[i][0]<=verti[j][2]&&verti[j][2]<=hori[i][1])
                        return;
    ok=1;
    ans=v;
}

void perm(int k, vector<int> v)
{
    if (k==n)
    {
        check(v);
        return;
    }
    for (int i=0;i<8;++i)
    {
        v.push_back((1<<i));
        perm(k+1,v);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    cin>>s;
    perm(0,{});
    if (ok)
    {
        cout<<"YES\n";
        for (int i : ans)
            cout<<i<<" ";
    }
    else
        cout<<"NO";
    return 0;
}