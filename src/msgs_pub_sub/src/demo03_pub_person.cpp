#include "ros/ros.h"
#include "msgs_pub_sub/person.h"

/*
    发布方
    1.头文件
    2.初始化ros节点
    3.创建节点句柄
    4.创建发布者对象
    5.编写发布逻辑，发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这是消息发布方");
    // 2.初始化ros节点
    ros::init(argc,argv,"banzhuren");
    // 3.创建节点句柄
    ros::NodeHandle jb;
    // 4.创建发布者对象
    ros::Publisher duixiang=jb.advertise<msgs_pub_sub::person>("liaotian",1000);
    // 5.编写发布逻辑，发布数据
    // 5.1创建发布的数据
    msgs_pub_sub::person shuju;
    shuju.name = "小明";
    shuju.age=1;
    shuju.height=1.73;
    // 5.2发布频率
    ros::Rate rate(1);
    // 5.3循环
    while(ros::ok())
    {
        shuju.age++;
        //核心 数据发布
        duixiang.publish(shuju);
        ROS_INFO("发布的消息：%s  %d  %.2f",shuju.name.c_str(),shuju.age,shuju.height);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
