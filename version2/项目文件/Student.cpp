#include"Student.h"




Student::Student(std::string id, std::string name, std::string pwd) {
	this->m_account.m_name = name;
	this->m_account.m_id = id;
	this->m_account.m_pwd = pwd;
}

Student::Student(const Account& a) {
	this->m_account = a;
}

void Student::showMenu() {
	std::cout << "\t\t\t\t\t  ��ӭ [" << this->m_account.m_name << "] ͬѧ��¼" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             1.����ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             2.�鿴�ҵ�ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             3.�鿴����ԤԼ           |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             4.ȡ��ԤԼ               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             5.�޸�����               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t|             0.ע����¼               |" << std::endl;
	std::cout << "\t\t\t\t|                                      |" << std::endl;
	std::cout << "\t\t\t\t----------------------------------------" << std::endl;
}

void Student::changePwd() {
	AccountFile af(STUDENT_FILE);

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
		if (newPwd1 == this->m_account.m_pwd) {
			std::cout << "�����벻�����������ͬ!" << std::endl;
		}
		else {
			af.modifyPwd(this->m_account.m_id, newPwd1);/*�ļ��и���*/
			this->m_account.m_pwd = newPwd1;/*�����и���*/
			std::cout << "�޸ĳɹ�" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::applyRsv() {

	Reservation r;

	std::cout << "������ԤԼ��ʱ��(��ʽ: YYYY MM DD ):" << std::endl
		<< "ע��:����һ������ԤԼ" << std::endl;
	do {
		if (std::cin >> r.m_date.year >> r.m_date.month >> r.m_date.day) {
			if (!r.m_date.is_legal()) std::cout << "��������ڲ��Ϸ�" << std::endl;
			else {
				int week = r.m_date.getWeek();
				if (week != 0 && week != 6) break;
				else std::cout << "��ĩ�ڼ䲻��ԤԼ,����������" << std::endl;
			}
		}
		else std::cout << "��������,����������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);


	/*����ʱ���*/
	std::cout << "��������ʱ���" << std::endl;
	std::cout << "  1.����" << std::endl;
	std::cout << "  2.����\n" << std::endl;

	do {
		std::cout << "������ԤԼ��ʱ���" << std::endl;
		if (std::cin >> r.m_period && (r.m_period == 1 || r.m_period == 2))break;
		std::cout << "��������,����������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	/*���������*/
	std::cout << "������Ϣ" << std::endl;
	std::cout << " ����\t����" << std::endl;
	ComputerRoomFile crf(COMPUTER_FILE);
	for (auto it = crf.m_allRoom.begin(); it != crf.m_allRoom.end(); it++) {
		std::cout << " " << it->first << '\t' << it->second << std::endl;
	}

	do {
		std::cout << "��ѡ�����" << std::endl;
		if (std::cin >> r.m_roomId) {
			if (crf.m_allRoom.count(r.m_roomId) == 1) break;
			else std::cout << "�޶�Ӧ�Ļ�����";
		}
		else std::cout << "��������";
		std::cout << ",����������" << std::endl;
		std::cin.clear();/*������뻺����*/
		std::cin.ignore(std::streamsize(std::numeric_limits<std::streamsize>::max()), '\n');
	} while (true);

	r.m_status = 1;
	r.m_stuId = this->m_account.m_id;
	r.m_stuName = this->m_account.m_name;

	ReservationFile rsf(RESERVATION_FILE);
	
	bool flag = 1;
	for (int i = 0; i < rsf.m_allResv.size(); i++) {
		if (rsf.m_allResv[i].is_conflict(r) && rsf.m_allResv[i].m_status == 2) {
			std::cout << "�û����ѱ�ԤԼ" << std::endl;
			flag = 0;
			break;
		}
	}
	if (flag) {
		rsf.m_allResv.push_back(r);
		std::cout << "ԤԼ�ɹ�,�����" << std::endl;
	}
	system("pause");
	system("cls");
}

void Student::showMyRsv() {
	bool empty = true;
	ReservationFile rsf(RESERVATION_FILE);

	for (auto it = rsf.m_allResv.begin(); it != rsf.m_allResv.end(); it++) {
		if (it->m_stuId == this->m_account.m_id) {
			if (empty) {
				std::cout << "����ԤԼ��¼����:" << std::endl;
				empty = false;
			}
			std::cout << "ԤԼʱ��: "
				<< it->m_date.year << '/' << it->m_date.month << '/' << it->m_date.day
				<< "  ʱ��: " << (it->m_period == 1 ? "����" : "����")
				<< "  ����: " << it->m_roomId << "  ״̬: ";

			//0 ȡ��ԤԼ 1 ����� 2 ��ԤԼ -1ԤԼʧ��
			if (it->m_status == 1) std::cout << "�����" << std::endl;
			else if (it->m_status == 2) std::cout << "��ԤԼ" << std::endl;
			else if (it->m_status == -1) std::cout << "ԤԼʧ��" << std::endl;
			else if (it->m_status == 0) std::cout << "��ȡ��" << std::endl;
		}
	}

	if (empty) std::cout << "����ԤԼ��¼Ϊ��" << std::endl;

	system("pause");
	system("cls");
}

void Student::cancelRsv() {

	ReservationFile rsf(RESERVATION_FILE);

	std::vector<int> v;/*��¼����ȡ����ԤԼ��rsf.m_allResv������*/
	for (int i = 0, j = 0; i < rsf.m_allResv.size(); i++) {
		if (rsf.m_allResv[i].m_stuId == this->m_account.m_id) {
			if (rsf.m_allResv[i].m_status == 1 || rsf.m_allResv[i].m_status == 2) {/*ԤԼ״̬*/
				if (v.size() == 0) std::cout << "����ǰԤԼ��¼ԤԼ����:(������ʾ��ȡ����ԤԼ)" << std::endl;
				v.push_back(i);
				std::cout << ++j << ". "
					<< "ԤԼ����: "
					<< rsf.m_allResv[i].m_date.year << '/'
					<< rsf.m_allResv[i].m_date.month << '/'
					<< rsf.m_allResv[i].m_date.year
					<< " ʱ��: " << (rsf.m_allResv[i].m_period == 1 ? "����" : "����")
					<< " ����: " << (rsf.m_allResv[i].m_roomId)
					<< " ״̬: " << (rsf.m_allResv[i].m_status == 1 ? "�����" : "��ԤԼ") << std::endl;
			}
		}
	}

	if (v.size() == 0) std::cout << "��ԤԼ��¼" << std::endl;
	else {
		std::cout << "\n������ȡ����ԤԼ���(�����밴0)" << std::endl;
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
			rsf.m_allResv[v[select - 1]].m_status = 0;
			std::cout << "ȡ��ԤԼ�ɹ�" << std::endl;
		}
	}

	system("pause");
	system("cls");
}
