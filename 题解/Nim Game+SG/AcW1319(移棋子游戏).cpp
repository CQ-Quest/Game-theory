#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=2020,M=6010;
int h[N],e[M],ne[M],idx; //邻接表，下标 
int f[M]; //存储sg函数的值 
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
} 
int sg(int u){
	if(f[u]==-1) return f[u];
	set<int>S;
	for(int i=h[u];i>=0;i=ne[i]){
		int j=e[i];
		S.insert(sg(j));
	}
	for(int i=0;; i++)
	if(S.count(i)==0){
		f[u]=i;
		break;
	}
	return f[u];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	memset(h,-1,sizeof h);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	int ans=0;
	for(int i=0;i<k;i++){
		int u;cin>>u;
		ans^=sg(u);
	}
	if(!ans) puts("lose");
	else puts("win");
} 
