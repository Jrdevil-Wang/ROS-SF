#include "sensor_msgs/MemoryManager.h"
MemoryManager mm;
MemoryManager::MemoryManager(/* args */) {}

MemoryManager::~MemoryManager() {
    msg_blocks.clear();
    block_order.clear();
}

int MemoryManager::append_msg_block(uint8_t * start_addr, int size, const boost::shared_array<uint8_t> & arr) {
    int block_id = msg_blocks.size();

    addr_id[start_addr] = block_id;
    map_addr2arr[start_addr] = arr;
    
    msg_blocks.push_back(std::pair<uint8_t*, int>(start_addr, size));
    block_order.push_back(block_id);
    std::sort(block_order.begin(), block_order.end(), [&](const int & first, const int & second) { return get_msg_addr(first) < get_msg_addr(second); });
    
    return block_id;
}

uint8_t * MemoryManager::get_msg_addr(int id) {
    return msg_blocks[id].first;
}

int MemoryManager::get_msg_length(uint8_t * start_addr) {
    int id = addr_id[start_addr];
    return msg_blocks[id].second;
}
boost::shared_array<uint8_t> MemoryManager::get_msg_array(uint8_t * start_addr) {
    return map_addr2arr[start_addr];
}
// uint8_t * MemoryManager::get_msg_end_addr(int id) {
//     return msg_blocks[id].first + msg_blocks[id].second;
// }

// int MemoryManager::get_msg_length(int id) {
//     return msg_blocks[id].second;
// }

std::pair<uint8_t *, int> MemoryManager::search_msg_block(uint8_t * addr) {
    // binary search
    int left = 0; 
    int right = block_order.size() - 1;

    while(left <= right) {
        int mid = (right + left) / 2;
        uint8_t * start = msg_blocks[block_order[mid]].first;

        int length = msg_blocks[block_order[mid]].second;
        if (start <= addr and start + length > addr) 
            return msg_blocks[block_order[mid]];
        else if (start > addr)
            right = mid - 1;
        else if (start + length <= addr) 
            left = mid + 1;
    }
    std::cout << "In @search_msg_block find -1" << std::endl; 
    return std::pair<uint8_t*, int>(nullptr, -1);
}

void MemoryManager::resize_msg_block(uint8_t * start_addr, int size_add) {
    int id = addr_id[start_addr];
    msg_blocks[id].second = msg_blocks[id].second + size_add;
}

void MemoryManager::delete_msg_block(uint8_t * start_addr) {
    int id = addr_id[start_addr];
    auto iter2 = block_order.begin();
    for (auto iter = block_order.begin(); iter != block_order.end(); iter++) {
        if (*iter == id) {
            iter2 = iter;
            break;
        }
    }
    block_order.erase(iter2);
    // uint8_t * addr = get_msg_addr(id);
    // free(start_addr);
    msg_blocks[id] = std::pair<uint8_t *, int>(nullptr, 0);
    addr_id.erase(start_addr);
    map_addr2arr.erase(start_addr);
}

void MemoryManager::print_msg_blocks() {
    std::cout << "msg blocks \n";
    for(int i = 0; i < msg_blocks.size(); i++) {
        std::cout << (int *)msg_blocks[i].first << " " << (int*)(msg_blocks[i].first + msg_blocks[i].second) << " " << msg_blocks[i].second << std::endl;
    } 
    std::cout << "block order \n";
    for (int i = 0; i < block_order.size(); i++) {
        std::cout << block_order[i] << std::endl;
    }
}
