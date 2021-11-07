#pragma once
#include "Heure.h"
namespace Time {
    class DateH : public Heure
    {
    private:
        int jour;
        int mois;
        int annee;
    public:
        DateH(int h, int m, int s, int j, int mo, int a);
        void afficher() const;
        bool operator>(DateH h)const;
        bool validerjour(int j)const;
    };

}

