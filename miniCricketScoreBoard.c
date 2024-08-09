#include<stdio.h>
int windeclr1(int tot_runs,int target){
    if(tot_runs>=target){
        int breflag=0;
        printf("Attacking team wins with 0 wickets");
        return 1;
    }
    return 0;
}
int windeclr2(int tot_runs,int target){
    if(target>=tot_runs){
        int runslef=target-tot_runs;
        printf("Defending team wins with %d runs",runslef);
        return 1;
    }
    return 0;
}
int team1bat(int i,int j,int over,int ball,int target,int firstbatter){
    int runs,tot_runs=0,breflag=0;
    printf("Team 1 runs\n");
    for(i=1;i<=over;i++){
        for(j=1;j<=ball;j++){
            printf("Enter runs at : %d %d : ",i,j);
            scanf("%d",&runs);
            tot_runs=runs+tot_runs;
            if(firstbatter==1){
                breflag=windeclr1(tot_runs,target);
                if(breflag==1){
                    break;
                }
            }
        }
    }
    windeclr2(tot_runs,target);
    return tot_runs;
}
int team2bat(int i,int j,int over,int ball,int target,int firstbatter){
    int runs,runslef,tot_runs=0,breflag=0;
    printf("Team 2 runs\n");
    for(i=1;i<=over;i++){
        for(j=1;j<=ball;j++){
            printf("Enter runs at : %d %d : ",i,j);
            scanf("%d",&runs);
            tot_runs=runs+tot_runs;
            if(firstbatter==1){
                breflag=windeclr1(tot_runs,target);
                if(breflag==1){
                    break;
                }
            }
        }
    }
    windeclr2(tot_runs,target);
    return tot_runs;
}
void main(){
    int team1scr,team2scr,over,ball=6,i,j,target=0,desci1,rand,runs,tot_runs=0,firstbatter=0,breflag=0;
    printf("Enter overs: ");
    scanf("%d",&over);
    printf("Enter random Number:  ");
    scanf("%d",&rand);
    if(rand%2==0){
        printf("Team 1 captain win toss");
        printf(" Choose 1=bat 0=ball: ");
        scanf("%d",&desci1);
        if(desci1==1){
            // first bat
            printf("1st Inn\n");
            firstbatter=0;
            team1scr=team1bat(i,j,over,ball,target,firstbatter);
            target=team1scr+1;
            printf("\nTotal runs scored by team 1 are: %d",team1scr);
            printf("\nTarget is: %d",target);
            printf("\n\n2nd Inn\n");
            firstbatter=1;
            team2scr=team2bat(i,j,over,ball,target,firstbatter);
            printf("\nTotal runs scored by team 2 are: %d",team2scr);
        }
        else{
            printf("1st Inn\n");
            firstbatter=0;
            team2scr=team2bat(i,j,over,ball,target,firstbatter);
            target=team2scr+1;
            printf("\nTotal runs scored by team 2 are: %d",team2scr);
            printf("\nTarget is: %d",target);
            printf("\n\n2nd Inn\n");
            firstbatter=1;
            team1scr=team1bat(i,j,over,ball,target,firstbatter);
            printf("\nTotal runs scored by team 1 are: %d",team1scr);
        }
    } // if (above) part is sorted
    else{
        printf("Team 2 captain win toss");
        printf(" Choose 1=bat 0=ball: ");
        scanf("%d",&desci1);
        if(desci1==1){
            // first bat
            printf("1st Inn\n");
            firstbatter=0;
            team2scr=team2bat(i,j,over,ball,target,firstbatter);
            target=team2scr+1;
            printf("\nTotal runs scored by team 2 are: %d",team2scr);
            printf("\nTarget is: %d",target);
            printf("\n\n2nd Inn\n");
            firstbatter=1;
            team1scr=team1bat(i,j,over,ball,target,firstbatter);
            printf("\nTotal runs scored by team 1 are: %d",team1scr);
            
        }
        else{
            printf("1st Inn\n");
            firstbatter=0;
            team1scr=team1bat(i,j,over,ball,target,firstbatter);
            target=team1scr+1;
            printf("\nTotal runs scored by team 1 are: %d",team1scr);
            printf("\nTarget is: %d",target);
            printf("\n\n2nd Inn\n");
            firstbatter=1;
            team2scr=team2bat(i,j,over,ball,target,firstbatter);
            printf("\nTotal runs scored by team 2 are: %d",team2scr);
        }
    }
}