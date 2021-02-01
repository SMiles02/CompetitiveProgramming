/*
ID: mahajan6
TASK: friday
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
//#define fin cin
//#define fout cout
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n,Y,y,c,d=13,m,w;
    int daysOfTheWeek[7]={0};
    fin >> n;
    for (int i=1900;i<1900+n;++i)
    {
    	for (int j=1;j<3;++j)
    	{
    		Y=i-1;
    		y=Y%100;
    		c=Y/100;
    		m=((j+9)%12)+1;
    		w=(2.6*m)-0.2;
    		w+=d+y+(y/4)+(c/4)-(2*c);
    		w%=7;
    		while (w<0)
    		{
    			w+=7;
    		}
    		w+=6;
    		w%=7;
    		++daysOfTheWeek[w];
    		//cout<<w<<"\n";
    	}
    	for (int j=3;j<13;++j)
    	{
    		Y=i;
    		y=Y%100;
    		c=Y/100;
    		m=((j+9)%12)+1;
    		w=(2.6*m)-0.2;
    		w+=d+y+(y/4)+(c/4)-(2*c);
    		w%=7;
    		while (w<0)
    		{
    			w+=7;
    		}
    		w+=6;
    		w%=7;
    		++daysOfTheWeek[w];
    		//cout<<w<<"\n";
    	}
    }
    fout << daysOfTheWeek[5] << " " << daysOfTheWeek[6] << " " << daysOfTheWeek[0] << " " << daysOfTheWeek[1] << " " << daysOfTheWeek[2] << " " << daysOfTheWeek[3] << " " << daysOfTheWeek[4] << endl;
	return 0;
}