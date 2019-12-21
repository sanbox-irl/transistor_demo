#include "Help.h"
#include "Breach.h"
#include "Spark.h"

void Help::default_callback(Ability* ab) {
    std::cout << "50% chance Help is preventing Cells from Spawning!" << std::endl;
}

void Help::on_enter() {
    m_SpawnedFriends.clear();
    switch (friend_type) {
        // depending on the friend type, we make a different friend!
        // and we save it in a vec. We probably would be storing
        // some kind of smart pointer in a real implemenation, since
        // we won't be in charge of destroying it.

        m_SpawnedFriends.push_back(Friend());
    }
}

bool Help::process(float dt) {
    // We don't have a process! All the Helps logic would be in the Friend
    return true;
}

void Help::on_exit() {
}

void Help::upgrade_ability(std::shared_ptr<Ability>& ability) {
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