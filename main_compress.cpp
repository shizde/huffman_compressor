#include "compression.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    huffman::compress_file(argv[1], argv[2]);
    return 0;
}