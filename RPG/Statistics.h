#pragma once

public ref class Statistics
{
private:
	int _hp;
	int _mana;
	int _intelligence;
	int _agility;
	int _strength;
	int _toughness;
	int _wisdom;
	int _gold = 100;

public:
	property int HP {
		int get();
		private: void set(int hp);
	}

	property int Mana {
		int get();
		private: void set(int mana);
	}

	property int Intelligence {
		int get();
		private: void set(int intelligence);
	}

	property int Agility {
		int get();
		private: void set(int intelligence);
	}

	property int Strength {
		int get();
		private: void set(int intelligence);
	}

	property int Toughness {
		int get();
		private: void set(int intelligence);
	}

	property int Wisdom {
		int get();
		private: void set(int intelligence);
	}

	property int Gold {
		int get();
		private: void set(int intelligence);
	}


	void add(Statistics^ s);
	void substract(Statistics^ s);

private:

};