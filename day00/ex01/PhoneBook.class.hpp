#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.class.hpp"

class   PhoneBook {
private:
        int             numberContacts_;
        int             rewriteContact_;
        Contact         contact_[8];
        void            RequestInfo(std::string message);
        int             get_count_contacts(int flag);
        void            set_count_contacts(int num, int flag);
        std::string     get_format(std::string str);

public:
        void    AddContact(void);
        void    SearchContact(void);

        PhoneBook(void);
        ~PhoneBook(void);
};

#endif
