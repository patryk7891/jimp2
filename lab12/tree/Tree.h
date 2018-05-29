//
// Created by mikolaj on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>
#include <algorithm>
namespace tree
{
    template<class T>
    class Tree
    {
    public:

        std::unique_ptr<Tree<T>> left;
        std::unique_ptr<Tree<T>> right;
        T value;
        size_t size;
        size_t depth;

        Tree(){
            left = nullptr;
            right = nullptr;
            value = T();
            size = 0;
            depth = 0;
        }
        Tree(T val){
            left = nullptr;
            right = nullptr;
            value = val;
            size = 1;
            depth = 1;
        }


        void Insert(const T &e) {
            if(e < this->value)
            {
                if(left != nullptr){left ->Insert(e);}
                else{
                    std::unique_ptr<Tree<T>> newnode = std::make_unique<Tree<T>>();
                    newnode->right = nullptr;
                    newnode->left = nullptr;
                    newnode->value = e;
                    this->left = std::move(newnode);
                }
            }
            else
            {
                if(right != nullptr){right ->Insert(e);}
                else{
                    std::unique_ptr<Tree<T>> newnode = std::make_unique<Tree<T>>();
                    newnode->right = nullptr;
                    newnode->left = nullptr;
                    newnode->value = e;
                    this->right = std::move(newnode);
                }
            }
            size++;
        }


        size_t Depth(){
            if(this){
                return 1+ std::max(this->left->Depth(), this->right->Depth());
            }
            else
            {
                return 0;
            }
        }
        size_t Size(){return size;}

        T Value()
        {
            return value;
        }

        bool operator<(const Tree &other) const{
            return this->value < other.value;
        }

    };
}

#endif //JIMP_EXERCISES_TREE_H
