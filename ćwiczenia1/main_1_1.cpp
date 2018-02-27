#include "glew.h"
#include "freeglut.h"

#include "Shader_Loader.h"
#include "Render_Utils.h"

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Wyczyszczenie zawartoœci okna ustalonym kolorem w formacie RGBA (np. (1, 0, 0, 1) to czerwony).
	glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
		// glClearColor(1, 0, 0, 1); // czerwone
	// Nalezy wywolac na koncu rysowania aktualnej klatki obrazu
	glutSwapBuffers();
}

void init()
{
	
}

void shutdown()
{
	
}

void idle()
{
	// Ta funkcja informuje freegluta, ze nalezy odzwiezyc (przerysowac) zawartosc okna przy uzyciu funkcji podanej w glutDisplayFunc
	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	// Stworzenie okna przy u¿yciu biblioteki freeglut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Pierwszy Program");

	// Inicjalizacja rozszerzen OpenGL
	glewInit();

	// Inicjalizacja programu (ladowanie shaderow, tekstur itp)
	init();

	// Poinformowanie freegluta jaka funkcja bedzie sluzyc do odswiezania obrazu
	glutDisplayFunc(renderScene);
	// Poinformowanie freegluta jaka funkcja bedzie wywolywana w glownej petli programu
	glutIdleFunc(idle);

	// Uruchomienie glownej petli
	glutMainLoop();

	// Sprzatanie (usuwanie shaderow itp)
	shutdown();

	return 0;
}
