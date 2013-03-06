/*
 * gl_worker.h
 *
 *  Created on: Feb 10, 2013
 *      Author: naps62
 */

#ifndef GL_WORKER_H_
#define GL_WORKER_H_

#include <boost/thread.hpp>
#include "config.h"

class async_gl {

	// opengl calls need to be static. A handle to the current async_gl instance is required
	// currently assumes only one instance is used at a time
	static async_gl* current_handle;


public:
	async_gl(Config& _config);

	void start();				// starts the window using a separate boost::thread
	void stop();				// triggers kill of the window thread
	void join();				// joins the current window thread
	void run();					// method run by the window thread

	// opengl public (overridable) callbacks
	void keyFunc(unsigned char, int, int);
	void mouseFunc(int, int, int, int);
	void specialFunc(int, int, int);
	void idleFunc();
	void renderFunc();

private:
	Config& config;
	boost::thread thread;

	void gl_init();			// initializes opengl stuff

	// opengl private callbacks
	static void _keyFunc(unsigned char, int, int);
	static void _mouseFunc(int, int, int, int);
	static void _specialFunc(int, int, int);
	static void _idleFunc();
	static void _renderFunc();
};


#endif /* GL_WORKER_H_ */
