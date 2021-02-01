/*
ID: mahajan6
TASK: berries
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
#define fin cin
#define fout cout
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//ofstream fout ("berries.out");
    //ifstream fin ("berries.in");
    int n,k,lastWorked;
    fin>>n>>k;
    int a[n];
    for (int i=0;i<n;++i)
    {
        fin>>a[i];
    }
    sort(a,a+n);
    int b[k];
    for (int i=0;i<k;++i)
    {
        b[i]=0;
    }
    for (int i=1;i<=min(n,k);++i)
    {
        b[k-i]=a[n-i];
    }
    for (int i=1;i<k;++i)
    {
        lastWorked=0;
        for (int j=2;j<=min(b[i]/2,i);++j)
        {
            if (!(b[i]%j))
            {
                if (b[i]/j>b[j-2])
                {
                    lastWorked=j;
                }
                else
                {
                    break;
                }
            }
        }
        if (lastWorked)
        {
            for (int j=0;j<lastWorked-1;++j)
            {
                b[j]=b[i]/lastWorked;
            }
            b[i]/=lastWorked;
            sort(b,b+k);
        }
    }
    int ans=0;
    for (int i=0;i<k/2;++i)
    {
        ans+=b[i];
    }
    fout<<ans;
	return 0;
}