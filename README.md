# Computer-room-management-system
管理学校机房的软件，解决撞车的问题









##  身份类



### 基类

抽象出子类(学生代表、老师、管理员)共性：

* virtual void penrMenu() = 0；/*展示菜单*/
* m_name; /*用户名*/
* m_pwd; /*密码*/



### 学生类

#### 接口

* 显示学生操作的菜单界面 virtual void operMenu();
* 申请预约  void applyOrder() ;
*  查看自身的预约 void showMyOrder();
* 取消预约 void cancelOrder();
* 查看所有预约 void showALLOrder();
* 取消预约 cancelOrder();
* 学号

