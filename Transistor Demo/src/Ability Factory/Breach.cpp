#pragma once
#include "Breach.h"

namespace Breach {
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
}