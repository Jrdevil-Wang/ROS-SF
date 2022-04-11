#pragma once

#include "Vec.h"
#include <string>

class String_vec : public Vec<char> {
private:
    /* data */
public:
    std::string get_string() const {
        return std::string(c_str());
    }
    void set_by_string(const std::string & str) {
		if (this->length != 0) {
		    std::cout << str << " " << this->length << std::endl;
		    std::cout << "Re-assignment of string is detected" << std::endl;
		    exit(0);
		}
		
		this->length = str.length() + 1;
		// std::cout << "in String_vec::set_by_string " << std::endl;

		uint8_t * cur_addr = (uint8_t *)this;
		// std::cout << (int*)cur_addr<< std::endl;
		
		std::pair<uint8_t *, int> msg_block = mm.search_msg_block(cur_addr);

		uint8_t * old_start = msg_block.first;

		int offset_of_string_vec = cur_addr - old_start;

		uint8_t * old_end = msg_block.first + msg_block.second;
		this->offset = old_end - cur_addr;
		int offset_of_value = this->offset;
		
		// attention: this->offset changes aftering calling mm.resize_msg_block?
		mm.resize_msg_block(old_start, this->length);

		uint8_t * new_cur_addr = old_start + offset_of_string_vec;
		
		memcpy(new_cur_addr + offset_of_value, str.c_str(), str.length() + 1);
	}
    
    operator const std::string &() const {
        return std::string(c_str());
    }
    String_vec & operator=(const std::string & str) {
        set_by_string(str);
        return *this;
    }
    int operator !=(const std::string & str) const {
        return strcmp(c_str(), str.c_str());
    }
    char * c_str() const {
        return (char *)this + this->offset;
    }
};

