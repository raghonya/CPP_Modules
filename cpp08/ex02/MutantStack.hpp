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
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();
	public:
		typedef typename \
		std::stack<T>::container_type::iterator		iterator;
		typedef typename \
		std::stack<T>::container_type::const_iterator	const_iterator;
		iterator		begin();
		const_iterator	cbegin() const;
		iterator		end();
		const_iterator	cend() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>::stack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>::stack(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	this->c = other.c;
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

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
