#include <iostream>

class Personagem
{
private:
    int hp;
    int mp;
    std::string nome;
public:
    Personagem(int hp, int mp, std::string nome){
        this->hp=hp;
        this->mp=mp;
        this->nome=nome;
    }
    virtual int ataqueEspecial()=0;
    virtual int ataqueBasico()=0;
    
    virtual void regenOfAll(){
        setHp(getHp()*(double)10.0/100.0);
        setMp(getMp()*(double)10.0/100.0);
    }
    virtual void superRegen(){
        setHp(getHp()*(double)50.0/100.0);
        setMp(getMp()*(double)50.0/100.0);
    }
    int getHp(){
        return this->hp;
    }
    void setHp(int valorBonus){
        this->hp=hp+valorBonus;
    }
    int getMp(){
        return this->mp;
    }
    void setMp(int valorBonus){
        this->mp=mp+valorBonus;
    }
    std::string getNome(){
        return this->nome;
    }
};
