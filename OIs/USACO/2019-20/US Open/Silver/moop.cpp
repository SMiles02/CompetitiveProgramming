/*
ID: mahajan6
TASK: moop
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
//#define fin cin
//#define fout cout
#define sz(x) (int)(x).size()
using namespace std;

int n;
map<int,vector<int>> edges;
pair<int,int> coOrds[1000000];
bool done[1000000];

void dfs(int cur)
{
    done[cur]=1;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i]);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("moop.out");
    ifstream fin ("moop.in");
    int ans=0;
    fin>>n;
    for (int i=0;i<n;++i)
    {
        fin>>coOrds[i].first>>coOrds[i].second;
    }
    sort(coOrds,coOrds+n);
    for (int i=0;i<n;++i)
    {
        if (!done[i])
        {
            for (int j=i+1;j<n;++j)
            {
                if (coOrds[i].first<=coOrds[j].first&&coOrds[i].second<=coOrds[j].second)
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                    done[j]=1;
                }
            }
        }
        done[i]=0;
    }
    for (int i=0;i<n;++i)
    {
        if (!done[i])
        {
            dfs(i);
            ++ans;
        }
    }
    fout<<ans;
	return 0;
}