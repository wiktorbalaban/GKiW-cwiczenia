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

	float tab[9];
	/*
	tab[0] = -0.22;
	tab[1] = -0.22;
	tab[2] = 1;
	*/ 
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 1;

	tab[3] = 0.22;
	tab[4] = 0.22;
	tab[5] = 1;

	tab[6] = 0.22;
	tab[7] = -0.22;
	tab[8] = 1;

	Core::DrawVertexArray(tab, 3, 3);

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
