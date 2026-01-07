#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "common.hpp"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
IP_ADDR split(const std::string &_str, char _delim)
{
    IP_ADDR r;

    std::string::size_type start = 0;
    std::string::size_type stop = _str.find_first_of(_delim);
    while(stop != std::string::npos)
    {
        IP_ADDR_BYTE addr_part = _str.substr(start, stop - start);
        r.push_back(std::move(addr_part));

        start = stop + 1;
        stop = _str.find_first_of(_delim, start);
    }

    IP_ADDR_BYTE addr_part = _str.substr(start);
    r.push_back(addr_part);

    return r;
}