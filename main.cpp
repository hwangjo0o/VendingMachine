#include "VM_System.h"

int main(){
	char quit;
	VM_System VM;

	while (true){
		VM.system_print();
		VM.set_buy();
		if (VM.get_choice() == 4) break;
	}
	cout << "q �Է½� ����˴ϴ� : "; cin >> quit;
	return 0;
}