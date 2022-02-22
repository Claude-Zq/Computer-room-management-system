#pragma once
#include"date.h"
#include<string>


class Reservation {

public:

	Reservation();

	/*判断两个预约是否冲突*/
	bool is_conflict(const Reservation &r);

	/*日期*/
	date m_date;

	/*时段 上午：1 下午：2*/
	int m_period;

	/*学生账号(学号)*/
	std::string m_stuId;

	/*学生姓名*/
	std::string m_stuName;

	/*房间号*/
	int m_roomId;

	/*预约状态 -1:预约失败 0:已取消 1:审核中 2:预约成功 */
	int m_status;

	/*处理该预约的老师的职工号 没有时为 "??"*/
	std::string m_empId;

};