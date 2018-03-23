//
// Created by mikolaj on 23.03.18.
//

#include "SimpleTemplateEngine.h"


namespace nets
{
    View::View(std::string szablon)
    {
        text = szablon;
    }
    View::~View(){};

    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const
    {
        std::string text1 = text;
        std::string curr;
        std::string next;
        std::string look_for;
        std::string text2="";
        size_t position;
        size_t position2;
        size_t length_cut;

        for (auto p : model)
        {
            text2="";
            curr = p.first;
            next = p.second;

            look_for = "{{" + curr + "}}";

        while(text2!=text1)
        {
            text2=text1;
            position = text1.find(look_for);

            if(position>text1.size() || position<0)
            {
                break;
            }

            text1.replace(position, look_for.size(), next);
            }


        }

        text2="";
        int change=0;
        while(text2!=text1 || change!=1)
        {
            text2=text1;
            look_for = "{{";
            position = text1.find(look_for);

            if(position>text1.size() || position<0)
            {
                break;
            }

            look_for = "}}";
            position2 = text1.find(look_for);

            if(position2>text1.size() || position2<0)
            {
                break;
            }

            length_cut = position2-position+2;

            for(int i=position; i<position2; i++)
            {
                if(text1[i]==' ')
                {
                    change=1;
                    break;
                }
            }

            if(change==1)
            {
                break;
            }

            text1.erase(position, length_cut);



        }

        return text1;


    }

}