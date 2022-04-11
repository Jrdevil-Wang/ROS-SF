// Generated by genheader.py from file sensor_msgs/Image.msg
// DO NOT EDIT!
#pragma once

#include <stdio.h>  
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory>

#include "ros/ros.h"

#include "Header.h"
#include "String_vec.h"
#include "Vec.h"

#include "MemoryManager.h"

#include <iostream>

namespace sensor_msgs {
class Image {
public:

  Header header;

  uint32_t height;

  uint32_t width;

  String_vec encoding;

  uint8_t is_bigendian;

  uint32_t step;

  Vec< uint8_t > data;

  Image() {}
  ~Image() {}
    
  Image(const Image & m) {
    // std::cout << "Alert: Don't copy() sensor_msgs::Image!\n";
    int32_t l1 = mm.get_msg_length((uint8_t *)this);
    int32_t l2 = mm.get_msg_length((uint8_t *)&m); // find length from memory manager
    mm.resize_msg_block((uint8_t *)this, l2 - l1);
    memcpy(this, &m, l2);
  }

  Image & operator=(const Image & m) {
    // std::cout << "Alert: Don't copy= sensor_msgs::Image!\n";
    int32_t l1 = mm.get_msg_length((uint8_t *)this);
    int32_t l2 = mm.get_msg_length((uint8_t *)&m); // find length from memory manager
    mm.resize_msg_block((uint8_t *)this, l2 - l1);
    memcpy(this, &m, l2);
  }

  void * operator new(size_t size) {
    const uint32_t MAXLEN = 6222720;
    uint8_t * start_shd = new uint8_t[MAXLEN];
    uint8_t * start_msg = start_shd + sizeof(SerializedHeader);
    mm.append_msg_block(start_msg, sizeof(Image), boost::shared_array<uint8_t>(start_shd));
    return start_msg;
  }

  void operator delete(void * p) {
    uint8_t * start_msg = (uint8_t *)p;
    mm.delete_msg_block(start_msg);
  }

  typedef boost::shared_ptr< ::sensor_msgs::Image > Ptr;
  typedef boost::shared_ptr< ::sensor_msgs::Image const> ConstPtr;

}; // class Image

typedef boost::shared_ptr< ::sensor_msgs::Image > ImagePtr;
typedef boost::shared_ptr< ::sensor_msgs::Image const> ImageConstPtr;

} // namespace sensor_msgs

template<>
boost::shared_ptr<sensor_msgs::Image> boost::make_shared<sensor_msgs::Image>() {
  return boost::shared_ptr<sensor_msgs::Image>(new sensor_msgs::Image);
}

namespace ros {
namespace message_traits {





template <>
struct IsFixedSize< ::sensor_msgs::Image >
  : FalseType { 
  };

template <>
struct IsFixedSize< ::sensor_msgs::Image const>
  : FalseType { 
  };

template <>
struct IsMessage< ::sensor_msgs::Image >
  : TrueType { 
  };

template <>
struct IsMessage< ::sensor_msgs::Image const>
  : TrueType { 
  };

template <>
struct HasHeader< ::sensor_msgs::Image >
  : TrueType { 
  };

template <>
struct HasHeader< ::sensor_msgs::Image const>
  : TrueType { 
  };


template <>
struct MD5Sum< ::sensor_msgs::Image > {
  static const char * value() {
    return 060021388200f6f0f447d0fcd9c64743;
  }

  static const char * value(const ::sensor_msgs::Image &) { 
    return value(); 
  }
  static const uint64_t static_value1 = 0x060021388200f6f0ULL;
  static const uint64_t static_value2 = 0xf447d0fcd9c64743ULL;

};

template <>
struct DataType< ::sensor_msgs::Image > {
  static const char * value() {
    return "sensor_msgs/Image";
  }

