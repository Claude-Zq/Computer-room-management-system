#include"Reservation.h"


Reservation::Reservation() {
	/*�����ԤԼ����ʦ��ְ���� û��ʱĬ��Ϊ "??"*/
	this->m_empId = "??";
}

bool Reservation::is_conflict(const Reservation& r) {
	if (this->m_period != r.m_period) return false;/*ʱ�β�ͬ*/
	if (this->m_roomId != r.m_roomId) return false;/*����Ų�ͬ*/
	if (this->m_date != r.m_date) return false;/*���ڲ�ͬ*/
	return false;
}