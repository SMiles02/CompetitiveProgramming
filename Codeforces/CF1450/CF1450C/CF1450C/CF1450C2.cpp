#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,mini=100,a[12];
bitset<12> d;

void perm(int x, int score, vector<int> v)
{
    if (x==n)
    {
        if (score<mini)
        {
            mini=score;
            cout<<mini<<"\n";
            for (int i=0;i<n;++i)
                cout<<v[i]<<" ";
            cout<<"\n";
        }
        return;
    }
    for (int i=0;i<n;++i)
        if (!d[i]&&a[i]!=a[v.back()])
        {
            d[i]=1;
            if (abs(v.back()-i)>1)
            {
                v.push_back(i);
                perm(x+1,score+1,v);
            }
            else
            {
                v.push_back(i);
                perm(x+1,score,v);
            }
            d[i]=0;
            v.pop_back();
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    vector<int> v;
    for (int i=0;i<n;++i)
    {
        v.push_back(i);
        d[i]=1;
        perm(1,0,v);
        v.pop_back();
        d[i]=0;
    }
    return 0;
}