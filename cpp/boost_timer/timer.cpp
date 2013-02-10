#include <boost/timer/timer.hpp>
#include <cmath>

int main() {
	{
		boost::timer::auto_cpu_timer t1;

		for(long i = 0; i < 10000000; ++i)
			std::sqrt(123.456L); // burn some time

	}

	{
		boost::timer::auto_cpu_timer t2;

		for(long i = 0; i < 10000000; ++i)
			std::sqrt(123.456L); // burn some time

	}
		return 0;
}
