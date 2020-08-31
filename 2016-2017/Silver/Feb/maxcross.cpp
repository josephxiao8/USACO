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

ofstream cout ("maxcross.out");
ifstream cin ("maxcross.in");

int n,k,b;
cin>>n>>k>>b;

vi v(b);
for(int i=0; i<b; i++) cin>>v[i];
sort(v.begin(), v.end());

vi prefix(n+1);
prefix[0]=0;
int pos=0;
for(int i=1; i<=n; i++){
	if(pos<b && i==v[pos]){
		pos++;
		prefix[i]=prefix[i-1]+1;
	}
	else prefix[i]=prefix[i-1];
}

int ans=INT_MAX;
for(int i=1; i<=n-k+1; i++){
	ans=min(ans, prefix[i+k-1]-prefix[i-1]);
}

cout<<ans<<"\n";
return 0;	
}
