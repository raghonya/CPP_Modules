#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	size;
	public:
		Array()
		{
			try { this->arr = new T(); }
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		Array(unsigned int n)
		{
			try	{ this->arr = new T[n]; }
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
		Array(const Array& other)
		{
			// for (size_t i = 0; i < other.size(); ++i)

		}
		Array&	operator=(const Array& other)
		{
			
		}
		~Array()
		{

		}
		T&	operator[](size_t pos)
		{
			if (pos >= this->size)
				throw std::runtime_error("PRIWET");
			return (this->arr[pos]);
		}
};

#endif
