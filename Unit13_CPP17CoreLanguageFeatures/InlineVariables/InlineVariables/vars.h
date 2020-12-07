#pragma once
inline int global{ 10 };

struct Test {
	inline static int m_Data{ 1 };
	constexpr static int PATHSIZE{ 255 };	// automatically inline
	int x = 5;
};