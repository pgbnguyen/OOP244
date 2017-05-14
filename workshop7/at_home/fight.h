// fight.h
// hasan.murtaza/submit 244_w7_home
// Anton Elistratov
// Seneca@York
// Email: eanton@myseneca.ca
// Program: CPA
#ifndef FIGHT_H
#define FIGHT_H

//hero class
const Hero & operator* (const Hero & a, const Hero & b);
void apply_damage(Hero& A, Hero& B);

//super hero class
const SuperHero & operator* (const SuperHero & a, const SuperHero & b);
void apply_damage(SuperHero& A, SuperHero& B);
#endif