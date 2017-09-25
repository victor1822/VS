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

        double p1[3],p2[3],p3[3];
       // double _model[4][4],_view[4][4],__view[4][4],_proj[4][4];

        ///===============montando a matriz view=================
///double camera_pos[3]    = {0.0,0.0,4.0}; /// Posicao da camera no universo.
///double camera_lookat[3] = {0.0,0.0,0.0}; /// Ponto para onde a camera esta olhando.
///double camera_up[3]     = {0.0,1.0,0.0}; /// 'up' da camera no espaco do universo.

 /*for (unsigned int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT ; i++)
                        {
                            FBptr[i*4]   = 0;
                            FBptr[i*4+1] = 0;
                            FBptr[i*4+2] = 0;
                            FBptr[i*4+3] = 255;
                        }

		for(int i=0; i<objData->faceCount; i++)
		{
			obj_face *o = objData->faceList[i];

                        /// vertices do macaco
						p1[0]=objData->vertexList[o->vertex_index[0]]->e[0];
						p1[1]=objData->vertexList[o->vertex_index[0]]->e[1];
						p1[2]=objData->vertexList[o->vertex_index[0]]->e[2];

						p2[0]=objData->vertexList[o->vertex_index[1]]->e[0];
						p2[1]=objData->vertexList[o->vertex_index[1]]->e[1];
						p2[2]=objData->vertexList[o->vertex_index[1]]->e[2];

						p3[0]=objData->vertexList[o->vertex_index[2]]->e[0];
						p3[1]=objData->vertexList[o->vertex_index[2]]->e[1];
						p3[2]=objData->vertexList[o->vertex_index[2]]->e[2];

						}*/
DrawTela();

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv){
    objData = new objLoader();			// cria o objeto que carrega o modelo
	//objData->load("C:\\Users\\victs\\Documents\\Proj_icg2\\cubo.obj");	// a carga do modelo é indicada atraves do nome do arquivo.
	objData->load("C:\\Users\\victs\\Documents\\obj_loader\\monkey_head2.obj");
										// Neste caso, deve ser sempre do tipo OBJ.
    // Habilite esta função se você deseja imprimir na tela dados do modelo
	// gerados durante a sua carga.
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
