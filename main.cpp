#include <bits/stdc++.h>
using namespace std;
struct BlockChain {
    string data;
    BlockChain *next;
};
string HashingCode(BlockChain* block) {
    vector<vector<char>> val = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'j'},
        {'k', 'l', 'm', 'n', 'o'},
        {'p', 'q', 'r', 's', 't'},
        {'u', 'v', 'w', 'x', 'y'},
    };
    string hashcode = "";
    int xor_key = 0;
    int offset = 7;
    for (int i = 0; i < block->data.length(); i++) {
        char currentChar = block->data[i];
        bool found = false;
        for (int j = 0; j < val.size() && !found; j++) {
            for (int k = 0; k < val[j].size() && !found; k++) {
                if (currentChar == val[j][k]) {
                    int x = (j + offset + i) % val.size();
                    int y = (k + offset + i) % val[j].size();
                    hashcode += to_string(x) + to_string(y);
                    xor_key ^= (x << 3) | y;
                    found = true;
                }
            }
        }
        if (!found) {
            stringstream ss;
            ss << hex << (int)currentChar;
            hashcode += ss.str();
        }
        offset = (offset + xor_key) % 5;
    }
    return hashcode;
}
unordered_map<string, BlockChain*> BlockHashTable;
BlockChain* BlockHashTableSearch(BlockChain* block) {
    string hashKey = HashingCode(block);
    if (BlockHashTable.find(hashKey) != BlockHashTable.end()) {
        return BlockHashTable[hashKey];
    } else {
        return nullptr;
    }
}
int main() {
    BlockChain block1;
    block1.data = "Hello";
    block1.next = NULL; 
    BlockChain block2;
    block2.data = "World";
    block2.next = NULL; 
    block1.next = &block2;
    BlockChain block3; 
    block3.data = "!";
    block3.next = NULL; 
    block2.next = &block3;
    BlockChain block4;
    block4.data = "This";
    block4.next = NULL; 
    block3.next = &block4;
    BlockChain block5; 
    block5.data = "is";
    block5.next = NULL; 
    block4.next = &block5;
    BlockChain block6;
    block6.data = "a";
    block6.next = NULL; 
    block5.next = &block6;
    BlockChain block7;
    block7.data = "test";
    block7.next = NULL; 
    block6.next = &block7;
    BlockChain block8;
    block8.data = "case";
    block8.next = NULL; 
    block7.next = &block8;
    BlockChain block9;
    block9.data = "for";
    block9.next = NULL; 
    block8.next = &block9;
    BlockChain block10;
    block10.data = "hashing";
    block10.next = NULL; 
    block9.next = &block10;
    vector<BlockChain> blocks = {block1, block2, block3, block4, block5, block6, block7, block8, block9, block10};
    for (int i = 0; i < blocks.size(); i++) {
        cout << HashingCode(&blocks[i]) << " " << blocks[i].data << endl;
    }
    for (int i = 0; i < blocks.size(); i++) {
        BlockHashTable[HashingCode(&blocks[i])] = &blocks[i];
    }
    for (auto it = BlockHashTable.begin(); it != BlockHashTable.end(); it++) {
        cout << it->first << " " << it->second->data << endl;
    }
    return 0;
}
