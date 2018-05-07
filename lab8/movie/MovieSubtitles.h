//
// Created by mikolaj on 04.05.18.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>       // std::string
#include <iostream>     // std::cout
#include <ostream>
#include <sstream>
#include <regex>
#include <stdexcept>



namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void
        ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out)=0;

        ~MovieSubtitles() = default;

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void
        ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out);
    };

    class SubtitlesException : public std::invalid_argument {
    public:
        SubtitlesException() = default;

        SubtitlesException(int num_line, std::string line_text) : std::invalid_argument{
                "At line " + std::to_string(num_line) + ": " + line_text} {};
    };

    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift() : SubtitlesException(0, "") {};

        NegativeFrameAfterShift(int num_line, std::string line_text) : SubtitlesException(num_line, line_text) {};
    };

    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
        SubtitleEndBeforeStart() : SubtitlesException(0, "") {};

        SubtitleEndBeforeStart(int num_line, std::string line_text) : SubtitlesException(num_line,
                                                                                         line_text) { num_val = num_line; };
        int num_val;

        int LineAt() const { return num_val; };

    };

    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        InvalidSubtitleLineFormat() : SubtitlesException(0, "") {};

        InvalidSubtitleLineFormat(int num_line, std::string line_text) : SubtitlesException(num_line, line_text) {};

    };

    class OutOfOrderFrames : public SubtitlesException {
    public:
        OutOfOrderFrames() : SubtitlesException(0, "") {};

        OutOfOrderFrames(int num_line, std::string line_text) : SubtitlesException(num_line, line_text) {};
    };

    class MissingTimeSpecification : public SubtitlesException {
    public:
        MissingTimeSpecification() : SubtitlesException(0, "") {};

        MissingTimeSpecification(int num_line, std::string line_text) : SubtitlesException(num_line, line_text) {};
    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        void
        ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out);
    };
}




#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
