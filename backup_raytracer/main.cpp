#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#ifdef MAC
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

#include "main.h"
#include "mygl.h"
#include "definitions.h"

#define PROGRAM_FILE "C:\\Users\\victs\\Desktop\\Aprendendo_OpenCl\\RayTracer\\Put_Pixel\\Ray_tracer_gpu_kernel.cl"
#define KERNEL_FUNC "RayTracer"

///OpenCL data structures
///DESCOMENTA AQUI
/*
cl_platform_id platform;
cl_device_id device;
cl_context context;
cl_program program;
cl_command_queue cmd_queue;
cl_kernel kernel;*/

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
    ///DESCOMENTA AQUI
    /*
    cl_int err;

    kernel = clCreateKernel(program,KERNEL_FUNC,&err);
    if(err<0){
            perror("Erro ao criar Kernel\n");
            exit(1);
    }*/

    for(int ii=0;ii<IMAGE_WIDTH;ii++)
       for(int jj=0;jj<IMAGE_HEIGHT;jj++)
            PutPixel({0,0,0,255},{ii,jj});

    ///====== Cores e pontos para testes ======///
    cor vermelho = {255,0,0,255};
    cor azul = {0,0,255,255};

    ///==========================================

    Camera camera;
    int pos_ = 5;

    camera.pos = {IMAGE_WIDTH/2,IMAGE_HEIGHT/2,-10+pos_};
    camera.dir = {0,0,1};
    camera.up = {0,1,0};

    static float inteiro = 0;
    inteiro++;

    light luz;
   /// luz.pos = {0,20,0};
    luz.pos = {256,256-inteiro,0};

    /*size_t szt = 10; /// numero de triangulos

    Triangle* triangulos = new Triangle[szt];

    ///back quad

    float value_back = 28;
    float value_front = 6;

    triangulos[0].cor = {255,255,0,255};///amarelo
    triangulos[0].p1 = {0,512,value_back}; ///mesmo z
    triangulos[0].p2 = {512,512,value_back}; /// para
    triangulos[0].p3 = {512,0,value_back}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[1].cor = {255,255,0,255};///amarelo
    triangulos[1].p1 = {0,512,value_back}; ///mesmo z
    triangulos[1].p2 = {0,0,value_back}; /// para
    triangulos[1].p3 = {512,0,value_back}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[2].cor = {0,255,255,255};///azul claro
    triangulos[2].p1 = {0,512,value_back}; ///mesmo z
    triangulos[2].p2 = {512,512,value_back}; /// para
    triangulos[2].p3 = {512,512,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[3].cor = {0,255,255,255};///azul claro
    triangulos[3].p1 = {0,512,value_back}; ///mesmo z
    triangulos[3].p2 = {0,512,value_front}; /// para
    triangulos[3].p3 = {512,512,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[4].cor = {255,255,255,255};///branco
    triangulos[4].p1 = {0,512,value_back}; ///mesmo z
    triangulos[4].p2 = {0,0,value_back}; /// para
    triangulos[4].p3 = {0,512,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[5].cor = {255,255,255,255};///branco
    triangulos[5].p1 = {0,0,value_back}; ///mesmo z
    triangulos[5].p2 = {0,512,value_front}; /// para
    triangulos[5].p3 = {0,0,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[6].cor = {255,255,255,255};///branco
    triangulos[6].p1 = {512,512,value_back}; ///mesmo z
    triangulos[6].p2 = {512,0,value_back}; /// para
    triangulos[6].p3 = {512,512,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[7].cor = {255,255,255,255};///branco
    triangulos[7].p1 = {512,512,value_front}; ///mesmo z
    triangulos[7].p2 = {512,0,value_front}; /// para
    triangulos[7].p3 = {512,0,value_back}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[8].cor = {0,255,255,255};///azul claro
    triangulos[8].p1 = {0,0,value_back}; ///mesmo z
    triangulos[8].p2 = {512,0,value_back}; /// para
    triangulos[8].p3 = {512,0,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[9].cor = {0,255,255,255};///azul claro
    triangulos[9].p1 = {0,0,value_back}; ///mesmo z
    triangulos[9].p2 = {0,0,value_front}; /// para
    triangulos[9].p3 = {512,0,value_front}; ///os tres pontos (para ser paralelo ao plano xy)

    float middle_value = ((value_back - value_front)/2)+ value_front;

    /*triangulos[10].cor = {255,0,0,255};///azul claro
    triangulos[10].p1 = {266,256,3}; ///mesmo z
    triangulos[10].p2 = {246,246,3}; /// para
    triangulos[10].p3 = {266,246,3}; ///os tres pontos (para ser paralelo ao plano xy)*/

        size_t szt = 3; ///numero de triangulos
    //size_t szp = 2; ///numero de planos
    //size_t szs = 2; /// numero de esferas
    size_t dist = 14; ///distancia dos objetos da origem da camera

    Triangle* triangulos = new Triangle[szt];

    triangulos[0].cor = {0,0,255,255};///Azul
    triangulos[0].p1 = {256,0,dist}; ///mesmo z
    triangulos[0].p2 = {0,512,dist}; /// para
    triangulos[0].p3 = {512,512,dist}; ///os tres pontos (para ser paralelo ao plano xy)

    triangulos[1].cor = {255,0,0,255};///Vermelho
    triangulos[1].p1 = {0,0,10}; ///mesmo z = 10
    triangulos[1].p2 = {256,512,10}; /// para
    triangulos[1].p3 = {512,0,10};  ///os 3 pontos (para ser paralelo ao plano xy)

    triangulos[2].cor ={255,255,255,255};///Branco
    triangulos[2].p1 = {-256,1024,15}; ///mesmo z = 15
    triangulos[2].p2 = {256,-512,15}; /// para
    triangulos[2].p3 = {788,1024,15};  ///os 3 pontos (para ser paralelo ao plano xy)

    /*size_t szs = 1;
    Sphere *spheres = new Sphere[szs];

    spheres[0].centro = {256,256,15.0};//middle_value};
    ///spheres[0].centro = {256,256,17.0};//middle_value};
    spheres[0].cor = {255,255,255,255};
    spheres[0].raio = 14.9;*/

    ///============================

    ponto c_t;

    ///for each pixel
    for(int i=0;i<IMAGE_WIDTH;i++){
        for(int j=0;j<IMAGE_HEIGHT;j++){

            c_t.z=0+pos_; ///posicao 3d
            c_t.x=i;
            c_t.y=j;

            Ray r;
            ponto tmp;

            tmp = camera.pos;

            r.origem = tmp;

            tmp.x = c_t.x-tmp.x;
            tmp.y = c_t.y-tmp.y;
            tmp.z = c_t.z-tmp.z;

            float norm = vnorma(tmp);

            tmp.x = tmp.x/norm;
            tmp.y = tmp.y/norm;
            tmp.z = tmp.z/norm;

            r.direcao = tmp;

            float t = 20000;
            float u=0,v=0;
            ponto point;

            ///check for intercections

            ///for all the triangles

            for(int s=0;s<szt;s++){
                ///if(intersect_triangle(&r,&triangulos[i],&t)){
                cor cor_reflexo;
                int indice;

                if(intersect_triangle2(&r,&triangulos[s],&t,&u,&v,&point,&cor_reflexo,triangulos,&szt)){
                ///if(intersect_triangle3(&r,&triangulos[s],&t,&u,&v)){
                    /*if(intersect_sphere(&r,&spheres[0],&t)){
                        if(t<0)continue;
                        ///color the pixel
                        ponto pi;
                        pi.x = r.origem.x + r.direcao.x*t;
                        pi.y = r.origem.y + r.direcao.y*t;
                        pi.z = r.origem.z + r.direcao.z*t;

                        Ray r2;
                        r2.origem = pi;
                        ponto temp = {pi.x - luz.pos.x, pi.y - luz.pos.y, pi.z - luz.pos.z};
                        //ponto temp = {luz.pos.x - point.x, luz.pos.y - point.y, luz.pos.z - point.z};
                        float p_dist = vnorma(temp);
                        vnormaliza(&temp);
                        r2.direcao = temp;
                        if(!isshadow(triangulos,szt,s,p_dist,&r2,&luz)){
                            ///color the pixel
                            PutPixel(spheres[s].cor,{c_t.x,c_t.y});
                            continue;
                        }

                        ///==========

                        //PutPixel(spheres[0].cor,{c_t.x,c_t.y});
                        continue;
                        }*/

                    if(t<0)continue;

                     float p_dist = 0;

                    ///check if the pixel is a shadow pixel or not

                    ponto temp = {point.x - luz.pos.x, point.y - luz.pos.y, point.z - luz.pos.z};
                    //ponto temp = {luz.pos.x - point.x, luz.pos.y - point.y, luz.pos.z - point.z};
                    p_dist = vnorma(temp);

                    vnormaliza(&temp);

                    Ray ray2;

                    ray2.direcao = temp;

                    //ray2.direcao.x = - ray2.direcao.x;
                    //ray2.direcao.y = - ray2.direcao.y;
                    //ray2.direcao.z = - ray2.direcao.z;

                    ray2.origem = point;

                    float w,q;

                    if(!isshadow(triangulos,szt,s,p_dist,&ray2,&luz)){// /*&& !isshadows(spheres,szs,p_dist,&ray2,&luz)){
                        ///color the pixel
                        /*if(!isshadows(spheres,szs,p_dist,&ray2,&luz))*/
                        if(cor_reflexo.a != 0){
                            float t3 = t;
                                cor_reflexo.r = (cor_reflexo.r + triangulos[s].cor.r)/2;
                                cor_reflexo.g = (cor_reflexo.g + triangulos[s].cor.g)/2;
                                cor_reflexo.b = (cor_reflexo.b + triangulos[s].cor.b)/2;
                                cor_reflexo.a = 255;

                        }
                        else cor_reflexo = triangulos[s].cor;
                        PutPixel(triangulos[s].cor,{c_t.x,c_t.y});

                    }


                }
            }


            /// if(intersect_sphere(&r,&spheres[0],&t)){
               ///     if(t<0)continue;
                ///    color the pixel
                ///    PutPixel(spheres[0].cor,{c_t.x,c_t.y});
               /// }


            ///ponto pi;
            ///for all spheres
            /*t = 20000;
            for(int s = 0; s<szs; s++){
                if(intersect_sphere(&r,&spheres[s],&t)){

                    pi.x = r.origem.x + r.direcao.x*t;
                    pi.y = r.origem.y + r.direcao.y*t;
                    pi.z = r.origem.z + r.direcao.z*t;

                    const ponto Normal = getSphereNormal(&pi,&spheres[s]);
                    Ray r2;
                    r2.origem = pi;
                    ponto temp = {pi.x - luz.pos.x, pi.y - luz.pos.y, pi.z - luz.pos.z};
                    //ponto temp = {luz.pos.x - point.x, luz.pos.y - point.y, luz.pos.z - point.z};
                    float p_dist = vnorma(temp);
                    vnormaliza(&temp);
                    r2.direcao = temp;
                    if(!isshadow(triangulos,szt,s,p_dist,&r2,&luz)){
                        ///color the pixel
                        if(!isshadows(spheres,szs,p_dist,&r2,&luz))
                        PutPixel(spheres[s].cor,{c_t.x,c_t.y});
                    }

                    }
            }*/

        }
    }
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv){
    ///DESCOMENTA AQUI
    /*
    cl_platform_id *platforms;
    cl_uint num_platforms;
    const char* platform_name="NVIDIA CUDA";
    size_t tam_info;///tamanho do array de informação
    size_t i;///contador do loop da informação da plataforma
    char* info_data;
    size_t platform_index = -1;
    int opcao;
    size_t err;
    cl_int err2;

    err = clGetPlatformIDs(5,NULL,&num_platforms);
   // clGetPlatformIDs(5,NULL,&num_platforms);///primeira chamada para saber o tamanho da regiao de memoria de platformas(com ponteiro setado pra null)
    if(err<0){
            perror("Erro em encontrar plataformas\n");
            exit(1);
    }
    else{
            printf("Plataforma(s) encontrada(s) com sucesso\nEm qual das plataformas desejas utilizar?\n");
   }

   platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id)*num_platforms);///aloca vetor de plataformas com o número de plataformas retornado pela primeira chamada da função
   err2 = clGetPlatformIDs(num_platforms,platforms,NULL);
   if(err2<0)perror("Erro ao preencher o vetor de platforms\n");

   for(i=0;i<num_platforms;i++){///retonra informações da plataforma
        err2 = clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,0,NULL,&tam_info);
        if(err2<0){
                perror("Erro ao retonrar informacoes da plataforma\n");
                exit(1);
        }
        info_data = (char*)malloc(tam_info);
        clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,tam_info,info_data,NULL);
        printf("%d)%s\n",i+1,info_data);
        free(info_data);
    }
    opcao = -1; ///default

    ///tratamento de erro
    while(opcao<0||opcao>=num_platforms){
        scanf("%d",&opcao);
        printf("Voce escolheu %d\n",opcao);
        opcao--;
        if(opcao<0||opcao>=(num_platforms))printf("Opcao invalida\n");
        }

    platform = platforms[opcao];

        ///device
    cl_device_id *devices;
    cl_uint num_devices;
    ///bool *disponibilidade[num_platforms]; caso queira retornar informações dos devices

        ///aloca espaço para regiao de memoria para os devices da plataforma escolhida e verifica se houve algum erro
        err2 = clGetDeviceIDs(platforms[opcao],CL_DEVICE_TYPE_GPU,1,NULL,&num_devices);
        if(err2<0){
            perror("Erro ao encontrar nenhum dispositivo\n");
            exit(1);
        }

    devices = (cl_device_id*)malloc(sizeof(cl_device_id)*num_devices);

    err2 = clGetDeviceIDs(platforms[opcao],CL_DEVICE_TYPE_GPU,num_devices,devices,NULL);
        if(err2<0){
            perror("Erro ao Preencher o array de dispositivos\n");
            exit(1);
        }
        device = devices[0]; ///device type = GPU
    //for(i=0;i<num_devices;i++){
       // err = clGetDeviceInfo(devices[i],CL_DEVICE_COMPILER_AVAILABLE,sizeof(bool),disponibilidade[i],NULL);
       // if(err<0){
        //    perror("Erro ao retornar informacao do dispositivo");
         //   exit(1);
       // }
       // if(disponibilidade[0]==false)printf("devices[%d] da plataforma %d nao tem compilador disponivel",i,opcao+1);
       // else printf("devices[%d] da plataforma %d tem compilador disponivel",i,opcao+1);
       // if(disponibilidade[1]==false)printf(" e nao esta disponivel para ser utilizada");
        //else printf(" e esta pronta para ser utilizada");
    //}

     ///contexts

    ///cl_context context; Variavel global

    context = clCreateContext(NULL,1,&devices[0],NULL,NULL,&err2);
    if(err2<0){
        perror("Erro ao criar contexto\n");
        exit(1);
    }
    else printf("Contexto criado com sucesso!\n");

    ///command queue

    cmd_queue = clCreateCommandQueue(context,device,0,&err2);
    if(err2<0){
            perror("Erro ao criar a Command Queue\n");
            exit(1);
    }
    else printf("Fila de comando criada com sucesso!\n");

    ///program

    ///cl_program structures

    FILE *program_handle;
    char *program_buffer,*program_log;
    //char *program_log;
    size_t program_size,log_size;

        ///===========
       /// Read program file and place content into buffer
   program_handle = fopen(PROGRAM_FILE, "r");
   if(program_handle == NULL) {
      perror("Couldn't find the program file");
      exit(1);
   }
   fseek(program_handle, 0, SEEK_END);
   program_size = ftell(program_handle);
   rewind(program_handle);
   program_buffer = (char*)malloc(program_size + 1);
   program_buffer[program_size] = '\0';
   fread(program_buffer, sizeof(char), program_size, program_handle);
   fclose(program_handle);

    ///===========

    std::cout<<"program_size: "<<program_size<<endl;
    program = clCreateProgramWithSource(context,1,(const char**)&program_buffer,&program_size,&err2);
    if(err2<0){
        perror("Erro ao criar programa\n");
        exit(1);
    }

    free(program_buffer);
    clBuildProgram(program,0,NULL,NULL,NULL,NULL);*/

        //free(platforms);///libera regiao de memoria de platforms
        //free(devices);///libera regiao de memoria de platforms

            ///colocar aqui os clreleasemem depois

    //clReleaseKernel(kernel);
    //clReleaseCommandQueue(cmd_queue);
    //clReleaseProgram(program);
    //clReleaseContext(context);

	// Inicializações.

	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;

   //return 0;
}

