#pragma once

#include "__preprocessor__.h"
#include <bitset>
#include <cassert>
#include <cstdio>
#include <memory>
#include <string_view>

#include "enums.h"

using namespace std;

class VM; // Forward declaration

class OpCodeHandler
{
    std::weak_ptr<VM> vm_ptr;

    std::shared_ptr<VM> getLock();

public:
    explicit OpCodeHandler(std::shared_ptr<VM> vm_instance);

    void ADD(uint16_t instr);
    void NOT(uint16_t instr);
    void BR(uint16_t instr);
};