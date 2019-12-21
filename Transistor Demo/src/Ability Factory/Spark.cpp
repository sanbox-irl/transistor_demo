#include "Spark.h"

namespace Spark {
    void Spark::on_enter() {
        // Spawn our Projectiles on Enter...
        for (int i = 0; i < m_ProjectileNumber; i++) {
            m_Projectiles.push_back(SparkProjectiles(m_ProjectileVelocity));
        }
    }

    bool Spark::process(float dt) {
        // We don't have a process! All the sparks logic would be in the Spark Projectiles
        return true;
    }

    void Spark::on_exit() {
    }

}