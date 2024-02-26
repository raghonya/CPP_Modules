#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& arr, int item)
{
	typename T::iterator ret = std::find(arr.begin(), arr.end(), item);

	if (ret == arr.end())
		throw std::out_of_range("Value not found");
	return (ret);
}

#endif
