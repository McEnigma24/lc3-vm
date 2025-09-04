#include "vm.h"

uint16_t VM::mem_read(const uint16_t address)
{
    // @{Memory Mapped I/O Read}
    return mem[address];
}

void VM::mem_write(const uint16_t address, const uint16_t val)
{
    // @{Memory Mapped I/O Write}
    mem[address] = val;
}

bool VM::read_image(const string_view& image_path) { return false; }

void VM::update_flags(const uint16_t r)
{
    if (reg[r] == 0)
        reg[ERegisters::COND] = EConditionFlags::ZERO;
    else if (reg[r] >> 15) // a negative number
        reg[ERegisters::COND] = EConditionFlags::NEGATIVE;
    else
        reg[ERegisters::COND] = EConditionFlags::POSITIVE;
}

VM::VM()
{
    // Create a shared_ptr to ourselves for the OpCodeHandler
    // This is safe because we control the lifetime
    self_ptr = std::shared_ptr<VM>(this, [](VM*) { /* custom deleter - do nothing */ });
    opcode_handlers = std::make_unique<OpCodeHandler>(self_ptr);
}

// Static factory method for smart pointer creation
std::shared_ptr<VM> VM::create()
{
    auto vm = std::make_shared<VM>();
    // Override self_ptr to point to the same object (no custom deleter needed)
    vm->self_ptr = vm;
    return vm;
}

void VM::init()
{
    // OpCodeHandler is already initialized in constructor
}

void VM::check_input(int argc, char* argv[])
{
    if (argc < 2)
    {
        /* show usage string */
        printf("lc3 [image-file1] ...\n");
        exit(2);
    }

    for (int j = 1; j < argc; ++j)
    {
        if (!read_image(argv[j]))
        {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }
}

void VM::start()
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
