#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <iostream>
#include "main.h"
#include "mygl.h"
#include "definitions.h"
#include <stdlib.h>
//#include <vector>
#include <stdio.h>
#include "objLoader.h"
//#include "leitura_obj.hpp"
#define _USE_MATH_DEFINES
#include<math.h>

double rot=0;
// Ponteiro para o objeto que carregará o modelo 3D (formato OBJ).
objLoader *objData;

//alterei alguns includes de acordo com o tutorial de configuração do codeblocks para usar
//o opengl
//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
/**Cores para testes*/
cor azul,vermelho,verde,branco,amarelo;
branco.set_color(255,255,255,255);
amarelo.set_color(255,255,0,255);
azul.set_color(0,0,255,255);
vermelho.set_color(255,0,0,255);
verde.set_color(0,255,0,255);

        double p1[4],p2[4],p3[4];
        double _model[4][4],_view[4][4],__view[4][4],_proj[4][4];

        ///=============montando a matriz model===============
        carrega_identidade(_model);
        carrega_translacao(_model,0,0,rot);
        //carrega_rotacao_em_z(_model,rot);
        //carrega_rotacao_em_y(_model,rot);
        //rot+=M_PI_4/9;
        rot-=0.01;
        //if(rot>2*M_PI)rot=0;
        ///testes da model

        ///===============montando a matriz view=================
double camera_pos[3]    = {0.0,0.0,4.0}; /// Posicao da camera no universo.
double camera_lookat[3] = {0.0,0.0,0.0}; /// Ponto para onde a camera esta olhando.
double camera_up[3]     = {0.0,1.0,0.0}; /// 'up' da camera no espaco do universo.

///double z_camera[3]=-(camera_lookat - camera_pos) / norm(camera_lookat - camera_pos)
double z_camera[3];

z_camera[0]=(camera_pos[0]-camera_lookat[0]);
z_camera[1]=(camera_pos[1]-camera_lookat[1]);
z_camera[2]=(camera_pos[2]-camera_lookat[2]);
vet_normaliza_3(z_camera);
///ok

///double x_camera[3] = cross(camera_up, z_camera) / norm(cross(camera_up, z_camera));
double x_camera[3];
vet1_prod_vetorial_vet2_3(camera_up,z_camera);
vet_normaliza_3(camera_up);
vet1_igual_vet2_3d(x_camera,camera_up);
x_camera[0]=-x_camera[0];
x_camera[1]=-x_camera[1];
x_camera[2]=-x_camera[2];
///ok

//vai precisar de um vetor temporario para manipular os valores de z_camera no calculo do y da camera
double z_tmp[3];
vet1_igual_vet2_3d(z_tmp,z_camera);
///y_camera = cross(z_camera, x_camera);
double y_camera[3];
vet1_prod_vetorial_vet2_3(z_tmp,x_camera);
vet_normaliza_3(z_tmp);
vet1_igual_vet2_3d(y_camera,z_tmp);
y_camera[0]=-y_camera[0];
y_camera[1]=-y_camera[1];
y_camera[2]=-y_camera[2];

///passa a base da camera para a matriz view
carrega_view(__view,x_camera,y_camera,z_camera); //matriz view ta correta
carrega_translacao(_view,-camera_pos[0],-camera_pos[1],-camera_pos[2]);
Matr_mult(__view,_view);
///matriz view _view
iguala_matriz(_view,__view);

///carrega matriz modelview para _view
Matr_mult(_view,_model); ///ok

///================= construindo matriz projection ==================

double d=1.92;
carrega_proj(_proj,d);

///modelview projection carregada em _proj
Matr_mult(_proj,_view);
//Matriz_round(_proj);

