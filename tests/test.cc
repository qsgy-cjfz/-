#include <iostream>
#include "../qsgy/log.h"
#include "../qsgy/util.h"

int main(int argc, char** argv) {
    qsgy::Logger::ptr logger(new qsgy::Logger);
    logger->addAppender(qsgy::LogAppender::ptr(new qsgy::StdoutLogAppender));

	qsgy::FileLogAppender::ptr file_appender(new qsgy::FileLogAppender("./log.txt"));
	qsgy::LogFormatter::ptr fmt(new qsgy::LogFormatter("%d%T%m%n"));
	file_appender->setFormatter(fmt);
	file_appender->setLevel(qsgy::LogLevel::ERROR);

	logger->addAppender(file_appender);

//	qsgy::LogEvent::ptr event(new qsgy::LogEvent(__FILE__, __LINE__, 0, qsgy::GetThreadId(), qsgy::GetFiberId(), time(0)));
//	event->getSS() << "Hello qsgy log";
//	logger->log(qsgy::LogLevel::DEBUG, event);
	std::cout << "Hello qsgy log" << std::endl;

	QSGY_LOG_INFO(logger) << "test macro";
	QSGY_LOG_ERROR(logger) << "test macro error";

	QSGY_LOG_FMT_ERROR(logger, "test macro fmt error %s", "aa");

	auto l = qsgy::LoggerMgr::GetInstance()->getLogger("xx");
	QSGY_LOG_INFO(l) << "XXX";
	return 0;
}
