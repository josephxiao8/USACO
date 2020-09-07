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

ofstream cout ("teleport.out");
ifstream cin ("teleport.in");

int n;
cin>>n;
vpi v(n);
for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s;

ll ans=0;
map<ll,ll> mapp; //the change in slope
for(int i=0; i<n; i++){
	ll a,b;
	tie(a,b)=v[i];
	ans+=abs(a-b);
	if(abs(a)>=abs(a-b)) continue;
	if(a*b<0){
		mapp[0]--;
		mapp[b]+=2;
		mapp[2*b]--;
	}
	else{
		mapp[2*(b-a)]--;
		mapp[b]+=2;
		mapp[2*a]--;
	}
}

ll dis=ans;
ll prevy=LONG_LONG_MAX;
ll prevslope=0;
for(auto x:mapp){
	ll y,slope;
	tie(y,slope)=x;
	if(prevy!=LONG_LONG_MAX){
		dis+=(y-prevy)*prevslope;
		ans=min(ans,dis);
	}
	prevy=y;
	prevslope+=slope;
}

cout<<ans<<"\n";
return 0;
}
