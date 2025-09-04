#include "__preprocessor__.h"
#include "opcodeHandler.h"
#include "vm.h"

#define bits(x) cout << std::dec << #x << " = " << x << " / 0x" << std::hex << x << " / 0b" << std::bitset<sizeof(x) * 8>(x) << std::dec << "\n";

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    int a = 0b1111'0000'0000'0000;
    int b = a >> 12;

    bits(b);

    VM vm;
    vm.init();

    vm.check_input(argc, argv);

    // vm.start();

    return 0;
}
#endif