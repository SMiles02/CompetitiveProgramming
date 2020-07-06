#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("planting.out");
    ifstream fin ("planting.in");
    map<int,int> m;
    int n,ans=0,a,b;
    fin>>n;
    for (int i=1;i<n;++i)
    {
        fin>>a>>b;
        ++m[a];
        ++m[b];
        ans=max(ans,max(m[a],m[b]));
    }
    fout<<ans+1<<"\n";
	return 0;
}