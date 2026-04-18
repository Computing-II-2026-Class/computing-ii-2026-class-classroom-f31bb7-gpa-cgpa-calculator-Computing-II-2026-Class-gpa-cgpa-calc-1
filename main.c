/*
Name: JAKIRA JUMA FAHAD
Registration Number: 25/U/BIO/01374/PD
*/

#include <stdio.h>

int getGradePoint(int score) {
    if (score >= 80) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else return 0;
}

char getGrade(int score) {
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}

int main() {
    /* Semester I courses */
    const char *sem1_codes[] = {
        "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104",
        "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108"
    };
    const char *sem1_names[] = {
        "Fundamentals of Engineering Mathematics",
        "Biochemistry and Medical Physics",
        "Electrical Engineering Science",
        "Mechanics I",
        "Computing I",
        "Mechanical Drawing",
        "Engineering Profession",
        "Functional Anatomy and Physiology I"
    };
    int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};

    /* Semester II courses */
    const char *sem2_codes[] = {
        "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204",
        "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208"
    };
    const char *sem2_names[] = {
        "Further Engineering Mathematics",
        "Computing II",
        "Mechatronics Drawing",
        "Fluid Mechanics",
        "Thermodynamics",
        "Workshop Practice",
        "Functional Anatomy and Physiology II",
        "Electronics I"
    };
    int sem2_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};

    int sem1_scores[8], sem2_scores[8];
    int i;

    /* Read Semester I scores */
    printf("=== Enter Semester I Scores ===\n");
    for (i = 0; i < 8; i++) {
        printf("Score for %s (%s): ", sem1_codes[i], sem1_names[i]);
        scanf("%d", &sem1_scores[i]);
        if (sem1_scores[i] < 0 || sem1_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
            return 0;
        }
    }

    /* Read Semester II scores */
    printf("\n=== Enter Semester II Scores ===\n");
    for (i = 0; i < 8; i++) {
        printf("Score for %s (%s): ", sem2_codes[i], sem2_names[i]);
        scanf("%d", &sem2_scores[i]);
        if (sem2_scores[i] < 0 || sem2_scores[i] > 100) {
            printf("Invalid score entered\n");
            return 1;
            return 0;
        }
    }

    /* Calculate Semester I GPA */
    int sem1_total_credits = 0, sem1_weighted = 0;
    for (i = 0; i < 8; i++) {
        sem1_total_credits += sem1_credits[i];
        sem1_weighted += getGradePoint(sem1_scores[i]) * sem1_credits[i];
    }
    double gpa1 = (double)sem1_weighted / sem1_total_credits;

    /* Calculate Semester II GPA */
    int sem2_total_credits = 0, sem2_weighted = 0;
    for (i = 0; i < 8; i++) {
        sem2_total_credits += sem2_credits[i];
        sem2_weighted += getGradePoint(sem2_scores[i]) * sem2_credits[i];
    }
    double gpa2 = (double)sem2_weighted / sem2_total_credits;

    /* Calculate CGPA */
    double cgpa = (double)(sem1_weighted + sem2_weighted) / (sem1_total_credits + sem2_total_credits);

    /* Determine classification */
    const char *classification;
    if (cgpa >= 4.40)
        classification = "First Class";
    else if (cgpa >= 3.60)
        classification = "Second Class Upper";
    else if (cgpa >= 2.80)
        classification = "Second Class Lower";
    else if (cgpa >= 2.00)
        classification = "Pass";
    else
        classification = "Fail";

    /* Print full academic report */
    printf("\n============================================================\n");
    printf("                  ACADEMIC REPORT - YEAR ONE               \n");
    printf("============================================================\n");

    printf("\n--- Semester I ---\n");
    printf("%-12s %-45s %5s %5s %2s %10s\n",
           "Code", "Course Name", "Score", "Grade", "GP", "Credits", "Weighted");
    printf("%-12s %-45s %5s %5s %2s %7s %8s\n",
           "----", "-----------", "-----", "-----", "--", "-------", "--------");
    for (i = 0; i < 8; i++) {
        int gp = getGradePoint(sem1_scores[i]);
        printf("%-12s %-45s %5d %5c %2d %7d %8d\n",
               sem1_codes[i], sem1_names[i],
               sem1_scores[i], getGrade(sem1_scores[i]),
               gp, sem1_credits[i], gp * sem1_credits[i]);
    }
    printf("\nSemester I Total Credits: %d | Weighted Points: %d\n",
           sem1_total_credits, sem1_weighted);

    printf("\n--- Semester II ---\n");
    printf("%-12s %-45s %5s %5s %2s %10s\n",
           "Code", "Course Name", "Score", "Grade", "GP", "Credits", "Weighted");
    printf("%-12s %-45s %5s %5s %2s %7s %8s\n",
           "----", "-----------", "-----", "-----", "--", "-------", "--------");
    for (i = 0; i < 8; i++) {
        int gp = getGradePoint(sem2_scores[i]);
        printf("%-12s %-45s %5d %5c %2d %7d %8d\n",
               sem2_codes[i], sem2_names[i],
               sem2_scores[i], getGrade(sem2_scores[i]),
               gp, sem2_credits[i], gp * sem2_credits[i]);
    }
    printf("\nSemester II Total Credits: %d | Weighted Points: %d\n",
           sem2_total_credits, sem2_weighted);

    printf("\n============================================================\n");
    printf("Semester I GPA: %.2f\n", gpa1);
    printf("Semester II GPA: %.2f\n", gpa2);
    printf("CGPA: %.2f\n", cgpa);
    printf("Classification: %s\n", classification);
    printf("============================================================\n");

    return 0;
}
