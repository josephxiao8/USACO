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

ofstream cout ("family.out");
ifstream cin ("family.in");

int n;
cin>>n;
string aa,bb;
cin>>aa>>bb;

vector<vi> adj(1e3);
map<string,int> mapp;
map<int,int> mother;
set<string> sett;
int counter=1;

for(int i=0; i<n; i++){
	string s1,s2;
	cin>>s1>>s2;
	
	if(!sett.count(s1)){
	    sett.insert(s1);
	    mapp[s1]=counter;
	    counter++;	
	}
	
	if(!sett.count(s2)){
	    sett.insert(s2);
	    mapp[s2]=counter;
	    counter++;	
	}
	adj[mapp[s1]].pb(mapp[s2]);
	mother[mapp[s2]]=mapp[s1];
}

int ans_aa=mapp[aa]; 
int ans_bb=mapp[bb]; 
while(mother[ans_aa]) ans_aa=mother[ans_aa];
while(mother[ans_bb]) ans_bb=mother[ans_bb];

if(ans_aa!=ans_bb){
	cout<<"NOT RELATED"<<endl;
	return 0;
}

//bfs
vi dis(1e3);
vi prev(1e3);
queue<int> q;
q.push(ans_aa);
dis[ans_aa]=0;
while(!q.empty()){
	int start=q.front();
	q.pop();
	for(auto u:adj[start]){
		q.push(u);
		dis[u]=dis[start]+1;
		prev[u]=start;
	}
}

int dif=abs(dis[mapp[aa]]-dis[mapp[bb]]);
if(dif==0){
	if(prev[mapp[aa]]==prev[mapp[bb]]) {
		cout<<"SIBLINGS"<<endl;
		return 0;
	}
}

else if(dif==1){
	if(dis[mapp[aa]]<dis[mapp[bb]]){
		if(prev[mapp[bb]]==mapp[aa]){ 
			cout<<aa<<" is the mother of "<<bb<<endl;
			return 0;
		}
		else{ 
			if(prev[mapp[aa]]==prev[prev[mapp[bb]]]) {
				cout<<aa<<" is the aunt of "<<bb<<endl;
				return 0;
			}
		}
	}
	else{
		if(prev[mapp[aa]]==mapp[bb]){  
			cout<<bb<<" is the mother of "<<aa<<endl;
			return 0;
		}
		else{ 
			if(prev[mapp[bb]]==prev[prev[mapp[aa]]]) {
				cout<<bb<<" is the aunt of "<<aa<<endl;
				return 0;
			}
		}
	}
}

else{
	if(dis[mapp[aa]]<dis[mapp[bb]]) {
		int temp=mapp[bb];
		for(int i=0; i<dif; i++) temp=prev[temp];
		
		if(temp==mapp[aa]){ 
			cout<<aa<<" is the ";
			for(int i=0; i<dif-2; i++) cout<<"great-";
			cout<<"grand-mother of "<<bb<<endl;
			return 0;
		}
		else{ 
			if(prev[temp]==prev[mapp[aa]]){
				cout<<aa<<" is the ";
				for(int i=0; i<dif-1; i++) cout<<"great-";
				cout<<"aunt of "<<bb<<endl;
				return 0;
			}
		}
	}
	
	else{
		int temp=mapp[aa];
		for(int i=0; i<dif; i++) temp=prev[temp];
		
		if(temp==mapp[bb]){
			cout<<bb<<" is the ";
			for(int i=0; i<dif-2; i++) cout<<"great-";
			cout<<"grand-mother of "<<aa<<endl;
			return 0;
		}
		else{ 
			if(prev[temp]==prev[mapp[bb]]){
				cout<<bb<<" is the ";
				for(int i=0; i<dif-1; i++) cout<<"great-";
				cout<<"aunt of "<<aa<<endl;
				return 0;
			}
		}
	}
}

cout<<"COUSINS"<<endl;
return 0;
}
