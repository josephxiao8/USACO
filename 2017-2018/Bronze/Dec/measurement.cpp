#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("measurement.out");
ifstream cin ("measurement.in");

int n;
cin>>n;

map<char,int> mapp;
mapp['B']=0;
mapp['E']=1;
mapp['M']=2;

vector<pair<int,pair<string,int> > >v;
for(int i=0; i<n; i++){
	int day,dif;
	string cow;
	cin>>day>>cow>>dif;
	v.pb(mp(day,mp(cow,dif)));
}
sort(v.begin(), v.end());

vi milk(3,7);
vi best(3,0); //1=highest output, 0=not highest output
int day_b4=v[0].f, counter=0;

for(int i=0; i<n; i++){
	if(v[i].f!=day_b4){
		int maxx=0;
		bool done=false;
		for(auto x:milk) maxx=max(maxx,x);
		for(int i=0; i<3; i++) {
			if(milk[i]==maxx && best[i]==0) {
				if(!done) {
					counter++;
					done=true;
				}
				best[i]=1;
			}
			else if(milk[i]!=maxx  && best[i]==1){
				if(!done) {
					counter++;
					done=true;
				}
				best[i]=0;
			}
		}
	}
	milk[mapp[v[i].s.f[0]]]+=v[i].s.s;
	day_b4=v[i].f;
}

//the last day
int maxx=0;
bool done=false;
for(auto x:milk) maxx=max(maxx,x);
for(int i=0; i<3; i++) {
	if(milk[i]==maxx && best[i]==0) {
		if(!done) {
			counter++;
			done=true;
		}
		best[i]=1;
	}
	else if(milk[i]!=maxx  && best[i]==1){
		if(!done) {
			counter++;
			done=true;
		}
		best[i]=0;
	}
}

cout<<counter<<endl;
return 0;
}
