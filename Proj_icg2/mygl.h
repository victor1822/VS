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


    //Vetor operator -(Vetor v){return Vetor(x-v.get_x(),y-v.get_y(),z-v.get_z());}

typedef struct pontoxyz{
double x,y,z;
}vectorR3;

typedef struct Ray{
vectorR3 origem,direcao;
};

vectorR3 cross(vectorR3 a,vectorR3 b){
vectorR3 result;
result.x = a.y*b.z-a.z*b.y;
result.y = a.z*b.x-a.x*b.z;
result.z = a.x*b.y-a.y*b.x;
return result;

}

struct Light{
vectorR3  pos;
};

double dot(vectorR3 a,vectorR3 b){
return a.x*b.x+a.y*b.y+a.z*b.z;
}

double norma(vectorR3 a){
a.x=a.x*a.x;
a.y=a.y*a.y;
a.z=a.z*a.z;
return sqrt(a.x+a.y+a.z);
}

double costeta(vectorR3 a,vectorR3 b){
return (dot(a,b)/(norma(a)*norma(b)));
}

class Triangle{
private:
    vectorR3 a;
    vectorR3 b;
    vectorR3 c;
    cor tcor;
public:
    Triangle(){
    a.x = 0;
    a.y = 0;
    a.z = 10;/// z -3
    b.x = 254;
    b.y = 512;
    b.z = 10;/// mesmo z
    c.x = 512;
    c.y = 0;
    c.z = 10;/// mesmo z
tcor.set_color(255,0,0,255);///cor vermelha
    }
    void set_triangle(double ax,double ay,double az,double bx,double by,double bz,double cx,double cy,double cz,cor color){
    a.x = ax;
    a.y = ay;
    a.z = az;
    b.x = ax;
    b.y = ay;
    b.z = az;
    c.x = ax;
    c.y = ay;
    c.z = az;

    tcor = color;
    }
    cor get_cor(){return tcor;}
    vectorR3 get_a(){return a;}
    vectorR3 get_b(){return b;}
    vectorR3 get_c(){return c;}

      bool intersect(Ray ray, double &t){

    double menx,maix,meny,maiy,menz,maiz;
    ///calculo da bounding box
    menx=a.x;
    maix=a.x;
    meny=a.y;
    maiy=a.y;
    menz=a.z;
    maiz=a.z;
    if(a.x<b.x){maix=b.x;}
    if(b.x<c.x){maix=c.x;}
    if(a.x>b.x){menx=b.x;}
    if(b.x>c.x){menx=c.x;}

    if(a.y<b.y){maiy=b.y;}
    if(b.y<c.y){maiy=c.y;}
    if(a.y>b.y){meny=b.y;}
    if(b.z>c.y){meny=c.y;}

    if(a.z<b.z){maiz=b.z;}
    if(b.z<c.z){maiz=c.z;}
    if(a.z>b.z){menz=b.z;}
    if(b.z>c.z){menz=c.z;}

          double a1,a2,a3,area;
    vectorR3 o = ray.origem;
    vectorR3 d = ray.direcao;

    vectorR3 ab,ac,N,N1,N2,N3,cp,cb,ap,bp;
    vectorR3 p;//ponto de interseção raio, plano
    ab.x = b.x-a.x;
    ab.y = b.y-a.y;
    ab.z = b.z-a.z;
    ac.x = c.x-a.x;
    ac.y = c.y-a.y;
    ac.z = c.z-a.z;
    cb.x = b.x-c.x;
    cb.y = b.y-c.y;
    cb.z = b.z-c.z;
    N=cross(ab,ac);
    area=norma(N)/2;
    double D = N.x*c.x+N.y*c.y+N.z*c.z;
    ///equacao do plano pi: N.x*X+N.y*Y+N.z*Z=d
    ///equacao da reta do raio: x=o.x+d.x*t
    ///y=o.y+d.y*t
    ///z=o.z+d.z*t
   if(N.x*d.x+N.y*d.y+N.z*d.z!=0){t=(D-N.x*o.x-N.y*o.y-N.z*o.z)/(N.x*d.x+N.y*d.y+N.z*d.z);
   p.x=o.x+d.x*t;
   p.y=o.y+d.y*t;
   p.z=o.z+d.z*t;

   ///if(p.x>maix||p.x<menx||p.y>maiy||p.y<meny||p.z>maiz||p.z<menz)return false;///teste da bounding box

    ap.x = p.x-a.x;
    ap.y = p.y-a.y;
    ap.z = p.z-a.z;

    bp.x = b.x-p.x;
    bp.y = b.y-p.y;
    bp.z = b.z-p.z;

    cp.x = p.x-c.x;
    cp.y = p.y-c.y;
    cp.z = p.z-c.z;

    N1=cross(ac,ap);
    N2=cross(ab,bp);
    N3=cross(cb,cp);

    a1=norma(N1)/2;
    a2=norma(N2)/2;
    a3=norma(N3)/2;
   ///calcula a1,a2 e a3
   if (round(area)==round(a1+a2+a3))return true;
   else return false;
   }else return false;
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


void DrawTela(){
	vectorR3 c_t;
	ponto pt;
//for each pixel
for(int i=0;i<W;i++){
for(int j=0;j<H;j++){
c_t.z=0;
c_t.x=i;
c_t.y=j;
Ray r;
vectorR3 tmp;
tmp.x=H/2;tmp.y=W/2;tmp.z=-10;
r.origem=tmp;
tmp.x=c_t.x-tmp.x;
tmp.y=c_t.y-tmp.y;
tmp.z=c_t.z-tmp.z;
double norm=norma(tmp);
tmp.x=tmp.x/norm;
tmp.y=tmp.y/norm;
tmp.z=tmp.z/norm;
r.direcao=tmp;
pt.set_x_y(c_t.x,c_t.y);

double t = 20000;

///Light luz;
///tmp.x=0;tmp.y=30;tmp.z=0;
///luz.pos=tmp;

Triangle triangulo;

//check for intercections
if(triangulo.intersect(r,t)){
   //color the pixel
	PutPixel(triangulo.get_cor(), pt);//cor e coordenada de tela

}
}
}
}





#endif // _MYGL_H_

