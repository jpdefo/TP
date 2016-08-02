#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define tamc 30
#define tamd 30
#define tamv 30

struct client
{
    int id;
    string nome;
    string endereco;
    string email;
    long long int telefone;
};
client cliente[tamc];

struct destiny
{
    int id;
    string local;
    string pais;
    int numlocais;
    double custo;
};
destiny destino[tamd];

struct deslocamento
{
    int mes;
    int dia;
    int id;
};
struct voyage
{
    int id;
    int tamdes;
    int tamcli;
    deslocamento des[tamd];
    int idcli[tamc];
    double custo;
};
voyage viagem[tamv];

//Funções:
//Menus:
void menua();
void menuc();
void menud();
void menuv();

//Arquivo:
void openf();
void savef();
void openfd();
void savefd();
void openfv();
void savefv();
void openr();

//Módulo Admin:
void exportacao();
void importacao();
void reinicializacao();
void sair();

//Módulo Cliente:
void insercaoc();
void remocaoc();
void alteracaoc();
void consultac();
void listagemc();

//Modulo destino:
void insercaod();
void remocaod();
void alteracaod();
void consultad();
void listagemd();

//Modulo viagem:
void insercaov();
void remocaov();
void alteracaov();
void consultav();
void inscricaov();
void desistenciav();
void listagemv();
void relatoriov();
bool des(int x);
bool cli(int x);

//Modulo
int n=0;
int d=0;
int v=0;
int main()
{
    menua();
    return 0;
}

//Módulo Cliente:
void menua()
{
    int a;
    cout << "1 - Exportacao: Armazena todos os dados armazenados em memoria no sistema de arquivos" << endl;
    cout << "2 - Importacao: Obtem os dados armazenados no sistema de arquivos armazenando-os em memoria"<< endl;
    cout << "3 - Reinicializacao: Volta ao estado inicial da aplicacao" << endl;
    cout << "4 - Acessar menu cliente" << endl;
    cout << "5 - Acessar menu destino" << endl;
    cout << "6 - Acessar menu viagem" << endl;
    cout << "7 - Sair: Encerra a aplicacao" << endl;
    cin >> a;
    switch(a)
    {
    case 1:
        savef();
        savefd();
        savefv();
        cout << "Arquivos exportados com sucesso" << endl;
        menua();
        break;
    case 2:
        openf();
        openfd();
        openfv();
        cout << "Arquivos importados com sucesso" << endl;
        menua();
        break;
    case 3:
        openr();
        cout << "Arquivos reinicializados" << endl;
        menua();
    case 4:
        menuc();
        break;
    case 5:
        menud();
        break;
    case 6:
        menuv();
        break;
    case 7:
        cout << endl << "1 - Exportacao: Pressione para salvar os arquivos antes de finalizar" << endl;
        cout << "2 - Pressione para finalizar e perder os dados" << endl;
        cin >> a;
        if(a=1)
        {
        savef();
        savefd();
        savefv();
        return;
        }
        return;
    }
}
void menuc()
{
    int a;
    cout << "1 - Insercao: Cadastro de novo cliente" << endl;
    cout << "2 - Remocao: Exclusao de um cliente" << endl;
    cout << "3 - Alteracao: Ateracao dos dados de um cliente" << endl;
    cout << "4 - Consulta: Consulta dados de um cliente" << endl;
    cout << "5 - Listagem: Lista de todos os clientes" << endl;
    cout << "0 - Voltar ao menu administrador" << endl;
    cin >> a;
    switch(a)
    {
    case 1:
        insercaoc();
        break;
    case 2:
        remocaoc();
        break;
    case 3:
        alteracaoc();
        break;
    case 4:
        consultac();
        break;
    case 5:
        listagemc();
        break;
    case 0:
        menua();
        break;
    }
}

