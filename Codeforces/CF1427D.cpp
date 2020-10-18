#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;

bool isSorted(int c[])
{
    for (int i=1;i<n;++i)
        if (c[i-1]+1!=c[i])
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<vector<int>> ans;
    int k,a[n],f[n+1];
    vector<int> b,c;
    for (int i=0;i<n;++i)
        cin>>a[i];
    while (1)
    {
        if (isSorted(a))
            break;
        for (int i=0;i<n;++i)
            f[a[i]]=i;
        b.clear();c.clear();
        for (int i=1;i<n;++i)
            if (f[i+1]<f[i])
            {
                for (int j=f[i]+1;j<n;++j)
                    b.push_back(a[j]);
                k=f[i+1];
                while (a[k]<a[k+1])
                    ++k;
                for (int j=k+1;j<=f[i];++j)
                    b.push_back(a[j]);
                for (int j=f[i+1];j<=k;++j)
                    b.push_back(a[j]);
                for (int j=0;j<f[i+1];++j)
                    b.push_back(a[j]);
                if (f[i+1]>0)
                    c.push_back(f[i+1]);
                c.push_back(k-f[i+1]+1);
                c.push_back(f[i]-k);
                if (n-f[i]-1>0)
                    c.push_back(n-f[i]-1);
                ans.push_back(c);
                for (int i=0;i<n;++i)
                    a[i]=b[i];
                break;
            }
    }
    cout<<sz(ans)<<"\n";
    for (auto i : ans)
    {
        cout<<sz(i)<<" ";
        for (int j : i)
            cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}