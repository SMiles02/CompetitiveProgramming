#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,score=0;
    bool b;
    cin>>n>>q;
    vector<int> open;
    string s(n,'?');
    for (int i=0;i<n;++i)
    {
        if (score==0)
        {
            ++score;
            s[i]='(';
            open.push_back(i);
            continue;
        }
        cout<<"? "<<open.back()+1<<" "<<i+1<<endl;
        cin>>b;
        if (b==1)
        {
            s[i]=')';
            open.pop_back();
        }
        else
        {
            s[i]='(';
            open.push_back(i);
        }
    }
    cout<<"! "<<s<<endl;
    return 0;
}