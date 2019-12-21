#pragma once
#include "Ability.h"

class Help : public Ability {
  public:
    Help() : Ability(AbilityName::Help){};

    static void upgrade_ability(std::shared_ptr<Ability>& ability);

    enum class FriendType { Normal, Hardy, Small };

    // Just a default impl for clarity, with fields
    // reflecting what we can change.

    // Of course, like all these classes, this would get
    // a lot bigger in our real implementation
    struct Friend {
        float attack_range;
        float turn_planning;
    };

    FriendType friend_type;

    // if only it was this easy in real life
    std::vector<Friend>& get_friends() {
        return m_SpawnedFriends;
    }

    static void default_callback(Ability* ab);

  private:
    void on_enter() override;
    bool process(float dt) override;
    void on_exit() override;

    std::vector<Friend> m_SpawnedFriends;
};
