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

ofstream cout ("moocrypt.out");
ifstream cin ("moocrypt.in");

int y,x;
cin>>y>>x;
vector<vector<char> > grid(y, vector<char>(x));
for(int j=0; j<y; j++){
	for(int i=0; i<x; i++){
	cin>>grid[j][i];	
	}
}

map<string,int> mapp;

//horizontal
for(int j=0; j<y; j++){
	for(int i=0; i<x-2; i++){
		if(grid[j][i]!=grid[j][i+1] && grid[j][i+1]==grid[j][i+2]) {
			string temp="";
			temp=temp+grid[j][i]+grid[j][i+1]+grid[j][i+2];	
			if(temp[0]=='M' || temp[1]=='O') ;
			else mapp[temp]++;
		}
		else if(grid[j][i]==grid[j][i+1] && grid[j][i+1]!=grid[j][i+2]){
			string temp="";
			temp=temp+grid[j][i+2]+grid[j][i+1]+grid[j][i];	
			if(temp[0]=='M' || temp[1]=='O') ;
			else mapp[temp]++;
		}
	}
}


//vertical
for(int i=0; i<x; i++){
	for(int j=0; j<y-2; j++){
		if(grid[j][i]!=grid[j+1][i] && grid[j+1][i]==grid[j+2][i]) {
			string temp="";
			temp=temp+grid[j][i]+grid[j+1][i]+grid[j+2][i];	
			if(temp[0]=='M' || temp[1]=='O') ;
			else mapp[temp]++;
		}
		else if(grid[j][i]==grid[j+1][i] && grid[j+1][i]!=grid[j+2][i]){
			string temp="";
			temp=temp+grid[j+2][i]+grid[j+1][i]+grid[j][i];	
			if(temp[0]=='M' || temp[1]=='O');
			else mapp[temp]++;
		}
	}
}

//diagonals
for(int j=0; j<y; j++){
	for(int i=0; i<x; i++){
		
		if(j-2>=0 && i+2<x){
			if(grid[j][i]!=grid[j-1][i+1] && grid[j-1][i+1]==grid[j-2][i+2]) {
				string temp="";
				temp=temp+grid[j][i]+grid[j-1][i+1]+grid[j-2][i+2];	
				if(temp[0]=='M' || temp[1]=='O'); 
				else mapp[temp]++;
			}
		}
		if(j-2>=0 && i-2>=0){
			if(grid[j][i]!=grid[j-1][i-1] && grid[j-1][i-1]==grid[j-2][i-2]) {
				string temp="";
				temp=temp+grid[j][i]+grid[j-1][i-1]+grid[j-2][i-2];	
				if(temp[0]=='M' || temp[1]=='O') ;
				else mapp[temp]++;
			}
		}
		if(j+2<y && i+2<x){
			if(grid[j][i]!=grid[j+1][i+1] && grid[j+1][i+1]==grid[j+2][i+2]) {
				string temp="";
				temp=temp+grid[j][i]+grid[j+1][i+1]+grid[j+2][i+2];	
				if(temp[0]=='M' || temp[1]=='O') ;
				else mapp[temp]++;
			}
		}
		if(j+2<y && i-2>=0){
			if(grid[j][i]!=grid[j+1][i-1] && grid[j+1][i-1]==grid[j+2][i-2]) {
				string temp="";
				temp=temp+grid[j][i]+grid[j+1][i-1]+grid[j+2][i-2];	
				if(temp[0]=='M' || temp[1]=='O') ;
				else mapp[temp]++;
			}
		}
	}
}

int maxx=0;
for(auto x:mapp) maxx=max(maxx,x.s);
cout<<maxx<<endl;
return 0;
}
