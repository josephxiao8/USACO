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

ofstream cout ("meeting.out");
ifstream cin ("meeting.in");

int n,m;
cin>>n>>m;
vector<pair<pi,pi>> paths;
for(int i=0; i<m; i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		paths.pb(mp(mp(a,b),mp(c,d)));
}


vector<vi> timesB(n+1); //field one is 1, field 2 is 2, ...
vector<vi> timesE(n+1) ; ////field one is 1, field 2 is 2, ...
timesB[1].pb(0);
timesE[1].pb(0);

for(int i=2; i<=n; i++){
	
	for(auto x:paths){
		int start=x.f.f;
		int dest=x.f.s;
		int addB=x.s.f;
		int addE=x.s.s;
		
		if(dest!=i) continue;
		
		for(auto y:timesB[start]){
			timesB[dest].pb(y+addB);
		}
		for(auto y:timesE[start]){
			timesE[dest].pb(y+addE);
		}
	}
}

sort(timesB[n].begin(), timesB[n].end());
sort(timesE[n].begin(), timesE[n].end());



int time=-1;
map<int,int> mapp;
for(auto x:timesB[n]) mapp[x]++;

for(auto x:timesE[n]){
	if (mapp[x]>0) {
		time=x;
		break;
	}
}
	
if(time==-1 || timesB[n].size()==0 || timesE[n].size()==0) cout<<"IMPOSSIBLE"<<endl;
else cout<<time<<endl;
		
return 0;
}
