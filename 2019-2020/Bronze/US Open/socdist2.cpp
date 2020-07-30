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

ofstream cout ("socdist2.out");
ifstream cin ("socdist2.in");

int n;
cin>>n;

vpi v;
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v.pb(mp(a,b));
}
sort(v.begin(), v.end());

int r=INT_MAX;
for(int i=0; i<n-1; i++){
	int a,b;
	tie(a,b)=v[i];
	
	if(b==0){
		if(i>0 && v[i-1].s==1) r=min(r,a-v[i-1].f);
		if(i<n-1 && v[i+1].s==1) r=min(r,v[i+1].f-a);
	}
}

if(r==INT_MAX) {
	cout<<1<<endl;
	return 0;
}

int counter=0;
bool found=false;
for(int i=0; i<n; i++){
	int a,b;
	tie(a,b)=v[i];
	
	if(b==1){
		if(!found) counter++;
		if(i<n-1 && v[i+1].s==1){
			if(v[i+1].f-a >= r) found=false;
			else found=true;
		}
	}
	else found=false;
}

cout<<counter<<endl;
return 0;
}
