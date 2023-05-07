import rospy
from msgs_pub_sub.msg import person

if __name__=="__main__":
    rospy.init_node("python_pub_msg")

    shuju=rospy.Publisher("liaotianpython", person,queue_size=10)

    p=person()

    p.name="小红"
    p.age=18
    p.height=0.75

    rate=rospy.Rate(1)
    while not rospy.is_shutdown():
        shuju.publish(p)
        rate.sleep()
        rospy.loginfo("姓名：%s  年龄：%d  身高：%.2f",p.name,p.age,p.height)