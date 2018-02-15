#ifndef _MYGL_H_
#define _MYGL_H_
#include <stdlib.h>
#include <math.h>

#include "definitions.h"
using namespace std;
//subrotinas simples

//================== structures and functions related to it
typedef struct float2d{
    float x;
    float y;
}ponto2d;

typedef struct Cor{
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char a;
}cor;

typedef struct Ponto{
    float x;
    float y;
    float z;
}ponto;

ponto soma(ponto *a, ponto *b){///chamada: soma(&a,&b) a+b;
   ponto c;
    c.x = a->x+(b->x);
    c.y = a->y+(b->y);
    c.z = a->z+(b->z);
    return c;
}

ponto sub(ponto *a, ponto *b){///chamada: sub(&a,&b) a-b;
   ponto c;
    c.x = a->x-(b->x);
    c.y = a->y-(b->y);
    c.z = a->z-(b->z);
    return c;
}

//float vnorma(ponto *a){
 //   return sqrt((a->x*a->x)+(a->y*a->y)+(a->z*a->z));
//}

float vnorma(ponto a){
a.x=a.x*a.x;
a.y=a.y*a.y;
a.z=a.z*a.z;
return sqrt(a.x+a.y+a.z);
}

ponto vcross(ponto a,ponto b){
    ponto result;
    result.x = a.y*b.z-a.z*b.y;
    result.y = a.z*b.x-a.x*b.z;
    result.z = a.x*b.y-a.y*b.x;
return result;
}

float vdot(ponto a,ponto b){
    return (a.x*b.x+a.y*b.y+a.z*b.z);
}

void vnormaliza(ponto *vet){
float norma = vnorma(*vet);
    vet->x=vet->x/norma;
    vet->y=vet->y/norma;
    vet->z=vet->z/norma;
}

typedef struct Sphere{
    struct Ponto centro;
    float raio;
    cor cor;
}Sphere;

typedef struct Triangle{
    ponto p1;
    ponto p2;
    ponto p3;
    cor cor;
}Triangle;

typedef struct Plane{
    ponto p;
    ponto N;
    cor cor;
}Plane;

typedef struct Ray{
    struct Ponto origem;
    struct Ponto direcao;
}Ray;

typedef struct Camera{
    ponto pos;
    ponto dir;
    ponto up;
}Camera;

typedef struct Light{
    ponto  pos;
}light;

ponto getSphereNormal(ponto* pi,Sphere *sp){

return{(pi->x - sp->centro.x)/sp->raio,(pi->y - sp->centro.y)/sp->raio,(pi->z - sp->centro.z)/sp->raio};

}

bool intersect_sphere(Ray *r, Sphere *sp, float *t){

    ponto o,d;
    o = r->origem;
    d = r->direcao;

    ponto oc;
    oc.x = o.x - sp->centro.x;
    oc.y = o.y - sp->centro.y;
    oc.z = o.z - sp->centro.z;

    const float b = 2*vdot(oc,d);
    const float c = vdot(oc,oc) - sp->raio*sp->raio;
    float disc = b*b - 4*c;
    if(disc < 1e-4) return false;
    disc = sqrt(disc);
    const float t0 = -b - disc;
    const float t1 = -b + disc;

    float tmp = (t0 < t1)? t0 : t1;

    if(tmp < *t){
        *t = tmp;
        return true;
    }

}

