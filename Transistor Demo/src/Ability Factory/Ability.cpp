#include "Ability.h"

std::ostream& operator<<(std::ostream& out, const AbilityName& ability_name) {
    const char* output = nullptr;

    switch (ability_name) {
        case AbilityName::Breach:
            output = "AbilityName::Breach";
            break;
        case AbilityName::Spark:
            output = "AbilityName::Spark";
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
    return out;
}