#include "qsgy/qsgy.h"
#include <unistd.h>

qsgy::Logger::ptr g_logger = QSGY_LOG_ROOT();

volatile int count = 0; //volatile 阻止编译器优化count
//qsgy::RWMutex s_mutex;
qsgy::Mutex s_mutex;

void fun1() {
	QSGY_LOG_INFO(g_logger) << "name: " << qsgy::Thread::GetName()
		<< " this.name: " << qsgy::Thread::GetThis()->getName()
		<< " id: " << qsgy::GetThreadId()
		<< " this.id: " << qsgy::Thread::GetThis()->getId();

	for(int i = 0; i < 10000000; ++i) {
		//qsgy::RWMutex::WriteLock lock(s_mutex);
		qsgy::Mutex::Lock lock(s_mutex);
		++count;
	}
}

void fun2() {
	while(true) {
		QSGY_LOG_INFO(g_logger) << "XXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	}
}

void fun3() {
	while(true) {
		QSGY_LOG_INFO(g_logger) << "============================";
	}
}

int main(int argc, char** argv) {
	QSGY_LOG_INFO(g_logger) << "thread test begin";
	YAML::Node root = YAML::LoadFile("tests/conf/log2.yml");
	qsgy::Config::LoadFromYaml(root);
	
	std::vector<qsgy::Thread::ptr> thrs;
	for(int i = 0; i < 1; ++i) { // 单个线程的时候即便没有锁写入的速度依然不是很快，大约30M/S，说明一个线程的读写能力是有极限的，并没有多个线程的效率好
		qsgy::Thread::ptr thr(new qsgy::Thread(&fun2, "name_" + std::to_string(i * 2)));
		//qsgy::Thread::ptr thr2(new qsgy::Thread(&fun3, "name_" + std::to_string(i * 2 + 1)));
		thrs.push_back(thr);
		//thrs.push_back(thr2);
	}

	for(size_t i = 0; i < thrs.size(); ++i) {
		thrs[i]->join();
	}
	QSGY_LOG_INFO(g_logger) << "thread test end";
	QSGY_LOG_INFO(g_logger) << count;

		return 0;
}
