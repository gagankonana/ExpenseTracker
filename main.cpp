#include "expense.h"
#include <cassert>
#include <iostream>

class TEST_EXPENSE {
public:
    TEST_EXPENSE() {
        reset();
    }
    static TEST_EXPENSE& get_instance() {
        static TEST_EXPENSE instance;
        return instance;
    }
    void test_add_expense() {
        test_system.add_expense("user2", ExpenseCategory::BILLS, 895);
        
        std::shared_ptr<Expense> expense = test_system.get_expense_top("user2");
        std::cout << expense;
        assert(expense->get_category() == ExpenseCategory::BILLS);
        assert(expense->get_price() == 895);
        reset();
    }
    void reset() {
        test_system = System();
        test_system.add_expense("user1",  ExpenseCategory::SHOPPING, 568);
    }
    void RUN_ALL_TESTS() {
        test_add_expense();
        std::cout << "Ran all test" << std::endl;
    }
private:
    System test_system;
};

int main() {
    TEST_EXPENSE::get_instance().RUN_ALL_TESTS();
    return 1;
}