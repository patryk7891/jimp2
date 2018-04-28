//
// Created by mikolaj on 26.04.18.
//

#include "Iterable.h"



namespace utility
{

    IterableIterator& ZipperIterator::Next()
    {
        ++left;
        ++right;
        return *this;
    }

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right,
                                   std::vector<int>::const_iterator left_end,
                                   std::vector<std::string>::const_iterator right_end)
    {
        this->left = left;
        this-> right = right;

    }

    ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                                   std::vector<std::string>::const_iterator right)
    {

        this->left = left;
        this->right = right;

    }

    std::pair<int, std::string> ZipperIterator::Dereference() const
    {
        return std::make_pair(*left, *right);
    };


    bool ZipperIterator::NotEquals(const std::unique_ptr<IterableIterator> &other) const {
        return ((right!=other->right) || (left!=other->left));
    }

    IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<IterableIterator> iterator) {
        iterator_=move(iterator);
    }

    bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
        return iterator_->NotEquals(other.iterator_);
    }

    std::pair<int, std::string> IterableIteratorWrapper::operator*()
    {
        return iterator_->Dereference();
    };

    IterableIteratorWrapper & IterableIteratorWrapper::operator++()
    {
        iterator_->Next();
        return *this;
    }

    IterableIteratorWrapper Iterable::cbegin() const
    {
        return IterableIteratorWrapper {ConstBegin()};
    }

    IterableIteratorWrapper Iterable::cend() const
    {
        return IterableIteratorWrapper {ConstEnd()};
    }


    IterableIteratorWrapper Iterable::begin() const
    {
        return cbegin();
    }

    IterableIteratorWrapper Iterable::end() const
    {
        return cend();
    }

    Zipper::Zipper(std::vector<int> vectorInt, std::vector<std::string> vectorString)
    {
        vInt_=vectorInt;
        vString_=vectorString;

        if (vInt_.size()>vString_.size())
        {
            for (auto i=vString_.size(); i<vInt_.size(); ++i)
            {
                vString_.emplace_back(vectorString.back());
            }
        }
        else
        {
            for (auto i = vInt_.size(); i < vString_.size(); ++i)
            {
                vInt_.emplace_back(vectorInt.back());
            }
        }
    }

    std::unique_ptr<IterableIterator> Zipper::ConstBegin() const
    {
        ZipperIterator zipperhelp (vInt_.begin(),vString_.begin());
        std::unique_ptr<IterableIterator> wsk = std::make_unique<ZipperIterator>(zipperhelp);
        return wsk;
    }

    std::unique_ptr<IterableIterator> Zipper::ConstEnd() const
    {
        ZipperIterator zipperhelp (vInt_.end(),vString_.end());
        std::unique_ptr<IterableIterator> wsk = std::make_unique<ZipperIterator>(zipperhelp);
        return wsk;
    }


    Enumerate::Enumerate(std::vector<std::string> vectorString)
    {
        vString_ = vectorString;
        for(int i = 1; i<=vString_.size(); ++i)
        {
            vInt_.emplace_back(i);
        }
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstBegin() const
    {
        ZipperIterator enumerhelp (vInt_.begin(),vString_.begin());
        std::unique_ptr<IterableIterator> wsk = std::make_unique<ZipperIterator>(enumerhelp);
        return wsk;
    }

    std::unique_ptr<IterableIterator> Enumerate::ConstEnd() const
    {
        ZipperIterator enumerhelp (vInt_.end(),vString_.end());
        std::unique_ptr<IterableIterator> wsk = std::make_unique<ZipperIterator>(enumerhelp);
        return wsk;
    }

    Product::Product(std::vector<int> vectorInt, std::vector<std::string> vectorString) {

        for (auto x : vectorInt)
        {
            for(auto y: vectorString)
            {
                vInt_.emplace_back(x);
                vString_.emplace_back(y);
            }
        }
    }
    std::unique_ptr<IterableIterator> Product::ConstBegin() const
    {
        ZipperIterator producthelp (vInt_.begin(),vString_.begin());
        std::unique_ptr<IterableIterator> wsk = std::make_unique<ZipperIterator>(producthelp);
        return wsk;
    }

    std::unique_ptr<IterableIterator> Product::ConstEnd() const
    {
        ZipperIterator producthelp (vInt_.end(),vString_.end());
        std::unique_ptr<IterableIterator> wsk = std::make_unique<ZipperIterator>(producthelp);
        return wsk;
    }

}