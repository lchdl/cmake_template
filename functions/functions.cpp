#include "functions.h"

double func(double in) {
#ifdef OPTION1_ENABLED
	return double(sqrt(in));
#else
	return 0.0;
#endif
}
