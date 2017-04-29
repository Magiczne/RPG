#include "stdafx.h"
#include "Statistics.h"

#pragma region Getters

int Statistics::HP::get() {
	return this->_hp;
}

int Statistics::Mana::get() {
	return this->_mana;
}

int Statistics::Intelligence::get() {
	return this->_intelligence;
}

int Statistics::Agility::get() {
	return this->_agility;
}

int Statistics::Strength::get() {
	return this->_agility;
}

int Statistics::Toughness::get() {
	return this->_agility;
}

int Statistics::Wisdom::get() {
	return this->_agility;
}

int Statistics::Gold::get() {
	return this->_agility;
}

#pragma endregion

#pragma region Setters

void Statistics::HP::set(int hp) {
	if (hp > 0 && hp <= Toughness * 5) {
		this->_hp = hp;
	}
}

void Statistics::Mana::set(int mana) {
	if (mana > 0 && mana <= this->Intelligence * 5) {
		this->_mana = mana;
	}
}

void Statistics::Intelligence::set(int intelligence) {
	if (intelligence >= 0) {
		this->_intelligence = intelligence;
	}
}

void Statistics::Agility::set(int agility) {
	if (agility >= 0) {
		this->_agility = agility;
	}
}

void Statistics::Strength::set(int strength) {
	if (strength >= 0) {
		this->_strength = strength;
	}
}

void Statistics::Toughness::set(int toughness) {
	if (toughness >= 0) {
		this->_toughness = toughness;
	}
}

void Statistics::Wisdom::set(int wisdom) {
	if (wisdom >= 0) {
		this->_wisdom = wisdom;
	}
}

void Statistics::Gold::set(int gold) {
	if (gold >= 0) {
		this->_gold = gold;
	}
}

#pragma endregion

void Statistics::add(Statistics^ s) {
	this->HP += s->HP;
	this->Mana += s->Mana;
	this->Intelligence += s->Intelligence;
	this->Agility += s->Agility;
	this->Strength += s->Strength;
	this->Toughness += s->Toughness;
	this->Wisdom += s->Wisdom;
	this->Gold += s->Gold;
}

void Statistics::substract(Statistics^ s) {
	this->HP -= s->HP;
	this->Mana -= s->Mana;
	this->Intelligence -= s->Intelligence;
	this->Agility -= s->Agility;
	this->Strength -= s->Strength;
	this->Toughness -= s->Toughness;
	this->Wisdom -= s->Wisdom;
	this->Gold -= s->Gold;
}
