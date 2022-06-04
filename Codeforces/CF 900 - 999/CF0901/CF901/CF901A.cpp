#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int h;

void builder(int a[])
{
    vector<int> vOld={0};
    vector<int> vNew;
    int cur=1;
    for (int i=0;i<=h;++i)
    {
        for (int j=0;j<a[i];++j)
        {
            cout<<vOld[0]<<" ";
            vNew.push_back(cur);
            ++cur;
        }
        vOld.clear();
        vOld=vNew;
        vNew.clear();
    }
    return;
}

void maker(int a[])
{
    vector<int> vOld={0};
    vector<int> vNew;
    int cur=1;
    for (int i=0;i<=h;++i)
    {
        if (sz(vOld)==1)
        {
            for (int j=0;j<a[i];++j)
            {
                cout<<vOld[0]<<" ";
                vNew.push_back(cur);
                ++cur;
            }
        }
        else
        {
            cout<<vOld[0]<<" ";
            vNew.push_back(cur);
            ++cur;
            for (int j=1;j<a[i];++j)
            {
                cout<<vOld[1]<<" ";
                vNew.push_back(cur);
                ++cur;
            }
        }
        vOld.clear();
        vOld=vNew;
        vNew.clear();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int b=1;
    cin>>h;
    int a[h+1];
    cin>>a[0];
    for (int i=1;i<=h;++i)
    {
        cin>>a[i];
        if (a[i]>1&&a[i-1]>1)
        {
            b=0;
        }
    }
    if (b)
    {
        cout<<"perfect\n";
        return 0;
    }
    cout<<"ambiguous\n";
    builder(a);
    cout<<"\n";
    maker(a);
    return 0;
}