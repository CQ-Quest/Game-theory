#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t,m,l;
	scanf("%d",&l);
	while(l--){
	int cnt=0;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		cnt^=n%(m+1);
	}
	if(!cnt) printf("Yes\n");
	else printf("No\n");
}
  return 0;
}
