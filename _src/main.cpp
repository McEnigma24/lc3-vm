#include "__preprocessor__.h"
#include <bitset>

// clang-format off
enum ERegisters
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

enum EOpcode
{
    BR        /* branch */
    , ADD     /* add  */
    , LD      /* load */
    , ST      /* store */
    , JSR     /* jump register */
    , AND     /* bitwise and */
    , LDR     /* load register */
    , STR     /* store register */
    , RTI     /* unused */
    , NOT     /* bitwise not */
    , LDI     /* load indirect */
    , STI     /* store indirect */
    , JMP     /* jump */
    , RES     /* reserved (unused) */
    , LEA     /* load effective address */
    , TRAP    /* execute trap */
};

enum EConditionFlags
{
    POSITIVE    = 1 << 0
    , ZERO      = 1 << 1
    , NEGATIVE  = 1 << 2
};
// clang-format on

class VM
{
    constexpr static size_t SIZE_MEMORY = ((uint16_t)(~0)); // 0xffff
    constexpr static size_t SIZE_REG = static_cast<size_t>(ERegisters::ALL);

    uint16_t mem[SIZE_MEMORY]{};
    uint16_t reg[SIZE_REG]{};

    uint16_t mem_read(const uint16_t address)
    {
        // @{Memory Mapped I/O Read}
        return mem[address];
    }

    void mem_write(const uint16_t address, const uint16_t val)
    {
        // @{Memory Mapped I/O Write}
        mem[address] = val;
    }

    void update_flags(const uint16_t r)
    {
        if (reg[r] == 0)
            reg[ERegisters::COND] = EConditionFlags::ZERO;
        else if (reg[r] >> 15) // a negative number
            reg[ERegisters::COND] = EConditionFlags::NEGATIVE;
        else
            reg[ERegisters::COND] = EConditionFlags::POSITIVE;
    }

public:
    void start()
    {
        /* since exactly one condition flag should be set at any given time, set the Z flag */
        reg[ERegisters::COND] = EConditionFlags::ZERO;

        /* set the PC to starting position */
        /* 0x3000 is the default */
        enum
        {
            PC_START = 0x3000
        };
        reg[ERegisters::PC] = PC_START;

        int running = 1;
        while (running)
        {
            /* FETCH */
            uint16_t instr = mem_read(reg[ERegisters::PC]++);
            uint16_t op = instr >> 12;

            /* DECODE & EXECUTE */
            switch (op)
            {
            case EOpcode::ADD:
                // @{ADD}
                break;
            case EOpcode::AND:
                // @{AND}
                break;
            case EOpcode::NOT:
                // @{NOT}
                break;
            case EOpcode::BR:
                // @{BR}
                break;
            case EOpcode::JMP:
                // @{JMP}
                break;
            case EOpcode::JSR:
                // @{JSR}
                break;
            case EOpcode::LD:
                // @{LD}
                break;
            case EOpcode::LDI:
                // @{LDI}
                break;
            case EOpcode::LDR:
                // @{LDR}
                break;
            case EOpcode::LEA:
                // @{LEA}
                break;
            case EOpcode::ST:
                // @{ST}
                break;
            case EOpcode::STI:
                // @{STI}
                break;
            case EOpcode::STR:
                // @{STR}
                break;
            case EOpcode::TRAP:
                // @{TRAP}
                break;
            case EOpcode::RES:
            case EOpcode::RTI:
            default:
                // @{BAD OPCODE}
                break;
            }
        }
        // @{Shutdown}
    }
};

#define bits(x) cout << std::dec << #x << " = " << x << " / 0x" << std::hex << x << " / 0b" << std::bitset<sizeof(x) * 8>(x) << std::dec << "\n";

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    int a = 0b1111'0000'0000'0000;
    int b = a >> 12;

    bits(b);

    return 0;
}
#endif