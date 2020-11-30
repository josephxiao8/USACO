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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("cereal.out");
ifstream cin ("cereal.in");

int n,m;
cin>>n>>m;

vpi cereal(n);
for(int i=0; i<n; i++){
	cin>>cereal[i].f>>cereal[i].s;
	cereal[i].f--;
	cereal[i].s--;
}

vpi took(m, {-1,-1}); //records last person to take cereal i as their first pick, second pick
vector<pair<pi,pi>> last(n); //records "took" for each cow
for(int i=0; i<n; i++){
	last[i]=mp(took[cereal[i].f], took[cereal[i].s]);
	took[cereal[i].f].f=i;
	took[cereal[i].s].s=i;
}

vpi iteration(n, {-1,-1}); //stores the iteration in which each cow begins to not take thier first choice, second choice
vpi pickdrop(n,{0,0}); //stores "buckets" to pick and drop for caculation of values to print out below
pickdrop[0].f++;
if(1<n) pickdrop[1].s++;
iteration[0]=mp(0, -1);

for(int i=1; i<n; i++){
	int a,b,c,d;
	tie(a,b)=last[i].f;
	tie(c,d)=last[i].s;
	
	
	if(b!=-1) iteration[i].f=max(a+1, iteration[b].s+1);
	else iteration[i].f=max(a+1, b+1);
	
	if(d!=-1) iteration[i].s=max(c+1, iteration[d].s+1);
	else iteration[i].s=max(c+1, d+1);
	
	if(iteration[i].s>=iteration[i].f) {
		pickdrop[iteration[i].f].f++;
		iteration[i].s--;
	}
	else {
		pickdrop[iteration[i].s].f++;
		iteration[i].s=iteration[i].f-1;
	}
	if(i+1<n) pickdrop[i+1].s++;
	
	iteration[i].f=i;
}

int count=0;
for(int i=0; i<n; i++){
	count+=pickdrop[i].f-pickdrop[i].s;
	cout<<count<<endl;
}

return 0;
}
