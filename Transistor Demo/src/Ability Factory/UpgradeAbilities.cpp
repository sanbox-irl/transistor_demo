#pragma once
#include "UpgradeAbilities.h"

namespace Breach {
    void upgrade_ability(Ability* ability) {
        switch (ability->get_name()) {
            case AbilityName::Breach:
                // I was never actually good enough at Transistor to get to this point,
                // so I am not exactly sure what the implementation of it would look like.
                throw std::exception("Unimplemented upgrading Breach with Breach");
                break;

            case AbilityName::Spark:
                // We static_cast here since we're enumerating the type above -- we're promising this is the right
                // kind of thing, and if we break that contract, we should crash.
                ability->attach_callback_on_enter({AbilityName::Breach, [](Ability* ab) {
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
                                                       Spark::Spark* spark = static_cast<Spark::Spark*>(ab);
                                                       for (auto projectile : spark->get_projectiles()) {
                                                           projectile.set_velocity(projectile.get_velocity() * 2.0f);
                                                       }
                                                   }});
                break;
        }
    }
}

namespace Spark {
    void upgrade_ability(Ability* ability) {
        switch (ability->get_name()) {
            case AbilityName::Breach: {
                Breach::Breach* breach = static_cast<Breach::Breach*>(ability);
                // We don't need to do any fancy callbacks, just tell Breach to do a tri-blade shot,
                // and breach will handle it itself.
                breach->set_laser_number(Breach::LaserCount::Triblade);
                break;
            }

            case AbilityName::Spark:
                throw std::exception("Unimplemented upgrading Spark with Spark");
                break;
        }
    }

}