#include <iostream>
#include <string>
#include <list>
#include "Sotrudnik.h"
#include "Units.h"
int main(int argc, const char * argv[]) {
    Units k("DesignDepartment");
    Sotrudnik Jon("Jon","creator",95000);
    Sotrudnik Kate("Katerin","trainee",25000);
    k.set_finance(750000);
    k.add(Jon);
    Sotrudnik Lany("Lany", "designer");
    Lany.set_salary(38000);
    Lany.set_prize(7000);
    k.add(Lany);
    k += Kate;
    std::cout<<k <<std::endl;
    k.print_all_sotr();
    std::cout << "Salary for all collaborators: " <<k.allsalaries() <<", reserve: " <<k.get_reserve();
    std::cout <<Jon <<"Salary without tax: " <<Jon.get_factsalary();
    Units f("SalesDepartament");
    f.set_finance(100000);
    Sotrudnik Kyle("Kyle","sales manager",80000, 10000);
    Sotrudnik Mily("Mily","trainee",25000);
    f.add(Mily);
    f += Kyle;
    std::cout <<f;
    f.print_all_sotr();
    std::cout <<f.get_tax();
    f.dismissal(Mily);
    f.print_all_sotr();
    Units All("UnionOfDepartments");
    All = k + f;
    std::cout <<All;
    return 0;
}