void menud()
{
    int a;
    cout << "1 - Insercao: Cadastro de um novo destino" << endl;
    cout << "2 - Remocao: Exclusao de um destino" << endl;
    cout << "3 - Alteracao: Alteracao de dados de um destino" << endl;
    cout << "4 - Consulta: Consulta de dados de um destino" << endl;
    cout << "5 - Lista dados de todos os destinos" << endl;
    cout << "0 - Voltar ao menu administrador" << endl;
    cin >> a;
    switch (a)
    {
    case 1:
        insercaod();
        break;
    case 2:
        remocaod();
        break;
    case 3:
        alteracaod();
        break;
    case 4:
        consultad();
        break;
    case 5:
        listagemd();
        break;
    case 0:
        menua();
        break;
    }
}
void menuv()
{
    int a;
    cout << "1 - Insercao: Cadastro de uma nova viagem" << endl;
    cout << "2 - Remocao: Exclusao de uma viagem" << endl;
    cout << "3 - Alteracao: Alteracao de dados de uma viagem" << endl;
    cout << "4 - Consulta: Consulta dados de uma viagem" << endl;
    cout << "5 - Inscricao: Inscricao de cliente em viagem" << endl;
    cout << "6 - Desistencia: Remocao de cliente em viagem" << endl;
    cout << "7 - Listagem: Lista de todas as viagens por data" << endl;
    cout << "8 - Relatorio: Relatorio sumarizado de viagens" << endl;
    cout << "0 - Voltar ao menu administrador" << endl;
    cin >> a;
    switch (a)
    {
    case 1:
        insercaov();
        break;
    case 2:
        remocaov();
        break;
    case 3:
        alteracaov();
        break;
    case 4:
        consultav();
        break;
    case 5:
        inscricaov();
        break;
    case 6:
       desistenciav();
       break;
    case 7:
        listagemv();
        break;
    case 8:
        relatoriov();
        break;
    case 0:
        menua();
        break;
    }
}

void insercaoc()
{
    int a;
    cout << "Id Do cliente:" << endl;
    cin >> cliente[n].id;
    a=0;
    for(int i=0; i<n; i++)
    {
        if(cliente[n].id == cliente[i].id)
        {
            cout << "Cliente ja cadastrado" << endl << endl;
            a=1;
        }
    }
    if(a==0)
    {
        cout << "Nome do cliente: ";
        getline(cin,cliente[n].nome);
        getline(cin,cliente[n].nome);
        cout << "Endereco do cliente: ";
        getline(cin,cliente[n].endereco);
        cout << "Email do cliente: ";
        getline(cin,cliente[n].email);
        cout << "Telefone do cliente: ";
        cin >> cliente[n].telefone;
        cout << "Cliente inserido" << endl << endl;
        n=n+1;
    }
    menuc();
}

void remocaoc()
{
    int a;
    cout << "ID do cliente a ser removido: ";
    cin >> a;
    for(int i=0; i<n; i++)
    {
        if(cliente[i].id==a)
        {
            for(int j=i; j<n; j++)
            {
                cliente[j]=cliente[j+1];
            }
            a=0;
            n = n-1;
            cout << "Cliente removido" << endl;
        }
    }
    if(a!=0)
    {
        cout << "Cliente inexistente" << endl<< endl;
    }
    menuc();
}

void alteracaoc()
{
    int a, c;
    cout <<"Digite o ID do cliente: ";
    cin >> a;
    for(int i=0; i<n; i++)
    {
        if(cliente[i].id == a)
        {
            do
            {
                cout << "1 - Alteracao do nome do cliente" << endl;
                cout << "2 - Alteracao do endereco do cliente" << endl;
                cout << "3 - Alteracao do email do cliente" << endl;
                cout << "4 - Alteracao do telefone do cliente" << endl;
                cout << "0 - Finalizar alteracoes" << endl;
                cin >> c;
                switch(c)
                {
                case 0:
                    break;
                case 1:
                    cout << "Digite o novo nome: ";
                    getline(cin,cliente[i].nome);
                    getline(cin,cliente[i].nome);
                    break;
                case 2:
                    cout << "Digite o novo endereco: ";
                    getline(cin,cliente[i].endereco);
                    getline(cin,cliente[i].endereco);
                    break;
                case 3:
                    cout << "Digite o novo email: ";
                    getline(cin,cliente[i].email);
                    getline(cin,cliente[i].email);
                    break;
                case 4:
                    cout << "Digite o novo telefone: ";
                    cin >> cliente[i].telefone;
                    break;
                }
            }
            while(c!=0);
        }
    }
    cout << endl;
    menuc();
}

void consultac()
{
    int a, s=0;
    cout << "Id do cliente: ";
    cin >> a;
    for(int i=0; i<n; i++)
    {
        if(cliente[i].id == a)
        {
            cout << "Nome: " << cliente[i].nome << endl;
            cout << "Endereco: " << cliente[i].endereco << endl;
            cout << "Email: " << cliente[i].email << endl;
            cout << "Telefone: " << cliente[i].telefone << endl;
            s=1;
        }
    }
    if(s==0)
    {
        cout << "Cliente inexistente" << endl;
    }
    cout << endl;
    menuc();
}

