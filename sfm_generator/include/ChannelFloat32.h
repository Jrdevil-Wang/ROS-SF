// Generated by genheader.py from file sensor_msgs/ChannelFloat32.msg
// DO NOT EDIT!
#pragma once

#include <stdio.h>  
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory>

#include "ros/ros.h"

#include "String_vec.h"
#include "Vec.h"

#include "MemoryManager.h"

#include <iostream>

namespace sensor_msgs {
class ChannelFloat32 {
public:

  String_vec name;

  Vec< float > values;

  ChannelFloat32() {}
  ~ChannelFloat32() {}
    
  ChannelFloat32(const ChannelFloat32 & m) {
    // std::cout << "Alert: Don't copy() sensor_msgs::ChannelFloat32!\n";
    int32_t l1 = mm.get_msg_length((uint8_t *)this);
    int32_t l2 = mm.get_msg_length((uint8_t *)&m); // find length from memory manager
    mm.resize_msg_block((uint8_t *)this, l2 - l1);
    memcpy(this, &m, l2);
  }

  ChannelFloat32 & operator=(const ChannelFloat32 & m) {
    // std::cout << "Alert: Don't copy= sensor_msgs::ChannelFloat32!\n";
    int32_t l1 = mm.get_msg_length((uint8_t *)this);
    int32_t l2 = mm.get_msg_length((uint8_t *)&m); // find length from memory manager
    mm.resize_msg_block((uint8_t *)this, l2 - l1);
    memcpy(this, &m, l2);
  }

  void * operator new(size_t size) {
    const uint32_t MAXLEN = 1920;
    uint8_t * start_shd = new uint8_t[MAXLEN];
    uint8_t * start_msg = start_shd + sizeof(SerializedHeader);
    mm.append_msg_block(start_msg, sizeof(Image), boost::shared_array<uint8_t>(start_shd));
    return start_msg;
  }

  void operator delete(void * p) {
    uint8_t * start_msg = (uint8_t *)p;
    mm.delete_msg_block(start_msg);
  }

  typedef boost::shared_ptr< ::sensor_msgs::ChannelFloat32 > Ptr;
  typedef boost::shared_ptr< ::sensor_msgs::ChannelFloat32 const> ConstPtr;

}; // class ChannelFloat32

typedef boost::shared_ptr< ::sensor_msgs::ChannelFloat32 > ChannelFloat32Ptr;
typedef boost::shared_ptr< ::sensor_msgs::ChannelFloat32 const> ChannelFloat32ConstPtr;

} // namespace sensor_msgs

template<>
boost::shared_ptr<sensor_msgs::ChannelFloat32> boost::make_shared<sensor_msgs::ChannelFloat32>() {
  return boost::shared_ptr<sensor_msgs::ChannelFloat32>(new sensor_msgs::ChannelFloat32);
}

namespace ros {
namespace message_traits {





template <>
struct IsFixedSize< ::sensor_msgs::ChannelFloat32 >
  : FalseType { 
  };

template <>
struct IsFixedSize< ::sensor_msgs::ChannelFloat32 const>
  : FalseType { 
  };

template <>
struct IsMessage< ::sensor_msgs::ChannelFloat32 >
  : TrueType { 
  };

template <>
struct IsMessage< ::sensor_msgs::ChannelFloat32 const>
  : TrueType { 
  };

template <>
struct HasHeader< ::sensor_msgs::ChannelFloat32 >
  : FalseType { 
  };

template <>
struct HasHeader< ::sensor_msgs::ChannelFloat32 const>
  : FalseType { 
  };


template <>
struct MD5Sum< ::sensor_msgs::ChannelFloat32 > {
  static const char * value() {
    return 3d40139cdd33dfedcb71ffeeeb42ae7f;
  }

  static const char * value(const ::sensor_msgs::ChannelFloat32 &) { 
    return value(); 
  }
  static const uint64_t static_value1 = 0x3d40139cdd33dfedULL;
  static const uint64_t static_value2 = 0xcb71ffeeeb42ae7fULL;

};

template <>
struct DataType< ::sensor_msgs::ChannelFloat32 > {
  static const char * value() {
    return "sensor_msgs/ChannelFloat32";
  }

  static const char * value(const ::sensor_msgs::ChannelFloat32 &) { 
    return value(); 
  }

};

template <>
struct Definition< ::sensor_msgs::ChannelFloat32 > {
  static const char * value() {
    return "# This message is used by the PointCloud message to hold optional data\n"
"# associated with each point in the cloud. The length of the values\n"
"# array should be the same as the length of the points array in the\n"
"# PointCloud, and each value should be associated with the corresponding\n"
"# point.\n"
"\n"
"# Channel names in existing practice include:\n"
"#   \"u\", \"v\" - row and column (respectively) in the left stereo image.\n"
"#              This is opposite to usual conventions but remains for\n"
"#              historical reasons. The newer PointCloud2 message has no\n"
"#              such problem.\n"
"#   \"rgb\" - For point clouds produced by color stereo cameras. uint8\n"
"#           (R,G,B) values packed into the least significant 24 bits,\n"
"#           in order.\n"
"#   \"intensity\" - laser or pixel intensity.\n"
"#   \"distance\"\n"
"\n"
"# The channel name should give semantics of the channel (e.g.\n"
"# \"intensity\" instead of \"value\").\n"
"string name\n"
"\n"
"# The values array should be 1-1 with the elements of the associated\n"
"# PointCloud.\n"
"float32[] values\n"
;
  }

  static const char * value(const ::sensor_msgs::ChannelFloat32 &) { 
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
inline SerializedMessage serializeMessage<sensor_msgs::ChannelFloat32>(const sensor_msgs::ChannelFloat32 & message) {
  SerializedMessage m;

  sensor_msgs::ChannelFloat32 * ptr_msg = (sensor_msgs::ChannelFloat32 *)&message;
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
class SubscriptionCallbackHelperT<const boost::shared_ptr<sensor_msgs::ChannelFloat32 const> &> : public SubscriptionCallbackHelper
{
public:
  typedef const boost::shared_ptr<sensor_msgs::ChannelFloat32 const> & P;
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

    sensor_msgs::ChannelFloat32 * ptr_msg = (sensor_msgs::ChannelFloat32 *)start_msg;
    NonConstTypePtr msg = boost::shared_ptr<sensor_msgs::ChannelFloat32>(ptr_msg);

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