/*
ID: mahajan6
TASK: milk2
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
//#define fin cin
//#define fout cout
using namespace std;

int differences[1000002];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n,a,b,cur=0,maxi=0,curNone=0,totalNone=0,dif=0;
    fin>>n;
    while (n--)
    {
        fin>>a>>b;
        ++differences[a];
        --differences[b];
    }
    for (int i=0;i<1000002;++i)
    {
        dif+=differences[i];
        if (dif)
        {
            if (maxi)
            {
                totalNone=max(curNone,totalNone);
            }
            curNone=0;
            ++cur;
            maxi=max(maxi,cur);
        }
        else
        {
            cur=0;
            ++curNone;
        }
    }
    fout<<maxi<<" "<<totalNone<<"\n";
	return 0;
}