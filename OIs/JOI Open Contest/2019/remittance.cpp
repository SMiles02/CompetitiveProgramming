#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

// actually, the updated slow version ACs
// and this one TLEs [priority_queue isn't needed]

int a[1<<20][2];
priority_queue<array<int,2>> p;

void add(int i)
{
    if (a[i][0]>a[i][1])
        p.push({a[i][0]-a[i][1],i});
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        add(i);
    }
    while (!p.empty())
    {
        x=p.top()[0];
        y=p.top()[1];
        p.pop();
        if (a[y][0]-a[y][1]!=x||a[y][0]==1)
            continue;
        a[(y+1)%n][0]+=(x+(a[y][1]!=0))/2;
        a[y][0]-=((x+(a[y][1]!=0))/2)*2;
        add((y+1)%n);
    }
    for (int i=0;i<n;++i)
        if (a[i][0]!=a[i][1])
        {
            cout<<"No";
            return 0;
        }
    cout<<"Yes";
    return 0;
}