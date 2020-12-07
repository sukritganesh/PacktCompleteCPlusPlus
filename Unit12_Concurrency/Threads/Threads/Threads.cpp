#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>
#include <Windows.h>

std::list<int> g_Data;
const int ASIZE = 5000000;
std::mutex g_Mutex;

void Download(const std::string & file) {
	std::cout << "[Downloader] Started download" << std::endl;
	for (int i = 0; i < ASIZE; i++) {
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
		// mtx will be destroyed at end of for loop (scope finishes)
	}
	std::cout << "[Downloader] Finished download" << std::endl;
}

void Download2(const std::string& file) {
	std::cout << "[Downloader2] Started download" << std::endl;
	for (int i = 0; i < ASIZE; i++) {
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
		// mtx will be destroyed at end of for loop (scope finishes)
	}
	std::cout << "[Downloader2] Finished download" << std::endl;
}

// BASIC THREAD

void basicThreadDemo() {
	std::string file{ "cppcast.mp4" };
	std::cout << "[main] User started an operation" << std::endl;
	std::thread thDownloader(Download, std::cref(file));		// necessary for pass by reference
	if (thDownloader.joinable()) {
		std::cout << "[main] thDownloader is joinable" << std::endl;
	}
	std::cout << "[main] User started another operation" << std::endl;

	//std::thread thDownloader2(Download);
	//thDownloader2.detach();
	//if (!thDownloader2.joinable()) {
	//	std::cout << "[main] thDownloader2 is detached" << std::endl;
	//}

	thDownloader.join();
	std::cout << "[main] All operations finished" << std::endl;
	system("Pause");
}

void threadSynchronizationDemo() {
	std::string file{ "cppcast.mp4" };
	std::thread thDownloader(Download, file);
	std::thread thDownloader2(Download2, file);
	thDownloader.join();
	thDownloader2.join();	
	std::cout << g_Data.size() << std::endl;
}

void Process() {
	std::cout << "Process thread id: " << std::this_thread::get_id() << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << i << ' ';
	}
	std::cout << std::endl;
}

void moreThreadFunctions() {
	std::thread t1(Process);
	auto id = t1.get_id();

	HANDLE handle = t1.native_handle();		// linux: pthread_t
	SetThreadDescription(handle, L"MyThread");	// linux: pthread_setname_np

	int cores = std::thread::hardware_concurrency();

	std::cout << "t1 thread id: " << id << std::endl;
	std::cout << "Cores: " << cores << std::endl;

	t1.join();
}

int main() {
	//basicThreadDemo();
	//threadSynchronizationDemo();
	moreThreadFunctions();

	return 0;
}