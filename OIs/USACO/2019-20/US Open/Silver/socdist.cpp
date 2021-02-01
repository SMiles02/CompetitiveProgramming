/*
ID: mahajan6
TASK: socdist
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
//#define fin cin
//#define fout cout
using namespace std;

int n,m;
vector<pair<ll,ll>> intervals;

int works(ll d)
{
    int cur=intervals[0].first;
    int ans=1;
    for (int i=0;i<m;++i)
    {
        if (cur+d<=intervals[i].first)
        {
            cur=intervals[i].first;
            ++ans;
        }
        while (intervals[i].first<=cur+d&&cur+d<=intervals[i].second)
        {
            cur+=d;
            ++ans;
        }
    }
    if (ans<n)
    {
        return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ofstream fout ("socdist.out");
    ifstream fin ("socdist.in");
    ll l=1,r=1000000000000000000,mid,a,b;
    fin >> n >> m;
    for (int i=0;i<m;++i)
    {
        fin>>a>>b;
        intervals.push_back({a,b});
    }
    sort(intervals.begin(), intervals.end());
    while (l<r)
    {
        mid=r-(r-l)/2;
        if (works(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    fout << l << "\n";
    return 0;
}