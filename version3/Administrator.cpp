#include"Administrator.h"

//�вι���(�˺š�����������)
Administrator::Administrator(std::string id, std::string name, std::string pwd) {
	this->m_account.m_id = id;
	this->m_account.m_name = name;
	this->m_account.m_pwd = pwd;

}

Administrator::Administrator(const Account& a) {
	this->m_account = a;
}


/*չʾ�˵�*/
void Administrator::showMenu() {
	std::cout << "\t\t\t\t\t��ӭ����Ա [" << this->m_account.m_name << "] ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              1.����˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              2.�鿴�˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              3.ɾ���˺�              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              4.�޸�����              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              5.��ӻ���              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              6.�鿴����              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              7.�޸Ļ���              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              8.���ԤԼ              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|              0.ע����¼              |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

//ɾ���˺�
void Administrator::deleteAccount() {

	std::cout << "������ɾ���˺ŵ�����" << std::endl;
	std::cout << "1.���ѧ��" << std::endl;
	std::cout << "2.�����ʦ" << std::endl;
	std::cout << "3.��ӹ���Ա" << std::endl;


	int select;
	do {
		std::cout << "��������ѡ��: " << std::endl;
		if (std::cin >> select) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);


	std::string fileName, tip;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
	}
	else if (select == 3) {
		fileName = ADMIN_FILE;
		tip = "������ְ�����:";
	}
	else {
		std::cout << "�޸�ѡ��" << std::endl;
		system("pause");
		system("cls");
		return;
	}


	std::string id;
	AccountFile af(fileName);


	std::cout << tip << std::endl;
	std::cin >> id;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (af.deleteAccount(id)) std::cout << "ɾ���ɹ�" << std::endl;
	else std::cout << "ɾ��ʧ��,�˺Ų�����" << std::endl;

	system("pause");
	system("cls");

}

//����˺�
void Administrator::addAccount() {
	std::cout << "����������˺ŵ�����" << std::endl;
	std::cout << "1.���ѧ��" << std::endl;
	std::cout << "2.�����ʦ" << std::endl;
	std::cout << "3.��ӹ���Ա" << std::endl;


	int select;
	do {
		std::cout << "��������ѡ��: " << std::endl;
		if (std::cin >> select) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);


	std::string fileName, tip;
	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
	}
	else if (select == 2) {
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
	}
	else if (select == 3) {
		fileName = ADMIN_FILE;
		tip = "������ְ�����:";
	}
	else {
		std::cout << "�޸�ѡ��" << std::endl;
		system("pause");
		system("cls");
		return;
	}


	Account a;
	AccountFile af(fileName);


	std::cout << tip << std::endl;
	std::cin >> a.m_id;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	std::cout << "����������:" << std::endl;
	std::cin >> a.m_name;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "����������:" << std::endl;
	std::cin >> a.m_pwd;
	std::cin.clear();/*������뻺����*/
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (af.addAccount(a)) std::cout << "��ӳɹ�" << std::endl;
	else std::cout << "�˺��ظ�,���ʧ��" << std::endl;

	system("pause");
	system("cls");
}

//��ӻ���
void Administrator::addComputerRoom() {
	ComputerRoomFile crf(COMPUTER_FILE);
	if (!crf.m_isOpen) {
		std::cout << "�ļ�" << COMPUTER_FILE << "ȱʧ" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	int roomId, size;
	do {
		std::cout << "�����������:" << std::endl;
		if (std::cin >> roomId) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (crf.m_allRoom.count(roomId) == 1) {
		std::cout << "�û������Ѵ���" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	do {
		std::cout << "����������:" << std::endl;
		if (std::cin >> size && size > 0) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	crf.m_allRoom[roomId] = size;
	std::cout << "��ӳɹ�" << std::endl;
	system("pause");
	system("cls");

}

//�鿴������Ϣ
void Administrator::showComputerRoom() {
	ComputerRoomFile crf(COMPUTER_FILE);
	if (!crf.m_isOpen) {
		std::cout << "�ļ�" << COMPUTER_FILE << "��ʧ��" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	if (crf.m_allRoom.size() == 0) std::cout << "��ǰ��¼Ϊ��" << std::endl;
	else {
		std::cout << "ȫ��������Ϣ����:" << std::endl
			<< " ������\t����" << std::endl;
		for (auto it = crf.m_allRoom.begin(); it != crf.m_allRoom.end(); it++)
			std::cout << " " << it->first << '\t' << it->second << std::endl;
	}
	system("pause");
	system("cls");
	return;
}

//�޸Ļ�����Ϣ
void Administrator::modifyComputerRoom() {
	ComputerRoomFile crf(COMPUTER_FILE);
	if (!crf.m_isOpen) {
		std::cout << "�ļ�" << COMPUTER_FILE << "ȱʧ" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	int roomId, size;
	do {
		std::cout << "�����������:" << std::endl;
		if (std::cin >> roomId) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (crf.m_allRoom.count(roomId) == 0) {
		std::cout << "�û����Ų�����" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	do {
		std::cout << "����������:" << std::endl;
		if (std::cin >> size && size > 0) break; /*����Ϸ��Լ��*/
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	crf.m_allRoom[roomId] = size;
	std::cout << "�޸ĳɹ�" << std::endl;
	system("pause");
	system("cls");
}

/*�޸���������*/
void Administrator::changePwd() {
	AccountFile af(ADMIN_FILE);

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

//�鿴�˺�
void Administrator::showAccount() {
	std::cout << "---------------------------------" << std::endl;
	std::cout << "|\t 1.�鿴����ѧ��\t\t|" << std::endl;
	std::cout << "|\t 2.�鿴������ʦ\t\t|" << std::endl;
	std::cout << "---------------------------------" << std::endl;

	int select = 0;
	do {
		std::cout << "����������ѡ��:" << std::endl;
		if (std::cin >> select) break;
		std::cout << "������������������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (true);

	if (select == 1) {

		AccountFile sf(STUDENT_FILE);

		if (sf.m_allAccount.empty()) std::cout << "��ѧ���˺ż�¼" << std::endl;
		else {
			std::cout << "ѧ��\t����\t����" << std::endl;
			std::cout << "ѧ��\t����\t����" << std::endl;
			for (auto it = sf.m_allAccount.begin(); it != sf.m_allAccount.end(); it++) {
				std::cout << it->second.m_id
					<< '\t' << it->second.m_name << '\t'
					<< it->second.m_pwd << std::endl;
			}
		}

	}
	else if (select == 2) {
		AccountFile tf(TEACHER_FILE);

		if (tf.m_allAccount.empty()) std::cout << "����ʦ�˺ż�¼" << std::endl;
		else {
			std::cout << "ְ����\t����\t����" << std::endl;
			std::cout << "ְ����\t����\t����" << std::endl;
			for (auto it = tf.m_allAccount.begin(); it != tf.m_allAccount.end(); it++) {
				std::cout << it->second.m_id
					<< '\t' << it->second.m_name
					<< '\t' << it->second.m_pwd << std::endl;
			}
		}
	}
	else {
		std::cout << "�޸�ѡ��!" << std::endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Administrator::clearRsv() {
	ReservationFile rf(RESERVATION_FILE);
	rf.m_allResv.clear();
}