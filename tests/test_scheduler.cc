#include "qsgy/qsgy.h"

static qsgy::Logger::ptr g_logger = QSGY_LOG_ROOT();

void test_fiber() {
	QSGY_LOG_INFO(g_logger) << "test in fiber";
}

int main(int argc, char** argv) {
	QSGY_LOG_INFO(g_logger) << "main";
	qsgy::Scheduler sc;
	sc.schedule(&test_fiber);
	sc.start();
	sc.stop();
	QSGY_LOG_INFO(g_logger) << "over";
	return 0;
}
