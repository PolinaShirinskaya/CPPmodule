#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include <iostream>
# include <string>
# include "Contact.class.hpp"

class   PhoneBook
{
private:
        int     _numberContacts;
        int     _rewriteContact;
        Contact _contact[8];

public:
        void    addContact(void);
        void    searchContact(void);

        PhoneBook(void);
        ~PhoneBook(void);
};

#endif
