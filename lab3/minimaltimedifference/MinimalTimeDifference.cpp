//
// Created by mikolaj on 11.03.18.
//

#include "MinimalTimeDifference.h"

namespace minimaltimedifference
{
    unsigned int ToMinutes(std::string time_HH_MM)
    {
        unsigned int sum=0;

        std::regex pattern {R"((\d{1,2}):(\d{2}))"};
        const char* line = time_HH_MM.c_str();
        std::cmatch matches;
        regex_match(line, matches, pattern);

        sum+=stoi(matches[1])*60;
        sum+=stoi(matches[2]);

        return sum;
    }

    unsigned int MinimalTimeDifference(std::vector<std::string> times)
    {

        unsigned int minimal_time=1440;
        unsigned int x;
        unsigned int y;

        int distance_x_y;
        for(std::string v: times)
        {
            for(std::string k: times)
            {
                x = ToMinutes(v);
                y = ToMinutes(k);

                distance_x_y = abs(x-y);

                if(distance_x_y < (1440 - distance_x_y) && distance_x_y > 0 && distance_x_y<minimal_time)
                {
                    minimal_time=distance_x_y;
                }
                else if(distance_x_y>0 && 1440-distance_x_y < minimal_time)
                {
                    minimal_time=1440-distance_x_y;
                }

            }
        }

        return minimal_time;
    }
}


