#include "qsgy/qsgy.h"

static qsgy::Logger::ptr g_logger = QSGY_LOG_ROOT();

void test_fiber() {
	static int s_count = 5;
	QSGY_LOG_INFO(g_logger) << "test in fiber s_count=" << s_count;
	sleep(1);
	if(--s_count >= 0) {
		qsgy::Scheduler::GetThis()->schedule(&test_fiber, qsgy::GetThreadId());
	}
}

int main(int argc, char** argv) {
	QSGY_LOG_INFO(g_logger) << "main";
	qsgy::Scheduler sc(3, false, "test");
	sc.start();
	sleep(2);
	QSGY_LOG_INFO(g_logger) << "scheduler";
	sc.schedule(&test_fiber);
	sc.stop();
	QSGY_LOG_INFO(g_logger) << "over";
	return 0;
}
