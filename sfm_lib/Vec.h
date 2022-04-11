#pragma once

#include "MemoryManager.h"
#include "Vec_iterator.h"

template <class T>
class Vec {
public:
    /* data */
    uint32_t offset = 0;
    uint32_t length = 0;

    Vec() : offset(0), length(0) {}
    ~Vec() {}

    void resize(int size) {
		if (this->length != 0) {
		    std::cout << this->length << std::endl;
		    std::cout << "Re-resize of Vec is detected" << std::endl;
		    exit(0);
		}

		this->length = size;

		uint8_t * cur_addr = (uint8_t *)this;

		std::pair<uint8_t *, int> msg_block = mm.search_msg_block(cur_addr);

		uint8_t * old_start = msg_block.first;
		int offset_of_vec = cur_addr - old_start;
		uint8_t * old_end = msg_block.first + msg_block.second;
		this->offset = old_end - cur_addr;
		int this_offset = this->offset;

		mm.resize_msg_block(old_start, size * sizeof(T));
	}
    T & operator[](int index) const {
		return *(T *) ((uint8_t *) this + offset + sizeof(T) * index);
	}

    int size() const {
		return this->length;
	}

    Vec_iterator<T> begin() const {
		return Vec_iterator<T>((uint8_t *) this + offset);
	}
    Vec_iterator<T> end() const {
		return Vec_iterator<T>((uint8_t *) this + offset + sizeof(T) * length);
	}
};

