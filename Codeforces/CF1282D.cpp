#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,qA,qB,last,thisOne,aCount,bCount;
    for (int i=0;i<300;++i) cout<<"a";
    cout<<endl;
    cin>>qA;
    if (qA==0) return 0;
    aCount=300-qA;
    for (int i=0;i<300;++i) cout<<"b";
    cout<<endl;
    cin>>qB;
    if (qB==0) return 0;
    bCount=300-qB;
    n=aCount+bCount;
    string cur="";
    for (int i=0;i<n;++i) cur+="a";
    last=bCount;
    if (last==0)
    {
        cout<<cur<<endl;
        cin>>last;
        return 0;
    }
    for (int i=0;i<n-1;++i)
    {
        cur[i]='b';
        cout<<cur<<endl;
        cin>>thisOne;
        if (thisOne==0) return 0;
        if (thisOne>last) cur[i]='a';
        last=min(thisOne,last);
    }
    cur[n-1]='b';
    cout<<cur<<endl;
    cin>>thisOne;
    return 0;
}