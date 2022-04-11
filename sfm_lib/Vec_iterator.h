#pragma once

template <class T>
class Vec_iterator {
    private:
        uint8_t * startAddr;
    public:
        Vec_iterator(uint8_t * addr) : startAddr(addr) {}
        
        T & operator * () const {
            return *(T *)startAddr;
        }

        Vec_iterator & operator++() {
            startAddr += sizeof(T);
            return *this;
        }

        Vec_iterator & operator+(int idx) {
            startAddr += idx * sizeof(T);
            return *this;
        }
        
        Vec_iterator operator++(int) {
            Vec_iterator ret = *this;
            ++*this;
            return ret;
        }

        bool operator==(const Vec_iterator &arg) const {
            return arg.startAddr == this->startAddr;
        }

        bool operator!=(const Vec_iterator &arg) const {
            return arg.startAddr != this->startAddr;
        }
        
        uint8_t * get_startAddr() {
            return startAddr;
        }
};

