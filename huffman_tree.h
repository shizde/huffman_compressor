#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <memory>
#include <unordered_map>
#include <queue>
#include <string>
#include <array>

namespace huffman
{

    class Node
    {
    public:
        unsigned char character;
        int frequency;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(unsigned char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

        struct Compare
        {
            bool operator()(std::shared_ptr<Node> const &l, std::shared_ptr<Node> const &r)
            {
                return l->frequency > r->frequency;
            }
        };
    };

    std::shared_ptr<Node> build_huffman_tree(const std::unordered_map<unsigned char, int> &frequency_table);
    void build_huffman_codes(const std::shared_ptr<Node> &root, const std::string &code,
                             std::unordered_map<unsigned char, std::string> &huffman_codes);

} // namespace huffman

#endif // HUFFMAN_TREE_H