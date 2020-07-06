#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,flag=0;
vector<vector<int>> allPossible;
map<vector<int>,int> done;
map<vector<int>,int> score;

void permutations(int cur, vector<int> v)
{
    if (n==cur)
    {
        allPossible.push_back(v);
        return;
    }
    v.push_back(0);
    permutations(cur+1,v);
    v.pop_back();
    v.push_back(1);
    permutations(cur+1,v);
    v.pop_back();
    return;
}

int checker(vector<int> v)
{   
    int heads=0;
    if (done[v])
    {
        return score[v];
    }
    done[v]=1;
    vector<int> w;
    if (v[0]==1)
    {
        ++heads;
    }
    w.push_back(v[1]);
    for (int i=1;i<n-1;++i)
    {
        w.push_back((v[i-1]+v[i+1])%2);
        if (v[i]==1)
        {
            ++heads;
        }
    }
    if (v[n-1]==1)
    {
        ++heads;
    }
    w.push_back(v[n-2]);
    if (heads)
    {
        score[v]=1+checker(w);
        return score[v];
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double ans=0;
    int k;
    cin>>n;
    vector<int> v;
    permutations(0,v);
    k=sz(allPossible);
    for (int i=0;i<k;++i)
    {
        ans+=checker(allPossible[i]);
    }
    cout<<ans<<"\n";
    return 0;
}