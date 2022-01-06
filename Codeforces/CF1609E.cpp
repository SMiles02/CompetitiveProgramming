#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
string s;
int seg[N*4][6];

/**

0: 123
1: 12
2: 23
3: 1
4: 2
5: 3

**/ 

void calc(int i)
{
    int l=i*2+1,r=i*2+2;
    seg[i][0]=min({seg[l][0]+seg[r][5],seg[l][3]+seg[r][0],seg[l][1]+seg[r][2]});
    seg[i][1]=min(seg[l][1]+seg[r][4],seg[l][3]+seg[r][1]);
    seg[i][2]=min(seg[l][2]+seg[r][5],seg[l][4]+seg[r][2]);
    seg[i][3]=seg[l][3]+seg[r][3];
    seg[i][4]=seg[l][4]+seg[r][4];
    seg[i][5]=seg[l][5]+seg[r][5];
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        if (s[l]=='a')
            seg[i][3]=1;
        else if (s[l]=='b')
            seg[i][4]=1;
        else
            seg[i][5]=1;
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    calc(i);
}

void update(int i, int l, int r, int x, char c)
{
    if (l==r)
    {
        s[l]=c;
        for (int j=0;j<6;++j)
            seg[i][j]=0;
        if (s[l]=='a')
            seg[i][3]=1;
        else if (s[l]=='b')
            seg[i][4]=1;
        else
            seg[i][5]=1;
        return;
    }
    if (x<=l+(r-l)/2)
        update(i*2+1,l,l+(r-l)/2,x,c);
    else
        update(i*2+2,l+(r-l)/2+1,r,x,c);
    calc(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t;
    char c;
    cin>>n>>q;
    cin>>s;
    build(0,0,n-1);
    while (q--)
    {
        cin>>t>>c;
        update(0,0,n-1,t-1,c);
        cout<<seg[0][0]<<"\n";
    }
    return 0;
}