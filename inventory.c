#include <stdio.h>

struct item 
{
	char name[256];
	int quantity;	
};

struct item* ReadFile(char *filename, int *count);
void WriteFile(char *filename, struct item *inv, int count);

int main(int argc, char **argv)
{
	int N;
	int i;
	int select;
	struct item* inv = ReadFile(argv[1], &N);
	while(1)
	{
		for(i = 0; i < N; i++)
		{
			printf("%d: %s %d\n",(i+1),inv[i].name,inv[i].quantity);
		}
		printf(">> ");
		int sval = scanf("%d", &select);
		
		if( sval == 0 )
		{
			break;
		}
	
		select -= 1;
		if( select > N )
		{
			struct item *temp_inv = malloc( (N+1) * sizeof(struct item));
			for(i=0;i<N;i++)
			{
				temp_inv[i] = inv[i];
			}
			free(inv);
			inv = temp_inv;
			printf(" NAME?>> ");
			char newname[256];
			int amt;
			scanf("%s",newname);
			printf(" HOW MUCH?>> ");
			scanf("%d",&amt);
			strcpy(inv[N].name,newname);
			inv[N].quantity = amt;
			N++;
		}
		else
		{
			//Modify existing
			int amt;
			printf(" HOW MUCH?>> ");
			scanf("%d",&amt);
			inv[select].quantity += amt;

		}
	}

	WriteFile(argv[1],inv,N);
	return 0;
}


void WriteFile(char *filename, struct item *inv, int count)
{
	int i;
	FILE *fp;
	fp = fopen(filename,"w");
	fprintf(fp,"%d\n",count);
	for(i = 0; i < count; i++)
	{
		fprintf(fp,"%s,%d\n",inv[i].name,inv[i].quantity);
	}
	fclose(fp);

}

struct item* ReadFile(char *filename, int *count)
{
	struct item* inventory;
	int i;
	FILE *fp;
	char ctemp[256];
	int itemp;
	fp  = fopen(filename,"r");
	fscanf(fp,"%d\n",count);

	inventory = malloc( sizeof(struct item) * (*count));

	for(i=0;i< *count;i++)
	{
		fscanf(fp,"%[^,],%d\n",ctemp,&itemp);
		strcpy(inventory[i].name,ctemp);
		inventory[i].quantity = itemp;
	}
	

	fclose(fp);


	return inventory;
}
