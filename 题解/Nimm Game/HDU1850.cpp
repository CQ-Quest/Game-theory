#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a[1000001];
int main(){
	int m;
	while(~scanf("%d",&m)&&m){
		memset(a,0,sizeof(a));
		int sum=0,num=0;
		for(int i=0;i<m;i++){
			scanf("%d",&a[i]);
			sum^=a[i];
		}
		if(!sum) puts("0");
		else{
			for(int i=0;i<m;i++){
				if(a[i]>(sum^a[i])) num++;
			}
			printf("%d\n",num);
		}	
	}
	return 0;
} 
