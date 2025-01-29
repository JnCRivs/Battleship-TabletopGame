#include <stdio.h>
#include <stdlib.h>				//CADA VARIABLE UTILIZADA SE DESCRIBE EN EL INFORME
#include <conio.h>

int i,j,f,z=0,c,m,n,o,confb3,confb2,valb4=0,valb3=0,valb2=0,infcolum,game=0,selfila,cont,nomval, bart2=2,bart3=2,bart4=1,totbarc=5;
int tjug1=0,tjug2=0,pjug1=0,pjug2=0,salid=0,cmjug=0;
char jug1[10],jug2[10],y,x,orint,opc1,opc,sdif, naves[2][8][8], ataque[2][8][8];

void Tableros(){
	for(z=0;z<2;z++){
		for(f=0;f<8;f++){
			for(c=0;c<8;c++){
				naves[z][f][c]='~';
			}	
		}		
	}
	
	for(z=0;z<2;z++){
		for(f=0;f<8;f++){
			for(c=0;c<8;c++){
				ataque[z][f][c]='~';
			}	
		}		
	}
}
void Display_Tb_J1(){

	printf("\t\t\t\t\t    A  B  C  D  E  F  G  H\n");
	    for(i=0;i<8;i++){
	    	printf("\t\t\t\t\t%i |",i+1);
	    		for(j=0;j<8;j++){
	    			printf(" %c ",naves[0][i][j]);
				}
			printf("|");
			printf("\n");
		}	
}
void Display_Tb_J2(){
	    
		printf("\t\t\t\t\t    A  B  C  D  E  F  G  H\n");
	    	for(i=0;i<8;i++){
	    		printf("\t\t\t\t\t%i |",i+1);
	    			for(j=0;j<8;j++){
	    				printf(" %c ",naves[1][i][j]);
					}
				printf("|");
				printf("\n");
			}
}
void Display_Tb_Ataque_J1(){
	
	printf("\t\t\t\t\t    A  B  C  D  E  F  G  H\n");
		for(i=0;i<8;i++){
			printf("\t\t\t\t\t%i |",i+1);
				for(j=0;j<8;j++){
				    printf(" %c ",ataque[0][i][j]);
				}
			printf("|");
			printf("\n");
		}
}
void Display_Tb_Ataque_J2(){

	printf("\t\t\t\t\t    A  B  C  D  E  F  G  H\n");
		for(i=0;i<8;i++){
			printf("\t\t\t\t\t%i |",i+1);
				for(j=0;j<8;j++){
				    printf(" %c ",ataque[1][i][j]);
				}
			printf("|");
			printf("\n");
		}
}
void Cambio_Columna(){
	switch(y){
		case'A': c=0; break;
		case'B': c=1; break;
		case'C': c=2; break;
		case'D': c=3; break;
		case'E': c=4; break;
		case'F': c=5; break;
		case'G': c=6; break;
		case'H': c=7; break;
		default: printf("\n\t\t\t\tLETRA SELECCIONADA NO ESTA DENTRO DEL RANGO\n\t\t\t\t"); system("pause"); system("cls");			
	}
}
void Cambio_Fila(){
	switch(x){
		case '1': f=0; break;
		case '2': f=1; break;
		case '3': f=2; break;
		case '4': f=3; break;
		case '5': f=4; break;
		case '6': f=5; break;
		case '7': f=6; break;
		case '8': f=7; break;
		default: printf("\n\t\t\t\tNUMERO SELECCIONADO NO ESTA DENTRO DEL RANGO\n\t\t\t\t"); system("pause"); system("cls");
	}
}
void Jugadores(){
        printf("\n\n\t\t\t\t\tINGRESE EL NOMBRE DEL JUGADOR 1\n");
        printf("\t\t\t\t\t\tJ1: "); gets(jug1); fflush(stdin);
        system("cls");

        printf("\n\n\t\t\t\t\tINGRESE EL NOMBRE DEL JUGADOR 2\n");
        printf("\t\t\t\t\t\tJ2: "); gets(jug2); fflush(stdin);
        system("cls");
}
void Resultados(){
	if(pjug1==14 || pjug2==14){
		
		if(pjug1==14){ printf("\n\t\t\t\tEL GANADOR DE ESTA PARTIDA ES %s ,FELICIDADES!\n\n",jug1); }
		else if(pjug2==14){ printf("\n\t\t\t\tEL GANADOR DE ESTA PARTIDA ES %s ,FELICIDADES!\n\n",jug2); }
		
		printf("\t\t\tA CONTINUACION SE MUESTRAN LAS COORDENADAS DE AMBOS JUGADORES\n");
		printf("\t\t\tPARA COMPROBAR LAS UBICACIONES DE LOS BARCOS JUNTO CON LAS DE\n");
		printf("\t\t\tATAQUE DE CADA JUGADOR\n\n");
		
		printf("\t\t\t\t\t");system("pause");system("cls");
		
		printf("\n\t\t\t\tUBICACION DE BARCOS DEL JUGADOR #1\n\n");
	
		Display_Tb_J1();
				
		printf("\n\t\t\t\tUBICACION DE COORDENADAS DE ATAQUE DEL JUGADOR #2\n\n");

		Display_Tb_Ataque_J2();
	
		printf("\n\t\t\t-------------------------------------------------------------\n");

		printf("\n\t\t\t\tUBICACION DE BARCOS DEL JUGADOR #2\n\n");

		Display_Tb_J2();
	
		printf("\n\t\t\t\tUBICACION DE COORDENADAS DE ATAQUE DEL JUGADOR #1\n\n");
			
		Display_Tb_Ataque_J1();
	
		printf("\n\n\t\t\t\t"); system("pause"); system("cls");	
	
	}
}
void Juego(){
	while(game==0){
		while(tjug1==0){
			
			if(sdif=='A'){	printf("\n\t\t\t\t\t    MODO DE JUEGO: FACIL\n\n"); }
			else if(sdif=='B'){	printf("\n\t\t\t\t\t    MODO DE JUEGO: DIFICIL\n\n"); }
			
			printf("\t\t\t\tJUGADOR #1: %s\n\t\t\t\tPUNTOS OBTENIDOS: %i/14\n\n",jug1,pjug1);
			printf("\t\t\t\tJUGADOR #2: %s\n\t\t\t\tPUNTOS OBTENIDOS: %i/14\n\n",jug2,pjug2);
		
			Display_Tb_Ataque_J1();
				
            printf("\n\t\t\t\t\tSELECCIONE UNA COORDENADA (J1)\n\n");
            printf("\t\t\t\t\t  Y:");
            scanf("%c",&y); fflush(stdin);
            Cambio_Columna();

            if(c>=0 && c<=7){
                printf("\t\t\t\t\t  X:");
                scanf("%c",&x); fflush(stdin);
                Cambio_Fila();

                if(f>=0 && f<=7){
                    if(ataque[0][f][c]=='~'){
                        ataque[0][f][c]='X';
                            if(naves[1][f][c]=='O'){
                                ataque[0][f][c]='O';
                                if(sdif=='B'){	ataque[0][f][c]='X'; }
                                printf("\n\t\t\t\t\t\t| ATINADO +1 |\n\n\t\t\t\t");
                                tjug1++; pjug1++;f=-1;c=-1;
                                system("pause"); if(pjug1==14){ system("cls"); return; } system("cls");
                            }
                            else if(naves[1][f][c]=='~'){    
                                printf("\n\t\t\t\t\t\t| PUNTO COLOCADO |\n\n\t\t\t\t");
                                tjug1++; f=-1; c=-1; system("pause"); system("cls");                               
                            }
                    }
                    else{ printf("\n\t\t\t\tESTE UBICACION YA ESTA MARCADA, SELECCIONE UNA DIFERENTE\n\t\t\t\t"); system("pause"); system("cls"); }
                }
                else{ c=-1; f=-1;}
            }
            else{ f=-1;c=-1;}
		}
		
		while(tjug2==0){
			
			if(sdif=='A'){	printf("\n\t\t\t\t\t    MODO DE JUEGO: FACIL\n\n"); }
			else if(sdif=='B'){	printf("\n\t\t\t\t\t    MODO DE JUEGO: DIFICIL\n\n"); }
			
			printf("\t\t\t\tJUGADOR #1: %s\n\t\t\t\tPUNTOS OBTENIDOS: %i/14\n\n",jug1,pjug1);
			printf("\t\t\t\tJUGADOR #2: %s\n\t\t\t\tPUNTOS OBTENIDOS: %i/14\n\n",jug2,pjug2);

			Display_Tb_Ataque_J2();

            printf("\n\t\t\t\t\tSELECCIONE UNA COORDENADA (J2)\n\n");
            printf("\t\t\t\t\t  Y:");
            scanf("%c",&y); fflush(stdin);
            Cambio_Columna();

            if(c>=0 && c<=7){
                printf("\t\t\t\t\t  X:");
                scanf("%c",&x); fflush(stdin);
                Cambio_Fila();

                if(f>=0 && f<=7){
                    if(ataque[1][f][c]=='~'){
                        ataque[1][f][c]='X';
                            if(naves[0][f][c]=='O'){
                                ataque[1][f][c]='O';
                                if(sdif=='B'){	ataque[1][f][c]='X'; }
                                printf("\n\t\t\t\t\t\t| ATINADO +1 |\n\n\t\t\t\t"); tjug2++; pjug2++; f=-1; c=-1;
                                system("pause"); if(pjug2==14){ system("cls"); return; } system("cls");
                            }
                            else if(naves[0][f][c]=='~'){
                                printf("\n\t\t\t\t\t\t| PUNTO COLOCADO |\n\n\t\t\t\t"); 
								tjug2++; f=-1; c=-1; system("pause"); system("cls");                               
                            }
                    }
                    else{ printf("\n\t\t\t\tESTE UBICACION YA ESTA MARCADA, SELECCIONE UNA DIFERENTE\n\t\t\t\t"); system("pause"); system("cls"); }
                }
                else{ f=-1; c=-1; }
            }
            else{ c=-1; f=-1; }
		}
		
		tjug1=0; tjug2=0;			
	}	
}
void Coordenadas(){
	while(totbarc>=0){
	 
		if(z==0){ printf("\n\t\t\t\t\tJ1: %s\n",jug1);} if(z==1){ printf("\n\t\t\t\t\tJ2: %s\n",jug2);} 	//MUESTRA LA INFORMACION DEPENDIENTO DEL JUGADOR
	    printf("\t\t\t\t\tCONSIDERE LO SIGUIENTE:\n\n");
	    printf("\t\t\t\t\t|\tOO = RESTANTE:%i\t\t|\n",bart2);
	    printf("\t\t\t\t\t|\tOOO = RESTANTE:%i\t|\n",bart3);
	    printf("\t\t\t\t\t|\tOOOO = RESTANTE:%i\t|\n\n\n",bart4);

		if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
			
	    if(totbarc==0){  //EL ALCANZAR EL LIMITE, SE LE PREGUNTA ESTO AL JUGADOR
	    	printf("\n\t\t\t\t    TODOS LOS BARCOS ESTAN COLOCADOS\n\n");
	    	printf("\t\t\t\t    [A:CONFIRMAR]   [B:VOLVER A EDITAR]");
	    	printf("\n\n\t\t\t\t\t\tX:");
	    	scanf("%c",&opc); fflush(stdin);
	    	
	    	switch(opc){
				case 'A': totbarc--; bart2=2; bart3=2; bart4=1; confb2=0; confb3=0; valb4=0; valb3=0; valb2=0; system("cls"); break;	    		
	    		case 'B': for(f=0;f<8;f++){ for(c=0;c<8;c++){ naves[z][f][c]='~'; } }
				totbarc=5; bart2=2; bart3=2; bart4=1; confb2=0; confb3=0; valb4=0; valb3=0; valb2=0; system("cls"); break;
	    		default: printf("\n\t\t\t\tOPCION NO VALIDA, VUELA A INGRESAR\n\t\t\t\t"); system("pause"); system("cls");
			}
		}
		else if(totbarc!=0){

		    printf("\n\t\t\t\tSELECCIONE EL TIPO DE BARCO QUE DESEA COLOCAR:\n\n");
		    printf("\t\t\t\t\t[2: OO] [3: OOO] [4: OOOO]\n\n");
		    printf("\t\t\t\t\t\t  X:");
		    scanf("%c",&opc); fflush(stdin);
		    
		switch(opc){
		    	
		    case '2':	// BARCO TAMAÑO OO
		    		
			    if(confb2==2){ valb2=2; if(valb2==2){ printf("\n\t\t\t\tNO PUEDES ESCOGER MAS ESTE TIPO DE BARCO\n\t\t\t\t"); system("pause"); bart2++; totbarc++; confb2--; } }
						
				else if(confb2!=2){ valb2=0; system("cls"); 	//EN CASO DE NO HABER PASADO EL LIMITE DE BARCOS DE ESTE TAMAÑO, SE INGRESA AQUI
					while(valb2==0){ cont=0;
					    printf("\n\t\t\t\t\t\t  BARCO OO:\n\n");

						if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
								
						printf("\n\t\t\tINDIQUE LAS COORDENADAS A LAS CUALES DESEA COLOCAR EL PUNTO INICIAL\n\n");
						printf("\t\t\t NOTA: PRIMERO INDIQUE LA LETRA DE COLUMNA (EN MAYUS) Y \n");
						printf("\t\t\t       POR CONSIGUIENTE EL NUMERO DE FILA\n");
						selfila=0;
						printf("\t\t\tY:");
						scanf("%c",&y); fflush(stdin);
						Cambio_Columna();
								
						if(c>=0 && c<=7){	//VALOR DE COLUMNA DENTRO DEL RANGO
							while(selfila==0){
								if(infcolum==1){
									printf("\n\t\t\t\t\t\t  BARCO OO:\n\n");
	
									if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
									    		
									printf("\n\t\t\tINDIQUE LAS COORDENADAS A LAS CUALES DESEA COLOCAR EL PUNTO INICIAL\n\n");
									printf("\t\t\t NOTA: PRIMERO INDIQUE LA LETRA DE COLUMNA (EN MAYUS) Y\n");
									printf("\t\t\t       POR CONSIGUIENTE EL NUMERO DE FILA\n");
									printf("\t\t\tY:%c\n",y);
								}
								printf("\t\t\tX:");
								scanf("%c",&x);fflush(stdin);
								Cambio_Fila();
										
								if(f>=0 && f<=7){	//VALOR DE FILA DENTRO DEL RANGO
									if(naves[z][f][c]=='~'){
										while(cont==0){
											naves[z][f][c]='O';
											system("cls");
											printf("\n\t\t\t\t\tUBICACION DEL BARCO: OO\n\n");
														
											if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
																
											printf("\n\n\t\t\t\t\tELIJA LA ORIENTACION DEL BARCO\n\n");
											printf("\t\t\tNOTA: SI TODAS LAS ORIENTACIONES OBSTACULIZAN CON ALGUNOS DE\n");
											printf("\t\t\tLOS BARCOS, PUEDE VOLVER A ESCOJER LAS COORDENADAS\n\n");
											printf("\t\t\t\t\t[1: ARRIBA ]\t[2: ABAJO]\n\t\t\t\t\t[3: IZQUIERDA]\t[4: DERECHA]\n\n\t\t\t\t\t[5:CAMBIAR COORDENADAS]\n");
											printf("\n\t\t\t\t\t\t    X:");
											scanf("%c",&orint); fflush(stdin);
														
											switch(orint){ 	
												case '1': m=f-1; //ORIENTACION (ARRIBA) BARCO OO
													if(m!=-1){
														if( (naves[z][f-1][c]!='O') ){ naves[z][f-1][c]='O'; cont++; selfila++; valb2++; m=0; }
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
											
												break;	
																				
												case '2': m=f+2; //ORIENTACION (ABAJO) BARCO OO
													if(m!=9){
														if( (naves[z][f+1][c]!='O') ){ naves[z][f+1][c]='O'; cont++; selfila++; valb2++; m=0; }
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }

													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;
																
												case '3': m=c-1; //ORIENTACION (IZQUIERDA) BARCO OO
													if(m!=-1){
														if( (naves[z][f][c-1]!='O') ){ naves[z][f][c-1]='O'; cont++; selfila++; valb2++; m=0; }
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;

												case '4': m=c+1; //ORIENTACION (DERECHA) BARCO OO
													if(m!=8){
														if((naves[z][f][c+1]!='O') ){ naves[z][f][c+1]='O'; cont++; selfila++; valb2++; m=0; }
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
									
												break;

												case'5': cont++; infcolum=0; selfila++; naves[z][f][c]='~'; f=-1; c=-1; system("cls"); break; //CAMBIO DE COORDENADAS
																			
												default: printf("\n\t\t\t\tESCOJA UNA ORIENTACION VALIDA\n\t\t\t\t"); system("pause"); system("cls");
								
											}					
										}			
									}
									else if(naves[z][f][c]=='O'){ printf("\n\t\t\t\tESTA COORDENADA YA ESTA OCUPADA\n\t\t\t\t");
										system("pause"); system("cls"); selfila++; f=-1; c=-1; infcolum=0;
									}				
								}
								else{ infcolum=1; } //ERROR DE SELECCION DE VALOR DE FILA (SE MUESTRA INFO CON LA COLUMNA ELEGIDA)
							}
	
						}
						else{ valb2--; valb2++; } //ERROR DE SELECCION DE VALOR DE COLUMNA									
					}
				}
				
				confb2++; f=-1; c=-1; infcolum=0; bart2--; system("cls"); totbarc--;
			    
			break;
			    		
		    case '3': // BARCO TAMAÑO OOO
		    		
			    if(confb3==2){ valb3=2; if(valb3==2){ printf("\n\t\t\t\tNO PUEDES ESCOGER MAS ESTE TIPO DE BARCO\n\t\t\t\t"); system("pause"); bart3++; totbarc++; confb3--; } }
						
				else if(confb3!=2){ valb3=0; system("cls");	//EN CASO DE NO HABER PASADO EL LIMITE DE BARCOS DE ESTE TAMAÑO, SE INGRESA AQUI
					while(valb3==0){ cont=0;
					    printf("\n\t\t\t\t\t\t  BARCO OOO:\n\n");		
						if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
	
																						
						printf("\n\t\t\tINDIQUE LAS COORDENADAS A LAS CUALES DESEA COLOCAR EL PUNTO INICIAL\n\n");
						printf("\t\t\t NOTA: PRIMERO INDIQUE LA LETRA DE COLUMNA (EN MAYUS) Y \n");
						printf("\t\t\t       POR CONSIGUIENTE EL NUMERO DE FILA\n");
						selfila=0;
						printf("\t\t\tY:");
						scanf("%c",&y); fflush(stdin);
						Cambio_Columna();
								
						if(c>=0 && c<=7){	//VALOR DE COLUMNA DENTRO DEL RANGO
							while(selfila==0){
								if(infcolum==1){
									printf("\n\t\t\t\t\t\t  BARCO OOO:\n\n");
										
									if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
									    		
									printf("\n\t\t\tINDIQUE LAS COORDENADAS A LAS CUALES DESEA COLOCAR EL PUNTO INICIAL\n\n");
									printf("\t\t\t NOTA: PRIMERO INDIQUE LA LETRA DE COLUMNA (EN MAYUS) Y\n");
									printf("\t\t\t       POR CONSIGUIENTE EL NUMERO DE FILA\n");
									printf("\t\t\tY:%c\n",y);
								}
								printf("\t\t\tX:");
								scanf("%c",&x); fflush(stdin);
								Cambio_Fila();
										
								if(f>=0 && f<=7){	//VALOR DE FILA DENTRO DEL RANGO
									if(naves[z][f][c]=='~'){
										while(cont==0){ naves[z][f][c]='O';
											system("cls");
											printf("\n\t\t\t\t\t UBICACION DEL BARCO: OOO\n\n");
														
											if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
																
											printf("\n\n\t\t\t\t\tELIJA LA ORIENTACION DEL BARCO\n\n");
											printf("\t\t\tNOTA: SI TODAS LAS ORIENTACIONES OBSTACULIZAN CON ALGUNOS DE\n");
											printf("\t\t\tLOS BARCOS, PUEDE VOLVER A ESCOJER LAS COORDENADAS\n\n");
											printf("\t\t\t\t\t[1: ARRIBA ]\t[2: ABAJO]\n\t\t\t\t\t[3: IZQUIERDA]\t[4: DERECHA]\n\n\t\t\t\t\t[5:CAMBIAR COORDENADAS]\n");
											printf("\n\t\t\t\t\t\t    X:");
											scanf("%c",&orint); fflush(stdin);
														
											switch(orint){
												case '1': m=f-1; n=f-2; //ORIENTACION (ARRIBA) BARCO OOO
													if(m!=-1 && n!=-1){
														if( (naves[z][f-1][c]!='O') && (naves[z][f-2][c]!='O') ){ naves[z][f-1][c]='O'; naves[z][f-2][c]='O'; cont++; selfila++;valb3++; m=0; n=0; }
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;	
																				
												case '2': m=f+2; n=f+3; //ORIENTACION (ABAJO) BARCO OOO
													if(m!=9 && n!=9){
														if( (naves[z][f+1][c]!='O') && (naves[z][f+2][c]!='O') ){ 
															naves[z][f+1][c]='O'; 
															naves[z][f+2][c]='O'; 
															cont++; selfila++;valb3++; m=0; n=0; }						
														
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;
																
												case '3': m=c-1; n=c-2; //ORIENTACION (IZQUIERDA) BARCO OOO
													if(m!=-1 && n!=-1){
														if( (naves[z][f][c-1]!='O') && (naves[z][f][c-2]!='O') ){
															naves[z][f][c-1]='O';
															naves[z][f][c-2]='O';
															cont++; selfila++;valb3++; m=0; n=0; }
															
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;

												case '4': m=c+1; n=c+2; //ORIENTACION (DERECHA) BARCO OOO
													if(m!=8 && n!=8){
														if((naves[z][f][c+1]!='O') && (naves[z][f][c+2]!='O') ){
															naves[z][f][c+1]='O';
															naves[z][f][c+2]='O';
															cont++; selfila++;valb3++; m=0; n=0; }
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }

													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;

												case'5': cont++; infcolum=0; selfila++; naves[z][f][c]='~'; f=-1; c=-1; system("cls"); break; //CAMBIO DE COORDENADAS
																			
												default: printf("\n\t\t\t\tESCOJA UNA ORIENTACION VALIDA\n\t\t\t\t"); system("pause"); system("cls");
											}
														
										}
													
									}
									else if(naves[z][f][c]=='O'){ printf("\n\t\t\t\tESTA COORDENADA YA ESTA OCUPADA\n\t\t\t\t"); system("pause"); system("cls");selfila++; infcolum=0; f=-1; c=-1; }
												
								}
								else{ infcolum=1; } //ERROR DE SELECCION DE VALOR DE FILA (SE MUESTRA INFO CON LA COLUMNA ELEGIDA)
							}
	
						}
						else{ valb3--; valb3++; } //ERROR DE SELECCION DE VALOR DE COLUMNA				
					}
				}
				
				confb3++; f=-1; c=-1; infcolum=0; bart3--; system("cls"); totbarc--;
			    		
			break;
			    		
		    case '4': // BARCO TAMAÑO OOOO
					
				if(valb4==1){ printf("\n\t\t\t\tNO PUEDES ESCOGER MAS ESTE TIPO DE BARCO\n\t\t\t\t"); system("pause"); bart4++; totbarc++; }
					
		    	while(valb4==0){ cont=0; system("cls");
					printf("\n\t\t\t\t\t\t  BARCO OOOO:\n\n");
					    		
					if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
								
						printf("\n\t\t\tINDIQUE LAS COORDENADAS A LAS CUALES DESEA COLOCAR EL PUNTO INICIAL\n\n");
						printf("\t\t\t NOTA: PRIMERO INDIQUE LA LETRA DE COLUMNA (EN MAYUS) Y \n");
						printf("\t\t\t       POR CONSIGUIENTE EL NUMERO DE FILA\n");
						selfila=0;
						printf("\t\t\tY:");
						scanf("%c",&y); fflush(stdin);
						Cambio_Columna();
							
						if(c>=0 && c<=7){ //VALOR DE COLUMNA DENTRO DEL RANGO
							while(selfila==0){
								if(infcolum==1){
									printf("\n\t\t\t\t\t\t  BARCO OOOO:\n\n");
	
									if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
									    		
									printf("\n\t\t\tINDIQUE LAS COORDENADAS A LAS CUALES DESEA COLOCAR EL PUNTO INICIAL\n\n");
									printf("\t\t\t NOTA: PRIMERO INDIQUE LA LETRA DE COLUMNA (EN MAYUS) Y\n");
									printf("\t\t\t       POR CONSIGUIENTE EL NUMERO DE FILA\n");
									printf("\t\t\tY:%c\n",y);
								}
								printf("\t\t\tX:");
								scanf("%c",&x); fflush(stdin);
								Cambio_Fila();
										
								if(f>=0 && f<=7){ 	//VALOR DE FILA DENTRO DEL RANGO
									if(naves[z][f][c]=='~'){
										while(cont==0){ naves[z][f][c]='O';
											system("cls");
											printf("\n\t\t\t\t\tUBICACION DEL BARCO: OOOO\n\n");
														
											if(z==0){ Display_Tb_J1();} else if(z==1){ Display_Tb_J2();}
																
											printf("\n\n\t\t\t\t\tELIJA LA ORIENTACION DEL BARCO\n\n");
											printf("\t\t\tNOTA: SI TODAS LAS ORIENTACIONES OBSTACULIZAN CON ALGUNOS DE\n\t\t\tLOS BARCOS, PUEDE VOLVER A ESCOJER LAS COORDENADAS\n\n");
											printf("\t\t\t\t\t[1: ARRIBA ]\t[2: ABAJO]\n\t\t\t\t\t[3: IZQUIERDA]\t[4: DERECHA]\n\n\t\t\t\t\t[5:CAMBIAR COORDENADAS]\n");
											printf("\n\t\t\t\t\t\t    X:");
											scanf("%c",&orint); fflush(stdin);
														
											switch(orint){
												case '1': m=f-1; n=f-2; o=f-3; 	//ORIENTACION (ARRIBA) BARCO OOOO
													if(m!=-1 && n!=-1 && o!=-1){
														if( (naves[z][f-1][c]!='O') && (naves[z][f-2][c]!='O') && (naves[z][f-3][c]!='O') ){
															naves[z][f-1][c]='O'; naves[z][f-2][c]='O'; naves[z][f-3][c]='O';
															cont++; selfila++; valb4++;
															m=0; n=0; o=0;
														}
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;	
																				
												case '2': m=f+1; n=f+2; o=f+3;	//ORIENTACION (ABAJO) BARCO OOOO
													if(m!=8 && n!=8 && o!=8){
														if( (naves[z][f+1][c]!='O') && (naves[z][f+2][c]!='O') && (naves[z][f+3][c]!='O') ){
															naves[z][f+1][c]='O'; naves[z][f+2][c]='O'; naves[z][f+3][c]='O';
															cont++; selfila++; valb4++;
															m=0; n=0; o=0;
														}
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }
													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;
													
												case '3': m=c-1; n=c-2; o=c-3;	//ORIENTACION (IZQUIERDA) BARCO OOOO
													if(m!=-1 && n!=-1 && o!=-1){
														if( (naves[z][f][c-1]!='O') && (naves[z][f][c-2]!='O') && (naves[z][f][c-3]!='O') ){
															naves[z][f][c-1]='O'; naves[z][f][c-2]='O'; naves[z][f][c-3]='O';
															cont++; selfila++; valb4++;
															m=0; n=0; o=0;
														}
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }

													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;

												case '4': m=c+1; n=c+2; o=c+3; //ORIENTACION (DERECHA) BARCO OOOO
													if(m!=8 && n!=8 && o!=8){
														if((naves[z][f][c+1]!='O') && (naves[z][f][c+2]!='O') && (naves[z][f][c+3]!='O') ){
															naves[z][f][c+1]='O'; naves[z][f][c+2]='O'; naves[z][f][c+3]='O';
															cont++; selfila++; valb4++;
															m=0; n=0; o=0;
														}
														else{ printf("\n\t\tLA ORIENTACION DE SU NAVE ESTA SOBREPONIENDO OTRA NAVE,SELECCIONE OTRA\n\t\t\t\t"); system("pause"); system("cls"); }

													}
													else{ printf("\n\t\t\tLA ORIENTACION DEL BARCO SOBREPASA LOS LIMITES DEL TABLERO\n\t\t\t"); system("pause"); system("cls"); }
																
												break;
																
												case'5': cont++; infcolum=0; selfila++; naves[z][f][c]='~'; f=-1; c=-1; system("cls"); break;
												
												default: printf("\n\t\t\t\tESCOJA UNA ORIENTACION VALIDA\n\t\t\t\t"); system("pause"); system("cls");
											}
														
										}
													
									}
									else if(naves[z][f][c]=='O'){ printf("\n\t\t\t\tESTA COORDENADA YA ESTA OCUPADA\n\t\t\t\t"); system("pause"); system("cls"); selfila++; infcolum=0; f=-1; c=-1; }
												
								}
								else{ infcolum=1; } //ERROR DE SELECCION DE VALOR DE FILA (SE MUESTRA INFO CON LA COLUMNA ELEGIDA)
							}			
						}
						else{ valb4--; valb4++; } //ERROR DE SELECCION DE VALOR DE COLUMNA
				}
					
					f=-1; c=-1; infcolum=0; bart4--; system("cls"); totbarc--;
					
		    break;
		    		
		    default: printf("\n\t\t\t\t( NOTA: SELECCIONE UN TIPO DE BARCO VALIDO )\n\n\t\t\t\t  "); system("pause"); system("cls"); fflush(stdin);
		    			
		}
		}	
	}
	totbarc=5; //SE RESETEA EL VALOR DE LOS BARCOS TOTALES PARA EL SIGUIENTE JUGADOR
}
void main(){

	Tableros(); //SE RELLENAN TODOS LOS TABLEROS (ATAQUE & POSICIONAMIENTO) CON EL VALOR INICIAL "~"
		
		printf("\n\n\t\t\t\t\tANTES DE EMPEZAR, RECUERDA QUE...");
		printf("\n\n\t\t| ES REQUERIDO ACTIVAR MAYUS CON EL FIN DE DETECTAR ALGUNAS OPCIONES CORRECTAMENTE |\n\n\t\t\t\t\t");
		system("pause"); system("cls");
		
	while(cmjug==0){ opc=0; opc1=0;	//PANTALLA DE TITULO	
	    printf("\n\n\t\t\t\t\t\tBATTLESHIP: THE GAME (v1.0)\n"); 	
	    printf("\t\t\t\t\t\tCREADO POR: JEAN RIVAS\n\n");
	    printf("\t\t\t\t\tA) INICIAR NUEVA PARTIDA (2 JUGADORES)\n");
	    printf("\t\t\t\t\tB) REGLAS DEL JUEGO\n\n");
	    printf("\t\t\t\t\tX:");
	    scanf("%c",&opc1);
	    fflush(stdin);
	    
	    switch(opc1){
	    	case 'A': system("cls");	    	
				while(opc==0){
		    		printf("\n\n\t\tSELECCIONAR LA DIFICULTAD:\n\n");
		    		printf("\t\tNOTA: FACIL: AYUDA PARA DETECTAR FACILMENTE LOS BARCOS DE LOS OPONENTES.\n");
		    		printf("\t\t      DIFICIL: PARA PARTIDAS MUCHO MAS INTERESANTES, NO HAY DETECCION DE BARCOS.\n\n");
		    		printf("\t\t\t\t[A: FACIL]\t[B: DIFICIL]\t[C: REGRESAR]\n\n\n");
		    		printf("\t\t\t\tX:"); scanf("%c",&opc1); fflush(stdin);
		    		
			    	switch(opc1){  //DIFICULTAD SELECCIONADA
			    		case 'A': sdif='A'; system("cls"); opc++; cmjug++; break;
			    		case 'B': sdif='B'; system("cls"); opc++; cmjug++; break;
			    		case 'C': opc++; system("cls"); break;
			    		default: printf("\n\t\t\t\tOPCION DE DIFICULTAD NO VALIDA, INGRESE OTRA VEZ\n\t\t\t\t"); system("pause"); system("cls");
					}	
				}
			 break;
				
	    	case'B':
	    		system("cls"); 	//SE MUESTRAN LAS REGLAS
	    		printf("\n\t\tREGLAS GENERALES DEL JUEGO:\n\n");
	    		printf("\t\tBIENVENIDOS A BATTLESHIP, EL OBJETIVO DE ESTE JUEGO ES EL DE ELIMINAR\n");
	    		printf("\t\tLA FLOTA DE SUS RESPECTIVOS OPONENTES. EL PRIMERO EN CONSEGUIR 14 PUNTOS\n");
	    		printf("\t\tES EL VENCEDOR DE LA PARTIDA (DE MOMENTO SOLO MODO DE 2 JUGADORES)\n\n"); printf("\t\tO: SELECCION DE COORDENADAS:\n\n");
	    		printf("\t\tA CADA JUGADOR LE CORRESPONDE UBICAR SUS CINCO BARCOS (DE DIFERENTES CLASES)\n");
	    		printf("\t\tDENTRO DEL RANGO DE UN TABLERO 8X8, LOS BARCOS NO PUEDEN EXCEDER LOS\n");
	    		printf("\t\tLIMITES O SOBREPONER OTROS PREVIAMENTE UBICADOS.\n\n"); printf("\t\tO: JUEGO EN CURSO:\n\n");
	    		printf("\t\tUNA VEZ EN PARTIDA, POR TURNOS, CADA JUGADOR TENDRA LA OPORTUNIDAD DE\n");
	    		printf("\t\tSELECCIONAR UNA COORDENADA ESPECIFICA, EL PROGRAMA LE INFORMARA SI\n");
	    		printf("\t\tLOS JUGADORES HAN ATINADO A UNO DE LOS PUNTOS DEL BARCO, O SIMPLEMENTE\n");
	    		printf("\t\tHAN COLOCADO EL PUNTO SIN EFECTO ALGUNO.\n\n\t\t\t\t"); system("pause"); system("cls");
	    	
			break;
	    	
			default:
				printf("\n\t\t\t\tASEGURATE DE ACTIVAR MAYUS Y/O DE SELECCIONAR UNA OPCION VALIDA\n\t\t\t\t\t"); system("pause"); system("cls");
		}			
	}
    
	Jugadores();

	do{		//SE MUESTRAN LOS NOMBRES PARA CONFIRMAR
		printf("\n\t\t\t\t\tNOMBRES DE LOS JUGADORES:\n\n");
        printf("\t\t\t\t\t J1: %s\n",jug1);
        printf("\t\t\t\t\t J2: %s\n",jug2);
        printf("\n\t\t\t\t|  CONFIRMAR NOMBRES O CAMBIARLOS  |\n\n");
        printf("\t\t\t\t   [1:CONFIRMAR]\t[0:CAMBIAR]\n\n");
        printf("\t\t\t\t\t\tX:");
        scanf("%c",&opc1); fflush(stdin);
            
		switch(opc1){ 	//OPCION DE SI DESEA VOLVER A EDITAR LOS NOMBRES
			case '0': system("cls"); Jugadores(); break;
			case '1': nomval++; system("cls"); break;
			default: printf("\n\t\t\t\tOPCION NO VALIDA, INTENTE DE NUEVO\n\t\t\t\t"); system("pause"); system("cls");												
		}	

	}while(nomval==0);
	
	for(z=0;z<2;z++){ Coordenadas(); } //AMBOS JUGADORES ORIENTAN LA POSICION DE SUS 5 NAVES EN EL TABLERO

	if(sdif=='A' || sdif=='B'){ Juego(); } //SELECCCION DE DIFICULTAD BASADO EN LA ELECCION DEL USUARIO

	Resultados(); //AL OBTENER UNO DE LOS JUGADORES (LOS 14 PUNTOS) SE REGRESA AL PROGRAMA PRINCIPAL Y ACCEDE A ESTA FUNCION
	
	while(salid==0){ 	//SE PREGUNTA SI DESEA VOLVER A JUGAR
		printf("\n\t\t\tEN CASO DE QUERER JUGAR OTRA PARTIDA, INGRESE LA OPCION CORRESPONDIENTE\n\n");
		printf("\t\t\t\t[A: INICIAR OTRA PARTIDA]\t[B: SALIR DEL JUEGO]");
		printf("\n\n\t\t\t\t\t\t\t  X:");
		scanf("%c",&opc1);fflush(stdin);
		
		switch(opc1){
			case 'A': system("cls"); cmjug=0; pjug1=0; pjug2=0; main(); break;
			case 'B': exit(-1);	break;
			default: printf("\n\t\t\t\tOPCION NO VALIDA, SELECCIONE UNA VALIDA\n\t\t\t\t"); system("pause"); system("cls");	
		}		
	
	}
}
