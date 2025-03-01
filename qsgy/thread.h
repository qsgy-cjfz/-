#ifndef __QSGY_THREAD_H__
#define __QSGY_THREAD_H__

#include <thread>
#include <functional>
#include <memory>
#include <pthread.h>

//pthread_xx
//std::thread, pthread
namespace qsgy {

class Thread {
public:
	typedef std::shared_ptr<Thread> ptr;
	Thread(std::function<void()> cd, const std::string& name);
	~Thread();

	tid_t getId() const {return m_id;}
	const std::string& getName() const {return m_name;}

	void join();

	static Thread* GetThis();
	static const std::string& GetName();
private:
	Thread(const Thread&) = delete;
	Thread(const Thread&&) = delete;
	Thread& operator=(const Thread&) = delete;
private:
	tid_t m_id;
	pthread_t m_thread;
	std::function<void()> m_cb;
	std::string m_name;
};

}

#endif
