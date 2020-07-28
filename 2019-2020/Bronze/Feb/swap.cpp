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
 
typedef priority_queue<pair<int,string>> pq;
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

ofstream cout ("swap.out");
ifstream cin ("swap.in");

int n,k;
cin>>n>>k;

vi v(n);
vector<vi> comp;
for(int i=0; i<n; i++) v[i]=i+1;
comp.pb(v);

pi a,b;
cin>>a.f>>a.s>>b.f>>b.s;
for(int i=0; i<k; i++){
	reverse(v.begin()+a.f-1,v.begin()+a.s);
	reverse(v.begin()+b.f-1,v.begin()+b.s);
	
	if(v==comp[0]) {
		for(auto x:comp[(k-i-1)%comp.size()]) cout<<x<<endl;
		return 0;
	}
	comp.pb(v);
}

for(auto x:v) cout<<x<<endl;
return 0;
}
