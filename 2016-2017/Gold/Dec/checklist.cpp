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
typedef priority_queue<ti,vector<ti>,greater<ti>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


ll dis(pl a, pl b){
	ll x1,y1,x2,y2;
	tie(x1,y1)=a;
	tie(x2,y2)=b;
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("checklist.out");
	ifstream cin ("checklist.in");
	
	ll h,g;
	cin>>h>>g;
	vpl hol(h+1);
	vpl gue(g+1);
	
	for(ll i=1; i<=h; i++) cin>>hol[i].f>>hol[i].s;
	for(ll i=1; i<=g; i++) cin>>gue[i].f>>gue[i].s;
	
	vector<vl> dph(h+1, vl(g+1,LONG_LONG_MAX));
	vector<vl> dpg(g+1, vl(h+1,LONG_LONG_MAX));
	
	dph[1][0]=0;
	for(ll size=2; size<=h+g; size++){
		
		for(ll i=0; i<=size; i++){ 
			ll j=size-i;
			if(i>h || j>g) continue;
			if(i-1>=0 && dph[i-1][j]!=LONG_LONG_MAX) dph[i][j]=min(dph[i][j], dph[i-1][j]+dis(hol[i-1], hol[i]));
			if(i-1>=0 && j>0 && dpg[j][i-1]!=LONG_LONG_MAX) dph[i][j]=min(dph[i][j], dpg[j][i-1]+dis(gue[j],hol[i])); 
		}
		
		for(ll i=0; i<=size; i++){
			ll j=size-i;
			if(i>g || j>h) continue;
			if(i-1>=0 && dpg[i-1][j]!=LONG_LONG_MAX) dpg[i][j]=min(dpg[i][j], dpg[i-1][j]+dis(gue[i-1], gue[i]));
			if(i-1>=0 && j>0 && dph[j][i-1]!=LONG_LONG_MAX) dpg[i][j]=min(dpg[i][j], dph[j][i-1]+dis(hol[j], gue[i]));
		}
		
	}
	
	cout<<dph[h][g]<<"\n";
	return 0;
	
}
