#pragma once
#include "UpgradeAbilities.h"

namespace Breach {
    void upgrade_ability(Ability* ability) {
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
                    Spark::Spark* spark = static_cast<Spark::Spark*>(ab);
                    for (auto projectile : spark->get_projectiles()) {
                        projectile.set_velocity(projectile.get_velocity() * 2.0f);
                    }
                });
            } break;

            case AbilityName::Help: {
                Help::Help* help = static_cast<Help::Help*>(ability);
                help->friend_type = Help::FriendType::Hardy;

                help->attach_callback_on_enter([](Ability* ab) {
                    Help::Help* help = static_cast<Help::Help*>(ab);
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
}

namespace Spark {
    void upgrade_ability(Ability* ability) {
        ability->register_upgrade(AbilityName::Spark);

        switch (ability->get_name()) {
            case AbilityName::Breach: {
                Breach::Breach* breach = static_cast<Breach::Breach*>(ability);
                // We don't need to do any fancy callbacks, just tell Breach to do a tri-blade shot,
                // and breach will handle it itself.
                breach->set_laser_number(Breach::LaserCount::Triblade);
                break;
            }

            case AbilityName::Spark: {
                throw std::exception("Unimplemented upgrading Spark with Spark");
            } break;

            case AbilityName::Help: {
                Help::Help* help = static_cast<Help::Help*>(ability);
                help->friend_type = Help::FriendType::Small;

                // We don't even need to attach a callback here!
            } break;
        }
    }
}

namespace Help {
    void upgrade_ability(Ability* ability) {
        ability->register_upgrade(AbilityName::Help);

        switch (ability->get_name()) {
            case AbilityName::Help: {
                throw std::exception("Unimplemented upgrading Help with Help");
            } break;

            default: {
                // this just adds a default callback which gives each Ability a 50% chance
                // to prevent Cells from spawning. We can just do this to all of them, and
                // the few exceptions, like Jaunt, can just get cases above on impl.
                ability->attach_callback_on_enter(Help::default_callback);
            } break;
        }
    }
}