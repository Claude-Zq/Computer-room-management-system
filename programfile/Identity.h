#pragma once
#include<string>


//身份抽象类
class Identity {	
public:
	//操作菜单
	virtual void operMenu() = 0;

	std::string m_name;//用户名
	std::string m_pwd;//密码
};
