#include "Spark.h"
#include "Breach.h"
#include "Help.h"

void Spark::on_enter() {
    std::cout << "Executing Spark!" << std::endl;
    // Spawn our Projectiles on Enter...
    for (int i = 0; i < m_ProjectileNumber; i++) {
        std::cout << "Creating projectile!" << std::endl;
        m_Projectiles.push_back(SparkProjectiles(m_ProjectileVelocity));
    }
}

bool Spark::process(float dt) {
    std::cout << "No update necessary for Spark" << std::endl;
    // We don't have a process! All the sparks logic would be in the Spark Projectiles
    return true;
}

void Spark::on_exit() {
    std::cout << "Ending Spark" << std::endl;
}

void Spark::upgrade_ability(std::shared_ptr<Ability>& ability) {
    ability->register_upgrade(AbilityName::Spark);

    switch (ability->get_name()) {
        case AbilityName::Breach: {
            auto breach = std::static_pointer_cast<Breach>(ability);
            // We don't need to do any fancy callbacks, just tell Breach to do a tri-blade shot,
            // and breach will handle it itself.
            breach->set_laser_number(Breach::LaserCount::Triblade);
            break;
        }

        case AbilityName::Spark: {
            throw std::exception("Unimplemented upgrading Spark with Spark");
        } break;

        case AbilityName::Help: {
            auto help = std::static_pointer_cast<Help>(ability);
            help->friend_type = Help::FriendType::Small;

            // We don't even need to attach a callback here!
        } break;
    }
}