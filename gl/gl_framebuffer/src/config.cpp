#include "config.h"

Config::Config(const char *desc, int _argc, char **_argv)
: beast::program_options::options(desc),
  argc(_argc), argv((const char**)_argv)
{
	parse(_argc, _argv);
}
