#include "__preprocessor__.h"
#include <bitset>

class Memory
{
    constexpr static size_t MAX_MEMORY = ((uint16_t)(~0)); // 0xffff
    uint16_t mem[MAX_MEMORY]{};
};

enum class ERegisters : uint8_t
{
    R_R0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC // program counter
    ,
    R_COND // condition flags

    ,
    R_COUNT
};

class Registers
{
    constexpr static size_t R_COUNT = static_cast<size_t>(ERegisters::R_COUNT);
    uint16_t reg[R_COUNT]{};
};

class lc3Computer
{
};

#define bits(x) cout << std::dec << #x << " = " << x << " / 0x" << std::hex << x << " / 0b" << std::bitset<sizeof(x) * 8>(x) << std::dec << "\n";

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));

    return 0;
}
#endif