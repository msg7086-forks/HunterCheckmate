#pragma once
#include<algorithm>

template <class T>
void swapEndian(T *p_obj)
{
	auto *p_mem = reinterpret_cast<unsigned char*>(p_obj);
	std::reverse(p_mem, p_mem + sizeof(T));
}