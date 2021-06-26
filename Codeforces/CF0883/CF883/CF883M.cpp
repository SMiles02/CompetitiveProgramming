#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    if (x1==x2||y1==y2)
    {
        cout<<2*(abs(x1-x2)+abs(y1-y2))+6;
        return 0;
    }
    cout<<2*(abs(x1-x2)+abs(y1-y2)+2);
    return 0;
}