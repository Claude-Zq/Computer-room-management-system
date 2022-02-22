#include"ReservationFile.h"


/*有参构造,传入文件名*/
ReservationFile::ReservationFile(std::string fileName) {
	this->m_fileName = fileName;
	initVector();
}

/*析构函数*/
ReservationFile::~ReservationFile() {
	this->saveVector();
}

/*从文件中读取预约记录到容器中*/
void ReservationFile::initVector() {
	/*文件默认格式 年 月 日 时段 学生id 学生姓名 房间号 预约状态 老师id */
	std::ifstream ifs;
	ifs.open(this->m_fileName, std::ios::in);
	if (!ifs.is_open()) { std::cout << this->m_fileName << " 文件缺失" << std::endl; return; }
	Reservation r;
	while (ifs >> r.m_date.year >> r.m_date.month >> r.m_date.day >> r.m_period >> r.m_stuId >> r.m_stuName >> r.m_roomId >> r.m_status >> r.m_empId) {
		this->m_allResv.push_back(r);
	}
	ifs.close();/*初始化完成，文件关闭*/
}

/*将容器中的预约记录存到文件中*/
void ReservationFile::saveVector() {
	/*文件默认格式 年 月 日 时段 学生id 学生姓名 房间号 预约状态 老师id */
	std::ofstream ofs;
	ofs.open(this->m_fileName, std::ios::out | std::ios::trunc);/*先删后写*/
	for (int i = 0; i < this->m_allResv.size(); i++) {
		ofs << m_allResv[i].m_date.year << " "
			<< m_allResv[i].m_date.month << " "
			<< m_allResv[i].m_date.day << " "
			<< m_allResv[i].m_period << " "
			<< m_allResv[i].m_roomId << " "
			<< m_allResv[i].m_stuName << " "
			<< m_allResv[i].m_roomId << " "
			<< m_allResv[i].m_status << " "
			<< m_allResv[i].m_empId << std::endl;
		std::cout << m_allResv[i].m_date.year << " "
			<< m_allResv[i].m_date.month << " "
			<< m_allResv[i].m_date.day << " "
			<< m_allResv[i].m_period << " "
			<< m_allResv[i].m_roomId << " "
			<< m_allResv[i].m_stuName << " "
			<< m_allResv[i].m_roomId << " "
			<< m_allResv[i].m_status << " "
			<< m_allResv[i].m_empId << std::endl;
	}
	ofs.close();
}

/*将文件清空*/
void ReservationFile::clearFlile() {
	this->m_allResv.clear();
}