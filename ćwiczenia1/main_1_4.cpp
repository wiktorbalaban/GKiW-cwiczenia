#include "glew.h"
#include "freeglut.h"

#include "Shader_Loader.h"
#include "Render_Utils.h"

GLuint program; // Identyfikator shadera uzywanego do rysowania
Core::Shader_Loader shaderLoader;

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Aktywowanie shadera
	glUseProgram(program);

	float tab[18];
	int tab1[18];

	tab[0] = -0.22;
	tab[1] = 0.22;
	tab[2] = 1;

	tab[3] = -0.22;
	tab[4] = -0.22;
	tab[5] = 1;

	tab[6] = 0.22;
	tab[7] = 0.22;
	tab[8] = 1;


	tab[9] = 0.22;
	tab[10] = 0.22;
	tab[11] = 1;

	tab[12] = -0.22;
	tab[13] = -0.22;
	tab[14] = 1;

	tab[15] = 0.22;
	tab[16] = -0.22;
	tab[17] = 1;


	tab1[0] = 0;
	tab1[1] = 1;
	tab1[2] = 2;

	tab1[3] = 3;
	tab1[4] = 4;
	tab1[5] = 5;

	tab1[6] = 6;
	tab1[7] = 7;
	tab1[8] = 8;

	tab1[9] = 9;
	tab1[10] = 10;
	tab1[11] = 11;

	tab1[12] = 12;
	tab1[13] = 13;
	tab1[14] = 14;

	tab1[15] = 15;
	tab1[16] = 16;
	tab1[17] = 17;


	//Core::DrawVertexArray(tab, 3, 3);
	Core::DrawVertexArrayIndexed(tab, tab1, 18, 3);

	// Wylaczenie shadera
	glUseProgram(0);

	glutSwapBuffers();
}

void init()
{
	program = shaderLoader.CreateProgram("shaders/shader_1_1.vert", "shaders/shader_1_1.frag");
}

void shutdown()
{
	shaderLoader.DeleteProgram(program);
}

void idle()
{
	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Pierwszy Program");
	glewInit();

	init();
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	glutMainLoop();

	shutdown();

	return 0;
}