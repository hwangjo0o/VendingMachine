//  VM_System.hpp
#ifndef VM_System_hpp
#define VM_System_hpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#define max_water 3

using namespace std;
class VM_System{

private:
	int money;
	int price;
	int choice;
	int potable_water[max_water];

public:
	VM_System();
	int get_money() const;
	int get_choice() const;
	void system_menu() const;
	void system_print();
	bool set_buy();
};

#endif /* VM_System_hpp */
