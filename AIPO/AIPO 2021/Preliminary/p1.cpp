#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<pair<char,char>> v;
    v.push_back({'C','P'});
    v.push_back({'P','R'});
    v.push_back({'R','L'});
    v.push_back({'L','S'});
    v.push_back({'S','C'});
    v.push_back({'C','L'});
    v.push_back({'L','P'});
    v.push_back({'P','S'});
    v.push_back({'S','R'});
    v.push_back({'R','C'});
    char c,d;
    cin>>c;
    cin>>d;
    if (c==d)
    {
        cout<<"D";
        return 0;
    }
    for (auto i : v)
        if (i.first==c&&i.second==d)
        {
            cout<<1;
            return 0;
        }
    cout<<2;
    return 0;
}