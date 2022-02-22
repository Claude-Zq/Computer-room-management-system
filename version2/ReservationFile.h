#pragma once
#include<fstream>
#include<vector>
#include<string>
#include"Reservation.h"
#include<iostream>


/*仅仅在构造函数中读取文件，析构时保存文件，所以请避免同时使用两个对象*/
/*文件默认格式 年 月 日 时段 学生id 学生姓名 房间号 预约状态 老师id */
class ReservationFile {

public:
	/*有参构造,传入文件名*/
	ReservationFile(std::string fileName);

	/*析构函数*/
	~ReservationFile();

	/*从文件中读取预约记录到容器中*/
	void initVector();

	/*将容器中的预约记录存到文件中*/
	void saveVector();

	/*将文件清空*/
	void clearFlile();

	/*存放所有的预约信息*/
	std::vector<Reservation> m_allResv;

private:
	std::string m_fileName;
	
};