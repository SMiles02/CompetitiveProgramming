#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    string s[9];
    for (int i=0;i<9;++i)
    {
        cin>>s[i];
    }
    s[0][0]=s[1][0];
    s[1][3]=s[2][3];
    s[2][6]=s[1][6];
    s[3][1]=s[4][1];
    s[4][4]=s[5][4];
    s[5][7]=s[4][7];
    s[6][2]=s[7][2];
    s[7][5]=s[8][5];
    s[8][8]=s[7][8];
    for (int i=0;i<9;++i)
    {
        cout<<s[i]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}