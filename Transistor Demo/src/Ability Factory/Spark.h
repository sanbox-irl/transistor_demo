#pragma once
#include "Ability.h"

class Spark : public Ability {
  public:
    Spark() : Ability(AbilityName::Spark){};
    static void upgrade_ability(std::shared_ptr<Ability>& ability);

    // Just a default class to show more complex interactions with Sparks..
    class SparkProjectiles {
      public:
        SparkProjectiles(float velocity) : m_Velocity(velocity) {
        }

        void set_velocity(float velocity) {
            m_Velocity = velocity;
        }

        float get_velocity() {
            return m_Velocity;
        }

      private:
        float m_Velocity;
    };

    std::vector<SparkProjectiles>& get_projectiles() {
        return m_Projectiles;
    }

  private:
    void on_enter() override;
    bool process(float dt) override;
    void on_exit() override;

    // Defaults...
    float m_ProjectileVelocity = 100;
    int m_ProjectileNumber = 2;
    std::vector<SparkProjectiles> m_Projectiles;
};