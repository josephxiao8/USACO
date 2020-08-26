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

int n;
cin>>n;
set<pi> settx;
set<pi> setty;
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	settx.insert(mp(a,b));
	setty.insert(mp(b,a));
}

int ans=INT_MAX;
for(int l=0; l<=3; l++){
	for(int r=0; r<=3-l; r++){
		for(int d=0; d<=3-l-r; d++){
			int u=3-l-d-r;
			
			set<pi> sett;
			auto it=settx.begin();
			for(int i=0; i<l; i++){
				sett.insert(*it);
				it++;
			}
			it=(--settx.end());
			for(int i=0; i<r; i++){
				sett.insert(*it);
				it--;
			}
			it=setty.begin();
			for(int i=0; i<d; i++){
				sett.insert(*it);
				it++;
			}
			it=(--setty.end());
			for(int i=0; i<u; i++){
				sett.insert(*it);
				it--;
			}
			
			int left=INT_MAX, right=INT_MIN, down=INT_MAX, up=INT_MIN;
			for(auto x:settx){
				if(sett.count(x) || sett.count(mp(x.s,x.f))) continue;
				left=min(left,x.f);
				right=max(right,x.f);
				down=min(down,x.s);
				up=max(up,x.s);
			}
			ans=min(ans,(right-left)*(up-down));
		}
	}
}

cout<<ans<<"\n";
return 0;	
}

