// Hero.cpp
// hasan.murtaza/submit 244_w7_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <cstring>
#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
#include <cstring>

using namespace std;

//////////////////////////////////////////////
// Default constructor
//
Hero::Hero()
{
	//going default
	m_name[0] = '\0';
	m_attack = 0;
	m_maximumHealth = 0;
	m_health = 0;
}

///////////////////////////////////////////////////
// Constructor
// 
Hero::Hero(const char name[], unsigned maximumHealth, unsigned attack)
{
	//safe state
	m_name[0] = '\0';
	m_attack = 0;
	m_maximumHealth = 0;
	m_health = 0;

	//validation
	//*a hero can't have a name
	//*attack can't be negative
	if (name != nullptr && name[0] != 0 && maximumHealth >= 0 && attack >= 0) {
		std::strcpy(m_name, name);
		m_attack = attack;
		m_health = maximumHealth;
		m_maximumHealth = maximumHealth;//for respawn

	}
}



/////////////////////////////////////////////////////////
// 
// Hero::display function
void Hero::display(ostream & out) const
{
	if (isEmpty()) {
		//does nothing
	}
	else {
		//outputs the name of a hero
		out << m_name;
	}
}



/////////////////////////////////////////////////
// Hero::isEmpty ()
// return true if the Hero object is uninitialized
//
bool Hero::isEmpty() const
{
	bool empty;
	//check for the safe state 
	if (m_name[0] == '\0' && m_maximumHealth == 0 &&
		m_attack == 0 && m_health == 0) {
		empty = true;
	}
	else {
		empty = false;
	}//if (m_name[0] == '\0' && m_maximumHealth == 0 && m_attack == 0 && m_health == 0)
	return empty;
}

/////////////////////////////////////////////////
// sets the Hero object's health back to full
//
void Hero::respawn()
{
	//restores hp 
	m_health = m_maximumHealth;
}

//void apply_damage(Hero& A, Hero& B) in fight.cpp