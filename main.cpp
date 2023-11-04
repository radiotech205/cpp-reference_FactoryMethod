#include <iostream>
#include <vector>
using namespace std;

// Иерархия классов игровых персонажей
class Warrior
{
  public:
    virtual void info() = 0;
    virtual void weapon() = 0;
    virtual ~Warrior() {}
};

class Infantryman: public Warrior
{
  public:
    void info() {   cout << "Infantryman, health = "<< health << endl;  }
    void weapon() {   cout << "Axe" << endl;  }
    Infantryman(int health_ = 105): health(health_) {}
    int health;
};



class Archer: public Warrior
{
  public:
    void info() {   cout << "Archer, health = "<< health << endl;    }
    void weapon() {   cout << "Arch" << endl;  }
    Archer(int health_ = 100): health(health_) {}
    int health;
};

class Horseman: public Warrior
{
  public:
    void info() {  cout << "Horseman, health = "<< health << endl; }
    void weapon() {  cout << "Horse" << endl;  }
    Horseman(int health_ = 150): health(health_) {}
    int health;
};

/*****************************/
// Фабрики объектов
class Factory
{
  public:
    virtual Warrior* createWarrior(int health) = 0;
    virtual ~Factory() {}
};

class InfantryFactory: public Factory
{
  public:
    Warrior* createWarrior(int health) {   return new Infantryman(health);    }
};

class ArchersFactory: public Factory
{
  public:
    Warrior* createWarrior(int health) {    return new Archer(health);  }
};

class CavalryFactory: public Factory
{
  public:
    Warrior* createWarrior(int health) {   return new Horseman(health);   }
};

int main()
{
    InfantryFactory* infantry_factory = new InfantryFactory;
    ArchersFactory*  archers_factory  = new ArchersFactory ;
    CavalryFactory*  cavalry_factory  = new CavalryFactory ;

    vector<Warrior*> v;
    v.push_back( infantry_factory->createWarrior(99));
    v.push_back( archers_factory->createWarrior(100));
    v.push_back( cavalry_factory->createWarrior(101));

    for(uint i=0; i<v.size(); i++)
    {
        v[i]->info();
        v[i]->weapon();
    }

    cout << "Hello World!" << endl;
    return 0;
}
