#include"ComputerRoomFile.h"



/*构造函数*/
ComputerRoomFile::ComputerRoomFile(std::string fileName) {
	this->m_fileName = fileName;
	initMap();
}

/*析构函数*/
ComputerRoomFile::~ComputerRoomFile() {
	saveMap();
}


/*初始化容器*/
void ComputerRoomFile::initMap() {
	this->m_allRoom.clear();

	std::ifstream ifs;/*打开文件*/
	ifs.open(this->m_fileName, std::ios::in);

	if (!ifs.is_open()) {
		std::cout << this->m_fileName << " 文件缺失" << std::endl;
		this->m_isOpen = false;
		return;
	}

	this->m_isOpen = true;/*文件成功打开*/
	int roomId, size;
	while (ifs >> roomId >> size) this->m_allRoom[roomId] = size;

	ifs.close();/*关闭文件*/
}

/*将容器内的信息保存到文件中*/
void ComputerRoomFile::saveMap() {
	std::ofstream ofs;
	ofs.open(this->m_fileName, std::ios::out | std::ios::trunc);/*先删掉后写*/

	for (auto it = this->m_allRoom.begin(); it != this->m_allRoom.end(); it++) 
		ofs << it->first << " " << it->second << std::endl;
	
	ofs.close();
}

