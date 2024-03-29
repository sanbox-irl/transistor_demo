#include "Ability Factory/AbilityFactory.h"
#include <iostream>
#include <memory>

// This is our "factory". An imagined caller would be Red, after
// being pinged with the requisite imagery from the UI menus.
// To that extent, we've made the AbilityNames exist in their own file
// so we can #include them in the UI and Resource classes without this
// actual ability logic.

// Right now this is just a pure function, for simplicity. This could
// easily turn into a whole class in the future, and certainly would not be in
// the main function!

// We also are only dealing with two abilities right here. This is a
// failure of this implementation, largely because I don't exactly remember
// how a double upgrade of an ability works. Theoretically, it should be as simple
// as running the second block again, but no doubt there would be complications from
// that!
std::shared_ptr<Ability> ability_factory(const AbilityName& ability_name, const AbilityName& upgrade_ability) {
    std::shared_ptr<Ability> ability(nullptr);

    switch (ability_name) {
        case AbilityName::Breach:
            ability = std::make_shared<Breach>();
            break;
        case AbilityName::Spark:
            ability = std::make_shared<Spark>();
            break;
        case AbilityName::Help:
            ability = std::make_shared<Help>();
            break;
        default:
            // Temp exception handling
            throw std::exception("We require a main ability!");
    }

    // We're upgrading the ability here!
    // All of these are just floating functions right now, which are
    // fine to me, but some might prefer to make this more OOP.
    switch (upgrade_ability) {
        case AbilityName::Breach:
            Breach::upgrade_ability(ability);
            break;
        case AbilityName::Spark:
            Spark::upgrade_ability(ability);
            break;
        case AbilityName::Help:
            Help::upgrade_ability(ability);
            break;
        case AbilityName::NONE:
            // No work here to do, just the basic ability.
            break;
        default:
            throw "Absurd -- Unknown ability type used";
    }

    return ability;
}

int main() {
    auto ability0 = ability_factory(AbilityName::Breach, AbilityName::NONE);
    auto ability1 = ability_factory(AbilityName::Breach, AbilityName::Spark);
    auto ability2 = ability_factory(AbilityName::Spark, AbilityName::Breach);

    std::cout << "Ability 0:----" << std::endl << *ability0 << "----" << std::endl;
    std::cout << "Ability 1:----" << std::endl << *ability1 << "----" << std::endl;
    std::cout << "Ability 2:----" << std::endl << *ability2 << "----" << std::endl;

    ability0->activate();

    ability1->activate();
    ability1->update(0.16f); // a nice looking 60 FPS

    ability2->activate();
    ability2->update(0.16f);
    ability2->end();
}