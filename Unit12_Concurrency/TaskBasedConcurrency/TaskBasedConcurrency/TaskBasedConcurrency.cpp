#include <iostream>
#include <thread>
#include <future>

int Operation(std::promise<int> & data) {
	auto f = data.get_future();
	try {
		std::cout << "[Task] Waiting for count" << std::endl;
		int count = f.get();		// Operation will continue execution ONLY WHEN f is ready
		std::cout << "[Task] Count acquired" << std::endl;
		int sum{};
		for (int i = 0; i < count; i++) {
			sum += i;
			std::cout << '.';
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
		std::cout << std::endl;
		return sum;
	}
	catch (std::exception & ex) {
		std::cout << "[Task] Exception: " << ex.what() << std::endl;
	}
	
}

int main() {
	// deferred means will be invoked at auto sum = result.get(), async means asynchronous execution
	std::promise<int> data;
	std::future<int> result{ std::async(std::launch::async, Operation, std::ref(data)) };
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "[main] Setting the data in promise \n";

	try {
		//throw std::runtime_error{ "Data not available" };
		data.set_value(10);		// can do only once
		if (result.valid()) {
			auto timepoint = std::chrono::system_clock::now();
			timepoint += std::chrono::seconds(1);
			auto status = result.wait_for(std::chrono::seconds(1));

			// auto status = result.wait_until(timepoint)		// 1 second wait
			// std::future_status::deferred - task is deferred, can't wait
			//					   ready - shared state became ready during wait (will return)
			//					   timeout - shared state not ready after wait
			switch (status) {
			case std::future_status::deferred:
				std::cout << "Task is synchronous" << std::endl;
				break;
			case std::future_status::ready:
				std::cout << "Result is ready" << std::endl;
				break;
			case std::future_status::timeout:
				std::cout << "Task is still running\n";
				break;
			}

			auto sum = result.get();
			std::cout << "Sum: " << sum << std::endl;
		}
	}
	catch (std::exception & ex) {
		// set exception instead of count to promise
		// Operation() will handle the exception
		data.set_exception(std::make_exception_ptr(ex));
	}
	
}