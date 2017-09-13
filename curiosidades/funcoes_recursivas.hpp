#ifndef FUNCOES_RECURSIVAS_HPP_INCLUDED
#define FUNCOES_RECURSIVAS_HPP_INCLUDED
#include<vector>
using namespace std;

int soma(int n){
if(n==0)return 0;
else return n+soma(n-1);
}

int fatorial(int n){
if(n==0||n==1)return 1;
if(n>0)return n*fatorial(n-1);
}

#endif // FUNCOESRECURSIVAS_HPP_INCLUDED
