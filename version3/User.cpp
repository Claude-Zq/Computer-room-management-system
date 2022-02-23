#include"User.h"


/*展示所有预约记录*/
void User::showAllRsv() {
	ReservationFile rf(RESERVATION_FILE);

	if (rf.m_allResv.size() == 0) {
		std::cout << "当前预约记录为空" << std::endl;
		return;
	}

	int count = 0;
	std::cout << "当前所有预约记录如下" << std::endl;
	for (auto it = rf.m_allResv.begin(); it != rf.m_allResv.end(); it++) {
		/*文件默认格式 年 月 日 时段 学生id 学生姓名 房间号 预约状态 老师id */
		std::cout << ++count << "、时间: "
			<< it->m_date.year << '/' << it->m_date.month << '/' << it->m_date.day
			<< " 时段: " << (it->m_period == 1 ? "上午" : "下午")
			<< " 姓名: " << it->m_stuName
			<< "\t机房号: " << it->m_roomId
			<< " 预约状态: ";
		if (it->m_status == -1) std::cout << "预约失败";
		else if (it->m_status == 0) std::cout << "已取消";
		else if (it->m_status == 1) std::cout << "审核中";
		else if (it->m_status == 2) std::cout << "预约成功";
		std::cout << "\t处理人:"
			<< (it->m_empId == "??" ? "暂无" : it->m_empId)
			<< std::endl;
	}
}