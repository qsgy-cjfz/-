#ifndef __QSGY_UTIL_H__
#define __QSGY_UTIL_H__

#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

namespace qsgy {

pid_t GetThreadId();
uint32_t GetFiberId();

}

#endif
