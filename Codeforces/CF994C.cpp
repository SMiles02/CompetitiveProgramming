#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int inSquare(int x, int y, int a, int b, int c, int d)
{
    if (a<=x&&x<=c&&b<=y&&y<=d)
    {
        return 1;
    }
    return 0;
}

int min(vector<int> v)
{
    int mini=100;
    int n=sz(v);
    for (int i=0;i<n;++i)
    {
        mini=min(mini,v[i]);
    }
    return mini;
}

int max(vector<int> v)
{
    int maxi=-100;
    int n=sz(v);
    for (int i=0;i<n;++i)
    {
        maxi=max(maxi,v[i]);
    }
    return maxi;
}

double triangleArea(int aX, int aY, int bX, int bY, int cX, int cY)
{
    double area=aX*(bY-cY)+bX*(cY-aY)+cX*(aY-bY);
    //cout<<"Area of ("<<aX<<","<<aY<<"), ("<<bX<<","<<bY<<"), ("<<cX<<","<<cY<<")\n";
    //cout<<"=> "<<abs(area/2)<<"\n";
    return abs(area/2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a[8];
    int b[8];
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7];
    cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5]>>b[6]>>b[7];
    int c,d;
    double area;
    if (inSquare(b[0],b[1],min({a[0],a[2],a[4],a[6]}),min({a[1],a[3],a[5],a[7]}),max({a[0],a[2],a[4],a[6]}),max({a[1],a[3],a[5],a[7]})))
    {
        cout<<"YES";
        return 0;
    }
    if (inSquare(b[2],b[3],min({a[0],a[2],a[4],a[6]}),min({a[1],a[3],a[5],a[7]}),max({a[0],a[2],a[4],a[6]}),max({a[1],a[3],a[5],a[7]})))
    {
        cout<<"YES";
        return 0;
    }
    if (inSquare(b[4],b[5],min({a[0],a[2],a[4],a[6]}),min({a[1],a[3],a[5],a[7]}),max({a[0],a[2],a[4],a[6]}),max({a[1],a[3],a[5],a[7]})))
    {
        cout<<"YES";
        return 0;
    }
    if (inSquare(b[6],b[7],min({a[0],a[2],a[4],a[6]}),min({a[1],a[3],a[5],a[7]}),max({a[0],a[2],a[4],a[6]}),max({a[1],a[3],a[5],a[7]})))
    {
        cout<<"YES";
        return 0;
    }
    if (inSquare((b[0]+b[2]+b[4]+b[6])/4,(b[1]+b[3]+b[5]+b[7])/4,min({a[0],a[2],a[4],a[6]}),min({a[1],a[3],a[5],a[7]}),max({a[0],a[2],a[4],a[6]}),max({a[1],a[3],a[5],a[7]})))
    {
        cout<<"YES";
        return 0;
    }
    area=((b[0]-b[2])*(b[0]-b[2]))+((b[1]-b[3])*(b[1]-b[3]));
    //area=sqrt(area);
    //cout<<((b[0]-b[2])*(b[0]-b[2]))<<"\n";
    //cout<<((b[1]-b[3])*(b[1]-b[3]))<<"\n";
    //cout<<area<<"\n";
    c=a[0];d=a[1];
    if (area==triangleArea(b[0],b[1],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[6],b[7],c,d)+triangleArea(b[0],b[1],b[6],b[7],c,d))
    {
        cout<<"YES";
        return 0;
    }
    //cout<<"-\n";
    c=a[2];d=a[3];
    if (area==triangleArea(b[0],b[1],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[6],b[7],c,d)+triangleArea(b[0],b[1],b[6],b[7],c,d))
    {
        cout<<"YES";
        return 0;
    }
    //cout<<"-\n";
    c=a[4];d=a[5];
    if (area==triangleArea(b[0],b[1],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[6],b[7],c,d)+triangleArea(b[0],b[1],b[6],b[7],c,d))
    {
        cout<<"YES";
        return 0;
    }
    //cout<<"-\n";
    c=a[6];d=a[7];
    if (area==triangleArea(b[0],b[1],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[6],b[7],c,d)+triangleArea(b[0],b[1],b[6],b[7],c,d))
    {
        cout<<"YES";
        return 0;
    }
    //cout<<"-\n";
    c=(a[0]+a[2]+a[4]+a[6])/4;
    d=(a[1]+a[3]+a[5]+a[7])/4;
    if (area==triangleArea(b[0],b[1],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[2],b[3],c,d)+triangleArea(b[4],b[5],b[6],b[7],c,d)+triangleArea(b[0],b[1],b[6],b[7],c,d))
    {
        cout<<"YES";
        return 0;
    }
    //cout<<"-\n";
    cout<<"NO";
    return 0;
}