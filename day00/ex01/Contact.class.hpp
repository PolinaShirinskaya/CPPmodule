#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

//класс для информации о контакте
class Contact {
private:
        std::string firstName_;
        std::string lastName_;
        std::string nickName_;
        std::string phoneNumber_;
        std::string darkestSecret_;

public:
        void        set_field(std::string field, std::string value);
        std::string get_field(std::string field);
        void        PrintField(void);
        int         IsEmpty(void);

        Contact(void); 
        ~Contact(void);
};

#endif
