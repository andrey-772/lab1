#include <iostream>
#include <iomanip>

class Time {
public:
    // Конструктор
    Time();

    // Функції для встановлення часу
    void setTime(int, int, int);
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);

    // Функції для отримання часу
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Функції для виведення часу
    void printUniversal() const;
    void printStandard() const;

private:
    int hour;
    int minute;
    int second;
};

// Визначення методів
Time::Time() {
    hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}

// Set-функції з валідацією
void Time::setHour(int h) {
    hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m) {
    minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::setSecond(int s) {
    second = (s >= 0 && s < 60) ? s : 0;
}

// Get-функції (позначені як const, оскільки не змінюють стан об'єкта)
int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}

// Функції виведення часу
void Time::printUniversal() const {
    std::cout << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setw(2) << minute << ":" << std::setw(2) << second;
}

void Time::printStandard() const {
    std::cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << std::setfill('0') << std::setw(2) << minute << ":"
        << std::setw(2) << second << (hour < 12 ? " AM" : " PM");
}

int main() {
    Time t;

    // Використання Set-функцій
    t.setHour(10);
    t.setMinute(30);
    t.setSecond(45);

    std::cout << "Time set using individual Set functions: ";
    t.printStandard();
    std::cout << "\n";

    // Використання Get-функцій
    std::cout << "Hour: " << t.getHour() << "\n";
    std::cout << "Minute: " << t.getMinute() << "\n";
    std::cout << "Second: " << t.getSecond() << "\n";

    // Оголошення масиву об'єктів Time
    const int N = 3;
    Time timeArray[N];

    std::cout << "\nInitial values of the Time array:\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "Element " << i << ": ";
        timeArray[i].printStandard();
        std::cout << std::endl;
    }

    return 0;
}