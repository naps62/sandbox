/*
 * main.cpp
 *
 *  Created on: December 14, 2012
 *      Author: Miguel Palhas
 */

#include <beast/debug.hpp>
#include <beast/profile.hpp>
#include <beast/gl/async_window.hpp>

#include <GL/freeglut.h>
#include <string>
#include <stdio.h>
using std::string;

class sample_window : public beast::gl::async_window {
public:
	sample_window(const string name, uint w, uint h)
	: beast::gl::async_window(name, w, h) { }

	void render() {
		glMatrixMode(GL_PROJECTION);
		glEnable(GL_SCISSOR_TEST);

		glViewport(0, 0, 400, 300);
		glScissor(0, 0, 400, 300);
		glLoadIdentity();
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glViewport(400, 300, 400, 300);
		glScissor(400, 300, 400, 300);
		glLoadIdentity();
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
};

#include <iostream>
int main(int argc, char **argv) {

	sample_window window(string("name"), 800, 600);
	window.start();
	window.join();
}
