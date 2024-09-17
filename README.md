# Expense Management System

## Overview

This project provides a basic system for managing and tracking expenses. It supports categorizing expenses and associating them with different users.

## How to Use

1. **Include the Header File**
2. **Create and Manage Expenses**:
   - Instantiate a `System` object to handle expenses.
   - Use the `add_expense` method to add expenses for a user.

3. **Retrieve Expenses**:
   - Call `get_expenses` to get a list of expenses for a specific user.
   - Use `get_expense_top` to retrieve the most recent expense for a user.

## Example

```cpp
#include "ExpenseSystem.h"

int main() {
    System system;

    // Add expenses for a user
    system.add_expense("Alice", SHOPPING, 50.0f);
    system.add_expense("Alice", BILLS, 30.0f);

    // Retrieve and display all expenses for the user
    auto expenses = system.get_expenses("Alice");
    for (const auto& expense : expenses) {
        std::cout << expense;
    }

    return 0;
}
```

## Notes
Expenses are categorized using the ExpenseCategory enum.
The system assigns a unique ID to each expense.
For more details, refer to the class definitions in the header file.