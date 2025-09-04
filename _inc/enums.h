#pragma once
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
