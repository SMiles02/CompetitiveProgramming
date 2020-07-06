#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> inputGet()
{
    string a,b;
    cin>>a>>b;
    vector<int> v;
    int k=sz(a),x=0;
    for (int i=0;i<k;++i)
    {
        if (a[i]=='-')
        {
            v.push_back(x);
            x=0;
        }
        else
        {
            x*=10;
            x+=(a[i]-'0');
        }
    }
    v.push_back(x);
    x=0;
    k=sz(b);
    for (int i=0;i<k;++i)
    {
        if (b[i]==':')
        {
            v.push_back(x);
            x=0;
        }
        else
        {
            x*=10;
            x+=(b[i]-'0');
        }
    }
    v.push_back(x);
    return v;
}

int lessEqual(vector<int> a, vector<int> b)
{
    for (int i=0;i<5;++i)
    {
        if (a[i]>b[i])
        {
            return 0;
        }
        if (b[i]>a[i])
        {
            return 1;
        }
    }
    return 1;
}

int lesser(vector<int> a, vector<int> b)
{
    for (int i=0;i<5;++i)
    {
        if (a[i]>b[i])
        {
            return 0;
        }
        if (b[i]>a[i])
        {
            return 1;
        }
    }
    return 0;
}

vector<int> minusHour(vector<int> v)
{
    if (v[3]==0)
    {
        if (v[2]==1)
        {
            if (v[1]==1)
            {
                --v[0];
                v[1]=12;
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==2)
            {
                --v[1];
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==3)
            {
                --v[1];
                if ((v[0]%4||v[0]%400))
                {
                    v[2]=28;
                }
                else
                {
                    v[2]=29;
                }
                v[3]=23;
                return v;
            }
            if (v[1]==4)
            {
                --v[1];
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==5)
            {
                --v[1];
                v[2]=30;
                v[3]=23;
                return v;
            }
            if (v[1]==6)
            {
                --v[1];
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==7)
            {
                --v[1];
                v[2]=30;
                v[3]=23;
                return v;
            }
            if (v[1]==8)
            {
                --v[1];
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==9)
            {
                --v[1];
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==10)
            {
                --v[1];
                v[2]=30;
                v[3]=23;
                return v;
            }
            if (v[1]==11)
            {
                --v[1];
                v[2]=31;
                v[3]=23;
                return v;
            }
            if (v[1]==12)
            {
                --v[1];
                v[2]=30;
                v[3]=23;
                return v;
            }
        }
        --v[2];
        v[3]=23;
        return v;
    }
    --v[3];
    return v;
}

vector<int> plusTen(vector<int> v)
{
    if (v[4]>49)
    {
        if (v[3]==23)
        {
            if (v[2]==31)
            {
                if (v[1]==12)
                {
                    ++v[0];
                    v[1]=1;
                    v[2]=1;
                    v[3]=0;
                    v[4]+=10;
                    v[4]%=60;
                    return v;
                }
                ++v[1];
                v[2]=1;
                v[3]=0;
                v[4]+=10;
                v[4]%=60;
                return v;
            }
            if (v[2]==30&&(v[1]==4||v[1]==6||v[1]==9||v[1]==11))
            {
                ++v[1];
                v[2]=1;
                v[3]=0;
                v[4]+=10;
                v[4]%=60;
                return v;
            }
            if (v[1]==2)
            {
                if ((v[0]%4||v[0]%400))
                {
                    if (v[2]==28)
                    {
                        ++v[1];
                        v[2]=1;
                        v[3]=0;
                        v[4]+=10;
                        v[4]%=60;
                        return v;
                    }
                }
                if (v[2]==29)
                {
                    ++v[1];
                    v[2]=1;
                    v[3]=0;
                    v[4]+=10;
                    v[4]%=60;
                    return v;
                }
            }
            ++v[2];
            v[3]=0;
            v[4]+=10;
            v[4]%=60;
            return v;
        }
        ++v[3];
        v[4]+=10;
        v[4]%=60;
        return v;
    }
    v[4]+=10;
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> v=inputGet();
    vector<int> w=inputGet();
    int n;
    cin>>n;
    while (n--)
    {
        vector<int> z=inputGet();
        if (lessEqual(minusHour(v),z))
        {
            if (lessEqual(z,v))
            {
                cout<<"Early\n";
            }
            else if (lessEqual(z,plusTen(v)))
            {
                cout<<"On time\n";
            }
            else if (lesser(w,z))
            {
                cout<<"Missed\n";
            }
            else
            {
                cout<<"Late\n";
            }
        }
        else
        {
            cout<<"Missed\n";
        }
    }
    return 0;
}