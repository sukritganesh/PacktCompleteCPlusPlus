#include <iostream>

// can check __has_include with platform specific header files also
#ifdef __has_include
#	if __has_include(<filesystem>)
#		include <filesystem>
		namespace fs = std::filesystem;
#	else
#		include <experimental / filesystem>
		namespace fs = std::experimental::filesystem;
#	endif
#endif

int main() {
	fs::path{ "C:" };

	std::cout << __cpp_inline_variables << std::endl;
	std::cout << __cpp_capture_star_this << std::endl;
}