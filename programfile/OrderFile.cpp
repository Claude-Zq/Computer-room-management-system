#include"OrderFile.h"


OrderFile::OrderFile() {
	std::ifstream ifs;
	ifs.open(ORDER_FILE, std::ios::in);
	m_size = 0;

	int ch;
	while ((ch = ifs.get())!=EOF) {
		ifs.putback(ch);/*把字符放回去*/
		std::string temp, key, value;
		int pos;
		std::map<std::string, std::string> m;
		for (int i = 0; i < NUM_OF_DATA_ONE_LINE ; i++) {
			ifs >> temp;
			pos = temp.find(':');
			if (pos == std::string::npos) std::cout << "orderFile.cpp文件格式出错" << std::endl;
			else {
				key = temp.substr(0, pos);
				value = temp.substr(pos + 1, temp.size() - pos-1);
				m[key] = value;
			}
		}
		ifs.get();/*吃掉行末回车*/

		m_orderData[m_size] = m;
		m_size++;
	}

	          /*日期、时间段、学生编号、学生姓名、机房编号、预约状态*/
	/*std::string date, interval, stuId, stuName, roomId, status;

	while (ifs >> date >> interval >> stuId >> stuName >> roomId >> status) {
		std::string key, value;
		int pos;
		std::map<std::string, std::string> m;

		pos = date.find(':');
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos-1);
			m[key] = value;
		}
		else std::cout << "orderFile.cpp文件格式出错" << std::endl;

		pos = interval.find(':');
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m[key] = value;
		}
		else std::cout << "orderFile.cpp文件格式出错" << std::endl;

		pos = stuId.find(':');
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, interval.size() - pos);
			m[key] = value;
		}
		else std::cout << "orderFile.cpp文件格式出错" << std::endl;

		pos = roomId.find(':');
		if (pos != -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos);
			m[key] = value;
		}
		else std::cout << "orderFile.cpp文件格式出错" << std::endl;

		pos = status.find(':');
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos);
			m[key] = value;
		}
		else std::cout << "orderFile.cpp文件格式出错" << std::endl;

		m_orderData[this->m_size] = m;
		this->m_size++;
	}*/

}


void OrderFile::updateOrder(){

	if (this->m_size == 0) return;
	std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);/*先删除，再写*/
	for (int i = 0; i < m_size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " "
			<< "interval:" << this->m_orderData[i]["interval"] << " "
			<< "stuId:" << this->m_orderData[i]["stuId"] << " "
			<< "roomId:" << this->m_orderData[i]["roomId"] << " "
			<< "status:" << this->m_orderData[i]["status"] << std::endl;
	}
	ofs.close();
}