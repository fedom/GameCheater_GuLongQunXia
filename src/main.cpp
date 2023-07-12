#include <iostream>

unsigned int rol_ignore_carry(unsigned int n, unsigned int shift) {
    assert(shift < 32);
    unsigned int part1 = n << shift;
    unsigned int part2 = n >> (32 - shift);
    return part1 | part2;
}

unsigned int ror_ignore_carry(unsigned int n, unsigned int shift) {
    assert(shift < 32);
    unsigned int part1 = n >> shift;
    unsigned int part2 = n << (32 - shift);
    return part1 | part2;
}

unsigned int encrypt(unsigned int n) {

    constexpr unsigned int kMagicNum_1 = 0x42E76A59;
    constexpr unsigned int kRolBit = 0x0B;

    constexpr unsigned int kMagicNum_2 = 0x89ABCDEF;
    constexpr unsigned int kRorBit = 0x11;

    unsigned int result = n ^ kMagicNum_1;
    result = rol_ignore_carry(result, kRolBit);
    result += kMagicNum_2; 
    result = ror_ignore_carry(result, kRorBit);

    return result;
}

int main(int argc, char **argv)
{
    std::cout << "=========================\n"
                 "This is tool for gulong_qun_xia_zhuan. Input a number, it "
                 "will output the corresponding\n"
                 "encrypted number which you can use to search with CheatEngine"
                 ". Input empty string to quit\n"
              << std::endl;

    for (std::string line; std::getline(std::cin, line);) {
        if (line.empty()) {
            break;
        }
        try {
            unsigned long n = std::stoul(line);
            std::cout << "0x" << std::hex << encrypt(n) << std::endl;
        } catch (...) {
            std::cout << "input string is not a number" << std::endl; 
        }
    }

    std::cout << "finish" << std::endl;
    return 0;
}