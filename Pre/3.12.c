#include <stdio.h>

int main(void) {
    int N_CALCULATIONS;
    int i;
    int attackerLevel;
    int opponentLevel;
    int opponentArmor;

    float baseAttack;
    float damageReduction;
    float netDamage;
    float damageDeficit;
    float worthThreshold = 150.0;

    scanf("%d", &N_CALCULATIONS);

    for (i = 0; i < N_CALCULATIONS; i++) {
        scanf("%d %d %d",
              &attackerLevel,
              &opponentLevel,
              &opponentArmor);

        baseAttack = attackerLevel * 10.0;

        if (opponentArmor < 50) {
            damageReduction = 0.20;
        } else {
            damageReduction = 0.40;
        }

        netDamage = baseAttack * (1.0 - damageReduction);

        if (netDamage >= worthThreshold) {
            printf("SUCCESS! Net Damage: %.2f\n", netDamage);
        } else {
            damageDeficit = worthThreshold - netDamage;
            printf("FAIL. Deficit: %.2f\n", damageDeficit);
        }
    }

    return 0;
}