bool intersect_plane(Ray *ray,Triangle *tr, float *t){

   /// float a1,a2,a3,area;
    ponto o = ray->origem;
    ponto d = ray->direcao;

    ponto a,b,c;
    a = tr->p1;
    b = tr->p2;
    c = tr->p3;

    ///cout<<"origem do raio: "<<d.x<<" "<<d.y<<" "<<d.z<<endl;
    ponto ab,ac,cb,N;

    ponto p;//ponto de interseção raio, plano
    ab.x = b.x-a.x;
    ab.y = b.y-a.y;
    ab.z = b.z-a.z;
    ac.x = c.x-a.x;
    ac.y = c.y-a.y;
    ac.z = c.z-a.z;
    cb.x = b.x-c.x;
    cb.y = b.y-c.y;
    cb.z = b.z-c.z;
    N = vcross(ab,ac);
    float D = N.x*c.x+N.y*c.y+N.z*c.z;
    ///equacao do plano pi: N.x*X+N.y*Y+N.z*Z=d
    ///equacao da reta do raio: x=o.x+d.x*t
    ///y=o.y+d.y*t
    ///z=o.z+d.z*t
    if(N.x*d.x+N.y*d.y+N.z*d.z!=0){float t2=(D-N.x*o.x-N.y*o.y-N.z*o.z)/(N.x*d.x+N.y*d.y+N.z*d.z);
        if(t2<*t){
            *t=t2;
           /// global_d = N.x*d.x+N.y*d.y+N.z*d.z;
            return true;
        }else return false;
    }else return false;
}

/*
bool intersect_plane2(Ray *ray, Triangle *tr, float *t, float *u, float *v){

        ponto edge1,edge2,tvec,pvec,qvec;

        float det,inv_det;

        // Find vectors for two edges sharing vert0
        edge1.x = tr->p2.x - tr->p1.x;
        edge1.y = tr->p2.y - tr->p1.y;
        edge1.z = tr->p2.z - tr->p1.z;

        edge2.x = tr->p3.x - tr->p1.x;
        edge2.y = tr->p3.y - tr->p1.y;
        edge2.z = tr->p3.z - tr->p1.z;

        // Begin calculating determinant - also used to calculate U parameter
        pvec = vcross(ray->direcao,edge2);

        // If determinant is near zero, ray lies in plane or triangle
        det = vdot(edge1,pvec);

        if(det > -EPSILON && det < EPSILON)
            return false;
        inv_det = 1.0/det;

        // Calculate distance from vert0 to ray origin
        tvec.x = ray->origem.x - tr->p1.x;
        tvec.y = ray->origem.y - tr->p1.y;
        tvec.z = ray->origem.z - tr->p1.z;

        // Calculate U parameter and test bounds
        *u = vdot(tvec,pvec)*inv_det;
        if(*u < 0.0 || *u > 1.0)
            return false;

        // Prepare to test V parameter
        qvec = vcross(tvec,edge1);

        // Calculate V parameter and test bounds
        *v = vdot(ray->direcao,qvec)* inv_det;
        if(*v < 0.0 || *u + *v > 1.0)
            return true;

        // Calculate t, ray intersects triangle
        *t = vdot(edge2,qvec)*inv_det;
        return true;
}

bool intersect_plane22(Ray *ray,Plane *pl, float *t){
    if(vdot(ray->direcao,pl->N) > 0){
        float tmp = -(vdot({pl->p.x - ray->origem.x,pl->p.y - ray->origem.y,pl->p.z - ray->origem.z},pl->N)/vdot(ray->origem,pl->N));
        if(tmp < *t){
            *t = tmp;
            return true;
        }
    }
}

bool intersect_plane23(Ray *ray,Plane *pl, float *t){
    if(abs(vdot(ray->direcao,pl->N)) > 0.0001f){
        float tmp = -(vdot({pl->p.x - ray->origem.x,pl->p.y - ray->origem.y,pl->p.z - ray->origem.z},pl->N)/vdot(ray->origem,pl->N));
        if(tmp>= 0 && tmp < *t){
            *t = tmp;
            return true;
        }
    }
}

bool intersect_plane3(Ray *ray,Plane *pl, float *t){

   /// float a1,a2,a3,area;
    ponto o = ray->origem;
    ponto d = ray->direcao;


    ///cout<<"origem do raio: "<<d.x<<" "<<d.y<<" "<<d.z<<endl;
    ponto N = pl->N;
    ponto c = pl->p;
    float D = N.x*c.x+N.y*c.y+N.z*c.z;

    if(N.x*d.x+N.y*d.y+N.z*d.z!=0){float t2=(D-N.x*o.x-N.y*o.y-N.z*o.z)/(N.x*d.x+N.y*d.y+N.z*d.z);
        if(t2<*t){
            *t=t2;
            return true;
        }else return false;
    }else return false;
}*/