///==========================finalização=============================
double S1[4][4],S2[4][4],T[4][4];
carrega_escala(S1,1,-1,1);
carrega_escala(S2,((IMAGE_WIDTH-1)/2),((IMAGE_HEIGHT-1)/2),1);
carrega_translacao(T,1,1,0);
///S2*T*S1 Matriz viewport carregada em S2
Matr_mult(T,S1);
Matr_mult(S2,T);
///todas as transformacoes Viewport*proj*View*Model carregada em S2
///Matr_mult(S2,_proj);
int w=1;
///limpa a tela
 for (unsigned int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT ; i++)
                        {
                            FBptr[i*4]   = 0;
                            FBptr[i*4+1] = 0;
                            FBptr[i*4+2] = 0;
                            FBptr[i*4+3] = 255;
                        }

		for(int i=0; i<objData->faceCount; i++)
		{
			obj_face *o = objData->faceList[i];

///setando vertices em coordenadas homogeneas,w=1

                        /// pinta base do objeto,x,y,z
                        ponto k,t;
                        double z[4];
                        //origem
                        z[0]=0;
                        z[1]=0;
                        z[2]=0;
                        z[3]=w;
                        Matrxvet4(_proj,z);//modelviewproj
                        for(int l=0;l<4;l++){//homologação
                        z[l]=z[l]/z[3];
                        }
                        Matrxvet4(S2,z);//viewport
                        z[0]=round(z[0]);
                        z[1]=round(z[1]);
                        k.set_x_y(z[0],z[1]);

                        double base[4];
                        //x
                        base[0]=2;
                        base[1]=0;
                        base[2]=0;
                        base[3]=w;

                        Matrxvet4(_proj,base);
                        for(int l=0;l<4;l++){
                        base[l]=base[l]/base[3];
                        }
                        Matrxvet4(S2,base);//viewport
                        base[0]=round(base[0]);
                        base[1]=round(base[1]);
                        t.set_x_y(base[0],base[1]);

                        DrawLine(k,vermelho,t,vermelho);

                        //y
                        base[0]=0;
                        base[1]=2;
                        base[2]=0;
                        base[3]=w;

                        Matrxvet4(_proj,base);
                        for(int l=0;l<4;l++){
                        base[l]=base[l]/base[3];
                        }
                        Matrxvet4(S2,base);//viewport
                        base[0]=round(base[0]);
                        base[1]=round(base[1]);
                        t.set_x_y(base[0],base[1]);

                        DrawLine(k,amarelo,t,amarelo);

                        //z
                        base[0]=0;
                        base[1]=0;
                        base[2]=2;
                        base[3]=w;

                        Matrxvet4(_proj,base);
                        for(int l=0;l<4;l++){
                        base[l]=base[l]/base[3];
                        }
                        Matrxvet4(S2,base);//viewport
                        base[0]=round(base[0]);
                        base[1]=round(base[1]);
                        t.set_x_y(base[0],base[1]);

                        DrawLine(k,azul,t,azul);



                        /// vertices do macaco
						p1[0]=objData->vertexList[o->vertex_index[0]]->e[0];
						p1[1]=objData->vertexList[o->vertex_index[0]]->e[1];
						p1[2]=objData->vertexList[o->vertex_index[0]]->e[2];
                        p1[3]=w;
                       // Matrxvet4(_proj,p1);
                        for(int l=0;l<4;l++){
                        p1[l]=p1[l]/p1[3];
                        }
                        //Matrxvet4(S2,p1);
						p2[0]=objData->vertexList[o->vertex_index[1]]->e[0];
						p2[1]=objData->vertexList[o->vertex_index[1]]->e[1];
						p2[2]=objData->vertexList[o->vertex_index[1]]->e[2];
						p2[3]=1;
                       // Matrxvet4(_proj,p2);
                        for(int l=0;l<4;l++){
                        p2[l]=p2[l]/p2[3];
                        }
                        Matrxvet4(S2,p2);
						p3[0]=objData->vertexList[o->vertex_index[2]]->e[0];
						p3[1]=objData->vertexList[o->vertex_index[2]]->e[1];
						p3[2]=objData->vertexList[o->vertex_index[2]]->e[2];
						p3[3]=1;
                        //Matrxvet4(_proj,p3);
                        for(int l=0;l<4;l++){
                        p3[l]=p3[l]/p3[3];
                        }
                        Matrxvet4(S2,p3);
                        ponto v1,v2,v3;
                        v1.set_x_y(round(p1[0]),round(p1[1]));
                        v2.set_x_y(round(p2[0]),round(p2[1]));
                        v3.set_x_y(round(p3[0]),round(p3[1]));
                        DrawTriangle(v1,branco,v2,branco,v3,branco);
						}


}

