#pragma once
#include "Ability.h"
#include <functional>
#include <iostream>

class Breach : public Ability {
  public:
    Breach() : Ability(AbilityName::Breach) {
    }

    static void upgrade_ability(std::shared_ptr<Ability>& ability);
    enum class LaserCount {
        Single,
        Triblade,
    };

    void set_laser_number(LaserCount new_laser_number) {
        m_LaserCount = new_laser_number;
    }

  private:
    void on_enter() override;
    bool process(float dt) override;
    void on_exit() override;

    float m_Damage = 100;                         // base damage of Breach
    LaserCount m_LaserCount = LaserCount::Single; // normally we only shoot out one laser
    float m_CountDownMax = 300;                   // max countdown
    float m_CountDown = 300;
};
