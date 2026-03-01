#ifndef MISSION_PLANNER_H
#define MISSION_PLANNER_H

#include <stdint.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} Waypoint_t;

/**
 * @brief İHA'nın hedef rotadaki bir sonraki setpoint'ini hesaplar.
 * @param current_pos Mevcut 3D konum
 * @param target_pos Hedeflenen waypoint
 * @return PID için gerekli hedef pitch açısı
 */
float Mission_Calculate_Target_Pitch(Waypoint_t current_pos, Waypoint_t target_pos);

/**
 * @brief İki nokta arasındaki Öklid mesafesini hesaplar.
 */
float Mission_Get_Distance(Waypoint_t p1, Waypoint_t p2);

#endif
