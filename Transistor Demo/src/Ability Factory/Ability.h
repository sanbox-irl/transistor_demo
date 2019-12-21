#pragma once

#include "vector"
#include <functional>
#include <iostream>
#include <string>

// Runtime type information for our abilities;
// we're going to be finding our functions at runtime
// based on these so we'll need them. We'll also store
// them for easier debugging.
enum class AbilityName {
    Breach,
    Spark,

    // ..etc
    COUNT,
    NONE
};

std::ostream& operator<<(std::ostream& out, const AbilityName& ability_name);

class Ability;

struct AbilityCallback {
    AbilityName ability_name;
    std::function<void(Ability*)> ability;
};

// This is our actual ability object. Red holds a number
// of these, and her own logic will determine when to
// activate one of these abilities.

// Inheritors of this class might add additional callbacks for
// specific upgrades to attach themselves too.

// Check where "Breach" upgrades "Mask" for a callback upgrade...
class Ability {
  public:
    Ability(AbilityName name) : m_Name(name) {
    }

    virtual ~Ability() {
    }

    void attach_callback_on_enter(AbilityCallback ac) {
        callbacks_on_enter.push_back(ac);
    }

    void attach_callback_on_process(AbilityCallback ac) {
        callbacks_on_process.push_back(ac);
    }

    void attach_callback_on_exit(AbilityCallback ac) {
        callbacks_on_exit.push_back(ac);
    }

    AbilityName get_name() const {
        return m_Name;
    }

  private:
    virtual void on_enter() = 0;
    virtual bool process(float delta_time) = 0;
    virtual void on_exit() = 0;

    std::vector<AbilityCallback> callbacks_on_enter;
    std::vector<AbilityCallback> callbacks_on_process;
    std::vector<AbilityCallback> callbacks_on_exit;
    const AbilityName m_Name;
};

std::ostream& operator<<(std::ostream& out, const Ability& ability);