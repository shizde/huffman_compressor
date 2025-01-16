#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <string>
#include <unordered_map>

namespace huffman
{

    void compress_file(const std::string &input_filename, const std::string &output_filename);

} // namespace huffman

#endif // COMPRESSION_H