#include "compression.h"
#include "huffman_tree.h"
#include <fstream>
#include <iostream>

namespace huffman
{

	std::unordered_map<unsigned char, int> build_frequency_table(const std::string &text)
	{
		std::unordered_map<unsigned char, int> frequency_table;
		for (unsigned char ch : text)
		{
			frequency_table[ch]++;
		}
		return frequency_table;
	}

	std::string encode_text(const std::string &text, const std::unordered_map<unsigned char, std::string> &huffman_codes)
	{
		std::string encoded;
		for (unsigned char ch : text)
		{
			encoded += huffman_codes.at(ch);
		}
		return encoded;
	}

	void write_huffman_dictionary(std::ofstream &outfile, const std::unordered_map<unsigned char, std::string> &huffman_codes)
	{
		char dict_size = static_cast<char>(huffman_codes.size());
		outfile.write(&dict_size, sizeof(char));

		for (const auto &entry : huffman_codes)
		{
			char character = static_cast<char>(entry.first);
			char length = static_cast<char>(entry.second.length());
			outfile.write(&character, sizeof(char));
			outfile.write(&length, sizeof(char));
			outfile.write(entry.second.c_str(), length);
		}
	}

	void compress_file(const std::string &input_filename, const std::string &output_filename)
	{
		std::ifstream infile(input_filename);
		if (!infile.is_open())
		{
			std::cerr << "ERROR OPENING INPUT FILE.\n";
			return;
		}

		std::string text((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
		infile.close();

		auto frequency_table = build_frequency_table(text);
		auto huffman_tree = build_huffman_tree(frequency_table);

		std::unordered_map<unsigned char, std::string> huffman_codes;
		build_huffman_codes(huffman_tree, "", huffman_codes);

		std::string encoded_text = encode_text(text, huffman_codes);

		std::ofstream outfile(output_filename, std::ios::binary);
		if (!outfile.is_open())
		{
			std::cerr << "ERROR CREATING OUTPUT FILE.\n";
			return;
		}

		write_huffman_dictionary(outfile, huffman_codes);

		char buffer = 0;
		int bit_pos = 0;

		for (char bit : encoded_text)
		{
			if (bit == '1')
			{
				buffer |= (1 << (7 - bit_pos));
			}
			bit_pos++;
			if (bit_pos == 8)
			{
				outfile.write(&buffer, sizeof(char));
				buffer = 0;
				bit_pos = 0;
			}
		}

		if (bit_pos > 0)
		{
			outfile.write(&buffer, sizeof(char));
		}

		outfile.close();
		std::cout << "File compressed successfully.\n";
	}

} // namespace huffman