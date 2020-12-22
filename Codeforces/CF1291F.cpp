#include <bits/stdc++.h>
using namespace std;

int q=0;
char inp;

bool query(int x)
{
    cout<<"? "<<x<<endl;
    ++q;
    cin>>inp;
    if (inp=='Y')
        return 1;
    return 0;
}

void reset()
{
    if (q)
        cout<<"R"<<endl;
    q=0;
}

bitset<1025> aqua;

int main()
{
    int n,k;
    cin>>n>>k;
    if (k==1)
    {
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
            {
                reset();
                query(i);
                if (query(j))
                    aqua[j]=1;
            }
        cout<<"! "<<n-aqua.count()<<endl;
        return 0;
    }
    for (int i=1;i<=n;++i)
        if (query(i))
            aqua[i]=1;
    for (int i=0;i<(2*n)/k;++i)
        for (int j=i+2;j<(2*n)/k;++j)
        {
            reset();
            for (int l=(k/2)*i+1;l<=(k/2)*(i+1);++l)
                if (!aqua[l])
                    query(l);
            for (int l=(k/2)*j+1;l<=(k/2)*(j+1);++l)
                if (!aqua[l])
                    if (query(l))
                        aqua[l]=1;
        }   
    cout<<"! "<<n-aqua.count()<<endl;
    return 0;
}