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

ofstream cout ("balancing.out");
ifstream cin ("balancing.in");

int N,B;
cin>>N>>B;
vpi grid;
set<int> hor,ver;
for(int i=0; i<N; i++){
	int x,y;
	cin>>x>>y;
	grid.pb(mp(y,x));
	hor.insert(x-1);
	hor.insert(x+1);
	ver.insert(y-1);
	ver.insert(y+1);
}

int ans=INT_MAX;
for(auto x: hor){
	for(auto y:ver){
		int q1=0, q2=0, q3=0, q4=0;
		for(auto z:grid){
			if(z.f<y){
				if(z.s<x)q2++;
				else q1++;
			}
			else{
				if(z.s<x)q3++;
				else q4++;
			}	
		}
		ans=min(ans,max(max(q1,q2),max(q3,q4)));
	}
}

cout<<ans<<endl;

return 0;
}
