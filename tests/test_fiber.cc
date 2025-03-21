#include "qsgy/qsgy.h"

qsgy::Logger::ptr g_logger = QSGY_LOG_ROOT();

void run_in_fiber() {
	QSGY_LOG_INFO(g_logger) << "run_in_fiber begin";
	qsgy::Fiber::YieldToHold();
	QSGY_LOG_INFO(g_logger) << "run_in_fiber end";
	qsgy::Fiber::YieldToHold();
}

int main(int argc, char** argv) {
	qsgy::Fiber::GetThis();
	QSGY_LOG_INFO(g_logger) << "main begin";
	qsgy::Fiber::ptr fiber(new qsgy::Fiber(run_in_fiber));
	fiber->swapIn();
	QSGY_LOG_INFO(g_logger) << "main after swapIn";
	fiber->swapIn();
	QSGY_LOG_INFO(g_logger) << "main after end";
 	return 0;
}
