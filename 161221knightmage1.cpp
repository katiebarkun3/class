//Баркун Екатерина
#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
using namespace std;

//рыцарь
class Knight {
	//данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;
public:

	//setter, функции - сеттеры (заменяют присваивание)
	void set_hp(double hp) { m_hp = hp; }
	void set_damage(double damage) { m_damage = damage; }
	void set_name(string name) { m_name = name; }

	//вместо всех сеттеров можно написать один конструктор
	/*Knight(string name, double hp, double damage) {
		m_hp = hp;
		m_damage = damage;
		m_name = name;
	}*/

	//getter / геттер
	double get_hp() { return m_hp; }
	double get_damage() { return m_damage; }
	string get_name() { return m_name; }

	//увеличение дамага
	void increase_damage() {
		m_damage += 5;
	}

	void print() {
		cout << "Knight name " << m_name << endl;
		cout << "Knight hp " << m_hp << endl;
		cout << "Knight damage " << m_damage << endl;
	}

	//регенерация хп 20
	void reg_hp(double reg) {
		m_hp += reg;
	}
};

//маг
class Mage {
	//данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;

	//методы класса (функции, определяющие поведение объекта)
public:

	//setter, функции - сеттеры (заменяют присваивание)
	void set_hp(double hp) { m_hp = hp; }
	void set_damage(double damage) { m_damage = damage; }
	void set_name(string name) { m_name = name; }

	//getter / геттер
	double get_hp() { return m_hp; }
	double get_damage() { return m_damage; }
	string get_name() { return m_name; }

	//увеличение дамага
	void increase_hp(double add_hp) {
		m_hp += add_hp;
	}

	//уменьшение дамага
	void decrease_attack(double dec_attack) {
		m_damage -= dec_attack;
	}

	void print() {
		cout << "Mage name " << m_name << endl;
		cout << "Mage hp " << m_hp << endl;
		cout << "Mage damage " << m_damage << endl;
	}
};



int main() {
	//создали рыцаря
	Knight k1;//("Valera", 100, 20)
	//записали в него данные
	string name123;
	system("color 6");
	cout << "???: Hello! What is your name, fearless knight? :D" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cin >> name123;
	k1.set_name(name123);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "??? :" << name123 << "... Such a gorgeous name!" << endl;
	cout << "???: I am Nicholas! Nice to meet you" << endl;
	cout << "Nicholas: Let's start our game!" << endl;
	cout << "Remember that by default each attack the knight(You;)) adds + 5 to the attack and the mage regenerates + 20 hp!" << endl;
	cout << "Good luck;)" << endl;
	cout << "Mage Travis: Oh... another pathetic knight ..." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	k1.set_hp(100);
	k1.set_damage(20);
	k1.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	//создали мага
	Mage m1;
	//записали в него данные
	m1.set_name("Travis");
	m1.set_hp(50);
	m1.set_damage(20);
	m1.print();

	//основной игровой цикл
	while (true) {
		//ход рыцаря, он бьёт мага
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Nicholas: Knight hit mage" << endl;
		//он бьёт мага
		m1.set_hp(m1.get_hp() - k1.get_damage());
		//распечатывем мага
		m1.print();
		//проверяем на смерть
		if (m1.get_hp() <= 0) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Nicholas: You win! Good game! :)" << endl;
			cout << "Mage Travis: NOOOO! o_o I.. I was sure that I would definitely win.. It can't be... CAN'T.. BEEee.." << endl;
			cout << "Nicholas:" << name123 << ", you're doing fine!!" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Nicholas: Brave knight, what is your choice? :)" << endl;
		cout << "Press 1 to increase damage +5" << endl;
		cout << "Press 2 to decrease mage attack -5" << endl;
		cout << "Press 3 to regenerate hp +20" << endl;
		cout << "Press 4 to do nothing... :O" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		int choice;
		cin >> choice;
		switch (choice) {

		case 1:k1.increase_damage();
			break;

		case 2:
			if (m1.get_damage() > 0) {
				m1.decrease_attack(5);
			}
			else {
				cout << "Nicholas: You can no longer reduce the mage's attack. It is equal to 0" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Nicholas: Brave knight, what is your choice? :)" << endl;
				cout << "Press 1 to increase damage +5" << endl;
				cout << "Press 3 to regenerate hp +20" << endl;
				cout << "Press 4 to do nothing... :O" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				int choice;
				cin >> choice;
				switch (choice) {

				case 1:k1.increase_damage();
					break;

				case 3:k1.reg_hp(20);
					break;

				case 4:k1.reg_hp(0);
					break;
				}
				cout << "Nicholas: " << name123 << ", It's a brilliant choice! ;)" << endl;
				break;

		case 3:k1.reg_hp(20);
			break;

		case 4:k1.reg_hp(0);
			break;
			}
			cout << "Nicholas: " << name123 << ", It's a brilliant choice! ;)" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			//задержка на 3000 мс
			Sleep(3000);
			// ход мага
			cout << "Nicholas: Mage hit knight" << endl;
			k1.set_hp(k1.get_hp() - m1.get_damage());
			//
			k1.print();
			if (k1.get_hp() <= 0) {
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Nicholas: Oh no! You lose.. ;(" << endl;
				cout << "Mage Travis: YAHOOOOOOO I WIN!!! >:)" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				break;
			}
			m1.increase_hp(20);
			Sleep(3000);
		}
	}
	return 0;
}