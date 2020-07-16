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

ofstream cout ("cbarn.out");
ifstream cin ("cbarn.in");

int n;
cin>>n;
vi rooms(n);
for(int i=0; i<n; i++) {
	cin>>rooms[i];
}

int ans=INT_MAX;
for(int i=0; i<n; i++){
	vi dis(n);
	for(int j=0; j<n; j++){
		int temp=j-i;
		if(temp<0) temp+=n;
		dis[j]=rooms[j]*(temp);
	}
	int minn=0;
	for(auto x:dis) minn+=x;
	ans=min(ans,minn);
}

cout<<ans<<endl;

return 0;
}
