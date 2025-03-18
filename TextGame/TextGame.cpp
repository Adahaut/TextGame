#include <iostream>
#include <string>
#include "monster.h"
#include "player.h"
using namespace std;

class Room
{
public:
    virtual ~Room() {}
    virtual Room* DoThing(const string& Playername, Player& p) = 0;
};


class DiningHall
    : public Room
{
    Room* m_mainHall;

public:
    DiningHall(Room* mainHall)
        : m_mainHall(mainHall)
    {}

    Room* DoThing(const string& Playername, Player& p) override
    {
        cout << Playername << " you're in the diningroom, what you wanna do ?" << endl;
        cout << "1: Eat" << endl;
        cout << "2: Back" << endl;

        int i;
        cin >> i;

        if (i == 1)
        {
            system("cls");
            return this;
        }

        if (i == 2)
        {
            system("cls");
            return m_mainHall;
        }

        return nullptr;
    }
};

class BathRoom
    :public Room
{
    Room* m_mainHall;

public:
    BathRoom(Room* mainHall) :
        m_mainHall(mainHall)
    {
    }

    Room* DoThing(const string& Playername, Player& p) override
    {
        cout << Playername << " you're in the bathroom, what you wanna do ?" << endl;
        cout << "1: Take a shower" << endl;
        cout << "2: Take a bath" << endl;
        cout << "3: Back" << endl;

        int i;
        cin >> i;

        if (i == 1)
        {
            system("cls");
            return this;
        }

        if (i == 2)
        {
            system("cls");
            return this;
        }

        if (i == 3)
        {
            system("cls");
            return m_mainHall;
        }

        return nullptr;
    }

};


class Garage
    :public Room
{
    Room* m_mainHall;

public:
    Garage(Room* mainHall) :
        m_mainHall(mainHall)
    {}

    Room* DoThing(const string& Playername, Player& p) override
    {
        Monster m;
        int a;

        cout << Playername << " There's a monster here !!!" << endl;
        cout << "You have to fight him !" << endl;
        cout << "Enter 1 to continue" << endl;
        cin >> a;

        while (m.getHp() > 0 && p.getHp() > 0)
        {
            system("cls");
            cout << "Your wand make 40 damage" << endl;
            cout << "The claws's monster make 25 damage" << endl;
            cout << "You have " << p.getHp() << " hp" << endl;
            cout << "The monster has " << m.getHp() << " hp" << endl;
            int choice;
            cout << "1)Heal yourself                2)Attack monster" << endl;
            cin >> choice;
            if (choice == 1) 
            {
                p.heal();
            }
            else if (choice == 2)
            {
                p.attack(m);
                m.attack(p);
            }
            else 
            {
                return this;
            }
            }
        if (m.getHp() <= 0)
        {
        cout << "You've killed the monster ! Congratulation !!!!!" << endl;
        cout << "Enter 1 to continue :" << endl;
        cin >> a;

        }
        else if (p.getHp() <= 0)
        {
            cout << "You lose..." << endl;
            cout << "Enter 1 to restart :" << endl;
            cin >> a;
        }

        if (a == 1) 
        {
            system("cls");
            return m_mainHall;
        }

        else 
        {
            return nullptr;
        }

    }
};

class SecretRoom
    :public Room
{
    Room* m_Pool;

public:
    SecretRoom(Room* Pool) :
        m_Pool(Pool)
    {
    }

    Room* DoThing(const string& Playername, Player& p) override
    {
        cout << "GG " << Playername << " you have found the SecretRoom !" << endl;
        cout << "Only a psycho can find it, so you are" << endl;
        cout << "You can do 2 things in it :" << endl;
        cout << "1: Do poop" << endl;
        cout << "2: Do pee" << endl;
        cout << "3: Back" << endl;

        int i;
        cin >> i;

        if (i == 1)
        {
            system("cls");
            cout << "proute\n\n" << endl;
            return this;
        }

        if (i == 2)
        {
            system("cls");
            cout << "pisssssssssssss\n\n" << endl;
            return this;
        }

        if (i == 3)
        {
            system("cls");
            return m_Pool;
        }

        return nullptr;
    }
};


class Pool
    :public Room
{
    Room* m_mainHall;
    Room* m_SecretRoom;

public:
    Pool(Room* mainHall) :
    m_mainHall(mainHall)
    {
        m_SecretRoom = new SecretRoom(this);
    }

    ~Pool()
    {
        delete m_SecretRoom;
    }
    Room* DoThing(const string& Playername, Player& p) override
    {
        cout << Playername << " you're in the pool, what you wanna do ?" << endl;
        cout << "1: Jump in it" << endl;
        cout << "2: Drown your brother" << endl;
        cout << "3: Back" << endl;

        int i;
        cin >> i;

        if (i == 1)
        {
            system("cls");
            return this;
        }

        if (i == 2)
        {
            system("cls");
            return m_SecretRoom;
        }

        if (i == 3)
        {
            system("cls");
            return m_mainHall;
        }

        return nullptr;
    }
};
class MainHall
    : public Room
{
    Room* m_diningHall;
    Room* m_Bathroom;
    Room* m_Garage;
    Room* m_Pool;

public:
    MainHall()
    {
        m_diningHall = new DiningHall(this);
        m_Bathroom = new BathRoom(this);
        m_Garage = new Garage(this);
        m_Pool = new Pool(this);

    }

    ~MainHall()
    {
        delete m_diningHall;
        delete m_Bathroom;
        delete m_Garage;
        delete m_Pool;
    }

    Room* DoThing(const string& Playername, Player& p) override
    {
        cout << Playername << " you're in the mainhall, what you wanna do ?" << endl;
        cout << "1: Go to the bathroom " << endl;
        cout << "2: Go to the dining room" << endl;
        cout << "3: Go to the garage" << endl;
        cout << "4: Go to the pool" << endl;

        int i;
        cin >> i;

        if (i == 1) 
        {
            system("cls");
            return m_Bathroom;
        }

        if (i == 2)
        {
            system("cls");
            return m_diningHall;
        }

        if (i == 3)
        {
            system("cls");
            return m_Garage;
        }

        if (i == 4)
        {
            system("cls");
            return m_Pool;
        }

        return nullptr;
    }
};


int main(int argc, char** argv)
{
    char* Playername = new char();
    cout << "What's your name ?" << endl;
    cin >> Playername;
    system("cls");
    Player p;
    MainHall mainHall;
    Room* currentRoom = &mainHall;

    while (currentRoom != nullptr) {
        currentRoom = currentRoom->DoThing(Playername, p);
    }

    system("cls");
    cout << "Wrong entry !!" << endl;
    delete Playername;
    return 0;
};
