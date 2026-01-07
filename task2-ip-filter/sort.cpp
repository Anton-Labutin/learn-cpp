#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

#include "common.hpp"

void reverse_sort(std::vector<IP_ADDR> &_ip_pool)
{
    const auto reverse_ips_comp = [](const IP_ADDR &_lhs_addr, const IP_ADDR &_rhs_addr) {
        int lhs_first_byte = std::stoi(_lhs_addr[0]);
        int lhs_second_byte = std::stoi(_lhs_addr[1]);
        int lhs_third_byte = std::stoi(_lhs_addr[2]);
        int lhs_fourth_byte = std::stoi(_lhs_addr[3]);

        int rhs_first_byte = std::stoi(_rhs_addr[0]);
        int rhs_second_byte = std::stoi(_rhs_addr[1]);
        int rhs_third_byte = std::stoi(_rhs_addr[2]);
        int rhs_fourth_byte = std::stoi(_rhs_addr[3]);

        return (std::tie(lhs_first_byte, lhs_second_byte, lhs_third_byte, lhs_fourth_byte) 
        > std::tie(rhs_first_byte, rhs_second_byte, rhs_third_byte, rhs_fourth_byte));
    };

    std::sort(_ip_pool.begin(), _ip_pool.end(), reverse_ips_comp);
}