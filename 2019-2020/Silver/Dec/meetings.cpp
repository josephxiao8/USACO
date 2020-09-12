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
typedef priority_queue<pi,vector<pi>,greater<pi> > pqg;
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

ofstream cout ("meetings.out");
ifstream cin ("meetings.in");

int n,l; 
cin>>n>>l;
vpi v;
int tot_w=0;
vi right;
vi left;
for(int i=0; i<n; i++){
	int a,b,c;
	cin>>a>>b>>c;
	v.pb(mp(b,a));
	if(c==1) right.pb(b);
	else left.pb(b);
	tot_w+=a;
}
sort(v.begin(), v.end());
sort(right.begin(), right.end());
sort(left.begin(), left.end());

vpi times;
auto it=right.begin();
auto jt=left.begin();
for(int i=0; i<n; i++){
	int a,b;
	tie(b,a)=v[i];
	if(i<left.size()){
		times.pb(mp(*jt,a));
		jt++;
	}
	else{
		times.pb(mp(l-*it,a));
		it++;
	}
}
sort(times.begin(), times.end());

int w=0;
int time_final;
for(int idx=0; idx<n; idx++){
	w+=times[idx].s; 
	if(2*w>=tot_w){
		time_final=times[idx].f;
		break;
	}
}

int ans=0;
for(auto kt=right.begin(); kt!=right.end(); kt++){
	ans+=distance(lb(left.begin(), left.end(),(*kt)),ub(left.begin(), left.end(), 2*time_final+*kt));
}

cout<<ans<<"\n";
return 0;	
}

