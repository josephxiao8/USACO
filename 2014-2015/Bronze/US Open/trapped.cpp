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

ofstream cout ("trapped.out");
ifstream cin ("trapped.in");

int n;
cin>>n;

vpi road;
for(int i=0; i<n; i++){
	int size, pos;
	cin>>size>>pos;
	road.pb(mp(pos,size));	
}

sort(road.begin(), road.end());

int interval=0;
for(int i=0; i<n-1; i++){
	int l=i, r=i+1;
	bool go_l=true, go_r=true;
	while(go_l || go_r){

		go_l=true;
		go_r=true;
		
		if(go_l){
			if(l==-1) break;
			int temp=abs(road[r].f-road[l].f);
			if(temp>road[l].s) l--;
			else go_l=false;
		}
		if(go_r){
			if(r==n) break;
			int temp=abs(road[r].f-road[l].f);
			if(temp>road[r].s) r++;
			else go_r=false;
		}		
	}
	if(r==n || l==-1);
	else interval+=abs(road[i+1].f-road[i].f); 
}

cout<<interval<<endl;

return 0;
}