bool intersect_triangle(Ray *ray,Triangle *tr, float *t){

    float a1,a2,a3,area;
    ponto o = ray->origem;
    ponto d = ray->direcao;

    ponto a,b,c;
    a = tr->p1;
    b = tr->p2;
    c = tr->p3;

    ///cout<<"origem do raio: "<<d.x<<" "<<d.y<<" "<<d.z<<endl;

    ponto ab,ac,N,N1,N2,N3,cp,cb,ap,bp;
    ponto p;//ponto de interseção raio, plano
    ab.x = b.x-a.x;
    ab.y = b.y-a.y;
    ab.z = b.z-a.z;
    ac.x = c.x-a.x;
    ac.y = c.y-a.y;
    ac.z = c.z-a.z;
    cb.x = b.x-c.x;
    cb.y = b.y-c.y;
    cb.z = b.z-c.z;
    N=vcross(ab,ac);
    area=vnorma(N)/2;
    float D = N.x*c.x+N.y*c.y+N.z*c.z;
    ///equacao do plano pi: N.x*X+N.y*Y+N.z*Z=d
    ///equacao da reta do raio: x=o.x+d.x*t
    ///y=o.y+d.y*t
    ///z=o.z+d.z*t
   if(N.x*d.x+N.y*d.y+N.z*d.z!=0){float t2=(D-N.x*o.x-N.y*o.y-N.z*o.z)/(N.x*d.x+N.y*d.y+N.z*d.z);
   if(t2<*t){//t=t2;
    *t = t2;
   p.x=o.x+d.x*t2;
   p.y=o.y+d.y*t2;
   p.z=o.z+d.z*t2;
   return true;
   }else return false;

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

    N1=vcross(ac,ap);
    N2=vcross(ab,bp);
    N3=vcross(cb,cp);

    a1=vnorma(N1)/2;
    a2=vnorma(N2)/2;
    a3=vnorma(N3)/2;
   ///calcula a1,a2 e a3
   if (round(area)==round(a1+a2+a3)){
        *t = t2;
        return true;
    }else return false;
   }else return false;
    }

bool intersect_triangle1(Ray *ray, Triangle *tr, float *t, float *u, float *v){

        ponto edge1,edge2,tvec,pvec,qvec;

        float det,inv_det;

        /* Find vectors for two edges sharing vert0 */
        edge1.x = tr->p2.x - tr->p1.x;
        edge1.y = tr->p2.y - tr->p1.y;
        edge1.z = tr->p2.z - tr->p1.z;

        edge2.x = tr->p3.x - tr->p1.x;
        edge2.y = tr->p3.y - tr->p1.y;
        edge2.z = tr->p3.z - tr->p1.z;

        /* Begin calculating determinant - also used to calculate U parameter*/
        pvec = vcross(ray->direcao,edge2);

        /* If determinant is near zero, ray lies in plane or triangle */
        det = vdot(edge1,pvec);

        if(det > -EPSILON && det < EPSILON)
            return false;
        inv_det = 1.0/det;

        /* Calculate distance from vert0 to ray origin */
        tvec.x = ray->origem.x - tr->p1.x;
        tvec.y = ray->origem.y - tr->p1.y;
        tvec.z = ray->origem.z - tr->p1.z;

        /* Calculate U parameter and test bounds */
        *u = vdot(tvec,pvec)*inv_det;
        if(*u < 0.0 || *u > 1.0)
            return false;

        /* Prepare to test V parameter */
        qvec = vcross(tvec,edge1);

        /* Calculate V parameter and test bounds */
        *v = vdot(ray->direcao,qvec)* inv_det;
        if(*v < 0.0 || *u + *v > 1.0)
            return false;

        /* Calculate t, ray intersects triangle */
        if(vdot(edge2,qvec)*inv_det<*t){
            *t = vdot(edge2,qvec)*inv_det;
            return true;
        }
        else return false;

}

