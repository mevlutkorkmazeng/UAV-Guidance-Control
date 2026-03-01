#include "mission_planner.h"

float Mission_Calculate_Target_Pitch(Waypoint_t current_pos, Waypoint_t target_pos) {
    float dz = target_pos.z - current_pos.z;
    float dx = target_pos.x - current_pos.x;
    float dy = target_pos.y - current_pos.y;
    
    // Yatay mesafe (Yer mesafesi)
    float ground_dist = sqrtf(dx*dx + dy*dy);
    
    // Basit bir Guidance mantığı: Hedefe olan dikey açı
    // pitch = atan2(yükseklik farkı, yatay mesafe)
    float target_pitch = atan2f(dz, ground_dist) * (180.0f / 3.14159f);
    
    // Güvenlik sınırı: İHA'nın burnunu 30 dereceden fazla dikme
    if (target_pitch > 30.0f) target_pitch = 30.0f;
    if (target_pitch < -30.0f) target_pitch = -30.0f;
    
    return target_pitch;
}

float Mission_Get_Distance(Waypoint_t p1, Waypoint_t p2) {
    return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2) + powf(p1.z - p2.z, 2));
}
