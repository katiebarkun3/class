//Баркун Екатерина
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
class Fruit {
protected:
	string m_name;
	string m_color;
public:
	Fruit(string name, string color) :
		m_name{ name }, m_color{ color }
	{}
	void setName(string name) { m_name = name; }
	void setColor(string color) { m_color = color; }
	string getName() { return m_name; }
	string getColor() { return m_color; }
	void print() {
		cout << " My " << m_name << " is " << m_color << "." << endl;
	}
};
	class Banana : public Fruit {
	public:
		Banana(string name = "banana", string color = "yellow") :
			Fruit(name, color)
		{}
		void print() {
			Fruit::print();
		}
	};
	class Apple : public Fruit {
	public:
		Apple(string color, string name = "apple") :
			Fruit(name, color)
		{}
		void print() {
			Fruit::print();
		}
	};
	class GrannySmith : public Apple {
	public:
		GrannySmith(string name = "Granny Smith apple", string color = "green") :
			Apple(color, name)
		{}
		void print() {
			cout << " My " << m_name << " is " << m_color << '.' << endl;
		}
	};
	//============MAIN==============
	int main() {
		system("color 9");
		Apple a("red");
		a.print();
		Banana b;
		b.print();
		GrannySmith c;
		c.print();
		return 0;
	}
