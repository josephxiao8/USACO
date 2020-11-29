#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


ll n,m;
vpl intervals;

bool possible(ll k){
	ll count=0;
	ll start=intervals[0].f;
	for(ll i=0; i<m; i++){
		ll dis=intervals[i].s-max(intervals[i].f,start);
		if(dis<0) continue;
		else{
			count+=dis/k +1;
			start=max(intervals[i].f,start)+(dis/k+1)*k;
			if(count>=n) return true;
		}
	}
	
	return false;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("socdist.out");
ifstream cin ("socdist.in");

cin>>n>>m;

intervals=vpl(m);
for(ll i=0; i<m; i++) {
	cin>>intervals[i].f>>intervals[i].s;
}
sort(intervals.begin(), intervals.end());

ll lower=intervals[0].f, upper=intervals[m-1].s;
ll k=1;
for(ll b=((upper-lower)/(n-1))/2; b>=1; b/=2){
	while(k+b<=(upper-lower)/(n-1) && possible(k+b)) k+=b;
}

cout<<k<<"\n";
return 0;	
}

