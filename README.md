# Computer-room-management-system


## 原版

###  身份类

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

  * 去重方方案

  ```c++
  //存放学生信息
  std::vector<Student> vStu;
  //存放老师信息
  std::vector<Teacher> vTea;
  //初始化以上容器(在每次Manager的构造、添加完学生信息后调用)
  void initVector();
  //检测重复(查看容器中是否有已yid)
  bool checkRepeat(int id, int type);
  ```

* 查看账号 void showPerson();

* 查看机房信息 void showComputer();

* 清空预约记录 void cleanFile();

  

### 登录模块

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



注意:orderfile.txt的每一行末尾不能有空格，运行时会提示错误









##  重构版

改进方面

* 将原版中main函数文件中的全局函数封装进一个类CRMS_manager，管理整个程序，便于后续扩展
* 学生/老师/管理员可以修改自己的密码
* 管理员可添加其他管理员、添加、修改机房信息，删除老师/学生/其他管理员的信息
* 直接填写日期(如2022 2 2 24)，而不是在 周一、二、三... 中选择,用到了本人之前写的[date](https://github.com/Claude-Zq/useful_class/tree/main/date)来判断是否是工作日
* 真正防止预约重复
  * 老师同意一个预约后，自动筛去 待审核预约中 与本预约抵触的预约
  * 若机房在一个时段已经被预约，学生提交申请便会提示
* 文件操作
  * 封装AccountFile类，管理储存账号的文件
  * 封装ReservationFile类，管理记录预约信息的文件
  * 封装ComputerRoomFile类，管理机房信息的文件




### 用户类

#### 基类User

* 成员变量: Account m_account //存放账号信息
* 成员函数  
  * virtual void showMenu() = 0;//展示菜单
  * virtual void changePwd() = 0;//修改密码
  * void showAllRsv();//展示所有预约记录

#### 子类Student

* Student(std::string id = "", std::string name = "", std::string pwd = "");/*构造函数*/
* Student(const Account& a);/*构造函数*/
* virtual void showMenu();/*展示菜单*/
* virtual void changePwd();/*修改自身密码*/
* void applyRsv();//申请预约
* void showMyRsv();//查看我的预约
* void cancelRsv();//取消预约



#### 子类Teacher

* Teacher(const Account& a);/*构造函数*/
* Teacher(std::string id = "", std::string name = "", std::string pwd = "");/*构造函数*/
* virtual void showMenu();/*展示菜单*/
* virtual void changePwd();/*修改自身密码*/
* void auditRsv();/*审核预约*/



#### 子类Administrator

* Administrator::Administrator(std::string id = "", std::string name = "", std::string pwd = "") //有参构造(账号、姓名、密码)

* virtual void Administrator::showMenu() //展示菜单
* virtual void Administrator::changePwd()修改自身密码
* void Administrator::addAccount() //添加账号
* void Administrator::deleteAccount()//删除账号
*  void Administrator::addComputerRoom() //添加机房信息
*  void Administrator::showComputerRoom() //查看机房信息
*  void Administrator::modifyComputerRoom() //修改机房信息
* void Administrator::showAccount()//查看账号
* void Administrator::clearRsv()//清空预约记录





### 文件类

注意:以下文件类的对象均只在构造函数中读取文件信息，析构时才将改动同步到文件中，所以请勿对同一文件同时使用多个对象

#### AccountFile类

###### 对内接口

* void initMap();/*初始化m_allAccount*/
* void saveMap();/*将容器中保存的信息保存到文件中*/
* std::string m_fileName;/*维护的文件名称*/
* ~AccountFile();/*析构时保存文件*/



###### 对外接口

* AccountFile(std::string fileName);/*构造函数(参数时管理的文件名)*/
* std::map<std::string, Account> m_allAccount;/*存放该文件中的所有账号信息(id-Account的映射)
* bool findId(std::string id);/*查找容器中是否有指定id第账号*/
* int verify(const Account& a);/*验证账号:0-没有账号 1-验证成功 -1-密码错误 2-姓名错误*/
* bool addAccount(const Account& a);/*添加账号 已有相同id时返回false*/
* bool deleteAccount(std::string id);/*按id号删除账号 无对应id时返回false*/
* bool modifyName(std::string id, std::string name);/*修改账号id对应的姓名无对应id时返回false*/
* bool modifyPwd(std::string id, std::string pwd);/*修改账号id对应的密码  无对应id时返回false*/



#### ComputerRoomFile类

###### 对内的接口

* void initMap();/*初始化容器*/
* void saveMap();/*将容器内的信息保存到文件中*/
* std::string m_fileName;/*管理的文件名*/
* ~ComputerRoomFile();/*析构函数*/

###### 对外接口

* ComputerRoomFile(std::string fileName);/*构造函数*/
* std::map<int, int> m_allRoom;/*所有的机房信息 编号-容量*/
* bool m_isOpen;/*文件是否打开成功*/



#### ReservationFile类

###### 对内接口

* ~ReservationFile();/*析构函数*/
* void initVector();	/*从文件中读取预约记录到容器中*/
* std::string m_fileName;/*管理的文件名*/
* void saveVector();/*将容器中的预约记录存到文件中*/

###### 对外接口

* ReservationFile(std::string fileName);/*有参构造,传入文件名*/
* void clearFlile();/*将文件清空*/
* std::vector<Reservation> m_allResv;/*存放所有的预约信息*/





