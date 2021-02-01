/*
ID: mahajan6
TASK: ride
LANG: C++14                 
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(char numToFind, std::vector<char> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i+1;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string s,t,alpha;
    alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<char> v;
    for (int i=0;i<26;++i)
    {
    	v.push_back(alpha[i]);
    }
    fin>>s;
    fin>>t;
    //cin>>s;
    //cin>>t;
    int score1=1,score2=1,a=s.length(),b=t.length();
    for (int i=0;i<a;++i)
    {
    	score1*=max(index(s[i],v),1);
    	score1%=47;
    	//cout<<index(s[i],v)<<" ";
    }
    //cout<<"\n";
    for (int i=0;i<b;++i)
    {
    	score2*=max(index(t[i],v),1);
    	score2%=47;
    	//cout<<index(t[i],v)<<" ";
    }
    //cout<<"\n";
    //cout<<score1<<" "<<score2<<"\n";
    if (score1==score2)
    {
    	fout << "GO" << endl;
    	//cout << "GO" << endl;
	}
	else
	{
		fout << "STAY" << endl;
		//cout << "STAY" << endl;
	}
	return 0;
}