#include <stdio.h>

int main() {
	int disk,i,j;
	char s[15]="Source";
	char a[20]="Auxiliary";
	char d[20]="Destination";
	printf("How many disks : ");
	scanf("%d",&disk); //jika jumlah disk genap maka akan berpindah ke auxiliary semuanya
					   //jika ganjil berpindah ke destination
	int rods[disk+1],roda[disk+1],rodd[disk+1],temp;
	int disks=disk,diska=0,diskd=0;
	int move=(1<<disk)-1; //1<<n = 2^n, rumus langkah hanoi tower = 2^n-1, n=jumlah disk
	/*
	susunan disk mula-mula (paling kiri paling atas, angka menunjukkan besarnya disk, 1 terkecil)
	source : 1 2 3 4
	auxiliary : 0 0 0 0 (kosong)
	destination : 0 0 0 0 (kosong)
	*/
	for (i=1;i<=disk;i++) {
		rods[i]=i;
		roda[i]=0;
		rodd[i]=0;
	}
	for(j=1;j<=disk;j++) {
		printf("%d ",rods[j]); //menunjukan susunan disk yang ada di rod/batang S (source)
	}
	printf("\n");
	for(j=1;j<=disk;j++) {
		printf("%d ",roda[j]); //menunjukan susunan disk yang ada di rod/batang a (auxiliary)
	}
	printf("\n");
	for(j=1;j<=disk;j++) {
		printf("%d ",rodd[j]); //menunjukan susunan disk yang ada di rod/batang d (destination)
	}
	printf("\n");
	for (i=1;i<=move;i++) {
		//algoritma : jika i%3=1 maka move yang legal adalah dari S ke D or vice versa
		//jika i%3=2 move legal dari S ke A or vice versa
		//jika i%3=0 move legal dari A ke D or vice versa
		//jika disk paling atas di rod D lbh kecil dari disk paling atas di rod A
		//maka disk bisa dipindahkan dr D ke A
		if (i%3==1 && disks==0 && (rodd[1]<roda[1] || roda[1]==0)) { //jika rod S kosong 
			temp=rodd[1];
			diska++;
			diskd--;
			int j=1;
			/*
			misal awalnya
			s : 0 0 0 0
			a : 4 0 0 0
			d : 1 2 3 0
			jadi
			s : 0 0 0 0
			a : 1 4 0 0
			d : 2 3 0 0
			*/
			while (j<=diskd) {
				rodd[j]=rodd[j+1];
				j++;
			}
			int k;
			for (k=diskd+1;k<=disk;k++) {
				rodd[k]=0;
			}
			if (diska>1) {
				for (k=diska;k>=2;k--) {
					roda[k]=roda[k-1];
				}
			}
			roda[1]=temp;
			printf("Move a disk from %s to %s\n",d,a);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
		else if (i%3==1 && (rodd[1]>rods[1] || rodd[1]==0) && disks>0) {
			temp=rods[1];
			diskd++;
			disks--;
			int j=1;
			while (j<=disks) {
				rods[j]=rods[j+1];
				j++;
			}
			int k;
			for (k=disks+1;k<=disk;k++) {
				rods[k]=0;
			}
			if (diskd>1) {
				for (k=diskd;k>=2;k--) {
					rodd[k]=rodd[k-1];
				}
			}
			rodd[1]=temp;
			printf("Move a disk from %s to %s\n",s,d);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
		else if (i%3==1 && (rodd[1]<rods[1] || rods[1]==0) && diskd>0) {
			temp=rodd[1];
			disks++;
			diskd--;
			int j=1;
			while (j<=diskd) {
				rodd[j]=rodd[j+1];
				j++;
			}
			int k;
			for (k=diskd+1;k<=disk;k++) {
				rodd[k]=0;
			}
			if (disks>1) {
				for (k=disks;k>=2;k--) {
					rods[k]=rods[k-1];
				}
			}
			rods[1]=temp;
			printf("Move a disk from %s to %s\n",d,s);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
		else if (i%3==2 && (roda[1]>rods[1] || roda[1]==0) && disks>0) {
			temp=rods[1];
			diska++;
			disks--;
			int j=1;
			while (j<=disks) {
				rods[j]=rods[j+1];
				j++;
			}
			int k;
			for (k=disks+1;k<=disk;k++) {
				rods[k]=0;
			}
			if (diska>1) {
				for (k=diska;k>=2;k--) {
					roda[k]=roda[k-1];
				}
			}
			roda[1]=temp;
			printf("Move a disk from %s to %s\n",s,a);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
		else if (i%3==2 && (roda[1]<rods[1] || rods[1]==0) && diska>0) {
			temp=roda[1];
			disks++;
			diska--;
			int j=1;
			while (j<=diska) {
				roda[j]=roda[j+1];
				j++;
			}
			int k;
			for (k=diska+1;k<=disk;k++) {
				roda[k]=0;
			}
			if (disks>1) {
				for (k=disks;k>=2;k--) {
					rods[k]=rods[k-1];
				}
			}
			rods[1]=temp;
			printf("Move a disk from %s to %s\n",a,s);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
		else if (i%3==0 && (rodd[1]>roda[1] || rodd[1]==0) && diska>0) {
			temp=roda[1];
			diskd++;
			diska--;
			int j=1;
			while (j<=diska) {
				roda[j]=roda[j+1];
				j++;
			}
			int k;
			for (k=diska+1;k<=disk;k++) {
				roda[k]=0;
			}
			if (diskd>1) {
				for (k=diskd;k>=2;k--) {
					rodd[k]=rodd[k-1];
				}
			}
			rodd[1]=temp;
			printf("Move a disk from %s to %s\n",a,d);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
		else if (i%3==0 && (rodd[1]<roda[1] || roda[1]==0) && diskd>0) {
			temp=rodd[1];
			diska++;
			diskd--;
			int j=1;
			while (j<=diskd) {
				rodd[j]=rodd[j+1];
				j++;
			}
			int k;
			for (k=diskd+1;k<=disk;k++) {
				rodd[k]=0;
			}
			if (diska>1) {
				for (k=diska;k>=2;k--) {
					roda[k]=roda[k-1];
				}
			}
			roda[1]=temp;
			printf("Move a disk from %s to %s\n",d,a);
			for(j=1;j<=disk;j++) {
				printf("%d ",rods[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",roda[j]);
			}
			printf("\n");
			for(j=1;j<=disk;j++) {
				printf("%d ",rodd[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
