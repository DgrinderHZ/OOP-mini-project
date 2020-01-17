#ifndef H_DATE
#define H_DATE
#include<iostream>
using namespace std;

class Date{

public:
    int jour;
    int mois;
    int annee;

public:
    bool operator==(Date& d){
        bool res = (jour == d.jour);
        res = res && (mois == d.mois) && (annee == d.annee);
        return res;
    }

    friend bool operator<(const Date& d, const Date& dd){
            if (d.annee < dd.annee) return true;
            else if (d.annee > dd.annee) return false;
            else if (d.mois < dd.mois) return true;
            else if (d.mois > dd.mois) return false;
            else if (d.jour < dd.jour) return true;
            else return false;
    }
    friend istream& operator>>(istream& is, Date& d){
            cout << "Jour: << "; cin >> d.jour;
            cout << "Mois: << "; cin >> d.mois;
            cout << "Annee: << "; cin >> d.annee;
    return is;
    }

    void affiche(){
        cout<< jour << "/" << mois << "/" << annee;
    }
};


#endif // H_DATE


/* FIRST codE
class Date{
    int jour;
    int mois;
    int annee;
public:
    bool operator==(Date& d){
        bool res = (jour == d.jour);
        res = res && (mois == d.mois) && (annee == d.annee);
        return res;
    }

    bool operator<(const Date& d){
        if (annee < d.annee) return true;
        else if (annee > d.annee) return false;
        else if (mois < d.mois) return true;
        else if (mois > d.mois) return false;
        else if (jour < d.jour) return true;
        else return false;
    }
    friend bool operator<(const Date& d, const Date& dd);
    friend istream& operator>>(istream& is, Date& d);

    void affiche(){
        cout<< jour << "/" << mois << "/" << annee;
    }
};

bool operator<(const Date& d, const Date& dd){
        if (d.annee < dd.annee) return true;
        else if (d.annee > dd.annee) return false;
        else if (d.mois < dd.mois) return true;
        else if (d.mois > dd.mois) return false;
        else if (d.jour < dd.jour) return true;
        else return false;
}

istream& operator>>(istream& is, Date& d){
        cout << "Jour: "; cin >> d.jour;
        cout << "Mois: "; cin >> d.mois;
        cout << "Annee: "; cin >> d.annee;
return is;
}
*/