bool intersect_triangle2(Ray *ray, Triangle *tr, float *t, float *u, float *v, ponto *point, /*int *indice*/cor *c, Triangle *Triangles,size_t *szt){

        ponto edge1,edge2,tvec,pvec,qvec;

        float det,inv_det;

        /* Find vectors for two edges sharing vert0 */
        edge1.x = tr->p2.x - tr->p1.x;
        edge1.y = tr->p2.y - tr->p1.y;
        edge1.z = tr->p2.z - tr->p1.z;

        edge2.x = tr->p3.x - tr->p1.x;
        edge2.y = tr->p3.y - tr->p1.y;
        edge2.z = tr->p3.z - tr->p1.z;

        /* Begin calculating determinant - also used to calculate U parameter*/
        pvec = vcross(ray->direcao,edge2);

        /* If determinant is near zero, ray lies in plane or triangle */
        det = vdot(edge1,pvec);

        if(det > -EPSILON && det < EPSILON)
            return false;
        inv_det = 1.0/det;

        /* Calculate distance from vert0 to ray origin */
        tvec.x = ray->origem.x - tr->p1.x;
        tvec.y = ray->origem.y - tr->p1.y;
        tvec.z = ray->origem.z - tr->p1.z;

        /* Calculate U parameter and test bounds */
        *u = vdot(tvec,pvec)*inv_det;
        if(*u < 0.0 || *u > 1.0)
            return false;

        /* Prepare to test V parameter */
        qvec = vcross(tvec,edge1);

        /* Calculate V parameter and test bounds */
        *v = vdot(ray->direcao,qvec)* inv_det;
        if(*v < 0.0 || *u + *v > 1.0)
            return false;

        /* Calculate t, ray intersects triangle */
        if(vdot(edge2,qvec)*inv_det<*t){

            *t = vdot(edge2,qvec)*inv_det;

            ponto N;

            ///raio refletido

            N = vcross(edge1,edge2);

            ///origem
            point->x = ray->origem.x+ray->direcao.x*(*t);
            point->y = ray->origem.y+ray->direcao.y*(*t);
            point->z = ray->origem.z+ray->direcao.z*(*t);

            ///direcao
            Ray r3;

            r3.direcao.x = ray->direcao.x - vdot(ray->direcao,N)*N.x*2;
            r3.direcao.y = ray->direcao.y - vdot(ray->direcao,N)*N.y*2;
            r3.direcao.z = ray->direcao.z - vdot(ray->direcao,N)*N.z*2;

            vnormaliza(&r3.direcao);

            r3.origem = *point;

            ///==================== Testa se o raio refletido bate em algum triangulo

            /*float t7 = 20000;
            for(int h = 0; h < *szt; h++){
                if(intersect_triangle1(&r3,&Triangles[h],&t7,u,v)){
                *c = Triangles[h].cor;
                ///*indice = h;
                }
                else *c = {0,0,0,0};
                ///else *indice = -1;
            }*/
            ///====================

            return true;
        }
        else return false;
}

bool intersect_triangle3(Ray *ray, Triangle *tr, float *t, float *u, float *v){

        ponto edge1,edge2,tvec,pvec,qvec;

        float det,inv_det;

        /* Find vectors for two edges sharing vert0 */
        edge1.x = tr->p2.x - tr->p1.x;
        edge1.y = tr->p2.y - tr->p1.y;
        edge1.z = tr->p2.z - tr->p1.z;

        edge2.x = tr->p3.x - tr->p1.x;
        edge2.y = tr->p3.y - tr->p1.y;
        edge2.z = tr->p3.z - tr->p1.z;

        /* Begin calculating determinant - also used to calculate U parameter*/
        pvec = vcross(ray->direcao,edge2);

        /* If determinant is near zero, ray lies in plane or triangle */
        det = vdot(edge1,pvec);

        if(det > -EPSILON && det < EPSILON)
            return false;
        inv_det = 1.0/det;

        /* Calculate distance from vert0 to ray origin */
        tvec.x = ray->origem.x - tr->p1.x;
        tvec.y = ray->origem.y - tr->p1.y;
        tvec.z = ray->origem.z - tr->p1.z;

        /* Calculate U parameter and test bounds */
        *u = vdot(tvec,pvec)*inv_det;
        if(*u < 0.0 || *u > 1.0)
            return false;

        /* Prepare to test V parameter */
        qvec = vcross(tvec,edge1);

        /* Calculate V parameter and test bounds */
        *v = vdot(ray->direcao,qvec)* inv_det;
        if(*v < 0.0 || *u + *v > 1.0)
            return false;

        /* Calculate t, ray intersects triangle */
        if(vdot(edge2,qvec)*inv_det<*t){
            *t = vdot(edge2,qvec)*inv_det;
            return true;
        }
        else return false;
}

