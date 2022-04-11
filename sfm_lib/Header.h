#pragma once

#include "ros/ros.h"
#include <iostream>
#include "std_msgs/Header.h"
#include "MemoryManager.h"
#include "String_vec.h"

class Header {

public:
    /* data */
    uint32_t seq;
    ros::Time stamp;
    String_vec frame_id;

    Header() : seq(0), stamp(), frame_id() {}
    ~Header() {}

    operator const std_msgs::Header &() const {
        std_msgs::Header h;
        h.seq = seq;
        h.stamp = stamp;
        h.frame_id = std::string(frame_id.c_str());
        return h;
    }
    Header & operator =(const std_msgs::Header & h) {
        seq = h.seq;
        stamp = h.stamp;
        frame_id = h.frame_id;
        return *this;
    }
};

class SerializedHeader {
public:
	uint32_t len;
};

