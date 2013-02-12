#include "gl_worker.h"
#include <boost/date_time.hpp>
#include <iostream>
using namespace std;

#include<GL/glut.h>

gl_worker* gl_worker::active;

gl_worker::gl_worker(Config _config)
: config(_config)
{
	gl_init();
}


void gl_worker::start() {
	thread = boost::thread(&gl_worker::run, this);
}


void gl_worker::join() {
	thread.join();
}


void gl_worker::render() {

}


void gl_worker::run() {
	glutDisplayFunc(gl_worker::render);

	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 800, 600);
	glLoadIdentity();
	glOrtho(0.f, 800 - 1.f, 0.f, 600 -1.f, -1.f, -1.f);

	glutMainLoop();
}

void gl_worker::gl_init() {
    char  arg0[] = "program_name";
    char* argv[] = { &arg0[0], NULL };
    int argc = 1;

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("gl_worker");
	gl_worker::active = this;
}