void  listagemc()
{
    for(int i=0; i<n; i++)
    {
        cout << "ID: " << cliente[i].id << endl;
        cout << "Nome: " << cliente[i].nome << endl;
        cout << "Endereco: " << cliente[i].endereco << endl;
        cout << "Email: " << cliente[i].email << endl;
        cout << "Telefone: " << cliente[i].telefone << endl;
        cout << endl;
    }
    if(n<=0)
    {
        cout << "Nao ha clientes cadastrados" << endl;
    }
    cout << endl;
    menuc();
}

void insercaod()
{
    int s=0;
    cout << "ID do destino: ";
    cin >> destino[d].id;
    for(int i=0; i<d; i++)
    {
        if(destino[d].id == destino[i].id)
        {
            cout << "Viagem já cadastrada" << endl;
            s=1;
        }
    }
    if(s==0)
    {
        cout << "Localidade: ";
        getline(cin,destino[d].local);
        getline(cin,destino[d].local);
        cout << "Pais: ";
        getline(cin,destino[d].pais);
        cout << "Numero de locais a visitar: ";
        cin >> destino[d].numlocais;
        cout << "Custo total: ";
        cin >> destino[d].custo;
        cout << "Viagem inserida" << endl << endl;
        d=d+1;
    }
    cout << endl;
    menud();
}

void remocaod()
{
    int a;
    cout << "ID do destino a ser removido: ";
    cin >> a;
    for(int i=0; i<d; i++)
    {
        if(destino[i].id==a)
        {
            for(int j=i; j<n; j++)
            {
                destino[j]=destino[j+1];
            }
            a=0;
            d = d-1;
            cout << "Destino removido" << endl;
        }
    }
    if(a!=0)
    {
        cout << "Destino inexistente" << endl<< endl;
    }
    menud();
}

void alteracaod()
{
    int a, c;
    cout << "ID do destino: ";
    cin >> a;
    for(int i=0; i<d; i++)
    {
        if(destino[i].id == a)
        {
            do
            {
                cout << "1 - Alteracao do local de destino" << endl;
                cout << "2 - Alteracao do pais de destino" << endl;
                cout << "3 - Alteracao do numero de locais de destino" << endl;
                cout << "4 - Alteracao do custo total de destino" << endl;
                cout << "0 - Finalizar alteracoes" << endl;
                cin >> c;
                switch(c)
                {
                case 0:
                    menud();
                    break;
                case 1:
                    cout << "Digite o novo local: ";
                    getline(cin,destino[i].local);
                    getline(cin,destino[i].local);
                    break;
                case 2:
                    cout << "Digite o novo pais: ";
                    getline(cin,destino[i].pais);
                    getline(cin,destino[i].pais);
                    break;
                case 3:
                    cout << "Digite o novo numero de locais: ";
                    cin >> destino[i].numlocais;
                    break;
                case 4:
                    cout << "Digite o novo custo: ";
                    cin >> destino[i].custo;
                    break;
                }
            }
            while(c!=0);
        }
    }
    cout << endl;
    menud();
}

void consultad()
{
    int a, s=0;
    cout << "Id de destino: ";
    cin >> a;
    for(int i=0; i<d; i++)
    {
        if(destino[i].id == a)
        {
            cout << "Local: " << destino[i].local << endl;
            cout << "Pais: " << destino[i].pais << endl;
            cout << "Numero de locais: " << destino[i].numlocais << endl;
            cout << "Custo: " << destino[i].custo << endl;
            s=1;
        }
    }
    if(s==0)
    {
        cout << "Destino Inexistente" << endl;
    }
    cout << endl;
    menud();
}

void listagemd()
{
    for(int i=0; i<d; i++)
    {
        cout << "ID: " <<destino[i].id<< endl;
        cout << "local: " << destino[i].local << endl;
        cout << "Pais: " << destino[i].pais << endl;
        cout << "Numero de locais: " << destino[i].numlocais << endl;
        cout << "Custo: " << destino[i].custo << endl;
        cout << endl;
    }
    if(d<=0)
    {
        cout << "Nao ha viagens cadastrados" << endl;
    }
    cout << endl;
    menud();
}

