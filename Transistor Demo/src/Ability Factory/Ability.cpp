#include "Ability.h"

// Implement the basic calls and callbacks here...
void Ability::activate() {
    on_enter();
    for (auto callback : callbacks_on_enter) {
        callback(this);
    }
}

// This returns a bool, signifying when a process is done.
// We don't do anything with it in this Demo but in a real
// impl, this would tell the engine when to stop running an
// ability.
bool Ability::update(float dt) {
    bool ret = process(dt);
    for (auto callback : callbacks_on_process) {
        callback(this);
    }
    return ret;
}
void Ability::end() {
    on_exit();
    for (auto callback : callbacks_on_exit) {
        callback(this);
    }
}

std::ostream& operator<<(std::ostream& out, const AbilityName& ability_name) {
    const char* output = nullptr;

    // We can probably do this with some fancy macro,
    // but it's awfully nice and simple to just write some strings.
    switch (ability_name) {
        case AbilityName::Breach:
            output = "AbilityName::Breach";
            break;
        case AbilityName::Spark:
            output = "AbilityName::Spark";
            break;
        case AbilityName::Help:
            output = "AbilityName::Help";
            break;
        case AbilityName::COUNT:
            output = "AbilityName::COUNT";
            break;
        case AbilityName::NONE:
            output = "AbilityName::NONE";
            break;
    }

    out << output;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Ability& ability) {
    out << "Main Ability: " << ability.get_name() << std::endl;
    out << "Upgrades: ";
    if (ability.m_Upgrades.empty()) {
        out << "NONE";
    } else {
        for (auto upgrade : ability.m_Upgrades) {
            out << upgrade << ", ";
        }
    }
    out << std::endl;
    return out;
}