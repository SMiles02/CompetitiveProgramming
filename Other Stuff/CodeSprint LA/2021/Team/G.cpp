#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int s[2002][2];
bitset<2002> single;

void build(int i, int l, int r)
{
    s[i][0]=l;
    s[i][1]=r;
    if (l==r)
    {
        single[i]=1;
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
}

int query(int l, int r)
{
    cout<<"ASK "<<l<<" "<<r<<endl;
    string S,T;
    return 2*(S=="yes")+(T=="yes");
}

int main()
{
    build(0,1,500);
    int x=0,y=0,z;
    while ((!single[x])||(!single[y]))
    {
        if (single[x])
        {
            z=query(s[y*2+1][0],s[y*2+1][1]);
            if (z)
        }
    }
    return 0;
}