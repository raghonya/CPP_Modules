#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename \
		std::stack<T>::container_type::iterator		iterator;
		typedef typename \
		std::stack<T>::container_type::const_iterator	const_iterator;
		// using iterator = std::random_access_iterator_tag;
		// using const_iterator = std::
				// typedef MutantStack<T>	iterator;
		// typedef MutantStack<const T>	const_iterator;
		iterator		begin();
		const_iterator	cbegin() const;
		iterator		end();
		const_iterator	cend() const;

	// 	voi
};

template <typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator 	MutantStack<T>::cbegin() const
{
	return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::iterator 	MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator 	MutantStack<T>::cend() const
{
	return (this->c.cend());
}


#endif
