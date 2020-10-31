// Generated by gencpp from file turtle_actionlib/ShapeActionGoal.msg
// DO NOT EDIT!


#ifndef TURTLE_ACTIONLIB_MESSAGE_SHAPEACTIONGOAL_H
#define TURTLE_ACTIONLIB_MESSAGE_SHAPEACTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalID.h>
#include <turtle_actionlib/ShapeGoal.h>

namespace turtle_actionlib
{
template <class ContainerAllocator>
struct ShapeActionGoal_
{
  typedef ShapeActionGoal_<ContainerAllocator> Type;

  ShapeActionGoal_()
    : header()
    , goal_id()
    , goal()  {
    }
  ShapeActionGoal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , goal_id(_alloc)
    , goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
  _goal_id_type goal_id;

   typedef  ::turtle_actionlib::ShapeGoal_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct ShapeActionGoal_

typedef ::turtle_actionlib::ShapeActionGoal_<std::allocator<void> > ShapeActionGoal;

typedef boost::shared_ptr< ::turtle_actionlib::ShapeActionGoal > ShapeActionGoalPtr;
typedef boost::shared_ptr< ::turtle_actionlib::ShapeActionGoal const> ShapeActionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator1> & lhs, const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.goal_id == rhs.goal_id &&
    lhs.goal == rhs.goal;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator1> & lhs, const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace turtle_actionlib

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dbfccd187f2ec9c593916447ffd6cc77";
  }

  static const char* value(const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdbfccd187f2ec9c5ULL;
  static const uint64_t static_value2 = 0x93916447ffd6cc77ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtle_actionlib/ShapeActionGoal";
  }

  static const char* value(const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"\n"
"Header header\n"
"actionlib_msgs/GoalID goal_id\n"
"ShapeGoal goal\n"
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
"\n"
"================================================================================\n"
"MSG: actionlib_msgs/GoalID\n"
"# The stamp should store the time at which this goal was requested.\n"
"# It is used by an action server when it tries to preempt all\n"
"# goals that were requested before a certain time\n"
"time stamp\n"
"\n"
"# The id provides a way to associate feedback and\n"
"# result message with specific goal requests. The id\n"
"# specified must be unique.\n"
"string id\n"
"\n"
"\n"
"================================================================================\n"
"MSG: turtle_actionlib/ShapeGoal\n"
"# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"#goal definition\n"
"int32 edges\n"
"float32 radius\n"
;
  }

  static const char* value(const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.goal_id);
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ShapeActionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtle_actionlib::ShapeActionGoal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::turtle_actionlib::ShapeGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLE_ACTIONLIB_MESSAGE_SHAPEACTIONGOAL_H
