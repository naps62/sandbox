#ifndef CONFIG_H_
#define CONFIG_H_

#include <beast/program_options.hpp>

struct Config : public beast::program_options::options {
	const int argc;
	const char** argv;
	int val_a, val_b;
	bool flag_1, flag_2;

	Config(const char *desc, int _argc, char **_argv);
};

#endif
