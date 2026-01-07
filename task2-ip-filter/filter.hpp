#pragma once

#include <vector>

#include "common.hpp"

std::vector<IP_ADDR> filter_ips_bytes_equal(std::vector<IP_ADDR> _ip_pool,
                                            int _first_byte_val = -1, 
                                            int _second_byte_val = -1, 
                                            int _third_byte_val = -1, 
                                            int _fourth_byte_val = -1);

std::vector<IP_ADDR> filter_ips_any_byte(std::vector<IP_ADDR> _ip_pool,
                                         int _byte_val);