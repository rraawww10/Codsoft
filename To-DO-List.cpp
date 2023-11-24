#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description;
                if (tasks[i].completed) {
                    cout << " (Completed)";
                } else {
                    cout << " (Pending)";
                }
                cout << endl;
            }
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Marked task as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Removed task: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList todo;
    char choice;

    do {
        cout << "\nTodo List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string taskDescription;
                cin.ignore();
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
            }
            case '2':
                todo.viewTasks();
                break;
            case '3': {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markAsCompleted(index);
                break;
            }
            case '4': {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            }
            case '5':
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.";
        }
    } while (choice != '5');

    return 0;
}
