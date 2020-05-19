#ifndef Sotrudnik_h
#define Sotrudnik_h

#pragma once
#include <iostream>
#include <string>
#include <list>
class Sotrudnik{
    std::string name;
    std::string post;
    std::string department;
    double salary;
    double prizesize;
    double tax;
public:
    Sotrudnik(){
        salary = prizesize = tax = 0;
        post = name = department = "Not known";
    }
    Sotrudnik(std::string n, std::string p){
        name = n;
        post = p;
        department = "Not known";
        salary = 0;
        prizesize = 0;
        tax = 13;
    }
    Sotrudnik(std::string n, std::string p, double s){
        name = n;
        post = p;
        department = "Not known";
        salary = s;
        prizesize = 0;
        tax = 13;
    }
    Sotrudnik(std::string n, std::string p, double s, double prsize){
        name = n;
        post = p;
        department = "Not known";
        salary = s;
        prizesize = prsize;
        tax = 13;
    }
    std::string get_name(){
        return name;
    }
    std::string get_post(){
        return post;
    }
    double get_factsalary(){
        double f;
        f = salary*(1-tax/100);
        return f;
    }
    double get_salary(){
        return salary;
    }
    void set_department(std::string d){
        department = d;
    }
    std::string get_department(){
        return department;
    }
    double get_prize(){
        return prizesize;
    }
    void set_salary(double s){
        salary = s;
    }
    void set_post(std::string p){
        post = p;
    }
    void set_prize(double prsize){
        if (prizesize == 0) prizesize = prsize;
        else prizesize += prsize;
    }
    ~Sotrudnik(){
    }
    friend std::ostream& operator<<(std::ostream& out, Sotrudnik& S);
};
std::ostream& operator<<(std::ostream& out, Sotrudnik& S){
    out <<std::endl << "Collaborator " << S.name << "," << "post: " << S.post << "," <<S.name <<"'s salary = " << S.salary << "," << "prize = " << S.prizesize <<std::endl;
    return out;
    }

#endif /* Sotrudnik_h */
