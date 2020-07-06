#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
int ans[20][20];

void printAns()
{
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>n;
    map<int,int> m;
    for (int i=0;i<n*n;++i)
    {
        cin>>k;
        ++m[k];
    }
    multiset<int> fours;
    multiset<int> twos;
    multiset<int> ones;
    multiset <int>::iterator it;
    for (int i=1;i<1001;++i)
    {
        while (m[i]>3)
        {
            m[i]-=4;
            fours.insert(i);
        }
        if (m[i]>1)
        {
            m[i]-=2;
            twos.insert(i);
        }
        if (m[i])
        {
            m[i]=0;
            ones.insert(i);
        }
    }
    for (int i=0;i<n/2;++i)
    {
        for (int j=0;j<n/2;++j)
        {
            if (!sz(fours))
            {
                cout<<"No\n";
                return 0;
            }
            it=fours.begin();
            ans[i][j]=*it;
            ans[n-i-1][j]=*it;
            ans[i][n-j-1]=*it;
            ans[n-i-1][n-j-1]=*it;
            fours.erase(it);
        }
    }
    if (!(n%2))
    {
        cout<<"Yes\n";
        printAns();
        return 0;
    }
    while (sz(fours))
    {
        it=fours.begin();
        twos.insert(*it);
        twos.insert(*it);
        fours.erase(it);
    }
    for (int i=0;i<n/2;++i)
    {
        if (!sz(twos))
        {
            cout<<"No\n";
            return 0;
        }
        it=twos.begin();
        ans[n/2][i]=*it;
        ans[n/2][n-i-1]=*it;
        twos.erase(it);
    }
    for (int i=0;i<n/2;++i)
    {
        if (!sz(twos))
        {
            cout<<"No\n";
            return 0;
        }
        it=twos.begin();
        ans[i][n/2]=*it;
        ans[n-i-1][n/2]=*it;
        twos.erase(it);
    }
    while (sz(twos))
    {
        it=twos.begin();
        ones.insert(*it);
        ones.insert(*it);
        twos.erase(it);
    }
    if (sz(ones))
    {
        it=ones.begin();
        ans[n/2][n/2]=*it;
        cout<<"Yes\n";
        printAns();
        return 0;
    }
    cout<<"No\n";
    return 0;
}