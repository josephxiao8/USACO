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

ofstream cout ("socdist1.out");
ifstream cin ("socdist1.in");

int n;
string s;
cin>>n>>s;

vi vacant;
int counter=0;
for(int i=0; i<n; i++){
	if(s[i]=='1'){
		if(i!=0) {
			vacant.pb(counter);
			counter=0;
		}
	}
	else{
		counter++;
		if(i==n-1) vacant.pb(counter);
	}
}

int minn=1e9, maxx=-1e9, second_maxx=-1e9;
for(int i=0; i<vacant.size(); i++){
	if(i==0 && s[0]=='0') continue;
	if(i==vacant.size()-1 && s[n-1]=='0') continue;
	if(vacant[i]>=maxx){
		second_maxx=maxx;
		maxx=vacant[i];
	}
	minn=min(minn,vacant[i]);
}
minn++;

if(vacant.size()==1 && s[0]=='0' && s[n-1]=='0'){
	cout<<(vacant[0]-2)+1<<endl;
	return 0;
}

int comp=-1e9;
if(s[0]=='0' && vacant[0]>=2){
	int temp=(vacant[0]-2)/2+1;
	comp=max(comp,temp);
}

if(s[n-1]=='0' && vacant[vacant.size()-1]>=2){
	int temp=(vacant[vacant.size()-1]-2)/2+1;
	comp=max(comp,temp);
}

if(s[0]=='0' && s[n-1]=='0'){
	int temp=vacant[0];
	int temp2=vacant[vacant.size()-1];
	comp=max(comp,min(temp,temp2));
}

if(s[0]=='0' && maxx!=-1*1e9){
	int temp=vacant[0];
	int temp2=(maxx-1)/2 +1;
	comp=max(comp,min(temp,temp2));
}

if(s[n-1]=='0' && maxx!=-1*1e9){
	int temp=vacant[vacant.size()-1];
	int temp2=(maxx-1)/2+1;
	comp=max(comp,min(temp,temp2));
}

if(maxx!=-1*1e9 && second_maxx!=-1*1e9){
	int temp=(second_maxx-1)/2 +1;
	comp=max(comp,temp);
}

if(maxx!=-1*1e9){
	int temp=(maxx-2)/3 +1;
	comp=max(comp,temp);
}

cout<<min(minn,comp)<<endl;
return 0;	
}
