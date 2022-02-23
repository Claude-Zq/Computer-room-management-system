#include"Teacher.h"


/*���캯��*/
Teacher::Teacher(std::string id, std::string name, std::string pwd) {
	this->m_account.m_id = id;
	this->m_account.m_name = name;
	this->m_account.m_pwd = pwd;
}

/*չʾ�˵�*/
void Teacher::showMenu() {
	std::cout << "\t\t\t\t\t  ��ӭ [" <<this->m_account.m_name << "] ��ʦ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.�鿴����ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.���ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             3.�޸�����               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.ע����¼               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

/*�޸���������*/
void Teacher::changePwd() {
	AccountFile af(TEACHER_FILE);

	std::string newPwd1, newPwd2;
	std::cout << "������������" << std::endl;
	std::cin >> newPwd1;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "���ٴ�������" << std::endl;
	std::cin >> newPwd2;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (newPwd1 != newPwd2) std::cout << "�޸�ʧ��,������������벻ͬ" << std::endl;
	else {
		af.modifyPwd(this->m_account.m_id, newPwd1);
		std::cout << "�޸ĳɹ�" << std::endl;
	}
	system("pause");
	system("cls");

}

/*���ԤԼ*/
void Teacher::auditRsv() {
	ReservationFile rsf(RESERVATION_FILE);

	std::vector<int> v;/*��¼����ȡ����ԤԼ��rsf.m_allResv������*/
	for (int i = 0; i < rsf.m_allResv.size(); i++) {
		/*ԤԼ״̬Ϊ�����*/
		if (rsf.m_allResv[i].m_status == 1) {
			if (v.size() == 0)  std::cout << "����˵�ԤԼ����:" << std::endl;
			std::cout << v.size() + 1 << "��ʱ��: " << rsf.m_allResv[i].m_date
				<< " ʱ��: " << (rsf.m_allResv[i].m_period == 1 ? "����" : "����")
				<< " ����: " << rsf.m_allResv[i].m_stuName
				<< "\t������: " << rsf.m_allResv[i].m_roomId << std::endl;
		}
	}

	if (v.size() == 0) std::cout << "����˵�ԤԼ" << std::endl;
	else {
		std::cout << "\n��������˵�ԤԼ���(�����밴0)" << std::endl;
		int select = 0;
		do {
			if (std::cin >> select && (select >= 0 && select <= v.size()))break;
			std::cout << "��������,����������" << std::endl;
			std::cin.clear();/*������뻺����*/
			std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
		} while (true);

		if (select == 0) {/*�����Ӳ˵�*/
			std::cout << "�ѷ���" << std::endl;
		}
		else {
			std::cout << "��ѡ��:\n1.ͬ��\n0.��ͬ��" << std::endl;
			int selection;
			do {
				if (std::cin >> selection && (selection == 1 || selection == 0))break;
				std::cout << "��������,����������" << std::endl;
				std::cin.clear();/*������뻺����*/
				std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
			} while (true);

			if (selection == 0) {
				rsf.m_allResv[v[select - 1]].m_status = -1;/*����׼*/
				std::cout << "�Ѿܾ�" << std::endl;
			}
			else {
				rsf.m_allResv[v[select - 1]].m_status = 2;/*��׼*/
				std::cout << "��ͬ��" << std::endl;
			}
		}
	}
	system("pause");
	system("cls");
}