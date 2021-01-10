#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if(n%(m+1)==1) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}
