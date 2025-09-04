#pragma once

#include "__preprocessor__.h"
#include <bitset>
#include <cassert>
#include <cstdio>
#include <memory>
#include <string_view>

#include "enums.h"
#include "opcodeHandler.h"

using namespace std;

class VM
{
    constexpr static size_t SIZE_MEMORY = ((uint16_t)(~0)); // 0xffff
    constexpr static size_t SIZE_REG = static_cast<size_t>(ERegisters::ALL);

    uint16_t mem[SIZE_MEMORY]{};
    uint16_t reg[SIZE_REG]{};

    std::shared_ptr<VM> self_ptr;
    std::unique_ptr<OpCodeHandler> opcode_handlers;

    uint16_t mem_read(const uint16_t address);
    void mem_write(const uint16_t address, const uint16_t val);
    bool read_image(const string_view& image_path);
    void update_flags(const uint16_t r);

public:
    VM();
    static std::shared_ptr<VM> create(); // Factory method for smart pointer creation
    void init();

    void check_input(int argc, char* argv[]);
    void start();

    friend class OpCodeHandler;
};
