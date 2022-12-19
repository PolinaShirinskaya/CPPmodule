#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>
# include <string>

class Contact
{
private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

public:
        void        _setField(std::string field, std::string value);
        std::string _getField(std::string field);
        void        _printField(void);
        int         _isEmpty(void);

        Contact(void);
        ~Contact(void);
};

#endif
