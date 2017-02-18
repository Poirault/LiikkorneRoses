
#include <influence-client.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct listcoor{
	coord co;
	listcoor queue;
}  cellule, listcoor;

listcoor init(){
	cellule* C=(cellule*)malloc(sizeof(cellule));
	C->co.x=0;
	C->co.y=0;
	C->queue=NULL;
	return(C);	
}
	
listcoor ajout(listcoor c,coord co){
	listcoor C=init();
	C->co=co;
	C->queue=c;
	return(C);
}

int vacuite(listcoor c){
	return(c==NULL);
}
	
	
	
typedef InflCell*** matcell;

matcell init_risk(matrice C){
	int o,u;
	matcell risk;
	risk=malloc(w*sizeof(InflCell**));
	for(o=0;o<h;o++){
		risk[o]=malloc(sizeof(InflCell*));
	}
	for(u=0;u<h;u++){
		for(o=0;o<w;o++){
			risk[o][u]=max(dangerosité(o,u,w,h,licorne));
		}
	}
	return(risk);
}
	

void attak(x,y,a_x,a_y){
	infl_client_attack(client, x, y, a_x, a_y);
	printf("Attaque (%d, %d) -> (%d, %d)\n", x, y, a_x, a_y);
}


void placement(x,y,val){
	infl_client_add_units(client, infl_field_get_cell(field, x, y), val);
}

coord maxi(int a0,int a1,int a2, int a3, int a4, int a5, int a6, int a7){
	coord maxx;
	maxx.x=a0;
	maxx.y=0
	if(a1>a0){
		maxx.x=a1;
		maxx.y=1;
	}
	if(a2>maxx){
		maxx=a2;
		maxx.y=2;
	}
	if(a3>maxx){
		maxx=a3;
		maxx.y=3;
	}
	if(a4>maxx){
		maxx=a4;
		maxx.y=4;
	}
	if(a5>maxx){
		maxx=a5;
		maxx.y=5;
	}
	if(a6>maxx){
		maxx=a6;
		maxx.y=6;
	}
	if(a7>maxx){
		maxx=a7;
		maxx.y=7;
	}
	return(maxx);
}



listcoor choixattak(x,y){

	coord grand,cloc;
	c
	int ha,ba,ga,dr,mil,d1,d2,d3,d4,val;
	mil=infl_cell_get_unit_count(infl_field_get_cell(field, x, y)
	listcoor bouyah;
	
	if(y+1<h){
		ha=infl_cell_get_unit_count(infl_field_get_cell(field, x, y+1));
	}
	else{ha=0;}
	if(y+1<h && x>0){
		d1=infl_cell_get_unit_count(infl_field_get_cell(field, x-1, y+1));
	}
	else{d1=0;}
	if(x>0){
		ga=infl_cell_get_unit_count(infl_field_get_cell(field, x-1, y));
	}
	else{ga=0;}
	if(x+1<w){
		dr=infl_cell_get_unit_count(infl_field_get_cell(field, x+1, y));
	}
	else{dr=0;}
	if(x+1<w && y+1<h){
		d2=infl_cell_get_unit_count(infl_field_get_cell(field, x+1, y+1));
	}
	else{d2=0;}
	if(y>0){
		ba=infl_cell_get_unit_count(infl_field_get_cell(field, x, y-1));
	}
	else{ba=0;}
	if(x+1<w && y>0){
		d3=infl_cell_get_unit_count(infl_field_get_cell(field, x+1, y-1));
	}
	else{d3=0;}
	if(x>0 && y>0){
		d4=infl_cell_get_unit_count(infl_field_get_cell(field, x-1, y-1));
	}
	else{d4=0;}
	
	grand=maxi(ha,ba,ga,dr,d1,d2,d3,d4); /* grand.x = la val du max et grand.y le no de la variable : 1=ha, 2=ba...) */
	val=grand.x

	if(val==ha){

		bouyah.co.x=x;
		bouyah.co.y=y+1;
	}
	if(val==ba){

		if(vacuite(bouyah)){
			bouyah.co.x=x;
			bouyah.co.y=y-1;
		}
		else{
		cloc.x=x;
		cloc.y=y-1;
		ajout(bouyah,cloc);
	}
	if(val==ga){

		if(vacuite(bouyah)){
			bouyah.co.x=x-1;
			bouyah.co.y=y;
		}
		else{
			cloc.x=x-1;
			cloc.y=y;
			ajout(bouyah,cloc);
		}
	}
	if(val==dr){

		if(vacuite(bouyah)){
			bouyah.co.x=x;
			bouyah.co.y=y+1;
		}
		else{
			cloc.x=x;
			cloc.y=y+1;
			ajout(bouyah,cloc);
		}
	}	
	if(val==d1){

		if(vacuite(bouyah)){
			bouyah.co.x=x-1;
			bouyah.co.y=y+1;
		}
		else{
			cloc.x=x-1;
			cloc.y=y+1;
			ajout(bouyah,cloc);
		}
	}
	if(val==d2){

		if(vacuite(bouyah)){
			bouyah.co.x=x+1;
			bouyah.co.y=y+1;
		}
		else{
			cloc.x=x+1;
			cloc.y=y+1;
			ajout(bouyah,cloc);
		}
	}
	if(val==d3){

		if(vacuite(bouyah)){
			bouyah.co.x=x+1;
			bouyah.co.y=y11;
		}
		else{
			cloc.x=x+1;
			cloc.y=y-1;
			ajout(bouyah,cloc);
		}
	}
	if(val==d4){

		if(vacuite(bouyah)){
			bouyah.co.x=x-1;
			bouyah.co.y=y-1;
		}
		else{
			cloc.x=x-1;
			cloc.y=y-1;
			ajout(bouyah,cloc);
		}
	}
	return(bouyah);
	
	
}

int dist_min(matrice P){
	int min,f1,g1,f2,g2;
	min=w+h;
	for(f1=0;f1<w;f1++){
		for(g1=0;g1<h;g1++){
			for(f2=0;f2<w;f2++){
				for(g2=0;g2<h;g2++){
					if(P[f1][g1]!=P[f2][g2] && P[f1][g1]!=0 && P[f2][g2]!=0){
						if(min>f2-f1+g2-g1){
							min=f2-f1+g2-g1;							
						}
					}
				}
			}
		}
	}
	return(min);
}



KIIROULE

	
	
int distance_entre_deux_cellules(int x1,int y1,int x2,int y2)
{
  int distance=fabs(x1-x2)+fabs(y1-y2)
  return distance;
}

matrice dangerosite(int x,int y,int w,int h,int licorne)
{
  matrice m;
  m=(int**)malloc(w*sizeof(int*));
  int m;
  for(q=0;q<w;q++)
  {
    m[q]=(int*)malloc(h*sizeof(int));
  }
  int i,j;
  int force=infl_cell_get_unit_count (infl_field_get_cell (field,x,y));
  for (i=0;i<w;i++)
  {
    for (j=0;j<h;j++)
    {
      if (infl_cell_get_owner (infl_field_get_cell (field,i,j))==licorne)
      {
        m[i][j]=NULL;
      }
      else
      {
        int force_ennemy=infl_cell_get_unit_count (infl_field_get_cell (field,x,y));
        int res = force_ennemy-force;
        if (res>=0)
        {
          res=res-distance(x,y,i,j);
        }
        else
        {
          res=res+distance(x,y,i,j);
        }
        m[i][j]=res;
      }
    }
  }
  return m;
}


InflCell max_dangerosite(int x,int y,int w,int h,int licorne)
{
  matrice m=dangerosite(x,y,w,h,licorne);
  int i,j;
  int max=0;
  InflCell best;
  for (i=0;i<w;i++)
  {
    for (j=0;j<h;j++)
    {
      if (m[i][j]>max)
      {
        max=m[i][j];
        best=infl_field_get_cell (field,x,y);
      }
    }
  }
  return best;
}

InflCell min_dangerosite(int x,int y,int w,int h,int licorne)
{
  matrice m=dangerosite(x,y,w,h,licorne);
  int i,j;
  int min=0;
  InflCell worst;
  for (i=0;i<w;i++)
  {
    for (j=0;j<h;j++)
    {
      if (m[i][j]<min)
      {
        min=m[i][j];
        worst=infl_field_get_cell (field,x,y);
      }
    }
   }
   return worst;
}
	
	
	
	
