#ifndef _MYGL_H_
#define _MYGL_H_
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "definitions.h"
using namespace std;
//subrotinas simples

double vet1_prod_escalar_vet2_3(double vet1[3],double vet2[3]){
    double produto_escalar=0;
for(int i=0;i<3;i++){
    produto_escalar+=vet1[i]*vet2[i];
}
return produto_escalar;
}

void vet1_igual_vet2_3d(double v1[3],double v2[3]){
for(int i=0;i<3;i++){
    v1[i]=v2[i];
}
}//funcioando

void vet1_prod_vetorial_vet2_3(double A[3], double B[3]){
    double C[3];
   C[0] = B[1]*A[2] - B[2]*A[1];
   C[1] = B[2]*A[0] - B[0]*A[2];
   C[2] = B[1]*A[0] - B[0]*A[1];
   for(int i=0;i<3;i++){
   A[i]=C[i];
   }
}//funcionando

void iguala_matriz(double A[4][4],double B[4][4]){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        A[i][j]=B[i][j];
    }
}
}//funcionando

void vet1_menos_vet2_3(double vet1[3],double vet2[3]){
for(int i=0;i<3;i++){
    vet1[i]=vet1[i]-vet2[i];
}
}//funcionando

void vet_mult_valor_3(double vet[3],double val){
for(int i=0;i<3;i++){
    vet[i]*=val;
}
}

Matriz_round(double A[4][4]){
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        A[i][j]=round(A[i][j]);
    }
}
}

void vet_normaliza_3(double vet[3]){
double norma=sqrt(vet[0]*vet[0]+vet[1]*vet[1]+vet[2]*vet[2]);
for(int i=0;i<3;i++){
    vet[i]=vet[i]/norma;
}
}

void Matrxvet4(double A[4][4],double B[4]){
double C[4];
C[0]=A[0][0]*B[0]+A[0][1]*B[1]+A[0][2]*B[2]+A[0][3]*B[3];
C[1]=A[1][0]*B[0]+A[1][1]*B[1]+A[1][2]*B[2]+A[1][3]*B[3];
C[2]=A[2][0]*B[0]+A[2][1]*B[1]+A[2][2]*B[2]+A[2][3]*B[3];
C[3]=A[3][0]*B[0]+A[3][1]*B[1]+A[3][2]*B[2]+A[3][3]*B[3];
for(int i=0;i<4;i++){
B[i]=C[i];
}
}

void Matr_mult(double A[4][4],double B[4][4]){
double C[4][4];
C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0]+A[0][2]*B[2][0]+A[0][3]*B[3][0];
C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1]+A[0][2]*B[2][1]+A[0][3]*B[3][1];
C[0][2]=A[0][0]*B[0][2]+A[0][1]*B[1][2]+A[0][2]*B[2][2]+A[0][3]*B[3][2];
C[0][3]=A[0][0]*B[0][3]+A[0][1]*B[1][3]+A[0][2]*B[2][3]+A[0][3]*B[3][3];

C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0]+A[1][2]*B[2][0]+A[1][3]*B[3][0];
C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1]+A[1][2]*B[2][1]+A[1][3]*B[3][1];
C[1][2]=A[1][0]*B[0][2]+A[1][1]*B[1][2]+A[1][2]*B[2][2]+A[1][3]*B[3][2];
C[1][3]=A[1][0]*B[0][3]+A[1][1]*B[1][3]+A[1][2]*B[2][3]+A[1][3]*B[3][3];

C[2][0]=A[2][0]*B[0][0]+A[2][1]*B[1][0]+A[2][2]*B[2][0]+A[2][3]*B[3][0];
C[2][1]=A[2][0]*B[0][1]+A[2][1]*B[1][1]+A[2][2]*B[2][1]+A[2][3]*B[3][1];
C[2][2]=A[2][0]*B[0][2]+A[2][1]*B[1][2]+A[2][2]*B[2][2]+A[2][3]*B[3][2];
C[2][3]=A[2][0]*B[0][3]+A[2][1]*B[1][3]+A[2][2]*B[2][3]+A[2][3]*B[3][3];

