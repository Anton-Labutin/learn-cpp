#include <vector>
#include <string>

#include "common.hpp"

std::vector<IP_ADDR> filter_ips_bytes_equal(std::vector<IP_ADDR> _ip_pool,
                                            int _first_byte_val, 
                                            int _second_byte_val, 
                                            int _third_byte_val, 
                                            int _fourth_byte_val)
{
    std::vector<IP_ADDR> ips_selected;

    auto check_byte_cond = [](const IP_ADDR &_ip_addr, size_t _byte_id, int _byte_val) {
        if ((_byte_val > -1 && std::stoi(_ip_addr[_byte_id]) == _byte_val) || (_byte_val < 0)) {
            return true;
        }

        return false;
    };

    for (const auto &ip_addr: _ip_pool) {
        if (ip_addr.size() != IP_ADDR_BYTES_NUM) {
            std::string error_msg = "IP address must consist of 4 bytes. Processing wrong address: ";
            for (const auto &addr_byte: ip_addr) {
                error_msg += addr_byte;
                error_msg += ".";
            }

            throw std::invalid_argument(error_msg);
        }

        if (check_byte_cond(ip_addr, 0, _first_byte_val) 
            && check_byte_cond(ip_addr, 1, _second_byte_val) 
            && check_byte_cond(ip_addr, 2, _third_byte_val) 
            && check_byte_cond(ip_addr, 3, _fourth_byte_val)) {

            ips_selected.push_back(ip_addr);
        }
    }

    return ips_selected;
}


std::vector<IP_ADDR> filter_ips_any_byte(std::vector<IP_ADDR> _ip_pool,
                                         int _byte_val)
{
    std::vector<IP_ADDR> ips_selected;

    auto check_byte_cond = [&_byte_val](const IP_ADDR &_ip_addr) {
        for (size_t byte_id = 0; byte_id < IP_ADDR_BYTES_NUM; ++byte_id) {
            if (std::stoi(_ip_addr[byte_id]) == _byte_val) {
                return true;
            }
        }

        return false;
    };

    for (const auto &ip_addr: _ip_pool) {
        if (ip_addr.size() != IP_ADDR_BYTES_NUM) {
            std::string error_msg = "IP address must consist of 4 bytes. Processing wrong address: ";
            for (const auto &addr_byte: ip_addr) {
                error_msg += addr_byte;
                error_msg += ".";
            }
            throw std::invalid_argument(error_msg);
        }

        if (check_byte_cond(ip_addr)) {
            ips_selected.push_back(ip_addr);
        }
    }

    return ips_selected;
}