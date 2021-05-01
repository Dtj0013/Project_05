#include "bard.hpp"


Bard::Bard(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the bard has entered the battle" << std::endl;
}



void Bard::ViciousMockery(Entity *target)
{
    Attack(target, GetIntelligence() * 1.5, "Vicious Mockery");
}


void Bard::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tIntelligence: " << this->GetIntelligence()
                << std::endl;

    PrintInventory();
}

void Bard::WeaponAttack(Entity * target)
{
    Attack(target, 8.0, "Rapier Attack");
}

void Bard::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "vicious_mockery")
    {
        ViciousMockery(target);
        return;
    }
    errorFindingAbility(spellName);
}