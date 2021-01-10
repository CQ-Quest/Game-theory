#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;
int Wythoff_Game(int a,int b){
	double x=(1+sqrt(5.0))/2;
     int n=b-a;
	if(a==(int)(x*n))  return 0;
	return 1;
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n>m) swap(&n,&m);
		printf("%d\n",Wythoff_Game(n,m)); 
	}
	return 0;
}
