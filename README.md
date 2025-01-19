# HuffmanCompressor

HuffmanCompressor is a C++ project that implements Huffman coding for file compression and decompression. This project includes functionality to compress and decompress files using Huffman coding, a popular lossless data compression algorithm.

## Features

- Compress files using Huffman coding
- Decompress files compressed with Huffman coding
- Efficient memory usage with smart pointers
- Modern C++ (C++17) features

## Project Structure

```
HuffmanCompressor/ 
├── CMakeLists.txt 
├── README.md 
├── huffman_tree.h 
├── huffman_tree.cpp 
├── compression.h 
├── compression.cpp 
├── decompression.h 
├── decompression.cpp 
├── main_compress.cpp 
└── main_decompress.cpp
```

## Getting Started

### Prerequisites

- C++17 compatible compiler (e.g., `g++`)
- CMake (optional, for building with CMake)

### Building the Project

#### Using CMake

1. Create a build directory and navigate into it:

    ```sh
    mkdir build
    cd build
    ```

2. Run CMake to configure the project:

    ```sh
    cmake ..
    ```

3. Build the project:

    ```sh
    make
    ```

#### Without CMake

1. Compile the source files:

    ```sh
    g++ -std=c++17 -c huffman_tree.cpp -o huffman_tree.o
    g++ -std=c++17 -c compression.cpp -o compression.o
    g++ -std=c++17 -c decompression.cpp -o decompression.o
    g++ -std=c++17 -c main_compress.cpp -o main_compress.o
    g++ -std=c++17 -c main_decompress.cpp -o main_decompress.o
    ```

2. Create static libraries:

    ```sh
    ar rcs libhuffman_tree.a huffman_tree.o
    ar rcs libcompression.a compression.o
    ar rcs libdecompression.a decompression.o
    ```

3. Link the executables:

    ```sh
    g++ -std=c++17 main_compress.o libhuffman_tree.a libcompression.a -o compress
    g++ -std=c++17 main_decompress.o libhuffman_tree.a libdecompression.a -o decompress
    ```

### Usage

#### Compress a File

   ```sh
   ./compress <input_file> <compressed_output_file>
   ```

#### Decompress a File
   ```sh
   ./decompress <compressed_input_file> <decompressed_output_file>
   ```

Replace <input_file>, <compressed_output_file>, <compressed_input_file>, and <decompressed_output_file> with the actual file paths you want to use.

#### Example

To compress a file named example.txt and create a compressed file named example.huff:

   ```sh
   ./compress example.txt example.huff
   ```

To decompress the file example.huff and create a decompressed file named example_decompressed.txt:

   ```sh
   ./decompress example.huff example_decompressed.txt
   ```

#### Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

#### License

This project is licensed under the MIT License. See the LICENSE file for details.

#### Acknowledgements

[Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding) - The algorithm used for compression and decompression.