#ifndef KAREN_H
# define KAREN_H

#include <iostream>

class Karen
{
    private:
        void    debug();
        void    info();
        void    warning();
        void    error();
    
    public:
        Karen(void);
        ~Karen(void);

        void    complain(std::string level);
};

#endif
