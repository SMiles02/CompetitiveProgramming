#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool ok(int k)
{
    if (k==0||k==1||k==2||k==5||k==8)
        return 1;
    return 0;
}

void solve()
{
    int H,M,h,m,x,y;
    cin>>H>>M;
    string s;
    cin>>s;
    h=(s[0]-'0')*10+(s[1]-'0');
    m=(s[3]-'0')*10+(s[4]-'0');
    while (m>=M)
    {
        m-=M;
        ++h;
    }
    h%=H;
    --m;
    map<int,int> rev;
    rev[1]=1;
    rev[2]=5;
    rev[5]=2;
    rev[8]=8;
    while (1)
    {
        ++m;
        if (m==M)
        {
            m=0;
            ++h;
        }
        if (h==H)
            h=0;
        //cout<<h<<" "<<m<<"\n";
        if (!ok(h/10)||!ok(h%10)||!ok(m/10)||!ok(m%10))
            continue;
        x=(rev[m%10])*10+(rev[m/10]);
        y=(rev[h%10])*10+(rev[h/10]);
        if (0<=x&&0<=y&&x<H&&y<M)
        {
            cout<<h/10<<h%10<<":"<<m/10<<m%10<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}