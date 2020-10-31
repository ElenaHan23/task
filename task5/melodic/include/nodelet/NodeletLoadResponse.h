// Generated by gencpp from file nodelet/NodeletLoadResponse.msg
// DO NOT EDIT!


#ifndef NODELET_MESSAGE_NODELETLOADRESPONSE_H
#define NODELET_MESSAGE_NODELETLOADRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace nodelet
{
template <class ContainerAllocator>
struct NodeletLoadResponse_
{
  typedef NodeletLoadResponse_<ContainerAllocator> Type;

  NodeletLoadResponse_()
    : success(false)  {
    }
  NodeletLoadResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::nodelet::NodeletLoadResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nodelet::NodeletLoadResponse_<ContainerAllocator> const> ConstPtr;

}; // struct NodeletLoadResponse_

typedef ::nodelet::NodeletLoadResponse_<std::allocator<void> > NodeletLoadResponse;

typedef boost::shared_ptr< ::nodelet::NodeletLoadResponse > NodeletLoadResponsePtr;
typedef boost::shared_ptr< ::nodelet::NodeletLoadResponse const> NodeletLoadResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nodelet::NodeletLoadResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::nodelet::NodeletLoadResponse_<ContainerAllocator1> & lhs, const ::nodelet::NodeletLoadResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::nodelet::NodeletLoadResponse_<ContainerAllocator1> & lhs, const ::nodelet::NodeletLoadResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace nodelet

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nodelet::NodeletLoadResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nodelet::NodeletLoadResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nodelet::NodeletLoadResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::nodelet::NodeletLoadResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nodelet/NodeletLoadResponse";
  }

  static const char* value(const ::nodelet::NodeletLoadResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n"
"\n"
;
  }

  static const char* value(const ::nodelet::NodeletLoadResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct NodeletLoadResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nodelet::NodeletLoadResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nodelet::NodeletLoadResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NODELET_MESSAGE_NODELETLOADRESPONSE_H
