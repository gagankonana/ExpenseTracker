#ifndef LIBRARY_EXPENSE_TRACKER_EXPENSE_H
#define LIBRARY_EXPENSE_TRACKER_EXPENSE_H

/*
Design and implement an expense tracking system in C++. The system should allow users to manage their expenses with the following functionalities:

requiremnts:
    expense tracking system
    add expense
    delete expense 
    list expenses
    update expense
    get total expense

questions:
    how will the user choose an expense? based on the id or the title?
    do we need to store deleted expense in case user needs to undo?
    What will expense info contain? what can users edit on it? : 

classes:
    Expense
        id, desc, categpory, amount, date
    User
        username, other info
    System
        unordered_map<username, expense>

*/

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

enum ExpenseCategory {
    SHOPPING,
    BILLS,
    TRANSPORT
};

class Expense {
public:
    Expense(int _id, const ExpenseCategory _category, const float& _price) : 
        id{_id}, price{_price}, category(_category) {}
    void set_price(const float& _price) { price = _price; }
    void set_category(const ExpenseCategory _category) { category = _category; }
    [[nodiscard]] const float get_price() noexcept { return price; }
    [[nodiscard]] const int get_id() noexcept { return id; }
    [[nodiscard]] const ExpenseCategory get_category() noexcept { return category; }
    friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<Expense> expense);
 private:
    int id;
    ExpenseCategory category;
    float price;
};

std::ostream& operator<< (std::ostream& out, const std::shared_ptr<Expense> expense) {
    out << expense->id << ": " << expense->price << " (" << expense->category << ")" << std::endl;
    return out; 
}

class System {
public:
    System() {}
    void add_expense(const std::string& username, ExpenseCategory _category, const float& _price) {
        std::shared_ptr<Expense> expense = std::make_shared<Expense>(id++, _category, _price);
        expenses[username].push_back(expense);
    }
    [[nodiscard]] const std::vector<std::shared_ptr<Expense>> get_expenses(const std::string& username) noexcept { return expenses[username]; }
    [[nodiscard]] const std::shared_ptr<Expense> get_expense_top(std::string username) { return expenses[username].back(); }
private:
    static inline int id = 0;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Expense>>> expenses;
};

#endif