C[3][0]=A[3][0]*B[0][0]+A[3][1]*B[1][0]+A[3][2]*B[2][0]+A[3][3]*B[3][0];
C[3][1]=A[3][0]*B[0][1]+A[3][1]*B[1][1]+A[3][2]*B[2][1]+A[3][3]*B[3][1];
C[3][2]=A[3][0]*B[0][2]+A[3][1]*B[1][2]+A[3][2]*B[2][2]+A[3][3]*B[3][2];
C[3][3]=A[3][0]*B[0][3]+A[3][1]*B[1][3]+A[3][2]*B[2][3]+A[3][3]*B[3][3];
for(int i=0;i<4;i++){
for(int j=0;j<4;j++){
   A[i][j]=C[i][j];
}
}
}


void soma1_vetor(double V[4]){
for(int i=0;i<4;i++){
    V[i]+=1;
}
}

void printa_vetor(double V[4]){
cout<<endl<<"-----------------"<<endl;
for(int i=0;i<4;i++){
    cout<<V[i]<<endl;
}
}

void printa_vetor3d(double V[3]){
cout<<endl<<"-----------------"<<endl;
for(int i=0;i<3;i++){
    cout<<V[i]<<endl;
}
}

void printa_matriz(double A[4][4]){
cout<<endl<<"-----------------"<<endl;
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
    if(j==3){cout<<" "<<A[i][j]<<" "<<endl;}else cout<<" "<<A[i][j]<<" ";
    }
}


}

carrega_proj(double A[4][4],double d){
    //primeira linha
A[0][0]=1;
A[0][1]=0;
A[0][2]=0;
A[0][3]=0;
    //segunda linha
A[1][0]=0;
A[1][1]=1;
A[1][2]=0;
A[1][3]=0;
    //terceira linha
A[2][0]=0;
A[2][1]=0;
A[2][2]=1;
A[2][3]=d;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=-1/d;
A[3][3]=0;
}

carrega_view(double A[4][4],double xc[3],double yc[3],double zc[3]){
    //primeira linha
A[0][0]=xc[0];
A[0][1]=xc[1];
A[0][2]=xc[2];
A[0][3]=0;
    //segunda linha
A[1][0]=yc[0];
A[1][1]=yc[1];
A[1][2]=yc[2];
A[1][3]=0;
    //terceira linha
A[2][0]=zc[0];
A[2][1]=zc[1];
A[2][2]=zc[2];
A[2][3]=0;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=0;
A[3][3]=1;
}

void carrega_identidade(double A[4][4]){
for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
    if(i==j) A[i][j]=1;
else A[i][j]=0;
}
}}

void carrega_escala(double A[4][4],int x, int y, int z){
    //primeira linha
A[0][0]=x;
A[0][1]=0;
A[0][2]=0;
A[0][3]=0;
    //segunda linha
A[1][0]=0;
A[1][1]=y;
A[1][2]=0;
A[1][3]=0;
    //terceira linha
A[2][0]=0;
A[2][1]=0;
A[2][2]=z;
A[2][3]=0;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=0;
A[3][3]=1;

}

void carrega_translacao(double A[4][4],double x, double y, double z){
    //primeira linha
A[0][0]=1;
A[0][1]=0;
A[0][2]=0;
A[0][3]=x;
    //segunda linha
A[1][0]=0;
A[1][1]=1;
A[1][2]=0;
A[1][3]=y;
    //terceira linha
A[2][0]=0;
A[2][1]=0;
A[2][2]=1;
A[2][3]=z;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=0;
A[3][3]=1;
}



void carrega_rotacao_em_x(double A[4][4],double_t th){
    //primeira linha
A[0][0]=1;
A[0][1]=0;
A[0][2]=0;
A[0][3]=0;
    //segunda linha
A[1][0]=0;
A[1][1]=cos(th);
A[1][2]=-sin(th);
A[1][3]=0;
    //terceira linha
A[2][0]=0;
A[2][1]=sin(th);
A[2][2]=cos(th);
A[2][3]=0;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=0;
A[3][3]=1;

}

