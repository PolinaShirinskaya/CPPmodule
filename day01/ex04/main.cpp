/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:21:17 by adian             #+#    #+#             */
/*   Updated: 2023/01/11 17:33:38 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

static int replace(std::string src, std::string replace, std::string str, Sed& sed)
{
    int src_len;
    int rep_len;
    int pos;
    
    if (0 == src.compare(replace))
        return 1;
    if (!sed.open(2))
        return 0;
    src_len = src.length();
    rep_len = replace.length();
    pos = str.rfind(src);
    while (pos >= 0)
    {
        str.erase(pos, src_len);
        str.insert(pos, replace);
        pos -= 1;
        if (pos >= 0)
            pos = str.rfind(src, pos);
    }
    sed.recording(str);
    return 1;
}

int main(int argc, char **argv)
{
    std::ifstream   *file;
    std::string     str;
    char            c;
    
    if (argc != 4)
    {
        std::cout
            << "Please enter: <filename> <old_str> <new_str>" << std::endl;
        return 1;
    }
    Sed *sed = new Sed(argv[1]);
    if (!(*sed).open(1))
    {
        std::cout
            << "Error: " << argv[1]
            << " no such file or directory" << std::endl;
        delete sed;
        return 1;
    }
    file = (*sed).getFd();
    while (!(*file).eof() && (*file) >> std::noskipws >> c)
        str += c;
    if (!replace(argv[2], argv[3], str, (*sed)))
    {
        std::cout << "Error: " << argv[1]
            << " new file doesn't create" << std::endl;
        delete sed;
        return 1;
    }
    delete sed;
    return 0;
}
