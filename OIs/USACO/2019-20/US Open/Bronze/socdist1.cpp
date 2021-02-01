#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("socdist1.out");
    ifstream fin ("socdist1.in");
    int n,oneCount;
    string s;
    fin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='1')
        {
            ++oneCount;
        }
    }
    if (!oneCount)
    {
        cout<<n-1;
        return 0;
    }
    
	return 0;
}