#include <iostream>
#include <string.h>
using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;


public:
	Data(int dia, int mes, int ano)
	{
		this->dia = dia;
		this->mes = mes;
		this->ano = ano;
	}

	Data()
	{
		this->dia = 28;
		this->mes = 9;
		this->ano = 1962;
	}

	void setDia(int dia)
	{
		this->dia = dia;
	}

	void setMes(int mes)
	{
		this->mes = mes;
	}

	void setAno(int ano)
	{
		this->ano = ano;
	}

	int getDia()
	{
		return this->dia;
	}

	int getMes()
	{
		return this->mes;
	}

	int getAno()
	{
		return this->ano;
	}

	string getData()
	{
		return to_string(this->dia) + "/" +
			   to_string(this->mes) + "/" +
			   to_string(this->ano);
	}
};

class Contato
{
private:
	string email;
	string nome;
	string telefone;
	Data dtnasc;

public:
	Contato(string nome, string email, string telefone, Data *data)
	{
		this->nome = nome;
		this->email = email;
		this->telefone = telefone;
		this->dtnasc = *data;
	}

	void setNome(string nome)
	{
		this->nome = nome;
	}

	string getNome()
	{
		return this->nome;
	}

	void setEmail(string email)
	{
		this->email = email;
	}

	string getEmail()
	{
		return this->email;
	}

	void setTelefone(string telefone)
	{
		this->telefone = telefone;
	}

	string getTelefone()
	{
		return this->telefone;
	}

	void setData(Data data)
	{
		this->dtnasc = data;
	}

	Data getData()
	{
		return this->dtnasc;
	}

	int idade()
	{
		return 2022 - dtnasc.getAno();
	}
};

int main()
{
    int idade;
	double soma_idade=0;
	Contato *contatos[3];
	Data *datas[3];

	string nome = "";
	string email = "";
	string telefone = "";
	int dia = 0;
	int mes = 0;
	int ano = 0;
	int cont_maior_idade=0;
	double media = 0;
	int mais_velho=0;
	
/*
	contatos[0]=new Contato("nome1", "email1", "fone1", new Data(1,1,1980));
	contatos[1]=new Contato("nome2", "email2", "fone2", new Data(1,1,1990));
	contatos[2]=new Contato("nome3", "email3", "fone3", new Data(1,1,1990));
*/	
	
	for (int i = 0; i < 3; ++i)
	{

		
		cout << "---- CADASTRANDO CONTATO ----" << endl;
		cout << "Digite um nome:  ";
		cin >> nome;

		cout << "Digite um email: ";
		cin >> email;

		cout << "Digite um telefone: ";
		cin >> telefone;

		cout << "Digite o dia de nascimento: ";
		cin >> dia;

		cout << "Digite o mes de nascimento: ";
		cin >> mes;

		cout << "Digite o ano de nascimento: ";
		cin >> ano;

		datas[i] = new Data(dia, mes, ano);
		contatos[i] = new Contato(nome, email, telefone, datas[i]);
		
		 
		soma_idade = soma_idade + contatos[i]->idade(); 
		media = ((soma_idade)/2);

		
	}

	
	cout << "---- CONTATOS COM IDADE ACIMA DA MÉDIA ----" << endl;
		
	for (int i = 0; i < 3; ++i)
	{
	
		
		if (contatos[i]->idade()>media){
		
		cout << "Nome: " << contatos[i]->getNome() << endl;
	//	cout << "Email: " << contatos[i]->getEmail() << endl;
	//	cout << "Telefone: " << contatos[i]->getTelefone() << endl;
	//	cout << "Idade: " << contatos[i]->idade() << endl;
	//	cout << endl;	
		}	
		
			
		if(contatos[i]->idade()>=18){
			
			cont_maior_idade ++;
			
		}
		
	}	
		cout << "Soma idades: " << soma_idade <<endl; 
		cout << "A media das idades e: " << media << endl;
		cout << "A quantidade de maiores e: " << cont_maior_idade <<endl;

		
		mais_velho = contatos[0]->idade(); // define o primeiro como mais velho
		
		
	
cout << "---- CONTATOS MAIS VELHOS ----" << endl;	
	for (int i = 1; i < 3; ++i)
	{
		if(contatos[i]->idade()>mais_velho){
			mais_velho = contatos[i]->idade(); 
		}
	}
	

	for (int i = 0; i < 3; ++i)
	{
		if(contatos[i]->idade()==mais_velho){
            cout << "Nome: " << contatos[i]->getNome() << endl;
	 		cout << "Email: " << contatos[i]->getEmail() << endl;
	  	   	cout << "Telefone: " << contatos[i]->getTelefone() << endl;
			cout << endl;

		}
	}
	
		

	return 0;

}




