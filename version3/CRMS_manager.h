#pragma once
#include<iostream>


class CRMS_manager {

public:

	/*չʾ���˵�*/
	void showMenu();

	/*��¼ ѧ��:1 ��ʦ:2 ����Ա:3*/
	void login(int type);

	/*ѧ���û�����*/
	void stu_interface();

	/*��ʦ�û�����*/
	void tea_interface();

	/*����Ա�û�����*/
	void admin_interface();

};