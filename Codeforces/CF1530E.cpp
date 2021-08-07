#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";

void solve()
{
    int e=0,x,y,z,n;
    string s;
    cin>>s;
    n=sz(s);
    if (n<3)
    {
        sort(s.begin(), s.end());
        cout<<s<<"\n";
        return;
    }
    vector<int> v(26,0), ans;
    for (auto i : s)
        ++v[i-'a'];
    for (int i=0;i<26;++i)
    {
        if (v[i]==1)
        {
            cout<<alpha[i];
            --v[i];
            for (int j=0;j<26;++j)
                while (v[j]--)
                    cout<<alpha[j];
            cout<<"\n";
            return;
        }
        e+=(v[i]==0);
    }
    if (e==25)
    {
        cout<<s<<"\n";
        return;
    }
    for (int i=25;i>=0;--i)
        if (0<v[i])
            x=i;
    // if (v[x]==n/2+1)
    // {
    //     if (n&1)
    //     {
    //         cout<<alpha[x];
    //         for (int i=0;i<26;++i)
    //             if (i!=x)
    //                 while (v[i]--)
    //                     cout<<alpha[x]<<alpha[i];
    //         cout<<"\n";
    //         return;
    //     }
    //     cout<<alpha[x]<<alpha[x];
    //     for (int i=0;i<26;++i)
    //         if (i!=x)
    //             while (v[i]--)
    //                 cout<<alpha[i]<<alpha[x];
    //     cout<<"\n";
    //     return;
    // }
    ans.push_back(x);
    --v[x];
    --n;
    for (int i=0;i<26;++i)
        if (v[i]>0)
        {
            if (i==x)
            {
                if ((v[x]-1)<=(n-1)/2)
                {
                    y=i;
                    break;
                }
            }
            else if (v[x]+v[i]!=n)
            {
                y=i;
                break;
            }
        }
    ans.push_back(y);
    --v[y];
    --n;
    while (n>0)
    {
        z=-1;
        for (int i=0;i<26;++i)
            if (v[i]>0)
            {
                if (x==i)
                {
                    if (ans.back()!=y)
                    {
                        z=i;
                        break;
                    }
                }
                else if (y==i) //guaranteed x!=y
                {
                    if (v[x]+v[y]!=n)
                    {
                        z=i;
                        break;
                    }
                }
                else if (x==y)
                {
                    if (v[x]<=n/2)
                    {
                        z=i;
                        break;
                    }
                }
                else
                {
                    z=i;
                    break;
                }
            }
        assert(z!=-1);
        ans.push_back(z);
        --v[z];
        --n;
    }
    for (int i : ans)
        cout<<alpha[i];
    cout<<"\n";
    return;
    cout<<" nothing yet\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}