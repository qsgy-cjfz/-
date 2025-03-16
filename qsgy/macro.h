#ifndef __QSGY_MACRO_H__
#define __QSGY_MACRO_H__

#include <string.h>
#include <assert.h>
#include "util.h"

#define QSGY_ASSERT(x) \
	if(!(x)) { \
		QSGY_LOG_ERROR(QSGY_LOG_ROOT()) << "ASSERTION: " #x \
			<< "\nbacktrace:\n" \
			<< qsgy::BacktraceToString(100, 2, "    "); \
		assert(x); \
	}

#define QSGY_ASSERT2(x, w) \
	if(!(x)) { \
		QSGY_LOG_ERROR(QSGY_LOG_ROOT()) << "ASSERTION: " #x \
			<< "\n" << w \
			<< "\nbacktrace:\n" \
			<< qsgy::BacktraceToString(100, 2, "    "); \
		assert(x); \
	}


#endif
