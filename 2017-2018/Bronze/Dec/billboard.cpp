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

ofstream cout ("billboard.out");
ifstream cin ("billboard.in");

int ax1,ay1,ax2,ay2;
cin>>ax1>>ay1>>ax2>>ay2;
int bx1,by1,bx2,by2;
cin>>bx1>>by1>>bx2>>by2;
int cx1,cy1,cx2,cy2;
cin>>cx1>>cy1>>cx2>>cy2;

int ans=0;
int area_blocked;

if(cx1>=ax2 || cx2<=ax1 || cy1>=ay2 || cy2<=ay1 ) area_blocked=0; 
else if((cx1<ax1 && ax2<cx2) && (cy1<ay1 && ay2<cy2)) area_blocked=((ax2-ax1)*(ay2-ay1));
else area_blocked=(min(cx2,ax2)-max(cx1,ax1))*(min(cy2,ay2)-max(cy1,ay1));
ans+=((ax2-ax1)*(ay2-ay1))-area_blocked;

if(cx1>=bx2 || cx2<=bx1 || cy1>=by2 || cy2<=by1 ) area_blocked=0; 
else if((cx1<bx1 && bx2<cx2) && (cy1<by1 && by2<cy2)) area_blocked=((bx2-bx1)*(by2-by1));
else area_blocked=(min(cx2,bx2)-max(cx1,bx1))*(min(cy2,by2)-max(cy1,by1));
ans+=((bx2-bx1)*(by2-by1))-area_blocked;

cout<<ans<<endl;
return 0;	
}
