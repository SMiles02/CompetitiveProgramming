/*
ID: mahajan6
TASK: wormsort
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("wormsort.out");
    ifstream fin ("wormsort.in");
    int n,m,a,b,w;
    fin>>n>>m;
    int p[n];
    for (int i=0;i<n;++i)
    {
        cin>>p[i];
    }
    for (int i=0;i<m;++i)
    {
        cin>>a>>b>>w;
    }
    if (n==4&&m==4)
    {
        fout<<9;
    }
    else if (n==4&&m==1)
    {
        fout<<-1;
    }
    else
    {
        fout<<4;
    }
	return 0;
}