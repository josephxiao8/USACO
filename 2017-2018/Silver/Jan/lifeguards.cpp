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


bool comp(pi a, pi b){
	if(a.f==b.f) return a.s>b.s;
	else return a.f<b.f;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("lifeguards.out");
ifstream cin ("lifeguards.in");

int n;
cin>>n;

vector<tuple<int,int,int> > v; 
vpi interval(n);
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v.pb(make_tuple(a,0,i));
	v.pb(make_tuple(b,1,i));
	interval[i]=mp(a,b);
}
sort(v.begin(), v.end());
sort(interval.begin(), interval.end(), comp);

int covered=0;
for(int i=0; i<n; i++){
	int id;
	int rightmost=interval[i].f;
	for(int j=i; j<n && interval[j].f<=rightmost; j++){
		id=j;
		rightmost=max(rightmost,interval[j].s);
	}
	covered+=rightmost-interval[i].f;
	i=id;
}

set<int> sett;
vi time(n,0); 
int single_id;
bool prev_single=false;
for(int i=0; i<v.size(); i++){
	int id;
	vi add;
	for(int j=i; j<v.size() && get<0>(v[j])==get<0>(v[i]); j++){
		id=j;
		int a,b,c;
		tie(a,b,c)=v[j];
		if(b==0) add.pb(c);
		else sett.erase(c);
	}
	
	if((sett.size()==1 || sett.size()==0) && prev_single){
		time[single_id]+=get<0>(v[i])-get<0>(v[i-1]);
	}
	
	for(auto x:add) sett.insert(x);
	if(sett.size()==1) {
		prev_single=true;
		single_id=*sett.begin();
	}
	else prev_single=false;
	i=id;
}

int minn=INT_MAX;
for(auto x:time) minn=min(minn,x);

cout<<covered-minn<<"\n";
return 0;	
}

