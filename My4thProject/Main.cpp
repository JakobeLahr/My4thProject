/*
    Jakobe Lahr
    Computer Science FA_24
    Due: 10/29/24
    Lab 4: Lab 4 is a program to process a list of temps and organize them on
    a bar chart with the output being the bar chart with stars next to the numbers
    associated with the temperature values. 
*/

#include <iostream>
#include <fstream>
#include <iomanip>


class TemperatureChart {
private:
    static const int MIN_TEMP = -30;  
    static const int MAX_TEMP = 120;  
    static const int RANGE = (MAX_TEMP - MIN_TEMP) / 3 + 1;  //Numbers of lines for stars
    int counts[RANGE] = { 0 };  

public:
    //Read temperatures from a file
    void readTemperatures(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "Cannot open file!\n";
            return;
        }

        int temp;    //Ranges
        while (file >> temp) {
            if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
                int index = (temp - MIN_TEMP) / 3;
                counts[index]++;
            }
            else {
                std::cout << "Invalid temperature: " << temp << '\n';
            }
        }
    }

    //Display the temperature chart
    void displayChart() const {
        std::cout << "Temperatures for 24 hours:\n";
        std::cout << std::setw(4) << "-30" << std::setw(8) << "0"
                  << std::setw(8) << "30" << std::setw(8) << "60"
                  << std::setw(8) << "90" << std::setw(8) << "120\n";
        std::cout << std::string(50, '-') << '\n';

        for (int i = 0; i < RANGE; ++i) {    //Calculate Ranges
            if (counts[i] > 0) {
                int rangeStart = MIN_TEMP + (i * 3);
                std::cout << std::setw(4) << rangeStart << " | ";
                for (int j = 0; j < counts[i]; ++j) {
                    std::cout << '*';
                }
                std::cout << '\n';
            }
        }
    }
};

int main() {
    TemperatureChart chart;
    chart.readTemperatures("input.dat"); 
    chart.displayChart(); 

    return 0;
}
