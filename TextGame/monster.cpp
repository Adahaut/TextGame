#include "monster.h"
#include "player.h"
#include <iostream>
#include <string>

Monster::Monster()
{
    m_hp = 200;
    m_damage = 25;
    m_weapon = "claws";
}

void Monster:: receiveDamage(int damage)
{
    m_hp -= damage;
}

void Monster::attack(Player& p)
{
    p.receiveDamage(m_damage);
}

int Monster::getHp()
{
    return m_hp;
}