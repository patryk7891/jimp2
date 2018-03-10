#include "GreatestProduct.h"
int GreatestProduct(const std::vector<int> &numbers, int k)
{/*
    int max1=0, max2=0;
    for (int v : numbers)
    {
        if (v>max1)
        {
            max2=max1;
            max1=v;
        }
        else if (v>max2)
        {
            max2=v;
        }
    }

    return max1*max2;
}
int GreatestProduct(const std::vector<int> &numbers, int k)
{*/
    int min=-1, wiekszy_min=-3,mniejszy_max=-3, max=-3, maxujemna=-1, prawiemaxujemna=1;
    for (int v : numbers)
    {
        if (v>max)
        {
            min=wiekszy_min;
            wiekszy_min=mniejszy_max;
            mniejszy_max=max;
            max=v;
        }
        else if (v>mniejszy_max)
        {
            min=wiekszy_min;
            wiekszy_min=mniejszy_max;
            mniejszy_max=v;
        }
        else if (v>wiekszy_min)
        {
            min=wiekszy_min;
            wiekszy_min=v;
        }
        else if (v>min)
        {
            min=v;
        }
        else if(v<maxujemna)
        {
            prawiemaxujemna=maxujemna;
            maxujemna=v;
        }
        else if(v<prawiemaxujemna)
        {
            prawiemaxujemna=v;
        }

    }
    if (k==2)
    {
        wiekszy_min=1;
        min=1;
    }
    if (k==3)
    {
        min=1;
    }
    if(k==2 and numbers.size()==3 and max>0 and mniejszy_max>0)
    {
        return max*mniejszy_max;
    }
    if (k==2 and numbers.size()==2)
    {
        if(max*mniejszy_max>maxujemna*prawiemaxujemna)
        {
            return max*mniejszy_max;
        } else
        {
            return maxujemna*prawiemaxujemna;
        }
    }
    if (max*mniejszy_max>maxujemna*prawiemaxujemna)
    {
        if (k==4)
        {
            return max*mniejszy_max*wiekszy_min*min;
        }
        else if(k==3)
        {
            return max*mniejszy_max*wiekszy_min;
        }
        else if (k==2)
        {
            return max*mniejszy_max;
        }
    }
    else
    {
        if (k==3 and max>0)
        {
            return maxujemna*prawiemaxujemna*max;

        }
        else if(k==3 and max<0)
            return max*mniejszy_max*wiekszy_min;
        else if(k==2)
        {
            return maxujemna*prawiemaxujemna;
        }
    }
}