void insercaov()
{
    int qtdexec, qtdexec2, s=0, a;
    viagem[v].custo=0;
    cout << "Digite o ID da viagem: ";
    cin >> viagem[v].id;
    for(int i=0; i<=v; i++)
    {
        while(viagem[i].id==viagem[i+1].id)
        {
            cout << "Viagem ja cadastrada" << endl;
            cin >> viagem[v].id;
            s=1;
        }
    if(s==0)
    {
        int id;
        viagem[v].custo=0;
        cout << "Digite o numero de destinos: ";
        cin >> viagem[v].tamdes;
        for(int m=0; m<viagem[v].tamdes; m++)
        {
            cout << "Digite o ID do destino: ";
            cin >> id;
            while(!cli(id))
            {
                cout << "Digite o ID do destino: ";
                cin >> id;
            }
            viagem[m].id=id;
            cout << "Digite o MES da viagem ";
            cin >> viagem[v].des[m].mes;
            while(viagem[v].des[m].mes<1 || viagem[v].des[m].mes>12)
            {
                cout << "Mes invalido " << endl;;
                cout << "Digite o MES da viagem ";
                cin >> viagem[v].des[m].mes;
            }
            cout << "Digite o DIA da viagem: ";
            cin >> viagem[v].des[m].dia;
            switch(viagem[v].des[m].mes)
            {
            case 1:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 2:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>28)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 3:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 4:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 5:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 6:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 7:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 8:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 9:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 10:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 11:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            case 12:
                while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                {
                    cout << "Dia invalido" << endl;
                    cout << "Digite o DIA da viagem: ";
                    cin >> viagem[v].des[m].dia;
                }
                break;
            }
            cout << "Viagem inserida" << endl;
            viagem[v].des[m].id = id;
            for(int u=0; u<viagem[m].tamdes; u++)
            {
                viagem[u].custo += destino[u].custo;
            }
        }
        cout << "Digite o numero de clientes: ";
        cin >> viagem[v].tamcli;
        for(int f=0; f<viagem[v].tamcli; f++)
        {
            int id;
            cout << "Digite o ID do cliente: ";
            cin >> viagem[v].idcli[f];
            while(!cli(viagem[v].idcli[f]))
            {
                cout << "Digite o ID do cliente: ";
                cin >> viagem[v].idcli[f];
            }
        }
        v=v+1;
    }
    menuv();
}

bool cli(int x)
{
    for(int i=0; i<n; i++)
    {
        if(cliente[i].id == x)
        {
            return true;
        }
    }
    cout << "Cliente inexistente" << endl;
    return false;
}
void remocaov()
{
    int a;
    cout << "ID da viagem: ";
    cin >> a;
    for(int i=0; i<v; i++)
    {
        if(viagem[i].id==a)
        {
            for(int j=i; j<v; j++)
            {
                destino[j]=destino[j+1];
            }
            a=0;
            v = v-1;
            cout << "Viagem removido" << endl;
        }
    }
    if(a!=0)
    {
        cout << "Viagem inexistente" << endl<< endl;
    }
    menuv();
}

void alteracaov()
{
    int a, c, qtdexec, qtdexec2;
    cout << "ID do destino: ";
    cin >> a;
    for(int i=0; i<d; i++)
    {
        if(destino[i].id == a)
        {
            do
            {
                cout << "1 - Alteracao do numero de destinos, mes e dia" << endl;
                cout << "2 - Alteracao dos clientes da viagem" << endl;
                cout << "0 - Finalizar alteracoes" << endl;
                cin >> c;
                switch(c)
                {
                case 0:
                    menuv();
                    break;
                case 1:
                    cout << "Digite o numero de destinos: ";
                    cin >> viagem[v].tamdes;
                    for(int m=0; m<viagem[v].tamdes; m++)
                    {
                        cout << "Digite o ID do destino: ";
                        cin >> viagem[v].des[m].id;
                        while(!des(viagem[v].des[m].id))
                        {
                            cout << "Digite o ID do destino: ";
                            cin >> viagem[v].des[m].id;
                        }
                        for(int u=0; u<v; u++)
                        {
                            viagem[v].custo += destino[u].custo;
                        }
                        cout << "Digite o MES da viagem ";
                        cin >> viagem[v].des[m].mes;
                        while(viagem[v].des[m].mes<1 || viagem[v].des[m].mes>12)
                        {
                            cout << "Mes invalido " << endl;;
                            cout << "Digite o MES da viagem ";
                            cin >> viagem[v].des[m].mes;
                        }
                        cout << "Digite o DIA da viagem: ";
                        cin >> viagem[v].des[m].dia;
                        switch(viagem[v].des[m].mes)
                        {
                        case 1:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 2:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>28)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 3:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 4:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 5:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 6:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 7:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 8:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 9:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 10:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 11:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>30)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        case 12:
                            while(viagem[v].des[m].dia<=0 || viagem[v].des[m].dia>31)
                            {
                                cout << "Dia invalido" << endl;
                                cout << "Digite o DIA da viagem: ";
                                cin >> viagem[v].des[m].dia;
                            }
                            break;
                        }
                    }
                case 2:
                    cout << "Digite o numero de clientes: ";
                    cin >> viagem[v].tamcli;
                    for(int f=0; f<viagem[v].tamcli; f++)
                    {
                        int id;
                        cout << "Digite o ID do cliente: ";
                        cin >> viagem[v].idcli[f];
                        while(!cli(viagem[v].idcli[f]))
                        {
                            cout << "Digite o ID do cliente: ";
                            cin >> viagem[v].idcli[f];
                        }
                    }
                    break;
                }
            }
            while(c!=0);
        }

    }

    cout << endl;
    menud();

}

