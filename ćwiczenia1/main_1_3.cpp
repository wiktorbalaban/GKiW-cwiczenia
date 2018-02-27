#include "glew.h"
#include "freeglut.h"
#include "glm.hpp"
#include "ext.hpp"
#include <cmath>

#include "Shader_Loader.h"
#include "Render_Utils.h"

GLuint program;
Core::Shader_Loader shaderLoader;


void renderScene()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);

	// Zmienna "time" po wykonaniu tej linii kodu zawiera liczbe sekund od uruchomienia programu
	float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

	glUseProgram(program);

	// "transform" jest automatycznie inicjalizowane na macierz jednostkowa 3 x 3
	glm::mat3 transform1;
	glm::mat3 transform2;
	glm::mat3 transform;

	
	/*pierwsza kolumna*/
	transform1[0][0] = cos(time);
	transform1[0][1] = sin(time);
	transform1[0][2] = 0;
	/*druga kolumna*/
	transform1[1][0] = -sin(time);
	transform1[1][1] = cos(time);
	transform1[1][2] = 0;
	/*trzecia kolumna*/
	transform1[2][0] = 0;
	transform1[2][1] = 0;
	transform1[2][2] = 1;



	/*pierwsza kolumna*/
	transform2[0][0] = 1;
	transform2[0][1] = 0;
	transform2[0][2] = 0;
	/*druga kolumna*/
	transform2[1][0] = 0;
	transform2[1][1] = 1;
	transform2[1][2] = 0;
	/*trzecia kolumna*/
	transform2[2][0] = 0;
	transform2[2][1] = sin(time*(-1));
	transform2[2][2] = 1;


	transform = transform2*transform1;


	// Polecenie glUniformMatrix3fv wysyla zmienna "transform" do karty graficznej i przypisuje ja do zmiennej typu mat3 o nazwie "transformation" w shaderze.
	// Shader uzyje tej macierzy do transformacji wierzcholkow podczas rysowania.
	glUniformMatrix3fv(glGetUniformLocation(program, "transformation"), 1, GL_FALSE, (float*)&transform);

	// Tutaj wstaw kod do rysowania trojkata z poprzedniego zadania
	float tab[9];
	/*
	tab[0] = -0.22;
	tab[1] = -0.22;
	tab[2] = 1;
	*/
	tab[0] = -0.28;
	tab[1] = 0;
	tab[2] = 1;

	tab[3] = 0.22;
	tab[4] = 0.22;
	tab[5] = 1;

	tab[6] = 0.22;
	tab[7] = -0.22;
	tab[8] = 1;

	Core::DrawVertexArray(tab, 3, 3);

	glUseProgram(0);
	glutSwapBuffers();
}

void init()
{
	program = shaderLoader.CreateProgram("shaders/shader_1_2.vert", "shaders/shader_1_2.frag");
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