//-----------------------------------------------------------------------------
/*void PrintModelInfo(objLoader* ptr)//DEIXA ESSE COMENTADO AQ
{
	printf("Number of vertices: %i\n", ptr->vertexCount);
	printf("Number of vertex normals: %i\n", ptr->normalCount);
	printf("Number of texture coordinates: %i\n", ptr->textureCount);
	printf("\n");

	printf("Number of faces: %i\n", ptr->faceCount);
	for(int i=0; i<ptr->faceCount; i++)
	{
		obj_face *o = ptr->faceList[i];
		printf(" face ");
		for(int j=0; j<3; j++)
		{
			printVector(ptr->vertexList[ o->vertex_index[j] ]);
		}
		printf("\n");
	}

	printf("\n");

	printf("Number of spheres: %i\n", ptr->sphereCount);
	for(int i=0; i<ptr->sphereCount; i++)
	{
		obj_sphere *o = ptr->sphereList[i];
		printf(" sphere ");
		printVector(ptr->vertexList[ o->pos_index ]);
		printVector(ptr->normalList[ o->up_normal_index ]);
		printVector(ptr->normalList[ o->equator_normal_index ]);
		printf("\n");
	}

	printf("\n");

	printf("Number of planes: %i\n", ptr->planeCount);
	for(int i=0; i<ptr->planeCount; i++)
	{
		obj_plane *o = ptr->planeList[i];
		printf(" plane ");
		printVector(ptr->vertexList[ o->pos_index ]);
		printVector(ptr->normalList[ o->normal_index]);
		printVector(ptr->normalList[ o->rotation_normal_index]);
		printf("\n");
	}

	printf("\n");

	printf("Number of point lights: %i\n", ptr->lightPointCount);
	for(int i=0; i<ptr->lightPointCount; i++)
	{
		obj_light_point *o = ptr->lightPointList[i];
		printf(" plight ");
		printVector(ptr->vertexList[ o->pos_index ]);
		printf("\n");
	}

	printf("\n");

	printf("Number of disc lights: %i\n", ptr->lightDiscCount);
	for(int i=0; i<ptr->lightDiscCount; i++)
	{
		obj_light_disc *o = ptr->lightDiscList[i];
		printf(" dlight ");
		printVector(ptr->vertexList[ o->pos_index ]);
		printVector(ptr->normalList[ o->normal_index ]);
		printf("\n");
	}

	printf("\n");

	printf("Number of quad lights: %i\n", ptr->lightQuadCount);
	for(int i=0; i<ptr->lightQuadCount; i++)
	{
		obj_light_quad *o = ptr->lightQuadList[i];
		printf(" qlight ");
		printVector(ptr->vertexList[ o->vertex_index[0] ]);
		printVector(ptr->vertexList[ o->vertex_index[1] ]);
		printVector(ptr->vertexList[ o->vertex_index[2] ]);
		printVector(ptr->vertexList[ o->vertex_index[3] ]);
		printf("\n");
	}

	printf("\n");

	if(ptr->camera != NULL)
	{
		printf("Found a camera\n");
		printf(" position: ");
		printVector(ptr->vertexList[ ptr->camera->camera_pos_index ]);
		printf("\n looking at: ");
		printVector(ptr->vertexList[ ptr->camera->camera_look_point_index ]);
		printf("\n up normal: ");
		printVector(ptr->normalList[ ptr->camera->camera_up_norm_index ]);
		printf("\n");
	}

	printf("\n");

	printf("Number of materials: %i\n", ptr->materialCount);
	for(int i=0; i<ptr->materialCount; i++)
	{
		obj_material *mtl = ptr->materialList[i];
		printf(" name: %s", mtl->name);
		printf(" amb: %.2f ", mtl->amb[0]);
		printf("%.2f ", mtl->amb[1]);
		printf("%.2f\n", mtl->amb[2]);

		printf(" diff: %.2f ", mtl->diff[0]);
		printf("%.2f ", mtl->diff[1]);
		printf("%.2f\n", mtl->diff[2]);

		printf(" spec: %.2f ", mtl->spec[0]);
		printf("%.2f ", mtl->spec[1]);
		printf("%.2f\n", mtl->spec[2]);

		printf(" reflect: %.2f\n", mtl->reflect);
		printf(" trans: %.2f\n", mtl->trans);
		printf(" glossy: %i\n", mtl->glossy);
		printf(" shiny: %i\n", mtl->shiny);
		printf(" refact: %.2f\n", mtl->refract_index);

		printf(" texture: %s\n", mtl->texture_filename);
		printf("\n");
	}

	printf("\n");

	//vertex, normal, and texture test
	if(ptr->textureCount > 2 && ptr->normalCount > 2 && ptr->faceCount > 2)
	{
		printf("Detailed face data:\n");

		for(int i=0; i<3; i++)
		{
			obj_face *o = ptr->faceList[i];
			printf(" face ");
			for(int j=0; j<3; j++)
			{
				printf("%i/", o->vertex_index[j] );
				printf("%i/", o->texture_index[j] );
				printf("%i ", o->normal_index[j] );
			}
			printf("\n");
		}
	}
}*/ //DEIXA ESSE AQUI


//-----------------------------------------------------------------------------
int main(int argc, char **argv){
    objData = new objLoader();			// cria o objeto que carrega o modelo
	//objData->load("C:\\Users\\victs\\Documents\\Proj_icg2\\cubo.obj");	// a carga do modelo é indicada atraves do nome do arquivo.
	objData->load("C:\\Users\\victs\\Documents\\obj_loader\\monkey_head2.obj");
										// Neste caso, deve ser sempre do tipo OBJ.
    // Habilite esta função se você deseja imprimir na tela dados do modelo
	// gerados durante a sua carga.
	//PrintModelInfo(objData);

	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}
