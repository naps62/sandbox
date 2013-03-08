/*
 * main.cpp
 *
 *  Created on: December 14, 2012
 *      Author: Miguel Palhas
 */

#include <beast/debug.hpp>
#include <beast/profile.hpp>

#include <beast/gl/async_window.hpp>
#include "config.h"

#include <iostream>
int main(int argc, char **argv) {

	beast::gl::async_window window;
	window.start();
	window.join();
}
