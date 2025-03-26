#include "qsgy/qsgy.h"

qsgy::Logger::ptr g_logger = QSGY_LOG_ROOT();

void run_in_fiber() {
	QSGY_LOG_INFO(g_logger) << "run_in_fiber begin";
	qsgy::Fiber::YieldToHold();
	QSGY_LOG_INFO(g_logger) << "run_in_fiber end";
	qsgy::Fiber::YieldToHold();
}

void test_fiber() {
	QSGY_LOG_INFO(g_logger) << "main begin -1";
	{
		qsgy::Fiber::GetThis();
		QSGY_LOG_INFO(g_logger) << "main begin";
		qsgy::Fiber::ptr fiber(new qsgy::Fiber(run_in_fiber));
		fiber->swapIn();
		QSGY_LOG_INFO(g_logger) << "main after swapIn";
		fiber->swapIn();
		QSGY_LOG_INFO(g_logger) << "main after end";
		fiber->swapIn();
	}
	QSGY_LOG_INFO(g_logger) << "main after end2";
}

int main(int argc, char** argv) {
	qsgy::Thread::SetName("main");

	std::vector<qsgy::Thread::ptr> thrs;
	for(int i = 0; i < 3; ++i) {
		thrs.push_back(qsgy::Thread::ptr(
					new qsgy::Thread(test_fiber, "name_" + std::to_string(i))));
	}
	for(auto i : thrs) {
		i->join();
	}
 	return 0;
}
