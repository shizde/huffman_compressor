cmake_minimum_required(VERSION 3.10)
project(HuffmanCompressor)

set(CMAKE_CXX_STANDARD 17)

add_library(huffman_tree huffman_tree.cpp)
add_library(compression compression.cpp)
add_library(decompression decompression.cpp)

add_executable(compress main_compress.cpp)
add_executable(decompress main_decompress.cpp)

target_link_libraries(compress huffman_tree compression)
target_link_libraries(decompress huffman_tree decompression)