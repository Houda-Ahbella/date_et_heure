#pragma once
namespace Time {
	class Heure
	{
	protected:
		int heure;
		int minute;
		int seconde;
	public:
		Heure(int h = 0, int m = 0, int s = 0);
		void afficher()const;
		int converttosec() const;
		bool operator>( Heure h)const;
	};
}


