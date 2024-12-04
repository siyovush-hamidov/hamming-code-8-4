#include "../include/HammingCode.h"
#include <iostream>
#include <bitset>

HammingCode::HammingCode() {}

uint8_t HammingCode::process_four_bits(uint8_t received_byte)
{
    bool d1, d2, d3, d4, p1, p2, p3, p4;
    uint8_t resulting_byte = 0;

    d1 = (received_byte >> 3) & 1;
    d2 = (received_byte >> 2) & 1;
    d3 = (received_byte >> 1) & 1;
    d4 = (received_byte >> 0) & 1;

    p1 = 1 ^ d1 ^ d3 ^ d4;
    p2 = 1 ^ d1 ^ d2 ^ d4;
    p3 = 1 ^ d1 ^ d2 ^ d3;
    p4 = 1 ^ p1 ^ d1 ^ p2 ^ d2 ^ p3 ^ d3 ^ d4;

    resulting_byte |= (p1 << 7);
    resulting_byte |= (d1 << 6);
    resulting_byte |= (p2 << 5);
    resulting_byte |= (d2 << 4);
    resulting_byte |= (p3 << 3);
    resulting_byte |= (d3 << 2);
    resulting_byte |= (p4 << 1);
    resulting_byte |= d4;

    return resulting_byte;
}

std::vector<uint8_t> HammingCode::encode(std::vector<uint8_t> initial_bytes_of_four)
{
    std::vector<uint8_t> resulting_vector_of_bytes;
    uint8_t resulting_byte;
    for (uint8_t &temp_byte : initial_bytes_of_four)
    {
        resulting_byte = process_four_bits(temp_byte);
        resulting_vector_of_bytes.push_back(resulting_byte);
    }
    return resulting_vector_of_bytes;
}

std::vector<uint8_t> HammingCode::divide_input_number_into_bytes(unsigned long long input_number)
{
    std::vector<uint8_t> divided_bytes;
    std::string input = std::bitset<64>(input_number).to_string();
    uint8_t value;
    size_t i;
    std::string temp;

    input.erase(0, input.find_first_not_of('0'));
    while (input.size() % 4 != 0)
        input = '0' + input;
    std::cout << "\nTHE PROVIDED NUMBER " << input_number << " FITS INTO " << input.size() << " BITS: " << input << std::endl;

    for (size_t i = 0; i < input.size(); i += 4)
    {
        temp = input.substr(i, 4);
        value = static_cast<uint8_t>(std::stoi(temp, nullptr, 2));
        divided_bytes.push_back(value);
    }
    return divided_bytes;
}

uint8_t HammingCode::a_b_c_d_checks(uint8_t x, int number_of_the_byte)
{
    bool p1, p2, p3, p4, d1, d2, d3, d4, A, B, C, D;
    int temp;

    p1 = (x & 0b10000000) ? true : false;
    d1 = (x & 0b01000000) ? true : false;
    p2 = (x & 0b00100000) ? true : false;
    d2 = (x & 0b00010000) ? true : false;
    p3 = (x & 0b00001000) ? true : false;
    d3 = (x & 0b00000100) ? true : false;
    p4 = (x & 0b00000010) ? true : false;
    d4 = (x & 0b00000001) ? true : false;

    A = (p1 ^ d1 ^ d3 ^ d4) == 1;
    B = (p2 ^ d1 ^ d2 ^ d4) == 1;
    C = (p3 ^ d1 ^ d2 ^ d3) == 1;
    D = (p1 ^ p2 ^ p3 ^ p4 ^ d1 ^ d2 ^ d3 ^ d4) == 1;

    if ((!A || !B || !C) && D)
        return 0b10000000;

    temp = !A + !B * 2 + !C * 4 + !D * 8;

    if (temp > 0)
    {
        switch (temp)
        {
        case 11:
            d4 ^= 1;
            std::cout << "A MISTAKE IN THE BYTE NUMBER " << number_of_the_byte << " AND IN THE BIT NUMBER 1" << std::endl;
            break;
        case 13:
            d3 ^= 1;
            std::cout << "A MISTAKE IN THE BYTE NUMBER " << number_of_the_byte << " AND IN THE BIT NUMBER 3" << std::endl;
            break;
        case 14:
            d2 ^= 1;
            std::cout << "A MISTAKE IN THE BYTE NUMBER " << number_of_the_byte << " AND IN THE BIT NUMBER 5" << std::endl;
            break;
        case 15:
            d1 ^= 1;
            std::cout << "A MISTAKE IN THE BYTE NUMBER " << number_of_the_byte << " AND IN THE BIT NUMBER 7" << std::endl;
            break;
        default:
            std::cout << "NO MISTAKES FOUND IN DATA BITS, MAYBE YOU TRIED TO ALTER PARITY BITS." << std::endl;
            break;
        }
    }

    return (d1 << 3) | (d2 << 2) | (d3 << 1) | d4;
}

std::vector<uint8_t> HammingCode::decode(std::vector<uint8_t> bytes)
{
    int index = 1;
    std::vector<uint8_t> resBytes;
    for (uint8_t byte : bytes)
    {
        uint8_t res = a_b_c_d_checks(byte, index);
        if (res == 0b10000000)
        {
            std::cout << index << ". " << std::bitset<8>(byte) << " 2 MISTAKES IS WHERE I SAY GOOD LUCK!" << std::endl;
            return std::vector<uint8_t>();
        }
        else
            std::cout << index << ". " << std::bitset<8>(byte) << " IS DECODED TO " << std::bitset<4>(res) << std::endl;
        index++;
        resBytes.push_back(res);
    }
    return resBytes;
}