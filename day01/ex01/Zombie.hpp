#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie {
private:
    std::string _name;
    size_t      _id;
public:
    Zombie(std::string name);
    Zombie(void);
    ~Zombie(void);

    void    announce(void);
    int     setGetId(int id);
    void    setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif