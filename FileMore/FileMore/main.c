//
//  main.c
//  FileMore
//
//  Created by Chuck Bartowski on 29/08/18.
//  Copyright © 2018 Chuck Bartowski. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef char stringa[60];

typedef struct{
    stringa nome;
    int verif;
}studente;

typedef struct{
    stringa nome;
    int verif;
}persona;


int numerorighe(stringa nome_file);
int contaoccorrenze(stringa nome_file,int voto_da_cercare);
float mediavoti(stringa nome_file);
void aggiungistudente(stringa nome_file,stringa nome_studente,int voto_studente);
void modificaVoto(stringa nome_file,stringa nome_studente,int nuovovoto);
void modificaVotoVariante(stringa nome_file,stringa nome_studente,int nuovovoto);
int maxVoto(stringa nome_file);
int minVoto(stringa nome_file);
void creaBinario(stringa nome_file,stringa nome_binario,int voto);
void creaBinarioVariante(stringa nome_file,stringa nome_binario,int voto);
void leggiBinario(stringa nome_binario);
void leggiBinario2(stringa nome_binario);
void leggiBinarioVariante(stringa nome_file,stringa nome_binario);
void creaBinarioConPos(stringa nome_file2,stringa nome_binario2,int numero,int pos);
void stampafiletesto(stringa nome_file);
void ringraziamenti();


int main() {
    
    //stringa nome_file;
    //stpcpy(nome_file,"/Users/chuckbartowski/desktop/colori");
    //stampafiletesto(nome_file);
    //stringa nome_binario;
    //stpcpy(nome_binario,"/Users/chuckbartowski/desktop/votiBinario.dat");
    //creaBinarioVariante(nome_file, nome_binario, 10);
    //leggiBinarioVariante(nome_file,nome_binario);
    //stringa nome_file2;
    //stpcpy(nome_file2,"/Users/chuckbartowski/desktop/speciale");
    //stringa nome_binario2;
    //stpcpy(nome_binario2,"/Users/chuckbartowski/desktop/numero_preferito.dat");
    //creaBinarioConPos(nome_file2,nome_binario2,40,3);
    //leggiBinario2(nome_binario2);
    //ringraziamenti();
    
    
    
    
    
    
    
    

}


