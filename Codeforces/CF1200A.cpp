#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int hotelRooms[10]={0};
    for (int i=0;i<n;++i)
    {
        if (s[i]=='L')
        {
            for (int j=0;j<10;++j)
            {
                if (hotelRooms[j]==0)
                {
                    hotelRooms[j]=1;
                    break;
                }
            }
        }
        else if (s[i]=='R')
        {
            for (int j=9;j>-1;--j)
            {
                if (hotelRooms[j]==0)
                {
                    hotelRooms[j]=1;
                    break;
                }
            }
        }
        else
        {
            hotelRooms[s[i]-'0']=0;
        }
    }
    for (int i=0;i<10;++i)
    {
        cout<<hotelRooms[i];
    }
    return 0;
}
Click to see test details