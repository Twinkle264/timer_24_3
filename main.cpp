#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    tm timer;
    cout << "Input: ";
    cin >> get_time(&timer, "%M:%S");

    time_t t = time(nullptr);
    tm current_time = *localtime(&t);

    int seconds = timer.tm_min * 60 + timer.tm_sec;
    time_t tt = time(nullptr);
    time_t target = tt + seconds;
    tm target_time = *localtime(&target);

    while (mktime(&current_time) < mktime(&target_time)) {
        if (time(nullptr) > mktime(&current_time)) {
            if (timer.tm_sec == 0) {
                timer.tm_min -= 1;
                timer.tm_sec = 60;
                timer.tm_sec -= 1;
            } else {
                timer.tm_sec -= 1;
            }
            cout << "\r" << put_time(&timer, "%M:%S") << flush;
            time_t t_now = time(nullptr);
            current_time = *localtime(&t_now);
        }
    }

    cout << "\r" << "DING! DING! DING!";
    return 0;
}