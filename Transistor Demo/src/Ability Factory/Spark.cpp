#include "Spark.h"

namespace Spark {
    void Spark::on_enter() {
        std::cout << "Executing Spark!" << std::endl;
        // Spawn our Projectiles on Enter...
        for (int i = 0; i < m_ProjectileNumber; i++) {
            std::cout << "Creating projectile!" << std::endl;
            m_Projectiles.push_back(SparkProjectiles(m_ProjectileVelocity));
        }
    }

    bool Spark::process(float dt) {
        std::cout << "No update necessary for Spark" << std::endl;
        // We don't have a process! All the sparks logic would be in the Spark Projectiles
        return true;
    }

    void Spark::on_exit() {
        std::cout << "Ending Spark" << std::endl;
    }

}