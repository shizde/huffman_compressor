#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include <string>

namespace huffman
{

    void decompress_file(const std::string &huffman_filename, const std::string &output_filename);

} // namespace huffman

#endif // DECOMPRESSION_H