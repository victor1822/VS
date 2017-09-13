//#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include "bitmapload.hpp"
#include <iostream>
#include "main.h"
#include "mygl.h"
#include "definitions.h"
#include <stdlib.h>
#include <vector>
//#include <vec3.hpp> // glm::vec3
//#include <vec2.hpp>
#include "leitura_obj.hpp"
//alterei alguns includes de acordo com o tutorial de configuração do codeblocks para usar
//o opengl
//-----------------------------------------------------------------------------

//GLint tx, ty;

//tx = 0; 
//ty = 0;

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

ponto px;
px.set_x_y(255,255);
switch(option){
case 0:
DrawTela();
break;
case 1:
DrawTelaN();
break;
case 2:
DrawTelaGS();
break;
case 3:
DrawTelaR();
break;
case 4:
DrawTelaG();
break;
case 5:
DrawTelaB();
}
/**descomente cada sessão, para testar as chamadas das fuções implementadas*/

/**teste do PutPixel*/
//ponto p;
//p.set_x_y(255,255);
//PutPixel(amarelo,p);

/**Teste de DrawTriangle*/
/*ponto p1,p2,p3,p30;
//triangulo 1
p1.set_x_y(128,108);
p2.set_x_y(383,108);
p3.set_x_y(255,20);
DrawTrianglePreenchido(p1,amarelo,p2,vermelho,p3,azul);

//triangulo 2
p1.set_x_y(128,148);
p2.set_x_y(383,148);
p3.set_x_y(255,235);
DrawTrianglePreenchido(p1,amarelo,p2,azul,p3,verde);

//triangulo 3
p1.set_x_y(108,20);
p2.set_x_y(108,235);
p3.set_x_y(0,128);
DrawTrianglePreenchido(p1,amarelo,p2,branco,p3,vermelho);

//triangulo 4
p1.set_x_y(50,255);
p2.set_x_y(50,403);
p3.set_x_y(158,383);
DrawTrianglePreenchido(p1,vermelho,p2,branco,p3,vermelho);

//triangulo 5
p1.set_x_y(180,383);
p2.set_x_y(180,255);
p3.set_x_y(400,500);
DrawTrianglePreenchido(p1,branco,p2,azul,p3,azul);

//triangulo 6
p1.set_x_y(450,20);
p2.set_x_y(510,403);
p3.set_x_y(412,403);
DrawTrianglePreenchido(p1,branco,p2,azul,p3,azul);*/


/**Teste de retas nos 8 octantes e as retas representando o eixo x e y*/
/*ponto pto1,pto2,pto3,p1,p2,p3,p4,c,meio,p_se,p_ne,p_so,e1,e2,e3,e4,d1,d2,d3,d4;
pto1.set_x_y(255,0);
pto2.set_x_y(0,255);
pto3.set_x_y(512,255);
c.set_x_y(0,0);
meio.set_x_y(255,255);
p_se.set_x_y(512,512);
p_ne.set_x_y(0,512);
p_so.set_x_y(512,0);
//retas do sistema de coordenadas convencional
p1.set_x_y(0,255);
p2.set_x_y(512,255);
p3.set_x_y(255,0);
p4.set_x_y(255,512);

e1.set_x_y(200,0);
e2.set_x_y(0,200);
e3.set_x_y(0,312);
e4.set_x_y(200,512);
d1.set_x_y(312,0);
d2.set_x_y(512,200);
d3.set_x_y(512,312);
d4.set_x_y(312,512);

DrawLine(p1,branco,p2,branco);
DrawLine(p3,branco,p4,branco);
//retas dos octantes
DrawLine(meio,vermelho,c,vermelho);
DrawLine(meio,azul,p_ne,azul);
DrawLine(meio,amarelo,p_so,amarelo);
DrawLine(meio,verde,p_se,verde);
DrawLine(meio,branco,e1,vermelho);
DrawLine(meio,branco,e2,vermelho);
DrawLine(meio,branco,e3,azul);
DrawLine(meio,branco,e4,azul);
DrawLine(meio,branco,d1,amarelo);
DrawLine(meio,branco,d2,amarelo);
DrawLine(meio,branco,d3,verde);
DrawLine(meio,branco,d4,verde);
/*

/**teste de ciculos e circunferencias(Drawcircle();)*/
//se aumentar o raio, dá problemas no preenchimento
/*
ponto pno,pne,pso,pse;
pno.set_x_y(128,128);
DrawCirclePreenchido(pno,118,branco);
pso.set_x_y(128,384);
DrawCirclePreenchido(pso,118,branco);
pse.set_x_y(384,384);
DrawCirclePreenchido(pse,118,branco);
pne.set_x_y(384,128);
DrawCirclePreenchido(pne,118,branco);*/
// Read our .obj file
//vector< glm::vec3 > vertices;
//vector< glm::vec2 > uvs;
//vector< glm::vec3 > normals; // Won't be used at the moment.
//bool res = loadOBJ("C:/Users/victs/Documents/ProjICGI1macaco.obj", vertices, uvs, normals);

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv){
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	glutSpecialFunc(TeclasEspeciais);
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

