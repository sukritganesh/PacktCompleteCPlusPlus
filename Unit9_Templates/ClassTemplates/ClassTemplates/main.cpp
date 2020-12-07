#include <iostream>

template<typename T, int size>
class Stack {
	T m_Buffer[size];
	int m_Top{ -1 };
public:
	Stack() = default;

	Stack(const Stack& obj) {
		m_Top = obj.m_Top;
		for (int i = 0; i <= m_Top; i++) {
			m_Buffer[i] = obj.m_Buffer[i];
		}
	}

	void Push(const T& elem) {
		m_Buffer[++m_Top] = elem;
	}

	T Pop();

	T Top() const {
		return m_Buffer[m_Top];
	}

	bool isEmpty() {
		return m_Top == -1;
	}

	static Stack Create() {
		return Stack<T, size>();
	}

};

template<typename T, int size>
T Stack<T, size>::Pop() {
	return m_Buffer[m_Top--];
}

int main() {
	Stack<int, 10> s;
	s.Push(2);
	s.Push(4);
	s.Push(6);

	auto s2(s);

	while (!s2.isEmpty()) {
		std::cout << s2.Pop() << " ";
	}

	return 0;
}