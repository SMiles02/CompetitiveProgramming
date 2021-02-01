/*
ID: mahajan6
TASK: cereal
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
//#define fout cout
//#define fin cin
using namespace std;

int n,m;
int preferences[100001][2];
int cerealToCow[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("cereal.out");
    ifstream fin ("cereal.in");
    int cowsHappy=0,cowInQuestion,cerealWanted,c;
    vector<int> v;
    fin >> n >> m;
    for (int i=1;i<=n;++i)
    {
        fin>>preferences[i][0]>>preferences[i][1];
    }
    for (int i=n;i;--i)
    {
        if (cerealToCow[preferences[i][0]])
        {
            cowInQuestion=cerealToCow[preferences[i][0]];
            cerealWanted=preferences[i][0];
            cerealToCow[preferences[i][0]]=i;
            while (1)
            {
                if (preferences[cowInQuestion][1]==cerealWanted)
                {
                    break;
                }
                c=cerealToCow[preferences[cowInQuestion][1]];
                if (c)
                {
                    if (c<cowInQuestion)
                    {
                        break;
                    }
                    cerealToCow[preferences[cowInQuestion][1]]=cowInQuestion;
                    //cout<<preferences[cowInQuestion][1]<<" is owned by cow "<<cowInQuestion<<"\n";
                    cowInQuestion=c;
                }
                else
                {
                    cerealToCow[preferences[cowInQuestion][1]]=cowInQuestion;
                    //cout<<preferences[cowInQuestion][1]<<" is owned by cow "<<cowInQuestion<<"\n";
                    ++cowsHappy;
                    break;
                }
            }
        }
        else
        {
            cerealToCow[preferences[i][0]]=i;
            ++cowsHappy;
        }
        v.push_back(cowsHappy);
        //fout<<cowsHappy<<"\n";
    }
    while (n--)
    {
        fout<<v.back()<<"\n";
        v.pop_back();
    }
	return 0;
}