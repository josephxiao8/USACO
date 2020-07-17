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

ofstream cout ("notlast.out");
ifstream cin ("notlast.in");

int n;
cin>>n;

map<char,int> mapp;
mapp['B']=0;
mapp['E']=1;
mapp['D']=2;
mapp['G']=3;
mapp['A']=4;
mapp['M']=5;
mapp['H']=6;

vpi v(7);
for(int i=0; i<7; i++){
	v[i]=mp(0,i);	
}

for(int i=0; i<n; i++){
	string name;
	int milk;
	cin>>name>>milk;
	v[mapp[name[0]]].f+=milk;
}
sort(v.begin(),v.end());

int ans=0;
int comp=-1;
for(int i=1; i<7; i++){
	if(v[i].f!=v[i-1].f){
		ans=v[i].s;
		comp=i;
		break;
	}
}

if(comp==-1 || (comp<6 && v[comp].f==v[comp+1].f)) cout<<"Tie";
else{
	if(ans==0)cout<<"Bessie";
	else if(ans==1){
		cout<<"Elsie";
	}
	else if(ans==2){
		cout<<"Daisy";
	}
	else if(ans==3){
		cout<<"Gertie";
	}
	else if(ans==4){
		cout<<"Annabelle";
	}
	else if(ans==5){
		cout<<"Maggie";
	}
	else{
		cout<<"Henrietta";
	}
}
	
cout<<endl;
return 0;	
}
