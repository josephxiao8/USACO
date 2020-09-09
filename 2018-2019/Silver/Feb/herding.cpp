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

ofstream cout ("herding.out");
ifstream cin ("herding.in");

int n;
cin>>n;
vi v(n);
for(int i=0; i<n; i++) cin>>v[i];
sort(v.begin(), v.end());

int minn=INT_MAX;
for(int l=0; l<n-1; l++){
	int id;
	for(int r=l; r<n && v[r]-v[l]<=n-1; r++) id=r;
	minn=min(minn,n-(id-l+1));
}
if(v[n-2]-v[0]+1==n-1 && v[n-1]-v[n-2]>2) minn=2;
else if(v[n-1]-v[1]+1==n-1 && v[1]-v[0]>2) minn=2;

int sum=0;
for(int i=0; i<n-1; i++) sum+=v[i+1]-v[i]-1;

cout<<minn<<"\n"<<sum-min(v[1]-v[0]-1,v[n-1]-v[n-2]-1)<<"\n";
return 0;	
}



