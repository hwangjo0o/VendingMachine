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
	cout << "<음료수 자판기>" << endl << endl;
	cout << "[0] Ade :      500 won";
	if (money < 500) cout << "(선택 불가능)" << endl;
	else cout << "(선택 가능)" << endl;

	cout << "[1] Smoothie : 600 won ";
	if (money < 600) cout << "(선택 불가능)" << endl;
	else cout << "(선택 가능)" << endl;

	cout << "[2] Yogurt :   700 won ";
	if (money < 700) cout << "(선택 불가능)" << endl;
	else cout << "(선택 가능)" << endl;

	cout << "[3] 잔액반환 (" << money << ") " << endl;
	cout << "[4] Quit" << endl;
}
void VM_System::system_print(){
	int temp_money;
	while (money < 500){
		if (money < 500) cout << "< 500원 이상 투입 >" << endl;
		cout << "(잔액" << money << ") 금액투입 : "; cin >> temp_money;
		money += temp_money;
		system_menu();
		system("cls");
	}
	while (true){
		system_menu();
		cout << "Choice : "; cin >> choice;
		system("cls");
		if (choice < 0 || choice > 4) cout << "0~" << max_water + 1 << "중 선택해주세요, 남은 잔액은 " << money << "원 입니다." << endl;
		else break;
	}
}
bool VM_System::set_buy(){
	if (get_choice() == max_water + 1){
		cout << "감사합니다" << endl;
		return false;
	}
	if (get_choice() == max_water){
		cout << "(" << money << ")" << "잔액이 반환되었습니다." << endl;
		money = 0;
		return true;
	}
	if (money - potable_water[choice] < 0){
		cout << "금액이 부족합니다." << endl;
		return true;
	}
	money -= potable_water[choice];
	system("cls");
	cout << choice << "번 음료 구매하였습니다, 남은 잔액은 " <<money<< "원 입니다."<< endl;
	return true;
}