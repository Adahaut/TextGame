#include "player.h"
#include "monster.h"


Player::Player()
{
    m_hp = 100;
    m_damage = 40;
    m_weapon = "wand";
}

void Player::attack(Monster& m)
{
    m.receiveDamage(m_damage);
}

void Player::receiveDamage(int damage)
{
    m_hp -= damage;
}

int Player::getHp()
{
    return m_hp;
}

void Player::heal()
{
    m_hp += 15;
}