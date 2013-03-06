/*
 * main.cpp
 *
 *  Created on: December 14, 2012
 *      Author: Miguel Palhas
 */

#include <beast/debug.hpp>
#include <beast/profile.hpp>
#include <beast/program_options.hpp>

#include "async_gl.h"
#include "config.h"

#include <iostream>
int main(int argc, char **argv) {

	Config config("options", argc, argv);

	async_gl gl(config);
	gl.start();
	gl.join();
}
