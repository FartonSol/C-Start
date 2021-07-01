/*
При разработке игры мы решили, что в ней должны быть монстры, потому что всем нравится сражаться с монстрами. Объявите структуру, которая представляет вашего монстра. Монстр может быть разным: ogre, goblin, skeleton, orc и troll.
Если ваш компилятор поддерживает C++11, то используйте классы enum, если нет — обычные перечисления.

Каждый монстр также должен иметь имя (используйте std::string) и количество здоровья, которое отображает, сколько урона он может получить, прежде чем умрет. 
Напишите функцию printMonster(), которая выведет все члены структуры.
Объявите монстров типа goblin и orc, инициализируйте их, используя список инициализаторов, и передайте в функцию printMonster().

Решил все сделать через класс, но не выходит 
*/

#include <iostream>
#include <cmath>
enum class monsterType
{
    ogre,
    goblin,
    skeleton,
    troll
};
class Monster
{
    public:
    monsterType type;
    std::string name;
    double health;
    void printMonster(monsterType type, std::string name, double health)
    {
        std::cout <<"Имя "<< name<< " Здоровье " << health<< "Класс" << type<< '\n';
    };
};
int main()
{
    Monster ogre{monsterType::ogre, "Fsddsf", 42}
    Monster.printMonster();
    return 0;
}
