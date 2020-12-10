#include <iostream>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

// BASIC PATH DEMO

void pathDemo() {
	fs::path selectedPath{R"(C:\Users\Sukrit Ganesh\Documents\LearningProgramming\CPlusPlus_\PacktCompleteCPlusPlus\Unit15_CPP17STL\Filesystem\dat)"};
	std::cout << selectedPath << std::endl << std::endl;
	std::cout << selectedPath.string() << std::endl << std::endl;

	std::cout << selectedPath.root_name() << std::endl << std::endl;
	std::cout << selectedPath.parent_path() << std::endl << std::endl;

	selectedPath.remove_filename();
	selectedPath /= "newfile.txt";
	std::cout << selectedPath.string() << std::endl << std::endl;

	if (selectedPath.has_relative_path()) {
		std::cout << selectedPath.relative_path().string() << std::endl;
	}
}

// DIRECTORY DEMO

void listDirectory(std::string_view file) {
	fs::path currentPath{ file };
	std::vector<fs::directory_entry> dir_entries{};

	//// error prone
	//fs::directory_iterator begin{ currentPath };
	//fs::directory_iterator end{};
	//while (begin != end) {
	//	auto de = *begin++;
	//	std::cout << de.path().filename() << std::endl;
	//}
	//std::cout << std::endl;

	// better way
	for (const auto& dir_entry : fs::directory_iterator{ currentPath }) {
		dir_entries.push_back(dir_entry);
	}


	// all directories happen first, non-directors are ordered afterwards
	std::partition(dir_entries.begin(), dir_entries.end(), [](fs::directory_entry& de) {
		return de.is_directory();
	});

	for (const auto& dir_entry : dir_entries) {
		switch (const auto& p = dir_entry.path(); /*dir_entry.status().type()*/ fs::status(p).type()) {
		case fs::file_type::directory:
			std::cout << "[DIR]\t" << p.filename() << std::endl;
			break;
		case fs::file_type::regular:
			std::cout << '\t' << p.filename() << '\t' << dir_entry.file_size() << std::endl;
			break;
		}
	}
}

void directoryOperations(std::string_view file) {
	fs::path currentPath{ file };
	if (!fs::exists(currentPath)) {
		std::cout << "Path does not exist = >" << currentPath.string() << std::endl;
		return;
	}

	currentPath /= "NewDir";
	if (!fs::create_directory(currentPath)) {
		std::cout << "Could not create a directory\n" << std::endl;
	}
	else {
		std::cout << "Directory created successfully\n" << std::endl;
	}

	// delete directory: fs::remove(currentPath)
	// works much the same as create_directory
	//if (!fs::remove(currentPath)) {
	//	std::cout << "Could not remove directory\n" << std::endl;
	//}
	//else {
	//	std::cout << "Directory removed successfully\n" << std::endl;
	//}

	std::cout << fs::current_path() << std::endl;
	std::cout << "Changing current path" << std::endl;
	std::error_code ec{};
	fs::current_path(currentPath, ec);
	if (ec) {
		std::cout << "Error:" << ec.message() << std::endl;
	}
	std::cout << fs::current_path() << std::endl;

}

void directoryDemo() {
	directoryOperations(R"(C:\Users\Sukrit Ganesh\Documents\LearningProgramming\CPlusPlus_\PacktCompleteCPlusPlus\Unit15_CPP17STL\Filesystem\Filesystem)");
	listDirectory(R"(C:\Users\Sukrit Ganesh\Documents\LearningProgramming\CPlusPlus_\PacktCompleteCPlusPlus\Unit15_CPP17STL\Filesystem\Filesystem)");
	
}

// PERMISSIONS DEMO

void demo_perms(fs::perms p)
{
	std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
		<< '\n';
}

void filePermissionDemo(std::string_view file) {
	fs::path file_to_modify{ file };

	auto perm = fs::status(file_to_modify).permissions();
	demo_perms(perm);

	std::cout << "Changing permissions\n";
	fs::permissions(file_to_modify, fs::perms::others_read, fs::perm_options::remove);
	demo_perms(perm);
}

void floatFun() {
	unsigned int x;
	std::cin >> std::hex >> x;
	float y = *((float*)&x);
	std::cout << std::setprecision(45) << y << std::endl;
	int z = *((int*)&y);
	std::cout << std::hex << std::uppercase << z << std::endl;
}

int main() {
	//pathDemo();
	//directoryDemo();
	//filePermissionDemo(R"(C:\Users\Sukrit Ganesh\Documents\LearningProgramming\CPlusPlus_\PacktCompleteCPlusPlus\Unit15_CPP17STL\Filesystem\Filesystem\randfolder\randfile.txt)");
	floatFun();
}

