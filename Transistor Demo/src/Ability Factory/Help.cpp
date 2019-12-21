#include "Help.h"

namespace Help {
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

}