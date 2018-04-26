//
// Created by mikolaj on 26.04.18.
//

#include "Iterable.h"



namespace utility{

    IterableIterator& ZipperIterator::Next()
    {
        left_begin_++;
        right_begin_++;
        return *this;
    }

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left_begin, std::vector<std::string>::const_iterator right_begin, std::vector<int>::const_iterator left_end, std::vector<std::string>::const_iterator right_end){
        left_begin_ = left_begin;
        right_begin_ = right_begin;
        left_end_ = left_end;
        right_end_ = right_end;
    }
    std::pair<int, std::string> ZipperIterator::Dereference() const
    {

        std::pair<int, std::string> parka = std::make_pair(*left_begin_, *right_begin_);
        return parka;
    };

    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const
    {
        return this->Dereference() != other->Dereference() ;
    }

}