#pragma once
#include"User.h"
#include"ReservationFile.h"
#include"globalFile.h"
#include"AccountFile.h"
#include"ComputerRoomFile.h"




class Administrator :public User {
public:

	//有参构造(账号、姓名、密码)
	Administrator(std::string id = "", std::string name = "", std::string pwd = "");

	Administrator(const Account& a);



	/*展示菜单*/
	virtual void showMenu();

	//删除账号
	void deleteAccount();

	//添加账号
	void addAccount();

	//添加机房
	void addComputerRoom();

	//查看机房信息
	void showComputerRoom();

	//修改机房信息
	void modifyComputerRoom();

	/*修改自身密码*/
	virtual void changePwd();

	//查看账号
	void showAccount();

	//清空预约记录
	void clearRsv();

};

