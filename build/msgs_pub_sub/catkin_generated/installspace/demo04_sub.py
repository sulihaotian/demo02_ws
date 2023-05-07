#!/usr/bin/env python3
"""
    订阅方:
        订阅消息

"""
import rospy
from msgs_pub_sub.msg import person

def doperson(p):
    rospy.loginfo("接收到的人的信息:%s, %d, %.2f",p.name, p.age, p.height)


if __name__ == "__main__":
    #1.初始化节点
    rospy.init_node("python_sub_msg")
    #2.创建订阅者对象
    sub = rospy.Subscriber("liaotianpython",person,doperson,queue_size=10)
    rospy.spin() #4.循环
