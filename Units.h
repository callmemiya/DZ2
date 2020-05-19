#ifndef Units_h
#define Units_h
#pragma once
#include <iostream>
#include <string>
#include <list>
class Units{
    std::string title;
    int sotrcount;
    double finance;
    std::list<Sotrudnik> Sotr;
public:
    Units(){
        title = "Not known";
        sotrcount = 0;
        finance = 0;
    }
    Units(std::string t){
        title = t;
        sotrcount = 0;
        finance = 0;
    }
    Units(std::string t, int count, double f){
        title = t;
        sotrcount = count;
        finance = f;
    }
    void add(Sotrudnik& S){
        S.set_department(title);
        Sotr.push_back(S);
        sotrcount++;
    }
    int get_countofsotr(){
        if (Sotr.empty()) return sotrcount;
        else return static_cast<int>(Sotr.size());
    }
    double allsalaries(){
        double s = 0;
        for (std::list<Sotrudnik>::iterator it = Sotr.begin(); it != Sotr.end(); it++){
            s += (it->get_prize() + it->get_salary());
        }
        return s;
    }
    double get_tax(){
        double t;
        t = allsalaries()*13/100;
        return t;
    }
    double get_reserve(){
        double r;
        r = finance - allsalaries();
        return r;
    }
    void set_finance(double f){
        finance = f;
    }
    void print_all_sotr(){
        std::cout <<std::endl;
        for (std::list<Sotrudnik>::iterator it = Sotr.begin(); it != Sotr.end(); it++){
            std::cout << it->get_name() <<", " <<it->get_department() <<", " <<it->get_post() <<", " <<it->get_salary()  <<", " << it->get_prize() <<std::endl;
        }
    }
    void dismissal(Sotrudnik &S){
        for (std::list<Sotrudnik>::iterator it = Sotr.begin(); it != Sotr.end(); it++){
            if (it->get_name() == S.get_name() && (it->get_post() == S.get_post())) Sotr.erase(it);
        }
    }
    Units operator+=(Sotrudnik &S){
        sotrcount++;
        S.set_department(title);
        Sotr.push_back(S);
        return *this;
    }
    Units& operator=(Units &U){
        sotrcount = U.sotrcount;
        finance = U.finance;
        Sotr = U.Sotr;
        return *this;
    }
    Units& operator+(Units &S){
        title = "Union";
        finance += S.finance;
        for (std::list<Sotrudnik>::iterator it = S.Sotr.begin(); it != S.Sotr.end(); it++){
            Sotr.push_back(*it);
        }
        sotrcount += S.sotrcount;
        return *this;
    }
    Units operator+(Sotrudnik &S){
        S.set_department(title);
        Sotr.push_back(S);
        sotrcount++;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& out, Units &S);
};
std::ostream& operator<<(std::ostream& out, Units &S){
    out <<std::endl << "Unit " << S.title << ": " << S.sotrcount << " collaborators, " << " finance of unit: " << S.finance <<", reserve for unexpected purpose: "<< S.get_reserve() << std::endl;
    return out;
    }

#endif /* Units_h */
