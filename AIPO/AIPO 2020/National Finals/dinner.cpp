#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[2000][2000];
int n;
map<int,int> placed;
vector<int> one;
vector<int> two;

void dfs(int cur, int tableNumber)
{
    for (int i=0;i<n;++i)
    {
        if (a[cur][i]==1)
        {
            if (!placed[i])
            {
                placed[i]=1;
                if (tableNumber==1)
                {
                    two.push_back(i);
                }
                else
                {
                    one.push_back(i);
                }
                dfs(i,3-tableNumber);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    for (int i=0;i<n;++i)
    {
        if (!placed[i])
        {
            one.push_back(i);
            placed[i]=1;
            dfs(i,1);
        }
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    if (sz(two)==0)
    {
        two.push_back(one.back());
        one.pop_back();
    }
    for (int i=0;i<sz(one);++i)
    {
        cout<<one[i]<<" ";
    }
    cout<<"\n";
    for (int i=0;i<sz(two);++i)
    {
        cout<<two[i]<<" ";
    }
    return 0;
}