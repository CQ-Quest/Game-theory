//给你一个n*n的棋盘，每次移动一个位置，若该点未经过，则继续，不能移动者则失败 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		long long m=n*n-1;
		if(m%2==0) puts("ailyanlu");
		else puts("8600");
	}
	return 0;
}
