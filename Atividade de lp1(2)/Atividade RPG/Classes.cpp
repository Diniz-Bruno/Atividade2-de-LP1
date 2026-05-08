#include"Personagem.cpp"

class Guerreiro :public Personagem{
private:
public:
    Guerreiro(int hp, int mp): Personagem(hp+40, mp,"Guerreiro"){
        
    }
    int ataqueEspecial() override{
        setMp(-(getMp()*(double)(15.0/100.0)));
        return getHp()*(double)(35.0/100.0);
    }
    void regenOfAll() override{
        setHp(getHp()*(double)15.0/100.0);
        setMp(getMp()*(double)10.0/100.0);
    };    
    int ataqueBasico()override{
        return 8;
    }
};

class Arqueiro:public Personagem{
private:
public:
    Arqueiro(int hp, int mp): Personagem(hp+20, mp+10,"Arqueiro"){
        
    }
    int ataqueEspecial() override{
        setMp(-(getMp()*(double)(15.0/100.0)));
        return (getHp()*(double)(10.0/100.0))+(getMp()*(double)(10.0/100.0));
    }
    int ataqueBasico()override{
        return 10;
    }
};

class Mago: public Personagem{
private:
public:
    Mago(int hp, int mp): Personagem(hp, mp+50,"Mago"){
        
    }
    int ataqueEspecial() override{
        setMp(-(getMp()*(double)(15.0/100.0)));
        return getMp()*(double)(40.0/100.0);
    }
    int ataqueBasico()override{
        setMp(-5);
        return 15;
    }
    void regenOfAll() override{
        setHp(getHp()*(double)10.0/100.0);
        setMp(getMp()*(double)15.0/100.0);
    };
};

//inimigos

class Ogro:public Personagem{
private:
public:
    Ogro(int hp,int mp):Personagem(hp,mp,"Ogro"){};
    int ataqueEspecial() override{
        setMp(-20);
        return getHp()*(double)(60.0/100.0);
    }
    int ataqueBasico()override{
        return 15;
    }
    
    void regenOfAll() override{
        setMp(getMp()*(double)20.0/100.0);
    };
};

class Orc:public Personagem{
private:
public:
    Orc(int hp,int mp):Personagem(hp,mp,"Orc"){};
    int ataqueEspecial() override{
        setMp(-20);
        return getHp()*(double)(30.0/100.0);
    }
    int ataqueBasico()override{
        return 10;
    }
    void regenOfAll() override{
        setMp(getMp()*(double)10.0/100.0);
    };
};


class Goblin:public Personagem{
private:
public:
    Goblin(int hp,int mp):Personagem(hp,mp,"Goblin"){};
    int ataqueEspecial() override{
        setMp(-20);
        return getMp()*(double)(80.0/100.0);
    }
    int ataqueBasico()override{
        return 8;
    }
    void regenOfAll() override{
        setMp(getMp()*(double)20.0/100.0);
    };
};