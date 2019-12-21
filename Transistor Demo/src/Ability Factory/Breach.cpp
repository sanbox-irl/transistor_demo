#pragma once
#include "Breach.h"
#include "Help.h"
#include "Spark.h"

void Breach::on_enter() {
    std::cout << "Entering Breach!" << std::endl;
    // VFX for Breach on Enter here...
    m_CountDown = m_CountDownMax;
}

bool Breach::process(float dt) {
    // The aiming, process, VFX, etc, of Red using Breach
    m_CountDown -= dt;

    if (m_CountDown < 0) {
        switch (m_LaserCount) {
            case LaserCount::Single:
                std::cout << "Firing Breach!" << std::endl;
                break;
            case LaserCount::Triblade:
                for (int i = 0; i < 3; i++) {
                    std::cout << "Firing Breach Laser " << i << std::endl;
                }
                break;
        }
        m_CountDown = m_CountDownMax - m_CountDown;
        return true;
    }
    return false;
}

void Breach::on_exit() {
    // any sort of exit we want to do when we end the breach (more VFX probably);
}

void Breach::upgrade_ability(std::shared_ptr<Ability>& ability) {
    ability->register_upgrade(AbilityName::Breach);

    switch (ability->get_name()) {
        case AbilityName::Breach: {
            // I was never actually good enough at Transistor to get to this point,
            // so I am not exactly sure what the implementation of it would look like.
            throw std::exception("Unimplemented upgrading Breach with Breach");
        } break;

        case AbilityName::Spark: {
            // I'll be doing all the callbacks in this file as lambda functions,
            // though they should turn into dedicated functions on each class in a full
            // implementation (though lambdas might have advantages too!)
            ability->attach_callback_on_enter([](Ability* ab) {
                // This is where VFX and SFX that will let the player know
                // they're using the UPGRADED mask will be executed. They
                // might also go in the other Callbacks, depending on what
                // designers choose to do.
                std::cout << "Excecuting callback from Breach!" << std::endl;

                // Find all our projectiles:
                // We should probably just alter the ability itself, but I wanted
                // to show how we get some flexibility here through the callback
                // + inheritance method to address the specifics of other
                // abilities!
                // We static_cast here since we're enumerating the type above --
                // we're promising this is the right
                // kind of thing, and if we break that contract, we should crash.
                Spark* spark = static_cast<Spark*>(ab);
                for (auto projectile : spark->get_projectiles()) {
                    projectile.set_velocity(projectile.get_velocity() * 2.0f);
                }
            });
        } break;

        case AbilityName::Help: {
            auto help = std::static_pointer_cast<Help>(ability);
            help->friend_type = Help::FriendType::Hardy;

            help->attach_callback_on_enter([](Ability* ab) {
                Help* help = static_cast<Help*>(ab);
                // Example impl of hardy friends with long range and
                // more turn planning
                for (auto spawned_friend : help->get_friends()) {
                    spawned_friend.attack_range += 100.0f;
                    spawned_friend.turn_planning += 100.0f;
                }
            });
        } break;
    }
}