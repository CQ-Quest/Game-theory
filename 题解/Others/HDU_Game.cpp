#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int n,t,cnt=1,ans;
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	    if(i%6==0||i%6==2||i%6==5)
	    ans^=a[i];
	}
	printf("Case %d: ",cnt++);
		   if(ans) puts("Alice");
		   else puts("Bob");
	}
	return 0;
}
