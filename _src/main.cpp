#include "__preprocessor__.h"
#include <bitset>

class Memory
{
    constexpr static size_t MAX_MEMORY = ((uint16_t)(~0)); // 0xffff
    uint16_t mem[MAX_MEMORY]{};
};

// clang-format off
enum class ERegisters : uint8_t
{
    R0
    , R1
    , R2
    , R3
    , R4
    , R5
    , R6
    , R7
    , PC // program counter
    , COND // condition flags

    , ALL
};
// clang-format on

class Registers
{
    constexpr static size_t R_COUNT = static_cast<size_t>(ERegisters::ALL);
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