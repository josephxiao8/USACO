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
typedef priority_queue<pi,vector<pi>,greater<pi>> pqg;
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

ofstream cout ("snowboots.out");
ifstream cin ("snowboots.in");

int n,b;
cin>>n>>b;
vi depth(n);
for(int i=0; i<n; i++) cin>>depth[i];
vpi boots(b);
for(int i=0; i<b; i++) cin>>boots[i].f>>boots[i].s; 

set<pi> q; //{boot #, tile #}
q.insert(mp(0,0));

vector<vector<bool> > already_tried(n,vector<bool>(b,false)); //true if we have tried the state before
already_tried[0][0]=true;

while(!q.empty()){
	int bootnum, tilenum;
	auto it=q.begin();
	tie(bootnum,tilenum)=*it; 
	q.erase(it);
	tilenum*=-1;
	if(tilenum==n-1){
		cout<<bootnum<<"\n";
		return 0;
	}
	
	for(int i=1; i<=boots[bootnum].s && tilenum+i<n; i++){
		if(depth[tilenum+i]<=boots[bootnum].f && !already_tried[tilenum+i][bootnum]){
			q.insert(mp(bootnum,-1*(tilenum+i)));
			already_tried[tilenum+i][bootnum]=true;
		}
	}
	
	for(int i=bootnum+1; i<b; i++){
		if(depth[tilenum]<=boots[i].f && !already_tried[tilenum][i]) {
			q.insert(mp(i,-1*(tilenum)));
			already_tried[tilenum][i]=true;
		}
	}
}

return 0;	
}
