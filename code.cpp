#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> todoList;

// Function to add a task to the list
void addTask(string description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    todoList.push_back(newTask);
    cout << "Task added to the to-do list." << endl;
}

// Function to view tasks
void viewTasks() {
    if (todoList.empty()) {
        cout << "To-do list is empty." << endl;
    } else {
        cout << "To-do List:" << endl;
        for (int i = 0; i < todoList.size(); i++) {
            cout << i + 1 << ". ";
            if (todoList[i].completed) {
                cout << "[Completed] ";
            }
            cout << todoList[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < todoList.size()) {
        todoList[taskIndex].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task
void removeTask(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < todoList.size()) {
        todoList.erase(todoList.begin() + taskIndex);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;

        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                addTask(description);
                break;
            }
            case 2: {
                viewTasks();
                break;
            }
            case 3: {
                cout << "Enter the task number to mark as completed: ";
                int taskIndex;
                cin >> taskIndex;
                markTaskAsCompleted(taskIndex - 1); // Subtract 1 for 0-based index
                break;
            }
            case 4: {
                cout << "Enter the task number to remove: ";
                int taskIndex;
                cin >> taskIndex;
                removeTask(taskIndex - 1); // Subtract 1 for 0-based index
                break;
            }
          
          default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
    return 0;
}
