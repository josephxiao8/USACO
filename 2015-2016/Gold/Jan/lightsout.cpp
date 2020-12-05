#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<ti,vector<ti>,greater<ti>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("lightsout.out");
	ifstream cin ("lightsout.in");
	
	int n;
	cin>>n;
	vpi coords(n);
	for(int i=0; i<n; i++) cin>>coords[i].f>>coords[i].s;
	
	vector<string> v;
	vi dis(n,0);
	int totdis=0;
	for(int i=0; i<n; i++){
		int a,b,c,d,e,f;
		tie(a,b)=coords[(i-1+n)%n];
		tie(c,d)=coords[i];
		tie(e,f)=coords[(i+1)%n];
		
		string dir="";
		if(c-a==0){
			if(d-b>0) dir+='u';
			else dir+='d';
		}
		else{
			if(c-a>0) dir+='r';
			else dir+='l';
		}
		if(e-c==0){
			if(f-d>0) dir+='u';
			else dir+='d';
		}
		else{
			if(e-c>0) dir+='r';
			else dir+='l';
		}
		
		if(dir=="lu" || dir=="ur" || dir=="rd" || dir=="dl") v.pb("-"); //90 deg
		else v.pb("+"); //270 deg
		
		int prevtotdis=totdis;
		totdis+=abs(coords[(i+1)%n].f-coords[i].f)+abs(coords[(i+1)%n].s-coords[i].s);
		dis[(i+1)%n]=totdis;
		v.pb(to_string(totdis-prevtotdis));
	}
	
	multiset<string> sett;
	vector<vector<string>> substr(v.size(), vector<string>(v.size()));
	for(int i=0; i<v.size(); i++){
		for(int j=0; j+i<v.size(); j++){
			if(i==0) substr[j][j]=v[j];
			else substr[j][j+i]=substr[j][j+i-1]+v[j+i];
			sett.insert(substr[j][j+i]);
		}
	}
	
	int ans=0;
	for(int i=1; i<n; i++){
		if(2*dis[i]>=totdis) break;
		
		int tempdis=0;
		for(int j=i; j<n; j++){
			if(sett.count(substr[2*i][2*j])==1) break;
			tempdis+=dis[j+1]-dis[j];
			if(sett.count(substr[2*i][2*j+1])==1) break;
		}
		
		if(2*(dis[i]+tempdis)>=totdis) ans=max(ans, totdis-2*dis[i]);
		else ans=max(ans, 2*tempdis);
	}

	cout<<ans<<"\n";
	return 0;
}
