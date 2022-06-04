#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
int n;
int ans=0,x=1,y=1;
bool s[500];
string t;
 
void swap_em(int a, int b)
{
    int cur=0,mini=0,z=0;
    for (int i=0;i<n;++i)
    {
        if (s[i])
            ++cur;
        else
            --cur;
        if (cur<mini)
        {
            mini=cur;
            z=1;
        }
        else if (cur==mini)
            ++z;
    }
    cur=z;
    if (cur>ans)
    {
        ans=cur;
        x=a+1;
        y=b+1;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    cin>>t;
    vector<int> v;
    vector<int> w;
    for (int i=0;i<n;++i)
    {
        if (t[i]=='(')
        {
            s[i]=1;
            v.push_back(i);
        }
        else
            w.push_back(i);
    }
    if (sz(v)!=sz(w))
    {
        cout<<"0\n1 1";
        return 0;
    }
    swap_em(0,0);
    for (auto i : v)
        for (auto j : w)
        {
            swap(s[i],s[j]);
            swap_em(i,j);
            swap(s[i],s[j]);
        }
    cout<<ans<<"\n"<<x<<" "<<y;
    return 0;
}