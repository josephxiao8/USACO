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


vi v;
int n;

int time(int k){
	pqg q;
	for(int i=0; i<k; i++) q.push(v[i]);
	for(int i=k; i<n; i++){
		int temp=q.top(); q.pop();
		temp+=v[i];
		q.push(temp);
	}
	while(q.size()!=1) q.pop();
	return q.top();
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("cowdance.out");
ifstream cin ("cowdance.in");

int tmax;
cin>>n>>tmax;

v=vi(n);
for(int i=0; i<n; i++) cin>>v[i];

int k=1;
for(int b=n/2; b>=1; b/=2){
	while(k+b<=n && time(k+b)>tmax) k+=b;
}

cout<<k+1<<"\n";
return 0;	
}

