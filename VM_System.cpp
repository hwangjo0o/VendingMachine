#include "VM_System.h"

VM_System::VM_System() : money(0), price(500){
	for (int i = 0; i<max_water; i++){
		potable_water[i] = price;
		price += 100;
	}
}
int VM_System::get_money() const{
	return money;
}
int VM_System::get_choice() const{
	return choice;
}
void VM_System::system_menu() const{
	cout << "<����� ���Ǳ�>" << endl << endl;
	cout << "[0] Ade :      500 won";
	if (money < 500) cout << "(���� �Ұ���)" << endl;
	else cout << "(���� ����)" << endl;

	cout << "[1] Smoothie : 600 won ";
	if (money < 600) cout << "(���� �Ұ���)" << endl;
	else cout << "(���� ����)" << endl;

	cout << "[2] Yogurt :   700 won ";
	if (money < 700) cout << "(���� �Ұ���)" << endl;
	else cout << "(���� ����)" << endl;

	cout << "[3] �ܾ׹�ȯ (" << money << ") " << endl;
	cout << "[4] Quit" << endl;
}
void VM_System::system_print(){
	int temp_money;
	while (money < 500){
		if (money < 500) cout << "< 500�� �̻� ���� >" << endl;
		cout << "(�ܾ�" << money << ") �ݾ����� : "; cin >> temp_money;
		money += temp_money;
		system_menu();
		system("cls");
	}
	while (true){
		system_menu();
		cout << "Choice : "; cin >> choice;
		system("cls");
		if (choice < 0 || choice > 4) cout << "0~" << max_water + 1 << "�� �������ּ���, ���� �ܾ��� " << money << "�� �Դϴ�." << endl;
		else break;
	}
}
bool VM_System::set_buy(){
	if (get_choice() == max_water + 1){
		cout << "�����մϴ�" << endl;
		return false;
	}
	if (get_choice() == max_water){
		cout << "(" << money << ")" << "�ܾ��� ��ȯ�Ǿ����ϴ�." << endl;
		money = 0;
		return true;
	}
	if (money - potable_water[choice] < 0){
		cout << "�ݾ��� �����մϴ�." << endl;
		return true;
	}
	money -= potable_water[choice];
	system("cls");
	cout << choice << "�� ���� �����Ͽ����ϴ�, ���� �ܾ��� " <<money<< "�� �Դϴ�."<< endl;
	return true;
}