bool isshadow_(Triangle *tr,size_t szt,int m,int s,float p_dist,Ray* raio2,light *Luz){

        ///ponto edge1,edge2,N;

            if(m == s) return false;

            float t2;
            float u,v;
            ///cor c;
            if(intersect_triangle2(raio2,tr,&t2,&u,&v,NULL,NULL,NULL,0)){
                if(t2 < p_dist)return true;
                else return false;
                }
}

bool isshadow(Triangle *tr,size_t szt,int s,float p_dist,Ray* raio2,light *Luz){

            ///ponto edge1,edge2,N;
            for(int m = 0; m < szt ; m++){
                if(m == s) continue;

                float t2;
                float u,v;
                ponto po;

                if(intersect_triangle3(raio2,&tr[m],&t2,&u,&v)){
                    if(t2 < p_dist)return true;
                    else continue;
                }
            } return false;
}

bool isshadows(Sphere *sp,size_t szs,float p_dist,Ray* raio2,light *Luz){

            ///ponto edge1,edge2,N;
            for(int m = 0; m < szs ; m++){

                float t2;
                float u,v;
                ponto po;

                if(intersect_sphere(raio2,sp,&t2)){
                    if(t2 < p_dist)return true;
                    else continue;
                }
            } return false;
}

/*
bool Ray_Triangle_intersect(Ray *raio,Triangle *triangulo,float *t){

    float t2;

    ponto o = raio->origem;
    ponto d = raio->direcao;
   /// cout<<"origem do raio: "<<d.x<<" "<<d.y<<" "<<d.z<<endl;
    float minx,miny,minz,maxx,maxy,maxz; ///minimum bounding box para excluir pontos que assumam valores diferentes desses daqueles que estiverem dentro desses limites.
    float a1,a2,a3,area; ///para teste se o ponto do plano esta dentro ou não do triangulo(areas)
    ponto a,b,c;
    a = triangulo->p1;
    b = triangulo->p2;
    c = triangulo->p3;

   // cout<<"a: "<<a.x<<" "<<a.y<<" "<<a.z<<endl;
   // cout<<"b: "<<b.x<<" "<<b.y<<" "<<b.z<<endl;
   // cout<<"c: "<<c.x<<" "<<c.y<<" "<<c.z<<endl;

   ///teste da bounding box

    ///minx = a.x;
    ///maxx = a.x;
    ///miny = a.y;
    ///maxy = a.y;
    ///minz = a.z;
    ///maxz = a.z;

    ///if(a.x<b.x){maxx=b.x;}
    ///if(b.x<c.x){maxx=c.x;}
    ///if(a.x>b.x){minx=b.x;}
    ///if(b.x>c.x){minx=c.x;}

    ///if(a.y<b.y){maxy=b.y;}
    ///if(b.y<c.y){maxy=c.y;}
    ///if(a.y>b.y){miny=b.y;}
    ///if(b.z>c.y){miny=c.y;}

    ///if(a.z<b.z){maxz=b.z;}
    ///if(b.z<c.z){maxz=c.z;}
    ///if(a.z>b.z){minz=b.z;}
    ///if(b.z>c.z){minz=c.z;}

    ponto ab,ac,N,N1,N2,N3,cp,cb,ap,bp;
    ponto p;//ponto de interseção raio, plano
    ab.x = b.x-a.x;
    ab.y = b.y-a.y;
    ab.z = b.z-a.z;
    ac.x = c.x-a.x;
    ac.y = c.y-a.y;
    ac.z = c.z-a.z;
    ///extra stuff
    cb.x = b.x-c.x;
    cb.y = b.y-c.y;
    cb.z = b.z-c.z;

    N = vcross(ab,ac);
    area = vnorma(N)/2;

    vnormaliza(&N);

    float D = N.x*c.x+N.y*c.y+N.z*c.z;

    if(N.x*d.x+N.y*d.y+N.z*d.z!=0){
        float t2=(D-N.x*o.x-N.y*o.y-N.z*o.z)/(N.x*d.x+N.y*d.y+N.z*d.z);
        if(t2<*t){//t=t2;
            p.x=o.x+d.x*t2;
            p.y=o.y+d.y*t2;
            p.z=o.z+d.z*t2;
        }else return false;
        ///if(p.x>maxx||p.x<minx||p.y>maxy||p.y<miny||p.z>maxz||p.z<minz)return false;///teste da bounding box

        ap.x = p.x-a.x;
        ap.y = p.y-a.y;
        ap.z = p.z-a.z;

        bp.x = b.x-p.x;
        bp.y = b.y-p.y;
        bp.z = b.z-p.z;

        cp.x = p.x-c.x;
        cp.y = p.y-c.y;
        cp.z = p.z-c.z;

        a2 = (vnorma(vcross(ac,ap))+vnorma(vcross(ab,bp))+vnorma(vcross(cb,cp)))/2;

        if (round(area)==round(a2)){
            *t = t2;
            ///std::cout<<"aqui"<<endl;
            return true;
        }else return false;
    }else return false;
}*/



