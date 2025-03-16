#include "qsgy/qsgy.h"
#include <assert.h>

qsgy::Logger::ptr g_logger = QSGY_LOG_ROOT();

void test_assert() {
	QSGY_LOG_INFO(g_logger) << qsgy::BacktraceToString(10);
	QSGY_ASSERT2(0 == 1, "abcdef xx");
}

int main(int argc, char** argv) {
	test_assert();
	return 0;
}
