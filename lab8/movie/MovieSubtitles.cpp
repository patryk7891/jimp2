//
// Created by mikolaj on 04.05.18.
//

#include "MovieSubtitles.h"


namespace moviesubs
{
    void  MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out)
    {
        int ile = (offset_in_micro_seconds/1000.0)*frame_per_second;
        if(ile <0)
        {
            throw NegativeFrameAfterShift();
        }
        std::string ret = "";
        std::string content{ std::istreambuf_iterator<char>(*in), std::istreambuf_iterator<char>() };
        std::regex pattern {R"((\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?(\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?(\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?(\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?)"};
        std::smatch matches;
        regex_match(content, matches, pattern);
        for(int i=1; i<10; i++)
        {
            if(matches[i]=="")
            {
                if (i==1)
                {
                    throw InvalidSubtitleLineFormat();
                }
                break;
            }
            else
            {
                std::string cont = matches[i];

                std::regex patterny {R"(\{([0-9]+)\}\{([0-9]+)\}([a-zA-Z\s\{\}:0-9\$!\|]+)\n?)"};
                std::smatch matches1;
                regex_match(cont, matches1, patterny);
                if (std::stoi(matches1[1]) > std::stoi(matches1[2]))
                {
                    std::string str = matches[i];
                    throw SubtitleEndBeforeStart(i, str.substr(0,str.length()-1));
                }
                ret += "{"+std::to_string((std::stoi(matches1[1])+ile)) + "}" + "{"+std::to_string((std::stoi(matches1[2])+ile)) + "}" + matches1[3].str();
            }
        }

        *out << ret;
    }

}