void carrega_rotacao_em_y(double A[4][4],double_t th){
    //primeira linha
A[0][0]=cos(th);
A[0][1]=0;
A[0][2]=sin(th);
A[0][3]=0;
    //segunda linha
A[1][0]=0;
A[1][1]=1;
A[1][2]=0;
A[1][3]=0;
    //terceira linha
A[2][0]=-sin(th);
A[2][1]=0;
A[2][2]=cos(th);
A[2][3]=0;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=0;
A[3][3]=1;
}

void carrega_rotacao_em_z(double A[4][4],double_t th){
    //primeira linha
A[0][0]=cos(th);
A[0][1]=-sin(th);
A[0][2]=0;
A[0][3]=0;
    //segunda linha
A[1][0]=sin(th);
A[1][1]=cos(th);
A[1][2]=0;
A[1][3]=0;
    //terceira linha
A[2][0]=0;
A[2][1]=0;
A[2][2]=1;
A[2][3]=0;
    //quarta linha
A[3][0]=0;
A[3][1]=0;
A[3][2]=0;
A[3][3]=1;
}

void traspor_matriz(double A[4][4]){
double B[4][4];
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        B[j][i]=A[i][j];
    }
}
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        A[i][j]=B[i][j];
    }
}
}

int mod_(int v){
if(v<0)v*=-1;
return v;
}
int max_(int a,int b){
if(a>=b)return a;
else return b;
}
int min_(int a,int b){
if(a<=b)return a;
else return b;
}
//
//========================= classes ============================

class vertice3d{
private:
    double x;
    double y;
    double z;
public:
    vertice3d(){
        x=0;
        y=0;
        z=0;
        }
    ~vertice3d();
   void set_XYZ(double a, double b, double c){
    x=a;
    y=b;
    z=c;
    }
   double get_x(){return x;}
   double get_y(){return y;}
   double get_z(){return z;}
};

class cor{
private:
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char a;
public:
cor(){
r=0;
g=0;
b=0;
a=0;
}
void set_color(unsigned char r_,unsigned char g_,unsigned char b_,unsigned char a_)
{
r=r_;
g=g_;
b=b_;
a=a_;
}
unsigned char get_r(){return r;}
unsigned char get_g(){return g;}
unsigned char get_b(){return b;}
unsigned char get_a(){return a;}
};

class ponto{
private:
int x;
int y;
public:
ponto()
{
    x=0;
    y=0;
}
void set_x_y(int x_,int y_)
{
x=x_;
y=y_;
}
int get_x(){return x;}
int get_y(){return y;}
};

//==============================================================

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
void PutPixel(cor color,ponto p0)
{
int _x = p0.get_x();
int _y = p0.get_y();
unsigned char red = color.get_r();
unsigned char green = color.get_g();
unsigned char blue = color.get_b();
unsigned char alfa = color.get_a();
int offset = 4*_x + 4*_y*IMAGE_WIDTH;
FBptr[offset + 0] = red;
FBptr[offset + 1] = green;
FBptr[offset + 2] = blue;
FBptr[offset + 3] = alfa;
}

