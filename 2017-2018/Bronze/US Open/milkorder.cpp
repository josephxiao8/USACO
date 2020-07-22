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

ofstream cout ("milkorder.out");
ifstream cin ("milkorder.in");

int n,m,k;
cin>>n>>m>>k;

map<int,int> pos; //keeps track of the position of each cow and if the cow has been placed yet
for(int i=1; i<=n; i++) pos[i]=-1; //-1 indicates that the cow has not yet been placed into order

deque<int> social;
bool in_social=false;
for(int i=0; i<m; i++){
	int temp;
	cin>>temp;
	social.pb(temp);
	if(temp==1) in_social=true;
}


vi order(n,0); //0 indicates the spot is vacant
for(int i=0; i<k; i++){
	int a,b;
	cin>>a>>b;
	b--;
	order[b]=a;
	pos[a]=b;
}

if(pos[1]!=-1){
	cout<<pos[1]+1<<endl;
	return 0;
}

int position=n-1;
if(!in_social){
	while(!social.empty()){
		int back=social.back();
		social.pop_back();	
		if(pos[back]!=-1) position=pos[back]-1;
		else{ 
			while(order[position]!=0) position--;
			order[position]=back;
			pos[back]=position;
			position--;
		}
	}
	
	for(int i=0; i<n; i++){
		if(order[i]==0){
			cout<<i+1<<endl;
			return 0;
		}
	}
}

position=0;
while(!social.empty()){
	int front=social.front();
	social.pop_front();	
	
	if(pos[front]!=-1){ //it is already in order
		position=pos[front]+1;
	}
	
	else{ //it is not in order yet
		if(front==1){
			while(order[position]!=0) position++;
			cout<<position+1<<endl;
			return 0;
		}
		else {
			while(order[position]!=0) position++;
			order[position]=front;
			pos[front]=position;
			position++;
		}
	}
}

return 0;
}
