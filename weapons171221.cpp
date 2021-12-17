//Баркун Екатерина
#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;
/*
class Color {
private:
	unsigned short int m_red;
	unsigned short int m_green;
	unsigned short int m_blue;
public:
	unsigned short int getRed() { return m_red; }
	unsigned short int getGreen() { return m_green; }
	unsigned short int getBlue() { return m_blue; }
	void setRed(unsigned short int red) { m_red = red; }
	void setGreen(unsigned short int green) { m_green = green; }
	void setBlue(unsigned short int blue) { m_blue = blue; }

	//конструкторы
	//Color() {
		//m_red = 0;
		//m_green = 0;
		//m_blue = 0;
	//}
	Color(unsigned short int red = 0,
		unsigned short int green = 0,
		unsigned short int blue = 0) :
		m_red{red},
		m_green{green},
		m_blue{blue}
	{   }
	
	void print() {
		cout << m_red << ' ' << m_green << ' ' << m_blue << endl;
	}
};
*/

//=======================WEAPON=====================
class Weapon {
protected:
	string m_name;
	int m_damage;
	double m_distance;
public:
	Weapon(string name = "", int damage = 0, double distance = 0.0) :
		m_name{name}, m_damage{damage}, m_distance{distance}
	{}
	void setName(string name) { m_name = name; }
	void setDamage(int damage) { m_damage = damage; }
	void setDistance(double distance) { m_distance = distance; }
	string getName(){return m_name;}
	int getDamage(){ return m_damage; }
	double getDistance(){ return m_distance; }
	void print() {
		cout << " Name " << m_name << " Damage " << m_damage << " Distance " << m_distance;
	}
};

//==============GRENADE==============
class Grenade : public Weapon {
private:
	double m_radius;
public:
	Grenade(string name = "", int damage = 0, double distance = 0.0, double radius = 0.0):
	 Weapon(name, damage, distance), m_radius{ radius }
	{}
	void setRadius(int radius) { m_radius = radius; }
	double getRadius() { return m_radius; }
	void print() {
		Weapon::print();
		cout << "Radius " << m_radius << endl;
	}
	void blow_up() {
		cout << "Grenade is blow up! :O" << endl;
	}
};

//=================PISTOL=================
class Pistol : public Weapon {
private:
	const int clip_count = 15;
	int m_ammo_count;
public:
	Pistol  (string name = "", int damage = 0, double distance = 0.0, int ammo_count = 0):
	Weapon(name, damage, distance), m_ammo_count{ammo_count}
	{}
	void setAmmo_count(int ammo_count) { m_ammo_count = ammo_count; }
	int getAmmo_count() { return m_ammo_count; }
	bool have_cartridges() { return m_ammo_count > 0; }
	void fire() {
		if (have_cartridges()) {
			cout << "Fire! >:)" << endl;
			m_ammo_count--;
		}
		else {
			cout << "No ammo :(" << endl;
		}
	}
	void reload() {
		m_ammo_count = clip_count;
	}
	void print() {
		Weapon::print();
		cout << " Ammo " << m_ammo_count << endl;
	}
};

//============MAIN==============
int main() {
	system("color 2");
	/*Color c1(12);
	c1.print();
	Color c2(11);
	c2.print();*/
	Grenade he_grenade1("F1", 100, 20, 200);
	he_grenade1.print();
	he_grenade1.blow_up();
	Pistol p1("Glock", 10, 50, 15);
	while (p1.have_cartridges()) {
		p1.fire();
	}
	p1.fire();
	p1.reload();
	p1.print();

	return 0;
}


