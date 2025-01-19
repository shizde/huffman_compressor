### CMakeLists.txt ###
cmake_minimum_required(VERSION 3.10)
project(HuffmanCompressor)

set(CMAKE_CXX_STANDARD 17)

# Libraries
add_library(huffman_tree huffman_tree.cpp)
add_library(compression compression.cpp)
add_library(decompression decompression.cpp)

# Link huffman_tree to compression
# Ensures that compression can access symbols from huffman_tree
target_link_libraries(compression PUBLIC huffman_tree)

target_link_libraries(decompression PUBLIC huffman_tree)

# Executables
add_executable(compress main_compress.cpp)
add_executable(decompress main_decompress.cpp)

target_link_libraries(compress huffman_tree compression)
target_link_libraries(decompress huffman_tree decompression)