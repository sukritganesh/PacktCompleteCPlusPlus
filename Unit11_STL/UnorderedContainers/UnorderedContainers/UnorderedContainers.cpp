#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

void unorderedSetDemo() {
	std::unordered_set<std::string> coll;
	coll.insert("Afghanistan");
	coll.insert("Armenia");
	coll.insert("Andorra");
	coll.insert("Albania");
	coll.insert("Angola");
	coll.insert("Algeria");
	coll.insert("Argentina");

	std::cout << "Number of buckets: " << coll.bucket_count() << std::endl;
	std::cout << "Number of elements: " << coll.size() << std::endl;
	std::cout << "Load factor: " << coll.load_factor() << std::endl;

	for (const auto x : coll) {
		std::cout << "Element: " << x << " | Bucket #: " << coll.bucket(x) << std::endl;
	}
	std::cout << std::endl;

	coll.insert("Australia");
	coll.insert("Antigua");
	coll.insert("Azerbaijan");
	coll.insert("Austria");

	std::cout << "Number of buckets: " << coll.bucket_count() << std::endl;
	std::cout << "Number of elements: " << coll.size() << std::endl;
	std::cout << "Load factor: " << coll.load_factor() << std::endl;

	for (const auto x : coll) {
		std::cout << "Element: " << x << " | Bucket #: " << coll.bucket(x) << std::endl;
	}
	std::cout << std::endl;

	coll.erase("Antigua");
	coll.insert("Antigua and Barbuda");

	// unordered multiset allows for duplicates, similar to multiset
}

void unorderedMapDemo() {
	std::unordered_map<std::string, int> age;

	age["Jimmy Carter"] = 96;
	age["Barack Obama"] = 59;
	age["Donald Trump"] = 74;

	for (const auto& x : age) {
		std::cout << "Element: " << x.first << ":" << x.second << " | Bucket#: " << age.bucket(x.first) << std::endl;
	}
	std::cout << std::endl;
}

class Employee {
	std::string m_Name;
	int m_Id;
public:
	Employee(std::string n, int id) : m_Name(n), m_Id(id) {

	}
	const std::string & getName() const {
		return m_Name;
	}
	int getId() const {
		return m_Id;
	}
};


struct EmployeeHash {
	size_t operator()(const Employee& emp) const {
		auto s1 = std::hash<std::string>{}(emp.getName());
		auto s2 = std::hash<int>{}(emp.getId());
		return s1 ^ s2;
	}
};

struct EmployeeEquality {
	bool operator()(const Employee& e1, const Employee& e2) const {
		return e1.getId() == e2.getId();
	}
};

void userDefinedObjectContainerDemo() {
	std::hash<std::string> h;
	std::cout << "Hash: " << h("Hello") << std::endl;

	/*auto empEq = [](const Employee& e1, const Employee& e2) {
		return e1.getId() == e2.getId();
	};*/

	std::unordered_set<Employee, EmployeeHash, EmployeeEquality> emps;
	emps.insert(Employee("Bill Gates", 100));
	emps.insert(Employee("Charles Koch", 101));
	emps.insert(Employee("Steve Jobs", 102));

	for (auto& x : emps) {
		std::cout << x.getName() << " " << x.getId() << std::endl;
	}

}

int main() {
	unorderedSetDemo();
	unorderedMapDemo();
	userDefinedObjectContainerDemo();

	return 0;
}