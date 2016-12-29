#include "input_works.h"
#include "plagiarism_check.h"
#include "output_results.h"

int main() {
    struct Student* student = create_student();

    struct works_list students_works = get_students_works();
    struct check_result_list check_results = check_for_plagiarism(students_works);
    notify_students_about_results(check_results);

    return 0;
}
