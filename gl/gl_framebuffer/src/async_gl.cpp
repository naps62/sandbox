#include "async_gl.h"
#include <boost/date_time.hpp>
#include <iostream>
using namespace std;

#include<GL/glut.h>

async_gl* async_gl::current_handle;

async_gl::async_gl(Config& _config)
: config(_config)
{
	gl_init();
}


void async_gl::start() {
	thread = boost::thread(&async_gl::run, this);
}

void async_gl::stop() {
	thread.interrupt();
}


void async_gl::join() {
	thread.join();
}


void async_gl::renderFunc() {
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f );
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
	//thread->
}


void async_gl::run() {
	try {
		glutMouseFunc(async_gl::_mouseFunc);
		glutKeyboardFunc(async_gl::_keyFunc);
		glutSpecialFunc(async_gl::_specialFunc);
		glutDisplayFunc(async_gl::_renderFunc);
		glutIdleFunc(async_gl::_idleFunc);

		glMatrixMode(GL_PROJECTION);
		glViewport(0, 0, 800, 600);
		glLoadIdentity();
		glOrtho(0.f, 800 - 1.f, 0.f, 600 -1.f, -1.f, -1.f);

		glutMainLoop();
	} catch (boost::thread_interrupted const &) {
		printf("asd");
		return;
	}
}

void async_gl::gl_init() {
    char  arg0[] = "program_name";
    char* argv[] = { &arg0[0], NULL };
    int argc = 1;

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("async_gl");
	async_gl::current_handle = this;
}

//
// Callbacks
//
void async_gl::keyFunc(unsigned char key, int mousex, int mousey) { }
void async_gl::mouseFunc(int btn, int state, int x, int y) { }
void async_gl::specialFunc(int key, int mousex, int mousey) { }
void async_gl::idleFunc() { }


void async_gl::_keyFunc(unsigned char key, int mousex, int mousey) {
	switch (key) {
	case 27: // ESC
		async_gl::current_handle->stop();
		break;
	}
	// delegate
	async_gl::current_handle->keyFunc(key, mousex, mousey);
}

void async_gl::_mouseFunc(int btn, int state, int x, int y) {
	// delegate
	async_gl::current_handle->mouseFunc(btn, state, x, y);
}

void async_gl::_specialFunc(int key, int mousex, int mousey) {

	// delegate
	async_gl::current_handle->specialFunc(key, mousex, mousey);
}

void async_gl::_idleFunc() {
	// delegate
	async_gl::current_handle->idleFunc();
}

void async_gl::_renderFunc() {
	// delegate
	async_gl::current_handle->renderFunc();
}
