#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Todolist {
public:
    vector<string> tasks;

    void completed(int data) {
        if (data >= 1 && data <= tasks.size()) {
            tasks[data - 1] += " (COMPLETED)";
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
        printTasks();
    }

    void addWork(const string& date, const string& work, bool isPriority) {
        string task = date + " : " + work;
        if (isPriority) {
            task += " (PRIORITY)";
        }
        tasks.push_back(task);
        cout << "Task added successfully." << endl;
    }

    void removeTask(int pos) {
        if (pos >= 1 && pos <= tasks.size()) {
            tasks.erase(tasks.begin() + pos - 1);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid position." << endl;
        }
        printTasks();
    }

    void printTasks() {
        cout << "The list of tasks is: " << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ") " << tasks[i] << endl;
        }
    }
};

int main() {
    Todolist list;

    int times = 0;
    cout << "Enter how many times you want to add tasks: ";
    cin >> times;
    cin.ignore(); // Consume the newline character

    while (times > 0) {
        string time;
        cout << "Enter the time: ";
        getline(cin, time);

        string work;
        cout << "Enter the work needed to be added: ";
        getline(cin, work);

        bool isPriority = false;
        cout << "Is it a priority task? (1 for yes, 0 for no): ";
        cin >> isPriority;
        cin.ignore(); // Consume the newline character

        list.addWork(time, work, isPriority);
        times--;
    }

    list.printTasks();

    int pos;
    cout << "Enter the position of the task to be removed: ";
    cin >> pos;
    cin.ignore(); // Consume the newline character

    list.removeTask(pos);

    int complte;
    cout << "Enter the number of the task to mark it as completed: " << endl;
    cin >> complte;
    cin.ignore(); // Consume the newline character

    list.completed(complte);

    return 0;
}
