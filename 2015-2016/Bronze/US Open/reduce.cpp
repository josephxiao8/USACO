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

ofstream cout ("reduce.out");
ifstream cin ("reduce.in");

ll n;
cin>>n;

set<pl> grid;
map<ll,ll> hor;
map<ll,ll> ver;
ll max_x=INT_MIN, min_x=INT_MAX, max_y=INT_MIN, min_y=INT_MAX;
for(ll i=0; i<n; i++){
	ll x,y;
	cin>>x>>y;
	max_x=max(max_x,x);
	min_x=min(min_x,x);
	max_y=max(max_y,y);
	min_y=min(min_y,y);
	grid.insert(mp(x,y));
	hor[x]++;
	ver[y]++;
}


ll ans=(max_x-min_x)*(max_y-min_y);
if(hor[min_x]==1){
	ll temp_max_x=INT_MIN, temp_min_x=INT_MAX, temp_max_y=INT_MIN, temp_min_y=INT_MAX;
	for(auto cow:grid){
		if(cow.f==min_x) continue;;
		temp_max_x=max(temp_max_x,cow.f);
		temp_min_x=min(temp_min_x,cow.f);
		temp_max_y=max(temp_max_y,cow.s);
		temp_min_y=min(temp_min_y,cow.s);
	}
	
	if(temp_min_x==temp_max_x || temp_min_y==temp_max_y){
		cout<<0<<endl;
		return 0;
	}
	
	else {
		ll temp=(temp_max_x-temp_min_x)*(temp_max_y-temp_min_y);
		ans=min(ans,temp);
	}
}

if(hor[max_x]==1){
ll temp_max_x=INT_MIN, temp_min_x=INT_MAX, temp_max_y=INT_MIN, temp_min_y=INT_MAX;
	for(auto cow:grid){
		if(cow.f==max_x) continue;;
		temp_max_x=max(temp_max_x,cow.f);
		temp_min_x=min(temp_min_x,cow.f);
		temp_max_y=max(temp_max_y,cow.s);
		temp_min_y=min(temp_min_y,cow.s);
	}
	
	if(temp_min_x==temp_max_x || temp_min_y==temp_max_y){
		cout<<0<<endl;
		return 0;
	}
	
	else {
		ll temp=(temp_max_x-temp_min_x)*(temp_max_y-temp_min_y);
		ans=min(ans,temp);
	}
}

if(ver[min_y]==1){
ll temp_max_x=INT_MIN, temp_min_x=INT_MAX, temp_max_y=INT_MIN, temp_min_y=INT_MAX;
	for(auto cow:grid){
		if(cow.s==min_y) continue;;
		temp_max_x=max(temp_max_x,cow.f);
		temp_min_x=min(temp_min_x,cow.f);
		temp_max_y=max(temp_max_y,cow.s);
		temp_min_y=min(temp_min_y,cow.s);
	}
	
	if(temp_min_x==temp_max_x || temp_min_y==temp_max_y){
		cout<<0<<endl;
		return 0;
	}
	
	else {
		ll temp=(temp_max_x-temp_min_x)*(temp_max_y-temp_min_y);
		ans=min(ans,temp);
	}
}

if(ver[max_y]==1){
ll temp_max_x=INT_MIN, temp_min_x=INT_MAX, temp_max_y=INT_MIN, temp_min_y=INT_MAX;
	for(auto cow:grid){
		if(cow.s==max_y) continue;;
		temp_max_x=max(temp_max_x,cow.f);
		temp_min_x=min(temp_min_x,cow.f);
		temp_max_y=max(temp_max_y,cow.s);
		temp_min_y=min(temp_min_y,cow.s);
	}
	
	if(temp_min_x==temp_max_x || temp_min_y==temp_max_y){
		cout<<0<<endl;
		return 0;
	}
	
	else {
		ll temp=(temp_max_x-temp_min_x)*(temp_max_y-temp_min_y);
		ans=min(ans,temp);
	}
}

cout<<ans<<endl;

return 0;
}
