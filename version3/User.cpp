#include"User.h"


/*չʾ����ԤԼ��¼*/
void User::showAllRsv() {
	ReservationFile rf(RESERVATION_FILE);

	if (rf.m_allResv.size() == 0) {
		std::cout << "��ǰԤԼ��¼Ϊ��" << std::endl;
		return;
	}

	int count = 0;
	std::cout << "��ǰ����ԤԼ��¼����" << std::endl;
	for (auto it = rf.m_allResv.begin(); it != rf.m_allResv.end(); it++) {
		/*�ļ�Ĭ�ϸ�ʽ �� �� �� ʱ�� ѧ��id ѧ������ ����� ԤԼ״̬ ��ʦid */
		std::cout << ++count << "��ʱ��: "
			<< it->m_date.year << '/' << it->m_date.month << '/' << it->m_date.day
			<< " ʱ��: " << (it->m_period == 1 ? "����" : "����")
			<< " ����: " << it->m_stuName
			<< "\t������: " << it->m_roomId
			<< " ԤԼ״̬: ";
		if (it->m_status == -1) std::cout << "ԤԼʧ��";
		else if (it->m_status == 0) std::cout << "��ȡ��";
		else if (it->m_status == 1) std::cout << "�����";
		else if (it->m_status == 2) std::cout << "ԤԼ�ɹ�";
		std::cout << "\t������:"
			<< (it->m_empId == "??" ? "����" : it->m_empId)
			<< std::endl;
	}
}