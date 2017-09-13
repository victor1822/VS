#include<stdio.h>

int x=10;

int f2(int c){
int d =c*100;
return d;
}

int f1(int a){
int b = a -f2(a);
return b;
}

int main(){
int w = f1(x);
	return 0;
}
