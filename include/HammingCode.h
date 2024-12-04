#pragma once
#include <cstdint>
#include <vector>

class HammingCode
{
public:
    HammingCode();
    std::vector<uint8_t> encode(std::vector<uint8_t>);
    std::vector<uint8_t> decode(std::vector<uint8_t>);
    std::vector<uint8_t> divide_input_number_into_bytes(unsigned long long);

private:
    uint8_t process_four_bits(uint8_t);
    uint8_t a_b_c_d_checks(uint8_t, int);
};
