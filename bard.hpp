#ifndef BARD_HPP
#define BARD_HPP


#include "JsonEntityBuilder.hpp"
#include "entity.hpp"

class Bard : public Entity
{
private:
    void ViciousMockery(Entity * target);

public:

    Bard(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid);

    virtual void OutputStatus() const override;
    virtual void WeaponAttack(Entity * target) override;

    virtual void UseAction(Entity * target, const std::string& spellName, const std::string & args) override;
};


#endif