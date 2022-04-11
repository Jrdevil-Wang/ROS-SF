#pragma once

#include <algorithm>
#include <stdio.h>  
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory>
#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <boost/shared_array.hpp>

class MemoryManager
{
private:
    /* data */
    std::vector<std::pair<uint8_t*, int>> msg_blocks; 
    std::vector<int> block_order;
    std::map<uint8_t *, int> addr_id;
    std::map<uint8_t *, boost::shared_array<uint8_t>> map_addr2arr;
    
public:
    MemoryManager(/* args */);
    ~MemoryManager();

    int append_msg_block(uint8_t * start_addr, int size, const boost::shared_array<uint8_t> & arr);
    uint8_t * get_msg_addr(int id);
    int get_msg_length(uint8_t * start_addr);
    boost::shared_array<uint8_t> get_msg_array(uint8_t * start_addr);
    std::pair<uint8_t *, int> search_msg_block(uint8_t * start_addr);
    void resize_msg_block(uint8_t * start_addr, int size_add);
    void delete_msg_block(uint8_t * start_addr);
    
    void print_msg_blocks();
    bool cmp(const int & a, const int & b) {
        return msg_blocks[a].first < msg_blocks[b].first;
    }
};

extern MemoryManager mm;

