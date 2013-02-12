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

class gl_worker {

	static gl_worker* active;


public:
	gl_worker(Config _config);

	void start();
	void join();

	void run();

	static void render();


private:
	Config config;
	boost::thread thread;

	void gl_init();
};


#endif /* GL_WORKER_H_ */
