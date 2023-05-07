#include "ros/ros.h"
#include "msgs_pub_sub/person.h"

void doperson(const msgs_pub_sub::person::ConstPtr& person_p)
{
    ROS_INFO("订阅人的消息：%s  %d  %.2f",person_p->name.c_str(),person_p->age,person_p->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"cpp_sub_msg");
    ros::NodeHandle lt;
    ros::Subscriber tiandao = lt.subscribe<msgs_pub_sub::person>("liaotian",10,doperson);
    ros::spin();
    return 0;
}
