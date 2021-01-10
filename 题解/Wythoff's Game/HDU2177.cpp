#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)&&a&&b){
		if(a>b) swap(&a,&b);
		int n=b-a;
		double x=(sqrt(5.0)+1)/2;
		int temp=(int)n*x;
		if(temp==a) puts("0");
		else{
			puts("1");
			int k=n+temp;
			printf("%d %d\n",temp,k);
			for(int i=0;i<a;i++){
				n=i*(sqrt(5.0)+1)/2;
				if(a-i==n){
					printf("%d %d\n",a-i,a);
					break;
				}
			}
		}
	}
	return 0;
}
