#include"ComputerRoomFile.h"



/*���캯��*/
ComputerRoomFile::ComputerRoomFile(std::string fileName) {
	this->m_fileName = fileName;
	initMap();
}

/*��������*/
ComputerRoomFile::~ComputerRoomFile() {
	saveMap();
}


/*��ʼ������*/
void ComputerRoomFile::initMap() {
	this->m_allRoom.clear();

	std::ifstream ifs;/*���ļ�*/
	ifs.open(this->m_fileName, std::ios::in);

	if (!ifs.is_open()) {
		std::cout << this->m_fileName << " �ļ�ȱʧ" << std::endl;
		this->m_isOpen = false;
		return;
	}

	this->m_isOpen = true;/*�ļ��ɹ���*/
	int roomId, size;
	while (ifs >> roomId >> size) this->m_allRoom[roomId] = size;

	ifs.close();/*�ر��ļ�*/
}

/*�������ڵ���Ϣ���浽�ļ���*/
void ComputerRoomFile::saveMap() {
	std::ofstream ofs;
	ofs.open(this->m_fileName, std::ios::out | std::ios::trunc);/*��ɾ����д*/

	for (auto it = this->m_allRoom.begin(); it != this->m_allRoom.end(); it++) 
		ofs << it->first << " " << it->second << std::endl;
	
	ofs.close();
}

