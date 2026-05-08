#include"Classes.cpp"

Personagem* seletorDeClasse(void){
    int option;
    bool errara=true;
    while (errara){
        errara=false;
        std::cout<<"Qual Personagem você irá escolher?"<<std::endl;
        std::cout<<"1-Guerreiro\n"<<"2-Arqueiro\n"<<"3-Mago"<<std::endl;
        std::cin>>option;
        switch (option){
        case 1:{
            int mana=0,vida=0;
            while(mana+vida!=120){
                std::cout<<"Por favor administre para sua vida e mana entre 120 pontos"<<std::endl;
                std::cout<<"vida:";
                std::cin>>vida;
                std::cout<<"Mana:";
                std::cin>>mana;
            }    
            std::cout<<"Personagem guerreiro criado!"<<std::endl;

            return new Guerreiro(vida,mana);
            break;
            }

        case 2:{
            int mana=0,vida=0;
            while(mana+vida!=110){
                std::cout<<"Por favor administre para sua vida e mana entre 110 pontos"<<std::endl;
                std::cout<<"vida:";
                std::cin>>vida;
                std::cout<<"Mana:";
                std::cin>>mana;
            }
            
            std::cout<<"Personagem Arqueiro criado!"<<std::endl;
            return new Arqueiro(vida,mana);
            break;
            }
        case 3:{
            int mana=0,vida=0;
            while(mana+vida!=100){
                std::cout<<"Por favor administre para sua vida e mana entre 100 pontos"<<std::endl;
                std::cout<<"vida:";
                std::cin>>vida;
                std::cout<<"Mana:";
                std::cin>>mana;
            }
            std::cout<<"Personagem Mago criado!"<<std::endl;
            return new Mago(vida,mana);
            break;
            }
        default:
            errara=true;
            std::cout<<"Opção invalida,tente novamente"<<std::endl;
            break;
        }
    }
    return nullptr;
}
Personagem* seletorMonstro(){
    bool errara=true;
    int option;
    while(errara){
        errara=false;
        std::cout<<"Qual Monstro vc quer enfrentar?"<<std::endl;
        std::cout<<"1-Goblin(Fácil)\n"<<"2-Orc(Medio)\n"<<"3-Ogro(dificil)"<<std::endl;
        std::cin>>option;
        switch (option){
        case 1:
            std::cout<<"Monstro selecionado com sucesso"<<std::endl;
            return new Goblin(80,60);
            break;
        case 2:
            std::cout<<"Monstro selecionado com sucesso"<<std::endl;
            return new Orc(120,30);
            break;
        case 3:
            std::cout<<"Monstro selecionado com sucesso"<<std::endl;    
            return new Ogro(200,20);
            break;
        default:
            errara=true;
            std::cout<<"Opção invalida,tente novamente"<<std::endl;
            break;
        }
    }
    return nullptr;
}


int main(void){
    bool continuaJogo=true;
    Personagem* personagem=seletorDeClasse();
    std::cout<<"Você tem "<<personagem->getHp()<<" de vida e "<<personagem->getMp()<<" de mana somando os seus bônus de classe\n*******************"<<std::endl;
    Personagem* monstro=seletorMonstro();
    std::cout<<"****************************************"<<std::endl;
        std::cout<<"\n Ao adentrar na dungeon, você percebe um túnel, ao pecorrer longos metros com armadilhas e uma escuridão tenebrosa... você se da de frente com um enorme "<<monstro->getNome()<<" protegendo um tesouro. Ele nota sua presença e caminha pra cima de te\n"<<std::endl;
    while (personagem->getHp()>=1 && continuaJogo){
        bool erro=true;
        int escolha;
        while (erro){
            erro=false;
            std::cout<<"Você tem "<<personagem->getHp()<<" de vida e "<<personagem->getMp()<<" de mana"<<std::endl;
            std::cout<<"Escolha oque você irá fazer:\n1-ataque basico\n2-ataque especial\n3-regenera vida e mana"<<std::endl;
            std::cin>>escolha;
            switch (escolha){
            case 1:{
                int dano= personagem->ataqueBasico(); 
                if (personagem->getMp()<0){
                    personagem->setMp(5);
                    std::cout<<"Mago, sua mana ainda esta carregando, espere sua mana carrega para executar esse movimento, tente algo de novo"<<std::endl;
                    erro=true;
                    break;
                }
                monstro->setHp(-dano);
                std::cout<<"você deu "<<dano<<" de dano e o "<<monstro->getNome()<< " ficou com "<<monstro->getHp()<< " de vida"<<std::endl;
                break;
                }
            case 2:{
                if(personagem->getMp()*0.15<=0){
                    std::cout<<"seu ataque especial ainda esta carregando, espere sua mana carrega para executar esse movimento, tente algo de novo"<<std::endl;
                    erro=true;
                    break;
                }
                int dano= personagem->ataqueEspecial();    
                monstro->setHp(-dano);
                std::cout<<"você deu "<<dano<<" de dano com o seu ataque especial o "<<monstro->getNome()<< " ficou com "<<monstro->getHp()<< " de vida"<<std::endl;
                break;
                }
            case 3:{
                int antesHp = personagem->getHp();
                int antesMp = personagem->getMp();
                personagem->superRegen();
                std::cout<<"Vocễ gastou o seu turno se curando\nAgora você está com "<<(personagem->getHp()-antesHp)<<" de vida e "<<(personagem->getMp()-antesMp)<<" de mana"<<std::endl;
                break;
                }
            default:
                std::cout<<"Opção invalida,tente novamente"<<std::endl;
                erro=true;
                break;
            }   
        }
        if(monstro->getHp()<=0){
            continuaJogo=false;
            std::cout<<"Você conseguiu! derrotou o "<<monstro->getNome()<<" e consegue por as mãos no tesouro e ficou rico!!\n\n OBRIGADO POR JOGA!!"<<std::endl;
            break;
        }
        std::cout<<"\n\nTurno do "<<monstro->getNome()<<std::endl;
        if(monstro->getMp()>=20){
            int dano=monstro->ataqueEspecial();
            personagem->setHp(-dano);
            std::cout<<"O monstro ferozmente ataca você com tudo, usando o seu ataque ESPECIAL! te dando "<<dano<<" de dano, fazendo você fica com "<<personagem->getHp()<<" de vida"<<std::endl;
        }else{
            int dano=monstro->ataqueBasico();
            personagem->setHp(-dano);
            std::cout<<"O monstro te ataca enfurecidamente, usando o seu ataque BÁSICO! te dando "<<dano<<" de dano, fazendo você fica com "<<personagem->getHp()<<" de vida"<<std::endl;
        }
        if (personagem->getHp()<=0){
            std::cout<<"\n\ninfelizmente sua historia chegou até aqui, esse último golpe foi fatal... \n OBRIGADO POR JOGA!"<<std::endl;
            continuaJogo=false;
            break;
        }else{
            int hpAntes = personagem->getHp();
            int mpAntes = personagem->getMp();
            personagem->regenOfAll();
            std::cout<<"Após toma um fortissimo dano, você gasta mais das suas energias para aguentar nesse duelo, regenerando "<< (personagem->getHp()-hpAntes)<<" de vida e "<< (personagem->getMp()-mpAntes)<<" de mana"<< std::endl; 
        }
        std::cout<<"Assim começando um novo turno de golpes...\n"<<std::endl;
    } 
    return 0;
}