void consultav()
{
    int a, s=0;
    cout << "Digite o ID da viagem:" << endl;
    cin >> a;
    for(int i=0; i<v; i++)
    {
        if(viagem[i].id==a)
        {
            for	(int j=0; i<viagem[i].tamdes; i++)
            {
                cout << "ID do destino: " << viagem[i].des[j].id << endl;
                cout << "Dia da viagem: " << viagem[i].des[j].dia << endl;
                cout << "Mes da viagem: " << viagem[i].des[j].mes <<endl;
            }
            for (int j=0; j<viagem[i].tamcli; j++)
            {
                cout << "Clientes da viagem: " << viagem[i].idcli[j] << endl;
            }
            s=1;
        }
    }
    if(s=0)
    {
        cout << "Viagem inexistente" << endl;
    }
    cout << endl;
    menuv();
}
void inscricaov()
{
    int id,id2, x;
    cout << "Digite o ID da viagem: ";
    cin >> id;
    {

    }
    cout << "Digite o ID do cliente:";
    cin >> x;
    while(!cli(x))
    {
        cout << "Digite o ID do cliente: ";
        cin >> x;
    }
    menuv();
}
void desistenciav()
{
    int id, id2;
    cout << "Digite o ID da viagem: ";
    cin >> id;
    for(int i=0; i<v; i++)
    {
        while(viagem[i].id != id)
        {
            cout << "Viagem inexistente" << endl;
            cout << "Digite o ID da viagem: ";
            cin >> id;
        }
    }
    cout << "Digite o ID do cliente: ";
    cin >> id2;
    for(int i=0; i<v; i++)
    {
        if(viagem[i].id==id)
        {
            for (int j=0; j<viagem[i].tamdes; j++)
            {
                if(viagem[i].idcli[j]==id)
                {
                    for(int k=0; k<viagem[i].tamdes; j++)
                    {
                        viagem[i].idcli[j]=viagem[i].idcli[j+1];
                    }
                    viagem[i].tamdes = viagem[i].tamdes - 1;
                }
            }
        }
    }
    menuv();
}

void listagemv()
{
    if (v==0)
    {
        cout << "Nenhuma viagem cadastrada"<< endl;
    }
    for (int i=0; i<v; i++)
    {
        cout << "ID: " << viagem[i].id << endl;
        cout << "Custo: " << viagem[i].custo << endl;
        cout << "Numero de destinos: " << viagem[i].tamdes << endl;
        for (int j=0; j<viagem[i].tamdes; j++)
        {
            cout << "ID do destino: " << viagem[i].des[j].id << endl;
            cout << "Dia: " << viagem[i].des[j].dia << endl;
            cout << "Mes: " << viagem[i].des[j].mes << endl;
        }
        for (int j=0; j<viagem[i].tamcli; j++)
        {
            cout << "ID do cliente: " << viagem[i].idcli[j] << endl;
        }
        cout << endl;
    }
    menuv();
}

