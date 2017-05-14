// SuperHero.cpp
// hasan.murtaza/submit 244_w7_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#include <iostream>
#include "Hero.h"//whatever I got the compilation guards ¯\_(ツ)_/¯
#include "SuperHero.h"


SuperHero::SuperHero() : Hero()
{
	m_superPowerAttack = 0;
	m_superPowerDefend = 0;
}

SuperHero::SuperHero(const char* name, unsigned maximumHealth, unsigned attack,
	unsigned superPowerAttack, unsigned superPowerDefend
) : Hero(name, maximumHealth, attack)
{		
	//safe state
	m_superPowerAttack = 0;
	m_superPowerDefend = 0;

	//checking if they are int
	//I assume that defence & attack can be 0
	if (superPowerAttack >= 0 && superPowerDefend >= 0) {
		m_superPowerAttack = superPowerAttack;
		m_superPowerDefend = superPowerDefend;
	}//if (superPowerAttack >= 0 && superPowerDefend >= 0)
}

unsigned SuperHero::getAttack() const
{
	return m_superPowerAttack;
}
