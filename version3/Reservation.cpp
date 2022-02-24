#include"Reservation.h"


Reservation::Reservation() {
	/*处理该预约的老师的职工号 没有时默认为 "??"*/
	this->m_empId = "??";
}

bool Reservation::is_conflict(const Reservation& r) {
	if (this->m_period != r.m_period) return false;/*时段不同*/
	if (this->m_roomId != r.m_roomId) return false;/*房间号不同*/
	if (this->m_date != r.m_date) return false;/*日期不同*/
	return false;
}