void relatoriov()
{
    if(v==0)
    {
        cout << "Nenhuma viagem cadastrada" << endl;
    }
    else
    {
        cout << "Numero total de viagens: " << v << endl;
        int a = viagem[0].custo;
        for(int i=1; i<v; i++)
        {
            if(viagem[i].custo < viagem[i-1].custo)
            {
                a = viagem[i].custo;
            }
        }
        cout << "Menor valor de viagens: " << a << endl;
        int b = viagem[0].custo;
        for(int i=0; i<v; i++)
        {
            if(viagem[i].custo < viagem[i+1].custo)
            {
                b = viagem[i+1].custo;
            }
        }
        cout << "Maior valor de viagens: " << b << endl;
        int c=0;
        for(int i=0; i<v; i++)
        {
            c += viagem[i].custo;
        }
        cout << "Valor medio de viagens: " << c/v << endl;
        int d=0;
        for(int i=0; i<v; i++)
        {
            d += viagem[i].tamcli;
        }
        cout << "Numero total de clientes: " << d << endl;
        cout << "Numero medio de clientes: " << d/v << endl;

    }
    menuv();
}
bool des(int x)
{
    for(int i=0; i<d; i++)
    {
        if(destino[i].id== x)
        {
            return true;
        }
    }
    cout << "Destino inexistente" << endl;
    return false;
}
void openf()
{
    ifstream arquivo("clientes.txt");
    arquivo >> n;
    for(int i=0; i<n; i++)
    {
        arquivo >> cliente[i].id;
        getline(arquivo,cliente[i].nome);
        getline(arquivo,cliente[i].nome);
        getline(arquivo,cliente[i].endereco);
        getline(arquivo,cliente[i].email);
        arquivo >> cliente[i].telefone;
    }
    arquivo.close();
}

void savef()
{
    ofstream arquivo("clientes.txt");
    arquivo << n << endl;
    for(int i=0; i<n; i++)
    {
        arquivo << cliente[i].id << endl;
        arquivo << cliente[i].nome << endl;
        arquivo << cliente[i].endereco << endl;
        arquivo << cliente[i].email << endl;
        arquivo << cliente[i].telefone << endl;
    }
    arquivo.close();
}

void openfd()
{
    ifstream arquivo("destino.txt");
    arquivo >> d;
    for(int i=0; i<d; i++)
    {
        arquivo >> destino[i].id;
        getline(arquivo,destino[i].local);
        getline(arquivo,destino[i].local);
        getline(arquivo,destino[i].pais);
        arquivo >> destino[i].numlocais;
        arquivo >> destino[i].custo;
    }
    arquivo.close();
}

void savefd()
{
    ofstream arquivo("destino.txt");
    arquivo << d << endl;
    for(int i=0; i<d; i++)
    {
        arquivo << destino[i].id << endl;
        arquivo << destino[i].local << endl;
        arquivo << destino[i].pais << endl;
        arquivo << destino[i].numlocais << endl;
        arquivo << destino[i].custo << endl;
    }
    arquivo.close();
}
void openfv()
{
    ifstream arquivo("viagem.txt");
    arquivo >> v;
    for(int i=0; i<v; i++)
    {
        arquivo >> viagem[i].id;
        arquivo >> viagem[i].tamdes;
        for(int j=0; j<viagem[i].tamdes; j++)
        {
            arquivo >> viagem[i].des[j].mes;
            arquivo >> viagem[i].des[j].dia;
            arquivo >> viagem[i].des[j].id;
        }
        arquivo >> viagem[i].tamcli;
        for(int k=0; k<viagem[i].tamcli; k++)
        arquivo >> viagem[i].idcli[k];
        arquivo >> viagem[i].custo;
    }
    arquivo.close();
}

void savefv()
{
    ofstream arquivo("viagem.txt");
    arquivo << v << endl << endl;
    for(int i=0; i<v; i++)
    {
        arquivo << viagem[i].id << endl << endl;
        arquivo << viagem[i].tamdes << endl;
        for(int j=0; j<viagem[i].tamdes; j++)
        {
            arquivo << viagem[i].des[j].mes << endl;
            arquivo << viagem[i].des[j].dia << endl;
            arquivo << viagem[i].des[j].id<< endl;
        }
        arquivo << endl << viagem[i].tamcli << endl;
        for(int k=0; k<viagem[i].tamcli; k++)
        arquivo << viagem[i].idcli[k] << endl;
        arquivo << endl << viagem[i].custo << endl << endl;
    }
    arquivo.close();
}
void openr()
{
    ofstream arquivo("viagem.txt");
    ofstream arquivo1("destino.txt");
    ofstream arquivo2("clientes.txt");
}
