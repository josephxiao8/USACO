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
typedef priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pqg;
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

ofstream cout ("convention2.out");
ifstream cin ("convention2.in");

int n;
cin>>n;
vector<tuple<int,int,int> > v;
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v.pb(make_tuple(a,i,b));
}
sort(v.begin(), v.end());

int ans=0;
int pos=0;
pqg q;
while(pos!=n){
	
	int time=get<0>(v[pos]);
	
	for(int i=pos; i<n && get<0>(v[i])<=time; i++){
		pos++;
		int a,b,c;
		tie(a,b,c)=v[i];
		q.push(make_tuple(b,a,c));
	}
	
	while(!q.empty()){
		int a,b,c;
		tie(a,b,c)=q.top(); q.pop();
		ans=max(ans, time-b);
		time+=c;
		
		for(int i=pos; i<n && get<0>(v[i])<=time; i++){
			pos++;
			int e,f,g;
			tie(e,f,g)=v[i];
			q.push(make_tuple(f,e,g));
		}
	}
}

cout<<ans<<"\n";
return 0;	
}