  static const char * value(const ::sensor_msgs::Image &) { 
    return value(); 
  }

};

template <>
struct Definition< ::sensor_msgs::Image > {
  static const char * value() {
    return "# This message contains an uncompressed image\n"
"# (0, 0) is at top-left corner of image\n"
"#\n"
"\n"
"Header header        # Header timestamp should be acquisition time of image\n"
"                     # Header frame_id should be optical frame of camera\n"
"                     # origin of frame should be optical center of camera\n"
"                     # +x should point to the right in the image\n"
"                     # +y should point down in the image\n"
"                     # +z should point into to plane of the image\n"
"                     # If the frame_id here and the frame_id of the CameraInfo\n"
"                     # message associated with the image conflict\n"
"                     # the behavior is undefined\n"
"\n"
"uint32 height         # image height, that is, number of rows\n"
"uint32 width          # image width, that is, number of columns\n"
"\n"
"# The legal values for encoding are in file src/image_encodings.cpp\n"
"# If you want to standardize a new string format, join\n"
"# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n"
"\n"
"string encoding       # Encoding of pixels -- channel meaning, ordering, size\n"
"                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n"
"\n"
"uint8 is_bigendian    # is this data bigendian?\n"
"uint32 step           # Full row length in bytes\n"
"uint8[] data          # actual matrix data, size is (step * rows)\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char * value(const ::sensor_msgs::Image &) { 
    return value(); 
  }

};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<>
inline SerializedMessage serializeMessage<sensor_msgs::Image>(const sensor_msgs::Image & message) {
  SerializedMessage m;

  sensor_msgs::Image * ptr_msg = (sensor_msgs::Image *)&message;
  uint8_t * start_msg = (uint8_t *)ptr_msg;
  uint8_t * start_shd = start_msg - sizeof(SerializedHeader);

  int32_t len = mm.get_msg_length(start_msg); // find length from memory manager
  m.num_bytes = len + sizeof(SerializedHeader);

  SerializedHeader * ptr_shd = (SerializedHeader *)start_shd;
  ptr_shd->len = len; // write length to serialized message

  m.buf = mm.get_msg_array(start_msg);
//  std::cout << "in ser: " << len << ", " << &message << "\n";
  return m;
}

} // namespace serialization

template<>
class SubscriptionCallbackHelperT<const boost::shared_ptr<sensor_msgs::Image const> &> : public SubscriptionCallbackHelper
{
public:
  typedef const boost::shared_ptr<sensor_msgs::Image const> & P;
  typedef ParameterAdapter<P> Adapter;
  typedef typename ParameterAdapter<P>::Message NonConstType;
  typedef typename ParameterAdapter<P>::Event Event;
  typedef typename boost::add_const<NonConstType>::type ConstType;
  typedef boost::shared_ptr<NonConstType> NonConstTypePtr;
  typedef boost::shared_ptr<ConstType> ConstTypePtr;

  static const bool is_const = ParameterAdapter<P>::is_const;

  typedef boost::function<void(typename Adapter::Parameter)> Callback;
  typedef boost::function<NonConstTypePtr()> CreateFunction;

  SubscriptionCallbackHelperT(const Callback& callback, 
			      const CreateFunction& create = DefaultMessageCreator<NonConstType>())
    : callback_(callback)
    , create_(create)
  { }

  void setCreateFunction(const CreateFunction& create)
  {
    create_ = create;
  }

  virtual bool hasHeader()
  {
     return message_traits::hasHeader<typename ParameterAdapter<P>::Message>();
  }

  virtual VoidConstPtr deserialize(const SubscriptionCallbackHelperDeserializeParams& params)
  {
    namespace ser = serialization;

    uint8_t * start_msg = params.buffer;
    int32_t len = params.length;

    mm.append_msg_block(start_msg, len, params.buf);

    sensor_msgs::Image * ptr_msg = (sensor_msgs::Image *)start_msg;
    NonConstTypePtr msg = boost::shared_ptr<sensor_msgs::Image>(ptr_msg);

    ser::PreDeserializeParams<NonConstType> predes_params;
    predes_params.message = msg;
    predes_params.connection_header = params.connection_header;
    ser::PreDeserialize<NonConstType>::notify(predes_params);

    return VoidConstPtr(msg);
  }

  virtual void call(SubscriptionCallbackHelperCallParams& params)
  {
    Event event(params.event, create_);
    callback_(ParameterAdapter<P>::getParameter(event));
  }

  virtual const std::type_info& getTypeInfo()
  {
    return typeid(NonConstType);
  }

  virtual bool isConst()
  {
    return ParameterAdapter<P>::is_const;
  }

private:
  Callback callback_;
  CreateFunction create_;
};

} // namespace ros