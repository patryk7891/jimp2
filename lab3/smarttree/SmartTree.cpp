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

    int WhenDivide(const std::string str)
    {
        int l=0;
        int r=0;
        for(int i=0; i<str.size(); i++)
        {
            if (str[i]=='[')
            {
                l++;
            }
            if (str[i]==']')
            {
                r++;
            }

            if((l==r&&l!=0))
            {
                return i;
            }
        }

        return 0;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree)
    {
        std::string strin = tree;
        if(strin[0]=='[')
        {
            strin.erase(0,1);
        }

        if(strin[strin.size()-1]==']')
        {
            strin.erase(strin.size()-1, 1);
        }

        std::regex pattern {R"((\-?\d+|[a-z]+)\s?(.*)?)"};
        std::smatch matches;
        std::regex_match(strin, matches, pattern);

        std::unique_ptr<SmartTree> parent = std::make_unique<SmartTree>();

        if(matches[1]=="none")
        {
            return nullptr;
        }
        else
        {
            parent = CreateLeaf(std::stoi(matches[1]));
        }

        strin = matches[2];

        const std::string str2 = strin.substr(0, WhenDivide(strin)+1);
        const std::string str3 = strin.substr(WhenDivide(strin)+3, strin.size());


        parent->left = RestoreTree(str2);
        parent->right = RestoreTree(str3);

        return parent;

    }
}