void DrawLine(ponto p0,cor c0,ponto p1,cor c1)//p0 e sua respectiva cor cor, p1 e suacor.
{
    //para espelhar defini alguns ifs com algumas condições especificas para determinar
    //o quadrante que a reta se encontrava e setei um valor especifico de flag, para realizar
    //as operações inversas antes de passar as coordenadas x,y para o putpixel e o calculo do
    //offset para ser impresso no local aproximado em que sua reta é descrita matematicamente.

//variaveis para os casos de dx<dy para poder usar o segundo octante
int flag=0;
int temp;
int ft=0;//se mudar os pontos, muda as cores, muda as cores dos pixel iniciais pintados na tela
cor ct;//caso precise inverter a cor
//cores de entrada
float ri,gi,bi,ai,rf,gf,bf,af;
//variacao da cor da linha
float r_var,g_var,b_var,a_var;

ponto pxy;//para o loop
    //Po(x0,y0)
int x0=p0.get_x();
int y0=p0.get_y();
    //P1(x1,y1)
int x1=p1.get_x();
int y1=p1.get_y();
    //variação de x e de y
int dx = x1 - x0;
int dy = y1 - y0;

if(dy<0){
temp=x0;
x0=x1;
x1=temp;
temp=y0;
y0=y1;
y1=temp;
dx = x1 - x0;
dy = y1 - y0;
ct=c0;
c0=c1;
c1=ct;
ft=1;//flag de mudança de cor
}

if(dx<0&&dy>=0&&mod_(dx)>=mod_(dy)){flag+=2;
x0*=-1;
x1*=-1;
dx = x1 - x0;
dy = y1 - y0;
}

if(dx<dy&&dx>=0){
flag++;//caso o dx>dy, com x e y positivos, temos o segundo octante,
//flag serve para inverter o x pelo y na hora de chamar PutPixel(cor,ponto);
//troca x por y nos dois pontos e recalcula tudo normal
temp=x0;/**troca x pelo y**/
x0=y0;//x0 recebe y0
y0=temp;//y0 recebe x0
temp=x1;
x1=y1;//x1 recebe y1
y1=temp;//y1 recebe x1
dx = x1 - x0;// recalcula os valores de dx e dy
dy = y1 - y0;
}

if(dx<0&&dy>=0&&mod_(dx)<mod_(dy)){
flag+=5;
temp=x0;/**troca x pelo y**/
x0=y0;//x0 recebe y0
y0=temp;//y0 recebe x0
temp=x1;
x1=y1;//x1 recebe y1
y1=temp;//y1 recebe x1
x0*=-1;
x1*=-1;
x1+=512;
x0+=512;
dx = x1 - x0;
dy = y1 - y0;
if(dy<0){
temp=x0;
x0=x1;
x1=temp;
temp=y0;
y0=y1;
y1=temp;
dx = x1 - x0;
dy = y1 - y0;
ct=c0;
c0=c1;
c1=ct;
ft=1;//flag de mudança de cor
}
}
//cor de p0
ri=c0.get_r();
gi=c0.get_g();
bi=c0.get_b();
ai=c0.get_a();
//cor de p1
rf=c1.get_r();
gf=c1.get_g();
bf=c1.get_b();
af=c1.get_a();
//variação de cor
r_var=(float)(rf-ri)/(dx+0.00001);//+0.00001para evitar divisão por zero
g_var=(float)(gf-gi)/(dx+0.00001);
b_var=(float)(bf-bi)/(dx+0.00001);
a_var=(float)(af-ai)/(dx+0.00001);
//variavel de decisão para acender o pixel d
int dnew=2*dy-dx;//primeira variavel de decisão
int d_new;
int inc_e=2*dy;
int inc_ne=2*(dy-dx);
d_new=2*dy-dx;//primeiro dold
int x=x0;int y=y0;
cor cl;ponto pl;
//pinta pontos limite com cores invertidas ou não, dependendo do valor da flag de cor
if(ft==0){
PutPixel(c0,p0);
PutPixel(c1,p1);}
if(ft==1&&flag!=5){
PutPixel(c0,p1);
PutPixel(c1,p0);}
for(int i=x;i<x1;i++){
   if(d_new<=0){
    d_new+=inc_e;
    x++;
   }
   else{
    d_new+=inc_ne;
    x++;
    y++;
   }
   //variação das cores
    ri+=r_var;
    gi+=g_var;
    bi+=b_var;
    ai+=a_var;
   cl.set_color(ri,gi,bi,ai);
   if(flag==0){
    pl.set_x_y(x,y);
   }
   if(flag==1){
    pl.set_x_y(y,x);
   }
   if(flag==2){
    pl.set_x_y(-x,y);
   }
   if(flag==5){
    pl.set_x_y(y,-x+512);
   }
   PutPixel(cl,pl);
}
}

