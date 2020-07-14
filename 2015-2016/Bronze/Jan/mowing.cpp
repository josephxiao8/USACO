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

ofstream cout ("mowing.out");
ifstream cin ("mowing.in");

int n;
cin>>n;

int counter=0;
vector<char> step;
for(int i=0; i<n; i++){
	char dir;
	int dis;
	cin>>dir>>dis;
	for(int i=0; i<dis; i++) {
		step.pb(dir);
	}
	counter+=dis;
}

set<pi> visited;
map<pi,int> time;
int t=0, y=0, x=0, maxx=INT_MAX;
while(t<=counter){
	if(visited.count(mp(y,x))) maxx=min(maxx,t-time[mp(y,x)]);
	else visited.insert(mp(y,x));
	time[mp(y,x)]=t;
	t++;
	
	if(step[(t-1)]=='N'){
		y+=1;
	}
	else if(step[(t-1)]=='S'){
		y-=1;
	}
	else if(step[(t-1)]=='E'){
		x+=1;
	}
	else{
		x-=1;
	}
}

if(maxx==INT_MAX) cout<<-1<<endl;
else cout<<maxx<<endl;

return 0;
}
