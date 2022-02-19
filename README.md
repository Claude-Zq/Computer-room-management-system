# Computer-room-management-system
管理学校机房的软件，解决撞车的问题













##  身份类



### 基类

抽象出子类(学生代表、老师、管理员)共性：

* virtual void penrMenu() = 0；/*展示菜单*/
* m_name; /*用户名*/
* m_pwd; /*密码*/



### 学生类

* 显示学生操作的菜单界面 virtual void operMenu();
* 申请预约  void applyOrder() ;
*  查看自身的预约 void showMyOrder();
* 取消预约 void cancelOrder();
* 查看所有预约 void showALLOrder();
* 取消预约 cancelOrder();
* 学号 m_id

### 老师类

* 显示教师操作的菜单界面 virtual void operMenu();
* 查看所有的预约 void showAllOrder();
* 审核预约 void validOrder();



### 管理员类

* 显示管理员操作的菜单界面 virtual void operMenu();

* 添加账号 void addPerson();

* 查看账号 void showPerson();

* 查看机房信息 void showComputer();

* 清空预约记录 void cleanFile();

  
