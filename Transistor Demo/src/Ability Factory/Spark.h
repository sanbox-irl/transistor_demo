#pragma once
#include "Ability.h"
#include "Breach.h"

namespace Spark {
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

    class Spark : public Ability {
      public:
        Spark() : Ability(AbilityName::Spark){};

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
}