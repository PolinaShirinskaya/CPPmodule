#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed
{
    private:
        std::string		_in_file;
        std::string		_out_file;
        std::ifstream	_in_fd;
        std::ofstream	_out_fd;
        int             _open;

	public:
		Sed(std::string file_name);
		~Sed(void);

		int				open(int flag);
		std::ifstream	*getFd(void);
		void			recording(std::string str);
};

#endif