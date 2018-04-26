//
// Created by mikolaj on 26.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>
#include <memory>

namespace utility{

    class IterableIterator{
    public:
        virtual std::pair<int, std::string> Dereference() const =0;
        virtual IterableIterator &Next() =0;
        virtual bool NotEquals(const std::unique_ptr<IterableIterator> &other) const =0;

};
    class Zipper{

    };

    class ZipperIterator: public IterableIterator
    {
    public:
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const std::unique_ptr<IterableIterator> &other) const override;
        explicit ZipperIterator(std::vector<int>::const_iterator left_begin, std::vector<std::string>::const_iterator right_begin, std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end);
    private:
        std::vector<int>::const_iterator left_begin_;
        std::vector<std::string>::const_iterator right_begin_;
        std::vector<int>::const_iterator left_end_;
        std::vector<std::string>::const_iterator right_end_;
    };

}


#endif //JIMP_EXERCISES_ITERABLE_H
