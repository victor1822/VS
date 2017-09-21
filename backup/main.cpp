//#include <windows.h>
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
#include <vector>




//-----------------------------------------------------------------------------


void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************

DrawTela();

}

//-----------------------------------------------------------------------------
int main(int argc, char **argv){
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

