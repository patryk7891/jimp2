//
// Created by mikolaj on 04.05.18.
//

#include "MovieSubtitles.h"


namespace moviesubs
{
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out)
    {
        int ile = (offset_in_micro_seconds / 1000.0) * frame_per_second;
        if (ile < 0)
        {
            throw NegativeFrameAfterShift();
        }

        std::string ret = "";
        std::string content{std::istreambuf_iterator<char>(*in), std::istreambuf_iterator<char>()};
        std::regex pattern{
                R"((\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?(\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?(\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?(\{[0-9]+\}\{[0-9]+\}\{?[a-zA-Z:0-9\$\s]+\}?[a-zA-Z\s0-9!\|]+\n?)?)"};
        std::smatch matches;
        regex_match(content, matches, pattern);
        for (int i = 1; i < 10; i++) {
            if (matches[i] == "") {
                if (i == 1) {
                    throw InvalidSubtitleLineFormat();
                }
                break;
            } else {
                std::string cont = matches[i];

                std::regex patterny{R"(\{([0-9]+)\}\{([0-9]+)\}([a-zA-Z\s\{\}:0-9\$!\|]+)\n?)"};
                std::smatch matches1;
                regex_match(cont, matches1, patterny);
                if (std::stoi(matches1[1]) > std::stoi(matches1[2])) {
                    std::string str = matches[i];
                    throw SubtitleEndBeforeStart(i, str.substr(0, str.length() - 1));
                }
                ret += "{" + std::to_string((std::stoi(matches1[1]) + ile)) + "}" + "{" +
                       std::to_string((std::stoi(matches1[2]) + ile)) + "}" + matches1[3].str();
            }
        }

        *out << ret;
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out)
    {
        int ile = offset_in_micro_seconds;
        int curr_fram_numb=0;

        std::string ret = "";
        std::string content{std::istreambuf_iterator<char>(*in), std::istreambuf_iterator<char>()};
        std::regex pattern{
                R"(([0-9]\n[0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9][0-9][0-9] \-\-> [0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9][0-9][0-9]\n[a-zA-Z\s'\?\.\-]+\n?[a-zA-Z\s'\?\.\-]+\n\n?)?([0-9]\n[0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9][0-9][0-9] \-\-> [0-9][0-9]:[0-9][0-9]:[0-9][0-9],[0-9][0-9][0-9]\n[a-zA-Z\s'\?\.\-]+\n?[a-zA-Z\s'\?\.\-]+\n\n?)?)"};
        std::smatch matches;
        regex_match(content, matches, pattern);
        for (int i = 1; i < 10; i++) {

            if (matches[i] == "") {
                    if (i == 1) {
                        throw InvalidSubtitleLineFormat();
                    }
                break;

            } else {
                std::string cont = matches[i];

                std::regex patterny{
                        R"(([0-9])\n([0-9][0-9]):([0-9][0-9]):([0-9][0-9]),([0-9][0-9][0-9]) \-\-> ([0-9][0-9]):([0-9][0-9]):([0-9][0-9]),([0-9][0-9][0-9])\n([a-zA-Z\s'\?\.\-]+\n?[a-zA-Z\s'\?\.\-])+\n\n?)"};
                std::smatch matches1;
                regex_match(cont, matches1, patterny);

                int nr = stoi(matches1[1]);
                int g1 = stoi(matches1[2]);
                int m1 = stoi(matches1[3]);
                int s1 = stoi(matches1[4]);
                int t1 = stoi(matches1[5]);
                int g2 = stoi(matches1[6]);
                int m2 = stoi(matches1[7]);
                int s2 = stoi(matches1[8]);
                int t2 = stoi(matches1[9]);

                if(nr != (curr_fram_numb+1))
                {
                    throw OutOfOrderFrames();
                }

                curr_fram_numb = nr;

                std::string txt = matches1[10];

                t1 += ile;
                if (t1 > 999) {
                    s1 += 1;
                    t1 = t1 % 1000;

                }
                t2 += ile;
                if (t2 > 999) {
                    s2 += 1 ;
                    t2 = t2 % 1000;

                }

                std::string str = matches[i];
                str = str.substr(2, str.length()-1);
                str = str.substr(0, str.find('\n'));

                if(g1>g2)
                {
                    throw SubtitleEndBeforeStart(nr, str);
                }
                else if(g1==g2&&m1>m2){
                    throw SubtitleEndBeforeStart(nr, str);
                }
                else if(g1==g2&&m1==m2&&s1>s2)
                {
                    throw SubtitleEndBeforeStart(nr, str);
                }
                else if(g1==g2&&m1==m2&&s1==s2&&t1>t2)
                {
                    throw SubtitleEndBeforeStart(nr, str);
                }

                std::string snr = std::to_string(nr);
                std::string sg1 = std::to_string(g1);
                if (g1 < 10) {
                    sg1.insert(0, "0");
                }
                std::string sm1 = std::to_string(m1);
                if (m1 < 10) {
                    sm1.insert(0, "0");
                }
                std::string ss1 = std::to_string(s1);
                if (s1 < 10) {
                    ss1.insert(0, "0");
                }
                std::string st1 = std::to_string(t1);
                if (t1 < 100 && t1 > 9) {
                    st1.insert(0, "0");
                }
                if (t1 < 10) {
                    sg1.insert(0, "00");
                }
                std::string sg2 = std::to_string(g2);
                if (g2 < 10) {
                    sg2.insert(0, "0");
                }
                std::string sm2 = std::to_string(m2);
                if (m2 < 10) {
                    sm2.insert(0, "0");
                }
                std::string ss2 = std::to_string(s2);
                if (s2 < 10) {
                    ss2.insert(0, "0");
                }
                std::string st2 = std::to_string(t2);
                if (t2 < 100 && t1 > 9) {
                    st2.insert(0, "0");
                }



                ret += snr + "\n" + sg1 + ":" + sm1 + ":" + ss1 + "," + st1 + " --> " + sg2 + ":" + sm2 + ":" + ss2 +
                       "," + st2 + "\n" + txt + "\n";

            }


        }
        if (ile < 0) {
            throw NegativeFrameAfterShift();
        }
        if (frame_per_second<0)
        {
            throw NegativeFrameAfterShift();
        }
        *out << ret;
    }
}


