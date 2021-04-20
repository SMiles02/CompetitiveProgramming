#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=0,y=0;
    cin>>n;
    string s;
    cin>>s;
    for (auto i : s)
    {
        if (i=='(')
            ++x;
        else if (x)
        {
            --x;
            y+=2;
        }
    }
    cout<<y;
    return 0;
}