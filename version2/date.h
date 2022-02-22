#pragma once
#include<cstdio>


/*�ж��Ƿ�������*/
bool is_leap(int year);

class date {


public:

	date(int Year = 0, int Month = 1, int Day = 1);
	bool operator<(const date& d);
	bool operator>(const date& d);
	bool operator==(const date& d);
	bool operator!=(const date& d);
	date& operator=(const date& d);

	/*����һ�����ڼ���n(n>=0)�����ʲô����*/
	date operator+(int n);
	/*����n(n>=0)��*/
	date& operator+=(int n);

	/*����һ�����ڼ�ȥn(n>=0)�����ʲô����*/
	date operator-(int n);
	/*����n(n>=0)��*/
	date& operator-=(int n);

	/*ǰ�õ�������*/
	date& operator++();
	/*���õ�������*/
	date operator++(int);

	/*ǰ�õݼ������*/
	date& operator--();

	/*���õݼ������*/
	date operator--(int);

	/*��������date*/
	void swap(date& d);

	/*���������·ݵ�������*/
	int getDays();
	/*���ظ����ܼ�(����:0 ��һ:1....)*/
	int getWeek();
	/*���������ڵĲ�,������������������ģ��涨���1��*/
	int operator-(const date& d);

	/*�����ںϷ��Լ��*/
	bool is_legal() {
		bool legal = true;
		if (month < 1 || month >12) legal = false; /*�ж��·�*/
		else { /*�ж���*/
			if (day <= 0) legal = false;
			else {
				if (month != 2) legal = (day <= DAYS[month - 1] ? true : false);
				else legal = (day <= (is_leap(year) ? 29 : 28) ? true : false);
			}
		}
		return legal;
	}

	int year, month, day;
private:
	/*���µ�������*/
	const int DAYS[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
};
