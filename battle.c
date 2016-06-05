#include <stdio.h>
//#include <conio.h>

void add4(int *[10]);
void add3(int *[10]);
void add2(int *[10]);
void add1(int *[10]);
void shot(int *[10],int *[10]);

int first[10][10],second[10][10],first2[10][10],second2[10][10];
/*
first - массив для размещенния кораблей первого игрока
second- массив для размещения кораблей второго игрока
first2- массив для выстрелов первого игрока
second2- массив для выстрелов второго игрока
*/
int main(int argc, char const *argv[])
{
	int i,j;
//	add4(&first[10][10]);
	for (i=0;i<10;++i){
		for (j=0;j<10;++j)
			printf("%d ",first[i][j]);
		printf("\n");
	}
	return 0;
}

void add4(int *a[10]){
	int a1x,a1y,b1x,b1y,bufx,bufy;
		printf("Введите координаты первой палубы четырехпалубного корабля\n");
		scanf("%d %d",&a1x,&a1y);
		printf("Введите координаты четвертой палубы четырехпалубного корабля\n");
		scanf("%d %d",&b1x,&b1y);
		if ((a1x==b1x || b1y==a1y) && ((b1x-a1x)/3==0) || ((b1y-a1y)/3==0)){
			a[a1x][a1y]=1;
			a[b1x][b1y]=1;
			if (a1x==b1x){
				if (b1y<a1y){
					bufy=a1y;
					a1y=b1y;
					b1y=bufy;
				}
				a[a1x][a1y+1]=1;
				a[a1x][a1y+2]=1;
			}
			else{
				if (b1x<a1x){
					bufx=a1x;
					a1x=b1x;
					b1x=bufx;
				}
				a[a1x+1][a1y]=1;
				a[a1x+2][a1y]=1;
			}
		}
}

void add3(int *a[10]){
	int a1x,a1y,b1x,b1y,bufx,bufy;
		printf("Введите координаты первой палубы трехпалубного корабля\n");
		scanf("%d %d",&a1x,&a1y);
		printf("Введите координаты третьей палубы трехпалубного корабля\n");
		scanf("%d %d",&b1x,&b1y);
		if ((a1x==b1x || b1y==a1y) && ((b1x-a1x)/2==0) || ((b1y-a1y)/2==0)){
			a[a1x][a1y]=1;
			a[b1x][b1y]=1;
			if (a1x==b1x){
				if (b1y<a1y){
					bufy=a1y;
					a1y=b1y;
					b1y=bufy;
				}
				a[a1x][a1y+1]=1;
			}
			else{
				if (b1x<a1x){
					bufx=a1x;
					a1x=b1x;
					b1x=bufx;
				}
				a[a1x+1][a1y]=1;
			}
		}
}

void add2(int *a[10]){
	int a1x,a1y,b1x,b1y;
		printf("Введите координаты первой палубы двуххпалубного корабля\n");
		scanf("%d %d",&a1x,&a1y);
		printf("Введите координаты второй палубы двухпалубного корабля\n");
		scanf("%d %d",&b1x,&b1y);
		if ((a1x==b1x || b1y==a1y) && ((b1x-a1x)/2==0) || ((b1y-a1y)/2==0)){
			a[a1x][a1y]=1;
			a[b1x][b1y]=1;
		}
}

void add1(int *a[10]){
	int ax,ay;
		printf("Введите координаты однопалубного корабля\n");
		scanf("%d %d",&ax,&ay);
		a[ax][ay]=1;
}

void shot(int *a[10],int *b[10]){
	int x,y;
	printf("Введите координаты вашего выстрела\n");
	scanf("%d %d",&x,&y);
	if (a[x][y]==1){
		printf("Вы попали!\n");
		a[x][y]=5;
		b[x][y]=5;
	}
	else{
		printf("Вы не попали\n");
		a[x][y]=2;
		b[x][y]=2;
	}
}