void DrawTriangle(ponto pa,cor ca,ponto pb,cor cb,ponto pc,cor cc){
//o ponto a tem coordenadas pa(xa,ya) e cor ca
//o ponto b tem coordenadas pb(xb,yb) e cor cb
//o ponto c tem coordenadas pc(xc,yc) e cor cc

//ab
DrawLine(pa,ca,pb,cb);
//bc
DrawLine(pb,cb,pc,cc);
//ca
DrawLine(pc,cc,pa,ca);
}

void FillDrawing(int xmin,int xmax,int ymin,int ymax){
    unsigned char r,g,b,a;
    int tmp;
    cor c1,c2;
    int o,o_;
    ponto p0,pk;
for(int x=xmin;x<xmax;x++){
    for(int y=ymin;y<ymax;y++){
 o = 4*x + 4*y*IMAGE_WIDTH;
if(FBptr[o]>0||FBptr[o+1]>0||FBptr[o+2]>0){
            for(int k=y+1;k<ymax;k++){
            o_=4*x+4*k*IMAGE_WIDTH;
            if(FBptr[o_]>0||FBptr[o_+1]>0||FBptr[o_+2]>0){
            p0.set_x_y(x,y);
            pk.set_x_y(x,k);
            if(k<ymax)y=k+1;//para nao precisar varrer isso dnv
            else y=k-1;
            r=FBptr[o];
            g=FBptr[o+1];
            b=FBptr[o+2];
            a=FBptr[o+3];
            c1.set_color(r,g,b,a);
            r=FBptr[o_];
            g=FBptr[o_+1];
            b=FBptr[o_+2];
            a=FBptr[o_+3];
            c2.set_color(r,g,b,a);
            DrawLine(p0,c1,pk,c2);
            }        }
}//mantem x, varia só o y
    }//y
}//x
}

void DrawTrianglePreenchido(ponto pa,cor ca,ponto pb,cor cb,ponto pc,cor cc){
DrawTriangle(pa,ca,pb,cb,pc,cc);
int xa=pa.get_x();
int xb=pb.get_x();
int xc=pc.get_x();
int ya=pa.get_y();
int yb=pb.get_y();
int yc=pc.get_y();
int xmax,ymax,xmin,ymin;//bounding box
//xmax
xmax=max_(xa,xb);
xmax=max_(xmax,xc);
xmax++;
//ymax
ymax=max_(ya,yb);
ymax=max_(ymax,yc);
ymax++;
//xmin
xmin=min_(xa,xb);
xmin=min_(xmin,xc);
xmin--;
//ymin
ymin=min_(ya,yb);
ymin=min_(ymin,yc);
ymin--;
//FillDrawing(0,512,0,512);
FillDrawing(xmin,xmax,ymin,ymax);
}


void DrawCircle(ponto p, int r,cor c) {
int x = 0;
int y = r;
int d = 1-r;
int px = p.get_x();
int py = p.get_y();
ponto p1,p2;
int xt,yt;
while (x<y) {
    p1.set_x_y(x+px,y+py);
    PutPixel(c,p1);
    p1.set_x_y(y+px,x+py);
    PutPixel(c,p1);
    p1.set_x_y(-x+px,y+py);
    PutPixel(c,p1);
    p1.set_x_y(-y+px,x+py);
    PutPixel(c,p1);
    p1.set_x_y(x+px,-y+py);
    PutPixel(c,p1);
    p1.set_x_y(y+px,-x+py);
    PutPixel(c,p1);
    p1.set_x_y(-x+px,-y+py);
    PutPixel(c,p1);
    p1.set_x_y(-y+px,-x+py);
    PutPixel(c,p1);
    if (d<0) {//escolher e
        d += 2*x+3;
    } else {
        d += 2*(x-y)+5;
        --y;}++x;}}
void DrawCirclePreenchido(ponto p, int r,cor c) {
int xmax,xmin,ymax,ymin;
xmax=p.get_x()+r+1;
xmin=p.get_x()-r-1;
ymax=p.get_y()+r+1;
ymin=p.get_y()-r-1;
DrawCircle(p,r,c);
FillDrawing(xmin,xmax,ymin,ymax);
//while(r>0){
  //  DrawCircle(p,r,c);
    //r--;
//}
}


#endif // _MYGL_H_

