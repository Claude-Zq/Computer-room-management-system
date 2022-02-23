#include"ReservationFile.h"


/*�вι���,�����ļ���*/
ReservationFile::ReservationFile(std::string fileName) {
	this->m_fileName = fileName;
	initVector();
}

/*��������*/
ReservationFile::~ReservationFile() {
	this->saveVector();
}

/*���ļ��ж�ȡԤԼ��¼��������*/
void ReservationFile::initVector() {
	/*�ļ�Ĭ�ϸ�ʽ �� �� �� ʱ�� ѧ��id ѧ������ ����� ԤԼ״̬ ��ʦid */
	std::ifstream ifs;
	ifs.open(this->m_fileName, std::ios::in);
	if (!ifs.is_open()) { std::cout << this->m_fileName << " �ļ�ȱʧ" << std::endl; return; }
	Reservation r;
	while (ifs >> r.m_date.year >> r.m_date.month >> r.m_date.day >> r.m_period >> r.m_stuId >> r.m_stuName >> r.m_roomId >> r.m_status >> r.m_empId) {
		this->m_allResv.push_back(r);
	}
	ifs.close();/*��ʼ����ɣ��ļ��ر�*/
}

/*�������е�ԤԼ��¼�浽�ļ���*/
void ReservationFile::saveVector() {
	/*�ļ�Ĭ�ϸ�ʽ �� �� �� ʱ�� ѧ��id ѧ������ ����� ԤԼ״̬ ��ʦid */
	std::ofstream ofs;
	ofs.open(this->m_fileName, std::ios::out | std::ios::trunc);/*��ɾ��д*/
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

/*���ļ����*/
void ReservationFile::clearFlile() {
	this->m_allResv.clear();
}