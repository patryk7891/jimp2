//
// Created by mikolaj on 18.03.18.
//

#include "SmartTree.h"

namespace datastructures
{
    std::unique_ptr<SmartTree> CreateLeaf(int value)
    {
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value = value;
        leaf->left= nullptr;
        leaf->right = nullptr;
        return leaf;
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
        tree->left = std::move(left_subtree);

        return tree;
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree)
    {
        tree->right= std::move(right_subtree);

        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out)
    {
        if (unique_ptr->left!=nullptr)
        {
            PrintTreeInOrder(unique_ptr->left, out);
        }
        *out<< unique_ptr->value;
        *out<<", ";
        if(unique_ptr->right!=nullptr)
        {
            PrintTreeInOrder(unique_ptr->right, out);
        }

    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        std::string ret="";

        ret+=("[" + std::to_string(tree->value)+" ");

        if(tree->left !=nullptr)
        {
            ret+=DumpTree(tree->left);
        }
        else
        {
            ret+= "[none]";
        }

        ret+= " ";

        if(tree->right !=nullptr)
        {
            ret+=DumpTree(tree->right);
        }
        else
        {
            ret+= "[none]";
        }
        ret+="]";

        return ret;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree)
    {

    }
}