//OK!
void stampafiletesto(stringa nome_file)
{
    char c;
    FILE *fp;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    for(;;)
    {
        c=getc(fp);
        if(c==EOF)
            break;
        printf("%c",c);
    }
}
//OK!
void creaBinarioConPos(stringa nome_file2,stringa nome_binario2,int numero,int pos)
{
    FILE *fp;
    fp=fopen(nome_file2,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    FILE* fb;
    fb=fopen(nome_binario2,"w+");
    if(fb==NULL)
        perror("Errore apertura file");
    int status;
    int cont=0;
    stringa nome;
    int n1,n2,n3;
    for(;;)
    {
        status=fscanf(fp,"%s %d %d %d\n",nome,&n1,&n2,&n3);
        if(status==EOF)
            break;
        persona p1;
        stpcpy(p1.nome,nome);
        p1.verif=0;
        if((numero==n1) && (pos==1)){
            p1.verif=1;
            cont++;
        }
        if((numero==n2) && (pos==2)){
            p1.verif=1;
            cont++;
        }
        if((numero==n3) && (pos==3)){
            p1.verif=1;
            cont++;
        }
        fwrite(&p1,sizeof(persona),1,fb);
        
    }
    printf("%d",cont);
    fclose(fp);
    fclose(fb);
}
//OK!
void creaBinarioVariante(stringa nome_file,stringa nome_binario,int voto)
{
    FILE* fp;
    FILE* fb;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    fb=fopen(nome_binario,"wb+");
    if(fb==NULL)
        perror("Errore apertura file");
    int dim=numerorighe(nome_file);
    studente stud[dim];
    stringa nome;
    int vot;
    int i;
    int status;
    for(i=0;i<dim-1;i++)
    {
        status=fscanf(fp,"%s %d\n",nome,&vot);
        
        stpcpy(stud[i].nome,nome);
        if(vot==voto)
            stud[i].verif=1;
        else
            stud[i].verif=0;
    }
    
    fwrite(stud,sizeof(stud),1,fb);
        
        
    
    fclose(fp);
    fclose(fb);
}
//OK!
void leggiBinarioVariante(stringa nome_file,stringa nome_binario)
{
    FILE* fb;
    int i;
    fb=fopen(nome_binario,"rb");
    if(fb==NULL)
        perror("Errore apertura file");
    int dim=numerorighe(nome_file);
    studente stud[dim];
    fread(stud,sizeof(studente),dim-1,fb);
    for(i=0;i<dim-1;i++)
    {
        printf("[NOME]: %s [ESISTE]: %d\n",stud[i].nome,stud[i].verif );
    }
}
//OK!
void leggiBinario2(stringa nome_binario)
{
    FILE* fb;
    fb=fopen(nome_binario,"rb");
    persona stud;
    int status;
    for(;;)
    {
        status=fread(&stud,sizeof(persona),1,fb);
        if(status==0)
            break;
        printf("[Persona] [Voto] %s-%d\n",stud.nome,stud.verif);
    }
}
//OK!
void leggiBinario(stringa nome_binario)
{
    FILE* fb;
    fb=fopen(nome_binario,"rb");
    studente stud;
    int status;
    for(;;)
    {
       status=fread(&stud,sizeof(studente),1,fb);
        if(status==0)
            break;
        printf("[Studente] [Voto] %s-%d\n",stud.nome,stud.verif);
    }
}
//OK!
void creaBinario(stringa nome_file,stringa nome_binario,int voto)
{
    FILE* fp;
    FILE* fb;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    fb=fopen(nome_binario,"wb+");
    if(fb==NULL)
        perror("Errore apertura file");
    int status;
    int vot;
    stringa nome;
    for(;;)
    {
        status=fscanf(fp,"%s %d\n",nome,&vot);
        if(status==EOF)
          break;
        studente d;
        stpcpy(d.nome,nome);
        if(vot==voto)
            d.verif=1;
        else
            d.verif=0;
        fwrite(&d,sizeof(studente),1,fb);
    }
    
    
    fclose(fp);
    fclose(fb);
}
//OK!
int minVoto(stringa nome_file)
{
    FILE *fp;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    int voto;
    stringa nome;
    int stat;
    fscanf(fp,"%s %d\n",nome,&voto);
    int min=voto;
    long pos=ftell(fp);
    printf("%ld",pos);
    
    for(;;)
    {
        stat=fscanf(fp,"%s %d\n",nome,&voto);
        if(stat==EOF)
            break;
        if(voto<min)
            min=voto;
    }
    fclose(fp);
    return min;
}
//OK!
int maxVoto(stringa nome_file)
{
    FILE *fp;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    int max=0;
    int voto;
    stringa nome;
    int stat;
    for(;;)
    {
        stat=fscanf(fp,"%s %d\n",nome,&voto);
        if(stat==EOF)
            break;
        if(voto>max)
            max=voto;
    }
    fclose(fp);
    return max;
}
//OK!
void modificaVoto(stringa nome_file,stringa nome_studente,int nuovovoto)
{
    FILE *fp;
    fp=fopen(nome_file,"r+");
    if(fp==NULL)
        perror("Errore apertura file");
    long pos;
    int voto;
    stringa nome;
    int stat;
    for(;;)
    {
        pos=ftell(fp);
        stat=fscanf(fp,"%s %d\n",nome,&voto);
        if(stat==EOF)
            break;
        if(strcmp(nome,nome_studente)==0)
        {
            fseek(fp,pos,SEEK_SET);
            fprintf(fp,"%s %d\n",nome_studente,nuovovoto);
        }
        
    }
    
    fclose(fp);
    
}
//OK!
void aggiungistudente(stringa nome_file,stringa nome_studente,int voto_studente)
{
    
    FILE *fp;
    fp=fopen(nome_file,"a+");
    if(fp==NULL)
        perror("Errore apertura file");
    fprintf(fp,"%s %d\n",nome_studente,voto_studente);
    fclose(fp);
}
//OK!
float mediavoti(stringa nome_file)
{
    
    int numerorigh=numerorighe(nome_file);
    FILE *fp;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    float media;
    int somma=0;
    int stat;
    int num;
    stringa s;
    for(;;){
        stat=fscanf(fp,"%s %d\n",s,&num);
        if(stat==EOF)
            break;
        somma=somma+num;
    }
    fclose(fp);
    media=somma/numerorigh;
    return media;
}
//OK!
int contaoccorrenze(stringa nome_file,int num)
{
    FILE *fp;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    int occorrenze=0;
    int stat;
    int voto;
    stringa s;
    for(;;)
    {
        stat=fscanf(fp,"%s %d\n",s,&voto);
        if(stat==EOF)
            break;
        if(voto==num)
            occorrenze++;
            
    }
    fclose(fp);
    return occorrenze;
    
}
//OK!
int numerorighe(stringa nome_file)
{
    FILE *fp;
    fp=fopen(nome_file,"r");
    if(fp==NULL)
        perror("Errore apertura file");
    int numero_righe=0;
    stringa s;
    int stat;
    int voto;
    for(;;)
    {
        stat=fscanf(fp,"%s %d\n",s,&voto);
        if(stat==EOF)
            break;
        numero_righe++;
    }
    fclose(fp);
    return numero_righe;
    
}
//OK!
void ringraziamenti()
{
    printf("---------------FILE RESUME---------------\n");
    printf("________________IVAN CESE________________\n");
    printf("******************THANKS*****************\n");
    
}
