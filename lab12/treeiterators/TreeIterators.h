//
// Created by mikolaj on 01.06.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H


#include <memory>
#include <algorithm>
#include "../tree/Tree.h"

namespace tree
{
    template <class T>
    class TreeIterator {
    public:
        TreeIterator(){numb=0;};
        TreeIterator(Tree<T> *root){this->root = root; numb=0;};
        Tree<T>*root;
        int numb;
        std::vector<T> nodes;
        void operator++(){this->numb++;};
        T operator*(){return nodes[numb];};
        bool operator!=(const TreeIterator&x)const{return this->numb !=x.numb;};

        virtual void BuildVector(Tree<T> *node)=0;
        const void PushBack(const T new_val){nodes.emplace_back(new_val);};
    };

    template <class T>
    class InOrderTreeIterator: public TreeIterator<T> {
    public:
        void BuildVector(Tree<T>*node)override{
            if(node->left!= nullptr){
                BuildVector(node->left.get());
            }
            this->PushBack(node->value);
            if(node->right!= nullptr){
                BuildVector(node->right.get());
            }
        }
        InOrderTreeIterator(){};
        InOrderTreeIterator(Tree<T>*node){
            BuildVector(node);
        }
    };

    template <class T>
    class InOrderTreeView{
    public:
        InOrderTreeView(){};
        InOrderTreeView(Tree<T> * root){tree_iterator=root;};
        InOrderTreeIterator<T> begin(){tree_iterator.numb=0; return tree_iterator; };
        InOrderTreeIterator<T> end(){tree_iterator.numb = int(tree_iterator.nodes.size()); return tree_iterator;};
        InOrderTreeIterator<T> tree_iterator;
    };

    template <class T>
    InOrderTreeView<T> InOrder(Tree<T> *root)
    {
        return InOrderTreeView<T>(root);
    }

//POST
    template <class T>
    class PostOrderTreeIterator: public TreeIterator<T> {
    public:
        void BuildVector(Tree<T>*node)override{
            if(node->left!= nullptr){
                BuildVector(node->left.get());
            }
            if(node->right!= nullptr){
                BuildVector(node->right.get());
            }
            this->PushBack(node->value);

        }
        PostOrderTreeIterator(){};
        PostOrderTreeIterator(Tree<T>*node){
            BuildVector(node);
        }
    };

    template <class T>
    class PostOrderTreeView{
    public:
        PostOrderTreeView(){};
        PostOrderTreeView(Tree<T> * root){tree_iterator=root;};
        PostOrderTreeIterator<T> begin(){tree_iterator.numb=0; return tree_iterator; };
        PostOrderTreeIterator<T> end(){tree_iterator.numb = int(tree_iterator.nodes.size()); return tree_iterator;};
        PostOrderTreeIterator<T> tree_iterator;
    };

    template <class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *root)
    {
        return PostOrderTreeView<T>(root);
    }

    //PRE
    template <class T>
    class PreOrderTreeIterator: public TreeIterator<T> {
    public:
        void BuildVector(Tree<T>*node)override{
            this->PushBack(node->value);
            if(node->left!= nullptr){
                BuildVector(node->left.get());
            }
            if(node->right!= nullptr){
                BuildVector(node->right.get());
            }

        }
        PreOrderTreeIterator(){};
        PreOrderTreeIterator(Tree<T>*node){
            BuildVector(node);
        }
    };

    template <class T>
    class PreOrderTreeView{
    public:
        PreOrderTreeView(){};
        PreOrderTreeView(Tree<T> * root){tree_iterator=root;};
        PreOrderTreeIterator<T> begin(){tree_iterator.numb=0; return tree_iterator; };
        PreOrderTreeIterator<T> end(){tree_iterator.numb = int(tree_iterator.nodes.size()); return tree_iterator;};
        PreOrderTreeIterator<T> tree_iterator;
    };

    template <class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *root)
    {
        return PreOrderTreeView<T>(root);
    }
}

#endif //JIMP_EXERCISES_TREEITERATORS_H
