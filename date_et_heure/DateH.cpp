#include "DateH.h"
#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

Time::DateH::DateH(int h, int m, int s, int j = 0, int mo = 0, int a = 0)
	:Heure(h, m, s)
{
	if (a > 1900)
	{
		this->annee = a;
		if (mo > 0 && mo < 13)
		{
			this->mois = mo;

			int mois_a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

			if (((this->annee % 4 == 0)&&(this->annee!=0))||(this->annee%400==0) )  mois_a[1] = 29;

			if (j > 0 && mois_a[this->mois - 1] >= j) this->jour = j;
			else
			{
				this->jour = 0;
				this->mois = 0;
				this->annee = 0;
			}
		}
		else
		{
			this->mois = 0;
			this->jour = 0;
			this->annee = 0;
		}
	}
	else
	{
		this->mois = 0;
		this->jour = 0;
		this->annee = 0;
	}
}


	

	
void Time::DateH::afficher() const
{
	this->Heure::afficher();
	if (this->annee == 0)
		cout << "il y un erreur dans le remplissage de la date\n";
	cout << this->jour << "/" << this->mois << "/" << this->annee << endl;
}

bool Time::DateH::operator>(DateH h) const
{
	bool res=false;
	
	if (this->annee > h.annee)res = true;
	else if (this->annee == h.annee) {
		if (this->mois > h.mois) res = true;
		else if (this->mois == h.mois)
		{
			if (this->jour > h.jour) res = true;
			else if (this->jour == h.jour)
			{
				res=this->Heure::operator>(h);
			}
		}
		
	}
	return res;
}
bool Time::DateH::validerjour(int j) const
{
	if (this->mois > 0 && this->mois < 13)
	{
		int mois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (mois[this->mois - 1] >= j &&  j>0 ) return true;
	}
	return false;
}



