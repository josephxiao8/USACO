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

ofstream cout ("cowqueue.out");
ifstream cin ("cowqueue.in");

int n;
cin>>n;

vpi v;
for(int i=0; i<n; i++){
	int t,d;
	cin>>t>>d;
	v.pb(mp(t,d));
}
sort(v.begin(), v.end());

int time;
int comp;
for(int i=0; i<n; i++){
	if(i==0) time=v[i].f+v[i].s;
	else{
		if(v[i].f==comp) time+=v[i].s;
		else{
			if(time<=v[i].f) time=v[i].f+v[i].s;
			else{
				time+=v[i].s;
			}
		}
	}
	comp=v[i].f;
}

cout<<time<<endl;
return 0;
}
