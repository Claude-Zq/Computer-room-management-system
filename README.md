# Computer-room-management-system
管理学校机房的软件，解决撞车的问题













##  身份类



#### 基类

抽象出子类(学生代表、老师、管理员)共性：

* virtual void penrMenu() = 0；/*展示菜单*/
* m_name; /*用户名*/
* m_pwd; /*密码*/



#### 学生类

* 显示学生操作的菜单界面 virtual void operMenu();
* 申请预约  void applyOrder() ;
*  查看自身的预约 void showMyOrder();
* 取消预约 void cancelOrder();
* 查看所有预约 void showALLOrder();
* 取消预约 cancelOrder();
* 学号 m_id

#### 老师类

* 显示教师操作的菜单界面 virtual void operMenu();
* 查看所有的预约 void showAllOrder();
* 审核预约 void validOrder();



#### 管理员类

* 显示管理员操作的菜单界面 virtual void operMenu();

* 添加账号 void addPerson();

* 查看账号 void showPerson();

* 查看机房信息 void showComputer();

* 清空预约记录 void cleanFile();

  

## 登录模块

* 全局文件：globalFile
* 登录函数：void LogIn(std::string fileName, int type);*文件名，用户选择*





#### 学生登录的实现

学生的账号信息保留在student.txt文件中

* 第一列 学号
* 第二列 学生姓名
* 第三列 密码

通过一行一行的读文件，与用户的输入比对，完成验证

注意：编码方式为UTF-8时，会出现中文乱码，可打开txt文件，点另存为，修改为ANSI



#### 教师登录功能的实现

教师的账号信息保留在teacher.txt文件中

* 第一列 教师职工编号
* 第二列 教师姓名
* 第三列 密码

方法同上



#### 管理员登录功能的实现

管理员的信息保存在admin.txt文件中

* 第一行 管理用户名
* 第二行 密码

注意：由于只有一个管理员，所以没有添加管理员的功能

方法同上







