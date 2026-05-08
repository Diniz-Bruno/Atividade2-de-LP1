#include<iostream>

class Veiculo{
private:
    bool comCombustivel;
    bool comEnergia;
public:
    Veiculo(){};
    void setComCombustivel(){
        this->comCombustivel=false;
        this->comEnergia=false;
    }
    virtual ~Veiculo() {}
    void setComCombustivel(bool a){
        this->comCombustivel=a;
    }

    void setComEnergia(bool b){
        this->comEnergia=b;
    }
    virtual void alimentarComFonteDeEnergia()=0;
    virtual void preparararViagem(double valorEnergetico)=0;

};

class CarroCombustao: public Veiculo{
    private:
        double quantidadeDeGasolina=0;
        double capacidadeDoTanque;
    public:
        CarroCombustao(double capacidadeMax): Veiculo(){
            this->capacidadeDoTanque=capacidadeMax;
        }
        double getQuantidadeDeGasolina(){
            return this->quantidadeDeGasolina;
        }
        void setQuantidadeDeGasolina(double litrosColocados){
            if(getQuantidadeDeGasolina()+litrosColocados>getCapacidadeDoTanque()){
                std::cout<<"Não é póssivel abastecer isso tudo de gasolina, irá transborda"<<std::endl;
            }else if(litrosColocados<0){
                std::cout<<"Não é póssivel retirar gasolina no tanque"<<std::endl;
            }else{
                this->quantidadeDeGasolina+=litrosColocados;
                std::cout<<"você abasteceu o carro com "<< litrosColocados<<" Litros, no total, o carro ficou com "<<getQuantidadeDeGasolina()<<" Litros no tanque de combustivel"<<std::endl;
            }
        }
        double getCapacidadeDoTanque(){
            return this->capacidadeDoTanque;
        }
        void preparararViagem(double gasolinaColocada){
            setComCombustivel(true);
            setQuantidadeDeGasolina(gasolinaColocada);
            alimentarComFonteDeEnergia();
        }
        void alimentarComFonteDeEnergia() override{
            std::cout<<"Carro abastecido!"<<std::endl;
        }
};

class CarroEletrico:public Veiculo{
    private:
        double quantidadeDeVolts=0;
        double capacidadeDaBateria;
    public:
        CarroEletrico(double capacidadeMax):Veiculo(){
            this->capacidadeDaBateria=capacidadeMax;
        }
        double getQuantidadeDeVolts(){
            return this->quantidadeDeVolts;
        }
        double getCapacidadeDeBateria(){
            return this->capacidadeDaBateria;
        }

        void setQuantidadeDeVolts(double energiaColocada){
            if(getQuantidadeDeVolts()+energiaColocada>getCapacidadeDeBateria()){
                std::cout<<"Não é póssivel carregar isso tudo de energia, irá desperdiçar"<<std::endl;
            }else if(energiaColocada<0){
                std::cout<<"Não é póssivel retirar energia no tanque"<<std::endl;
            }else{
                this->quantidadeDeVolts+=energiaColocada;
                std::cout<<"você carregou o carro com "<< energiaColocada<<" Volts, no total, o carro ficou com "<<getQuantidadeDeVolts()<<" Volts na bateria do carro"<<std::endl;
            }
        }
        void preparararViagem(double energiaColocada){
            setComEnergia(true);
            setQuantidadeDeVolts(energiaColocada);
            alimentarComFonteDeEnergia();
        }
        void alimentarComFonteDeEnergia() override{
            std::cout<<"Carro carregado!"<<std::endl;
        }
};


/*
Resposta da questão na implementação do anunciado é inadequada porque quando ele chama o método PrepararViagem ira roda metodo de abastecer do objeto pai(no caso, o Carro),devido ser um metodo virtual retornando um algoritimo padrão, no caso uma mensagem de sucesso ao abastecer, e se na situação que é passado um objeto CarroEletrico, irá aparecer essa mensagem de sucesso e a versão transcrita no próprio objeto CarroEletrico com a excessão de erro ao abastecer, resumindo dando uma contradição ao usar essa implementação. Logo, a solução é criar um objeto pai e trascrever o metodo para um objeto carro e outro carroEletrico  
*/
int main(void)
{
    Veiculo* meuKwid = new CarroCombustao(40.0); // 40 Litros
    Veiculo* eletrico = new CarroEletrico(220.0); // 220 Volts

    std::cout << "*** Preparando Viagem 1 ***" << std::endl;
    meuKwid->preparararViagem(20.0);

    std::cout << "\n*** Preparando Viagem 2 ***" << std::endl;
    eletrico->preparararViagem(100.0);

    // Graças ao seu destrutor virtual, o delete aqui é seguro!
    delete meuKwid;
    delete eletrico;

    return 0;
}
