#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[])
{
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2); // add constant to constant-pool
    writeChunk(&chunk, OP_CONSTANT, 123); // write constant op-code
    writeChunk(&chunk, constant, 123);    // write constant value
    writeChunk(&chunk, OP_RETURN, 123);   // write return
    disassembleChunk(&chunk, "Test Chunk");
    freeChunk(&chunk);

    return 0;
}
