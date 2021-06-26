#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l=0,r=0,ans=0,lastZ=0,flag=0,cur=0;
    string s;
    cin>>n;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]==')')
        {
            if (cur==0)
            {
                //cout<<"flag up at "<<i+1<<"\n";
                flag=1;
            }
            ++l;
            --cur;
        }
        else
        {
            ++cur;
            ++r;
        }
        if (cur==0)
        {
            if (flag)
            {
                ans+=(i-lastZ+1);
            }
            flag=0;
            lastZ=i+1;
        }
    }
     if (l!=r)
    {
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}