//==============================================================

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************
void PutPixel(cor color,ponto2d p0)
{
int _x = p0.x;
int _y = p0.y;
unsigned char red = color.r;
unsigned char green = color.g;
unsigned char blue = color.b;
unsigned char alfa = color.a;
int offset = 4*_x + 4*_y*IMAGE_WIDTH;
FBptr[offset + 0] = red;
FBptr[offset + 1] = green;
FBptr[offset + 2] = blue;
FBptr[offset + 3] = alfa;
}

void DrawTelaTriangle(){
	ponto c_t;
	ponto2d pt;
//for each pixel
for(int i=0;i<IMAGE_WIDTH;i++){
    for(int j=0;j<IMAGE_HEIGHT;j++){

        c_t.z=0; ///posicao 3d
        c_t.x=i;
        c_t.y=j;

        Ray r;
        ponto tmp;

        tmp.x = IMAGE_WIDTH/2;
        tmp.y = IMAGE_HEIGHT/2;
        tmp.z = -10;

        r.origem=tmp;

        tmp.x = c_t.x-tmp.x;
        tmp.y = c_t.y-tmp.y;
        tmp.z = c_t.z-tmp.z;

        float norm = vnorma(tmp);

        tmp.x = tmp.x/norm;
        tmp.y = tmp.y/norm;
        tmp.z = tmp.z/norm;

        r.direcao = tmp;
        ///pt.set_x_y(c_t.x,c_t.y);
        pt.x = c_t.x;
        pt.y = c_t.y;

        float t = 20000;

        Triangle triangulo;
        Triangle triangulo2;
        ///sphere esfera;
        cor vermelho,azul;
        vermelho = {255,0,0,255};
        azul = {0,0,255,255};

        int dist = 14;
        triangulo.cor = vermelho;
        triangulo.p1 = {256,0,dist};
        triangulo.p2 = {0,512,dist};
        triangulo.p3 = {512,512,dist};

        dist = 16;
        int dist2 = 8;

        triangulo2.cor = azul;
        triangulo2.p1 = {0,0,dist};
        triangulo2.p2 = {256,512,dist2};
        triangulo2.p3 = {512,0,dist};

        //check for intercections
        if(intersect_triangle(&r,&triangulo,&t)){
          // color the pixel
            if(t<0)continue;
            PutPixel(triangulo.cor, pt);//cor e coordenada de tela
        }
        if(intersect_triangle(&r,&triangulo2,&t)){
            if(t<0)continue;
            PutPixel(triangulo2.cor,pt);
        }
}
}
}

#endif // _MYGL_H_

