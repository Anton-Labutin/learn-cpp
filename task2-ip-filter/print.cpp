#include <vector>
#include <iostream>
#include "string_view"

#include "common.hpp"

void print_ips(const std::vector<IP_ADDR> &_ip_pool)
{
    static const std::string_view IP_ADDR_PARTS_SEP = ".";

    for (auto pool_cit = _ip_pool.cbegin(); pool_cit != _ip_pool.cend(); ++pool_cit) {
        for (auto pool_part_cit = pool_cit->cbegin(); pool_part_cit != pool_cit->cend(); ++pool_part_cit) {
            if (pool_part_cit != pool_cit->cbegin()) {
                std::cout << IP_ADDR_PARTS_SEP;

            }

            std::cout << *pool_part_cit;
        }

        std::cout << std::endl;
    }
}