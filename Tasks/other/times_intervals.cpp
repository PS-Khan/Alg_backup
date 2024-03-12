#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> find_pa_times(const std::vector<std::pair<int, int>> &classes) {
    //vector for result
    std::vector<int> announcementTimes;
    //sorted classes
    std::vector<std::pair<int, int>> sortedClasses(classes.begin(), classes.end());
    std::sort(sortedClasses.begin(), sortedClasses.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
    { 
        return a.second < b.second;
    });
    /* ....
        ....
          ....
            .....
             ....
                  ...
                     ..
     */
    for(auto const &par : sortedClasses){
        std::cout << par.first << " " << par.second << std::endl;
    }
    
    int lastEndTime = -1;
    for (const auto &classTime : sortedClasses) {
        if (classTime.first > lastEndTime) {
            announcementTimes.push_back(classTime.second);
            lastEndTime = classTime.second;
        }
    }
    


    return announcementTimes;
}

int main(){
   
    std::vector<std::pair<int, int>> classes = {
        {1, 3},
        {4, 6},
        {5, 7},
        {2, 4},
        {8, 11},
        {6, 7},
        {9, 12},
        {3, 5}
    };
    
   
    std::vector<int> optimalAnnouncementTimes = find_pa_times(classes);

    std::cout << "Optimal Announcement Times: ";
    for (int time : optimalAnnouncementTimes) {
        std::cout << time << " ";
    }
    std::cout << std::endl;


    return 0;
}