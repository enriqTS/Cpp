/*
Implementar no código abaixo:
1 - Inicializaçãoo
2 - Inserção
3 - Remoção
4 - Impressão da estrutura
5 - Impressão da lista na ordem lógica (registros)
5 - Pesquisa
6 - Insere ordenado pela chave
*/
#include<iostream>

using namespace std;

/*definição da estrutura a ser armazenada*/
struct dados
{
    int chave;
    //outros dados
};

union celula
{
    struct
    {
        int quant, first, last, free;
    } cabecalho;
    struct
    {
        int next, prev;
        dados reg;
    } lista;
};

void inicializa(celula *l, int n)
{
    /*Criando e inicializando a estrutura de dados*/
    cout<<endl<<endl<<"Inicializando a estrutura de registros"<<endl;

    l[0].cabecalho.quant=0;
    l[0].cabecalho.first=-1;
    l[0].cabecalho.last=-1;
    l[0].cabecalho.free=1;
    
    for(int i=1;i<n;i++)
    {
        l[i].lista.next=i+1;
        /*A linha abaixo é desnecessária só coloquei para facilitar a visualização das estruturas na impressão*/
        l[i].lista.prev=0;
        
    }
        
    l[n-1].lista.next=-1;     
}

void insere(celula *l, dados d)
{
    if(l[0].cabecalho.quant==0){
        l[0].cabecalho.first=1;
        l[0].cabecalho.last=1;
        l[1].lista.reg=d;
        l[0].cabecalho.free++;
        l[0].cabecalho.quant++;
    }
    else{
        l[l[0].cabecalho.free].lista.reg = d;
        l[l[0].cabecalho.free].lista.next = l[0].cabecalho.free + 1;
        l[l[0].cabecalho.free].lista.prev = l[0].cabecalho.free - 1;
        l[0].cabecalho.last = l[0].cabecalho.free;
        l[0].cabecalho.free++;
        l[0].cabecalho.quant++;
    }
    
}

dados remove(celula *l, int chave)
{
    
}

void imprimeRegistros(celula *l)
{

    cout<<endl<<endl<<"Imprimindo os registros"<<endl<<endl;
    
    int p=l[0].cabecalho.first;
    if(p==-1)
    {
        cout<<"Lista Vazia!!!"<<endl;
        return;
    }

    while(p!=-1)
    {
        cout<<"Registro: "<<l[p].lista.reg.chave<<endl;
        p=l[p].lista.next;
    }

}

void imprimeEstrutura(celula *l, int n)
{
    cout<<endl<<endl<<"Imprimindo Estrutura"<<endl;

    cout<<"Cabecalho"<<endl;
    cout<<"========="<<endl;
    cout<<"quant:"<< l[0].cabecalho.quant<<endl;
    cout<<"first:"<<l[0].cabecalho.first<<endl;
    cout<<"last:"<<l[0].cabecalho.last<<endl;
    cout<<"free:"<<l[0].cabecalho.free<<endl;
    
    cout<<"\nLista"<<endl;
    cout<<"========="<<endl;
    int i;
    for(int i=1;i<n;i++)
    {
        
         cout<<"Posicao "<<i<<endl;
        /*A parte verdadeira do if  abaixo é desnecessária só coloquei para facilitar a visualização das estruturas na impressão*/
        /*Neste caso, quando prev==0 o código entende que é um registro vazio e imprime "-" nas informações não relevantes*/
        if(l[i].lista.prev==0)
        {
            cout<<"Registro: - "<<endl;
            cout<<"next: "<<l[i].lista.next<<endl;
            cout<<"prev:  -"<<endl<<endl;
        }
        else
        {
            cout<<"Registro: "<<l[i].lista.reg.chave<<endl;
            cout<<"next: "<<l[i].lista.next<<endl;
            cout<<"prev: "<<l[i].lista.prev<<endl<<endl;
        }
    }
        
   
}

dados pesquisa(celula *l, int chave)
{
    
}


void insereOrdenado(celula *l, dados d)
{
      
}




int main()
{
    celula *lista;
    dados d;
    int n,op=1;
    /*Solicita o tamanho da lista e aloca dinamicamente. 
    É alocado uma célula a mais para o cabeçalho*/
    cout<<"Digite o tamanho da lista: ";
    cin>>n;
    n=n+1;

    lista= new celula[n];
    inicializa(lista,n);

    /*Adicionar Menu de opções*/
    while(op!=0)
    {
        cout<<"\n\nMenu\n=================\n";
        cout<<"1 - Insere"<<endl;
        cout<<"2 - Remove"<<endl;
        cout<<"3 - Pesquisa"<<endl;
        cout<<"4 - Imprime registros"<<endl;
        cout<<"5 - Imprime estrutura da lista"<<endl;
        cout<<"6 - Insere ordenado"<<endl;
        cout<<"0 - Sair"<<endl;
        cout<<"Digite uma opcao: ";
        cin>>op;

        switch(op)
        {
            case 1:
                cout<<"Digite a chave a ser inserida: ";
                cin>>d.chave;
                insere(lista,d);
                break;

            case 2:
                cout<<"Digite a chave a ser removida: ";
                cin>>d.chave;
                d=remove(lista,d.chave);
                //imprimir as informações do registro d
                break;

            case 3:
                cout<<"Digite a chave a ser pesquisada: ";
                cin>>d.chave;
                d=pesquisa(lista,d.chave);
                //imprimir as informações do registro d
                break;

            case 4:
                imprimeRegistros(lista);
            break;

            case 5:
                imprimeEstrutura(lista,n);
                break;

            case 6:
                cout<<"Digite a chave a ser inserida: ";
                cin>>d.chave;
                insereOrdenado(lista,d);
                break;

            case 0:
            break;

            default: cout<<"Opcao Invalida!!!"<<endl;
        }
    }
    
    //apaga a memória alocada
    delete [] lista;
    return 0;
}
