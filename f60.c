#include <stdio.h>

struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Emp ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Name: ");
        scanf(" %[^\n]", emp[i].name);  // read string with spaces

        printf("Designation: ");
        scanf(" %[^\n]", emp[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basic_salary);

        printf("HRA%%: ");
        scanf("%f", &emp[i].hra_percent);

        printf("DA%%: ");
        scanf("%f", &emp[i].da_percent);

        // Calculate gross salary
        emp[i].gross_salary = emp[i].basic_salary +
                              (emp[i].basic_salary * emp[i].hra_percent / 100) +
                              (emp[i].basic_salary * emp[i].da_percent / 100);
    }

    printf("\nEmployee Details with Gross Salary:\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmp ID: %d\n", emp[i].emp_id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basic_salary);
        printf("HRA%%: %.2f\n", emp[i].hra_percent);
        printf("DA%%: %.2f\n", emp[i].da_percent);
        printf("Gross Salary: %.2f\n", emp[i].gross_salary);
    }

    return 0;
}
