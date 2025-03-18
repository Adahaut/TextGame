#include <string>
#include <iostream>
using namespace std;

class Monster;

class Player
{
    int m_hp;
    int m_damage;
    string m_weapon;
public:
    Player();
    void attack(Monster& m);
    void receiveDamage(int damage);
    int getHp();
    void heal();
};