#include<stdio.h>
#include<string.h>
struct employee{
    char name[20];
    int age;
    char position[20];
    char doj[11];
};
int main(){
    int n,i,j;
    printf("Enter the number of employees: ");
    scanf("%d",&n);
    struct employee emp[n],temp;
    for(i=0;i<n;i++){
        printf("Enter details of employee %d:\n",i+1);
        printf("Name: ");
        scanf("%s",emp[i].name);
        printf("Age: ");
        scanf("%d",&emp[i].age);
        printf("Position: ");
        scanf("%s",emp[i].position);
        printf("Date of joining (dd/mm/yyyy): ");
        scanf("%s",emp[i].doj);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(emp[i].name,emp[j].name)>0){
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
    }
    printf("\nEmployee List sorted by name:\n\n");
    for(i=0;i<n;i++){
        printf("Name: %s\n",emp[i].name);
        printf("Age: %d\n",emp[i].age);
        printf("Position: %s\n",emp[i].position);
        printf("Date of Joining: %s\n\n",emp[i].doj);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            int d1,m1,y1,d2,m2,y2;
            sscanf(emp[i].doj,"%d/%d/%d",&d1,&m1,&y1);
            sscanf(emp[j].doj,"%d/%d/%d",&d2,&m2,&y2);
            if(y1>y2 || (y1==y2 && m1>m2) || (y1==y2 && m1==m2 && d1>d2)){
                temp=emp[i];
                emp[i]=emp[j];
                emp[j]=temp;
            }
        }
    }
    printf("\nEmployee List sorted by date of joining:\n\n");
    for(i=0;i<n;i++){
        printf("Name: %s\n",emp[i].name);
        printf("Age: %d\n",emp[i].age);
        printf("Position: %s\n",emp[i].position);
        printf("Date of Joining: %s\n\n",emp[i].doj);
    }
    return 0;
}