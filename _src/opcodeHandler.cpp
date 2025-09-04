#include "opcodeHandler.h"
#include "vm.h"

std::shared_ptr<VM> OpCodeHandler::getLock()
{
    if (auto v = vm_ptr.lock()) { return v; }

    assert(false && "VM instance is no longer available");
    return nullptr;
}

OpCodeHandler::OpCodeHandler(std::shared_ptr<VM> vm_instance) : vm_ptr(vm_instance) {}

void OpCodeHandler::ADD(uint16_t instr)
{
    auto vm = getLock();

    // uint16_t r0 = (instr >> 9) & 0x7; // destination register

    vm->update_flags(0);
}

// void OpCodeHandler::NOT(uint16_t instr);
// void OpCodeHandler::BR(uint16_t instr);