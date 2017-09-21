#ifndef _MYGL_H_
#define _MYGL_H_
#include <stdlib.h>
#include <math.h>
#include "definitions.h"
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <cmath>
using namespace std;

//Mat inputImage, outputImage, channel[3];
//std::string colorSpace;
//subrotinas simples
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


//========================= classes ============================
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

class Vetor{
private:
    double x,y,z;
public:
    Vetor(){x=0;y=0;z=0;}
    void set_c(double _x,double _y,double _z){
    x=_x;
    y=_y;
    z=_z;
    }
    int getx(){return x;}
    int gety(){return y;}
    int getz(){return z;}
    Vetor mult(double v){
	Vetor vet;
	vet.set_c(x*v,y*v,z*v);}
    void sum(Vetor a,Vetor b){x=a.getx()+b.getx();y=a.gety()+b.gety();z=a.getz()+b.getz();}
    void sub(Vetor a){x=x-a.getx();y=y-a.gety();z=z-a.getz();}
    //Vetor operator -(Vetor v){return Vetor(x-v.get_x(),y-v.get_y(),z-v.get_z());}
};


class Ray{

private:

Vetor origem;
Vetor direcao;

public:

    Ray(){
	origem.set_c(0,0,0);
	direcao.set_c(0,0,0);
}

   void set_ray(Vetor o,Vetor d){
    origem=o;
    direcao=d;
    }
    Vetor get_origem(){return origem;}
    Vetor get_direcao(){return direcao;}
};

double dot(Vetor a,Vetor b){
return(a.getx()*b.getx() + a.gety()*b.gety() + a.getz()*b.getz());
}

class Sphere{
private:
Vetor centro;
double raio;
cor color;
public:
    Sphere(){
	centro.set_c(0,0,3);
	raio=1.0;
}
    void set_sphere(Vetor c,double r,cor c1){
    centro = c;
    raio = r;
    color = c1;
    }
    cor get_cor(){return color;}
    bool intersect(Ray ray, double &t){
    Vetor o = ray.get_origem();
    Vetor d = ray.get_direcao();
    Vetor oc;
    oc.set_c(o.getx()-centro.getx(),o.gety()-centro.gety(),o.getz()-centro.getz());
    double b = 2*dot(oc,d);
    double centro = dot(oc,oc)-raio*raio;
    double disc = b*b-4*centro;
    if(disc<0) return false;
    else{
    disc = sqrt(disc); 
    double t0 = -b-disc;
    double t1 = -b+disc;
    
    t = (t0<t1) ? t0 :t1;
    return true;
        
    }
    }
};

class Light{
private:
Vetor pos;//posição da luz
public:
void set_pos(double a,double b,double c){
pos.set_c(a,b,c);
}
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

/*void DrawTela(){
cout<<"";
}*/


void DrawTela(){
	ponto c_t;//coordenada de tela
	cor vermelho;//cor vermelha
	vermelho.set_color(255,0,0,255);
   Vetor origem,direcao;
//for each pixel
for(int i=0;i<W;i++){
for(int j=0;j<H;j++){
c_t.set_x_y(i,j);
//  send a ray trough each pixel
origem.set_c(i,j,0);
direcao.set_c(0,0,1);
Ray raio;
raio.set_ray(origem, direcao);

double t = 20000;

Light luz;
luz.set_pos(0,0,1);

Vetor cen;
cen.set_c(H/2,W/2,1);

Sphere esfera;
esfera.set_sphere(cen,100,vermelho);
//check for intercections
if(esfera.intersect(raio,t)){
   //color the pixel
	PutPixel(esfera.get_cor(), c_t);//cor e coordenada de tela
    
}
}
}
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




#endif // _MYGL_H_

