#include "decompression.h"
#include "huffman_tree.h"
#include <fstream>
#include <iostream>

namespace huffman
{

    void read_huffman_dictionary(std::ifstream &infile, std::shared_ptr<Node> &root)
    {
        char dict_size;
        infile.read(&dict_size, sizeof(char));

        for (int i = 0; i < dict_size; ++i)
        {
            char character;
            char code_length;
            infile.read(&character, sizeof(char));
            infile.read(&code_length, sizeof(char));

            std::string code;
            code.resize(code_length);
            infile.read(&code[0], code_length);

            std::shared_ptr<Node> current = root;
            for (char bit : code)
            {
                if (bit == '0')
                {
                    if (!current->left)
                    {
                        current->left = std::make_shared<Node>('+', 0);
                    }
                    current = current->left;
                }
                else
                {
                    if (!current->right)
                    {
                        current->right = std::make_shared<Node>('+', 0);
                    }
                    current = current->right;
                }
            }
            current->character = static_cast<unsigned char>(character);
        }
    }

    std::string decode_data(std::ifstream &infile, std::shared_ptr<Node> &root, int encoded_length)
    {
        std::string decoded_text;
        std::shared_ptr<Node> current = root;

        char buffer;
        int bit_count = 0;
        while (infile.read(&buffer, sizeof(char)))
        {
            for (int i = 7; i >= 0; --i)
            {
                bool bit = (buffer & (1 << i)) != 0;

                if (bit)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                }

                if (!current->left && !current->right)
                {
                    decoded_text += current->character;
                    current = root;
                }
                bit_count++;
                if (bit_count >= encoded_length)
                    break;
            }
        }

        return decoded_text;
    }

    void decompress_file(const std::string &huffman_filename, const std::string &output_filename)
    {
        std::ifstream infile(huffman_filename, std::ios::binary);
        if (!infile.is_open())
        {
            std::cerr << "ERROR OPENING HUFFMAN FILE.\n";
            return;
        }

        std::shared_ptr<Node> root = std::make_shared<Node>('+', 0);
        read_huffman_dictionary(infile, root);

        infile.seekg(0, std::ios::end);
        std::streampos file_size = infile.tellg();
        infile.seekg(-1, std::ios::cur);
        int encoded_length = static_cast<int>(file_size);

        std::string decoded_text = decode_data(infile, root, encoded_length);

        std::ofstream outfile(output_filename);
        if (!outfile.is_open())
        {
            std::cerr << "ERROR CREATING OUTPUT FILE.\n";
            return;
        }

        outfile << decoded_text;
        outfile.close();
        infile.close();

        std::cout << "File decompressed successfully.\n";
    }

} // namespace huffman