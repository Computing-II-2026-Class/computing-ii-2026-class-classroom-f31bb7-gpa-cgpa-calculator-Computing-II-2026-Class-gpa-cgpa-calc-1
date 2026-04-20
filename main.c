/*
Name: OREM ABRAHAM
Registration Number: 25/U/BIE/01415/PE
*/

#include <stdio.h>

    // function to get grade point from score
int getGradePoint(int score){
    if (score >= 80) return 5;
    else if (score >= 70) return 4;
    else if (score >= 60) return 3;
    else if (score >= 50) return 2;
    else return 0;
    
}

//Function to get grade letter from score
char getGrade(int score){
    if (score >= 80) return 'A';
    else if (score >= 70) return 'B';
    else if (score >= 60) return 'C';
    else if (score >= 50) return 'D';
    else return 'F';
}
int main(void) {
    /* Declare variables here */
    //Semester One data
const char *sem1_codes[] = {
    "TEMB 1101", "TEMB 1102", "TEMB 1103", "TEMB 1104", "TEMB 1105", "TEMB 1106", "TEMB 1107", "TEMB 1108", 
};
const char *sem1_codes[] = {
    "Fundamentals of Engineering Mathematics",
    "Biochemistry and Medical Physics",
    "Electrical Engineering  Science",
    "Mechanics I",
    "Computing I",
    "Mechanical Drawing",
    "Engineering Profession",
    "Functional Anatomy and Physiology I",
};
 int sem1_credits[] = {4, 3, 3, 3, 3, 3, 2, 3};
    //Semester 2 data
const char *sem2_codes[] = {
    "TEMB 1201", "TEMB 1202", "TEMB 1203", "TEMB 1204", "TEMB 1205", "TEMB 1206", "TEMB 1207", "TEMB 1208", 
};
const char *sem1_codes[] = {
    "Fundamentals of Engineering Mathematics",
    "Computing II",
    "Mechatronics Drawing",
    "Fluid Mechanics",
    "Thermodynamics",
    "Workshop Practice",
    "Functional Anatomy and Physiology I",
    "Electronics I",
};
 int sem1_credits[] = {4, 3, 3, 3, 3, 3, 3, 3};


int sem1_scores[8], sem2_scores[8];
int i;
    
    /* Read 16 scores */
//Data entry for semester one
printf("\n...Enter your scores for semester one...\n");
for (i = 0; i < 8; i++){
    printf("Enter score for %s (%s): ", sem1_codes[i], sem1_names[i]);
    scanf("%d", &sem1_scores[i]);
    if (sem1_scores[i] < 0 || sem1_scores > 100){
        printf("\nInvalid score entered\n");
        return 1;
    };
};
    //Data entry for semester two
printf("\n...Enter your scores for semester two...\n");
for (i = 0; i < 8; i++){
    printf("Enter score for %s (%s): ", sem2_codes[i], sem2_names[i]);
    scanf("%d", &sem2_scores[i]);
    if (sem2_scores[i] < 0 || sem2_scores > 100){
        printf("\nInvalid score entered\n");
        return o;
    };
};
    /* Validate input */

    /* Determine grades and grade points */
int sem1_total_credits = 0, sem1_weighted_sum = 0;
int sem1_gp[8], sem1_weighted[8];
char sem1_graded[8];

int sem2_total_credits = 0, sem2_weighted_sum = 0;
int sem2_gp[8], sem2_weighted[8];
char sem2_graded[8];

for (i = 0, i < 8, i++){
    sem1_gp[i] = getGradePoint(sem1_scores[i]);
    sem1_grade[i] = getGrade(sem1_scores[i]);
    sem1_weighted[i] = sem1_gp[i] * sem1_credits[i];
    sem1_total_credits += sem1_credits[i];
    sem1_weighted_sum += sem1_weighted[i];
}

for (i = 0, i < 8, i++){
    sem2_gp[i] = getGradePoint(sem2_scores[i]);
    sem2_grade[i] = getGrade(sem2_scores[i]);
    sem2_weighted[i] = sem2_gp[i] * sem2_credits[i];
    sem2_total_credits += sem2_credits[i];
    sem2_weighted_sum += sem2_weighted[i];
}

    /* Compute Semester I GPA */

double sem1_gpa = (double)sem1_weighted_sum / sem1_total_credits;

    /* Compute Semester II GPA */

double sem2_gpa = (double)sem2_weighted_sum / sem2_total_credits;

    /* Compute CGPA */
int total_credits = sem1_total_credits + sem2_total_credits;
int total_weighted = sem1_weighted_sum + sem2_weighted_sum;
double cgpa = (double)total-weighted / total_credits;

    /* Determine classification */
const char *classification;
if (cgpa > 4.40)
    classification = "First Class";
else if (cgpa >= 3.60)
    classification = "Second Class Upper";
else if (cgpa >= 2.80)
    classification = "Second Class Lower";
else if (cgpa >= 2.00)
    classification = "Pass";
else classification = "Fail";

    /* Display full academic report */
printf("\n...............................................................................\n");
printf("                   KYAMBOGO UNIVERSITY ACADEMIC REPORT                         \n");
printf("                          YEAR ONE - TEMB                                       \n");
printf(".................................................................................\n"),

printf("..............................SEMSTER ONE.........................\n");
printf("%-12s %-42s %5s %6s %3s %8s %10s\n",
    "Code", "Course Name", "Score", "Grade", "GP", "Credits", "Weighted",
    );
printf(".................................................................\n");
for (i = 0, i < 8, i++){
    printf("%-12s %-42s %5d %6c %3d %8d %10d\n"
    sem1_codes[i], sem1_names[i], sem1_scores[i], sem1-grade[i], sem1_gp[i], sem1_credits[i], sem1_weighted[i];
    );
}
printf(".................................................................\n");
printf("Total Credit Units: %d Weighted Sum: %%d\n", sem1_total_credits, sem1_weighted_sum);

printf("..............................SEMSTER TWO.........................\n");
printf("%-12s %-42s %5s %6s %3s %8s %10s\n",
    "Code", "Course Name", "Score", "Grade", "GP", "Credits", "Weighted",
    );
printf(".................................................................\n");
for (i = 0, i < 8, i++){
    printf("%-12s %-42s %5d %6c %3d %8d %10d\n"
    sem2_codes[i], sem2_names[i], sem2_scores[i], sem2-grade[i], sem2_gp[i], sem2_credits[i], sem2_weighted[i];
    );
}
printf(".................................................................\n");
printf("Total Credit Units: %d Weighted Sum: %%d\n", sem2_total_credits, sem2_weighted_sum);

printf(".................................................................\n");
printf("Semester One GPA: %.2f\n", sem1_gpa);
printf("Semester Two GPA: %.2f\n", sem2_gpa);
printf("CGPA: %.2f", cgpa);
printf("Classification: %s\n", classification);
printf(".................................................................\n");

    return 0;
}
