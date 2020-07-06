/*
ID: mahajan6
TASK: loan
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k;

int checker(ll x)
{
    ll g=0;
    for (int i=0;i<k&&g<n;++i)
    {
        g+=max((n-g)/x,m);
    }
    if (g<n)
    {
        return 0;
    }
    return 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("loan.out");
    ifstream fin ("loan.in");
    ll l=1,r=1000000000000,mid;
    fin>>n>>m>>k;
    while (l!=r)
    {
        mid=r-(r-l)/2;
        if (checker(mid))
        {
            l=m;
        }
        else
        {
            r=mid-1;
        }
    }
    fout << mid << endl;
	return 0;
}