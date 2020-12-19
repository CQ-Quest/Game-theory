/*http://acm.hdu.edu.cn/showproblem.php?pid=2147*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n&&m){
		if(n&1&&m&1) printf("What a pity!\n");
		else printf("Wonderful!\n");
	}
	return 0;
}
