#include <stdio.h>
#include <math.h>

// ตัวแปรสำหรับคำนวณแรงยก
float Cl;               // Lift Coefficient
float P;                // Air density (kg/m^3)
float g;                // Gravity (m/s^2)
float Velocity;         // Air velocity (m/s)
float Area_OF_WINGS;    // Wing area (m^2)
float Lift_force;       // Lift force (N)
float Mass_of_UAV;      // UAV mass (kg)
float angle_of_wings;   // Wing angle (degrees)

// ความเร็วขั้นต่ำที่ต้องใช้
float Velocity_find;

int main()
{
    printf("============================================================\n");
    printf("       PROGRAM CALCULATE LIFT FORCE UNDER UAV'S WINGS\n");
    printf("============================================================\n\n");

    // รับค่า Cl
    printf("Enter the value of Cl : ");
    scanf("%f", &Cl);

    // รับค่า g
    printf("Enter the G value : ");
    scanf("%f", &g);

    // รับค่าความหนาแน่นของอากาศ
    printf("Enter the value of air density (kg/m^3) : ");
    scanf("%f", &P);

    // รับค่าความเร็วลม
    printf("Enter the velocity of air (m/s) : ");
    scanf("%f", &Velocity);

    // รับค่าพื้นที่ปีก
    printf("Enter the UAV's wing area (m^2) : ");
    scanf("%f", &Area_OF_WINGS);

    // รับค่ามุมปีก
    printf("Enter the UAV's wings angle (degrees) : ");
    scanf("%f", &angle_of_wings);

    // รับค่ามวล UAV
    printf("Enter the mass of UAV (kg): ");
    scanf("%f", &Mass_of_UAV);


    // ========================================================
    // แปลงองศาเป็นเรเดียน
    // ========================================================

    float angle_rad = angle_of_wings * M_PI / 180.0f;


    // ========================================================
    // คำนวณแรงยก
    // L = 0.5 * Cl * P * V^2 * A
    // ========================================================

    Lift_force =
        0.5f *
        Cl *
        P *
        (Velocity * Velocity) *
        Area_OF_WINGS;


    // ========================================================
    // คำนวณองค์ประกอบแรงในแนวดิ่ง
    // ========================================================

    float Vertical_Lift = Lift_force * sin(angle_rad);


    // ========================================================
    // น้ำหนักของ UAV
    // W = mg
    // ========================================================

    float Weight = Mass_of_UAV * g;


    // ========================================================
    // หาความเร็วขั้นต่ำ
    // L = mg
    //
    // V = sqrt(2mg / (P*A*Cl))
    // ========================================================

    Velocity_find =
        sqrt(
            (2.0f * Mass_of_UAV * g) /
            (P * Area_OF_WINGS * Cl)
        );


    // ========================================================
    // แสดงผล
    // ========================================================

    printf("\n============================================================\n");
    printf("                  CALCULATION RESULT\n");
    printf("============================================================\n");

    printf("Lift Coefficient (Cl) = %.3f\n", Cl);

    printf("Air Density (P)       = %.3f kg/m^3\n", P);

    printf("Gravity (g)            = %.3f m/s^2\n", g);

    printf("Air Velocity           = %.3f m/s\n", Velocity);

    printf("Wing Area              = %.3f m^2\n", Area_OF_WINGS);

    printf("Wing Angle             = %.3f degrees\n", angle_of_wings);

    printf("Lift Force             = %.3f N\n", Lift_force);

    printf("Vertical Lift          = %.3f N\n", Vertical_Lift);

    printf("UAV Weight             = %.3f N\n", Weight);

    printf("Minimum Velocity       = %.3f m/s\n", Velocity_find);


    // ========================================================
    // ตรวจสอบว่าสามารถยก UAV ได้หรือไม่
    // ========================================================

    printf("\n============================================================\n");

    if (Vertical_Lift < Weight)
    {
        printf("CAN NOT LIFT THE UAV\n");
    }
    else if (fabs(Vertical_Lift - Weight) < 0.001f)
    {
        printf("UAV CAN JUST HOVER\n");
    }
    else
    {
        printf("UAV CAN LIFT\n");
    }

    printf("============================================================\n");

    return 0;
}