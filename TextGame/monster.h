#include <iostream>
#include <string>
using namespace std;

class Player;

class Monster
{
    int m_hp;
    int m_damage;
    string m_weapon;
public:
    Monster();
    void attack(Player& p);
    void receiveDamage(int damage);
    int getHp();

};