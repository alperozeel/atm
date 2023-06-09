#include <stdio.h>
#include <stdbool.h>


enum Islem{
	bakiyeSorgu = 1,
	paraCek,
	paraYatir,
	paraHavale,
	kartIade,
	islemGoruntule
};

void islemEkrani(){
	printf("ISLEMLER :\n\n\
1:Bakiye Sorgulama\n\
2:Para Cekme\n\
3:Para Yatirma\n\
4:Havale Yapma\n\
5:Kart Iade\n\
6:Islem goruntule\n");
}

void hosgeldinEkrani(){
	printf("                                   \n");
	printf("          ******  HOS GELDINIZ  ******\n\n\n");
	islemEkrani();
}

void paraCekk(int *bakiye){
	int tutar = 0;
	printf("Bakiyeniz: %dTL\n", *bakiye);
	printf("Cekmek Istediginiz Tutar: ");
	scanf("%d",&tutar);
	
	if (tutar > *bakiye) {
    	printf("Bakiyeniz Yetersiz.\n");
	}
	else {
	   *bakiye -= tutar;
	   printf("Kalan Bakiyeniz: %d\n", *bakiye);
	}  
}

void paraYatirr(int *bakiye){
	int tutar = 0;
	printf("Bakiyeniz: %d\n", *bakiye);
	printf("Yatirmak Istediginiz Tutar: ", tutar);
	scanf("%d",&tutar);
	
	*bakiye += tutar;
	
	printf("Yeni Bakiyeniz: %d\n", *bakiye);
}

void paraHavalee(int *bakiye){
	int tutar = 0;
	printf("Bakiyeniz: %d\n", *bakiye);
	printf("Havale Etmek Istediginiz Tutar: ", tutar);
	scanf("%d",&tutar);
	
	if (tutar > *bakiye) {
	printf("Bakiyeniz Yetersiz.\n");
	}
	
	if (tutar <= *bakiye) {
	
	*bakiye -= tutar;
	
	printf("Yeni Bakiyeniz: %d", *bakiye);
	}	
}

int main() {
	
	enum Islem islem;
	int bakiye =1000;
	bool kartIadeEdilsinMi = false;
	
	hosgeldinEkrani();
	
	while(!kartIadeEdilsinMi){

		printf("Yapmak istediginiz islemin numarasini girin:");
		scanf("%d",&islem);
	
		switch (islem) {
			
			case bakiyeSorgu: 
	     	   printf("Bakiyeniz:%d TL\n",bakiye);
	           break;
		    
		    case paraCek:
				paraCekk(&bakiye);
				break;
					   
		    case paraYatir: 
				paraYatirr(&bakiye);
				break;
		           
		    case paraHavale:
				paraHavalee(&bakiye);
		    	break;
		    
		    	   
		    case kartIade:
		    	   printf("Kartiniz Iade Ediliyor.\n");
		    	   kartIadeEdilsinMi = true;
		           break;
				
			case islemGoruntule:
				islemEkrani();
				break;
			
			default : 
			        printf("Yanlis Bir Numara Girdiniz, Lutfen Tekrar Deneyin.\n");
				
				break;
		}
	}
	
	return 0;
	
}
