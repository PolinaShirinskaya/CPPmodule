#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

# ifndef EASYFIND_HPP
#  error easyfind.tpp should be included from easyfind.hpp
# endif

template<typename T>
typename T::iterator    easyfind(T &array, int find)
{
    typename T::iterator it;

    it = std::find(array.begin(), array.end(), find);
    
    if (it == array.end())
        throw NoElementFoundException();
    return it;
    
};

#endif