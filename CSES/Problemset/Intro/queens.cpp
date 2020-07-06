#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int ans;
string board[8];
map<int,int> rowDone;
map<int,int> sumBoth; //x+y
map<int,int> subtractBoth; //x-y

void permChecker(int cur)
{
    if (cur==8)
    {
        ++ans;
        return;
    }
    for (int i=0;i<8;++i)
    {
        if (board[cur][i]=='.'&&!rowDone[i]&&!sumBoth[i+cur]&&!subtractBoth[i-cur])
        {
            rowDone[i]=1;
            sumBoth[i+cur]=1;
            subtractBoth[i-cur]=1;
            permChecker(cur+1);
            rowDone[i]=0;
            sumBoth[i+cur]=0;
            subtractBoth[i-cur]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<8;++i)
        cin>>board[i];
    permChecker(0);
    cout<<ans;
    return 0;
}