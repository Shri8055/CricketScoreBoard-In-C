#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define TEAM_SIZE 11
void main(){
// Team India
    typedef struct{
    int player_id;
    char player_name[100],player_type[100];
    }Player;
    Player teamInd[TEAM_SIZE];
// Variables declarations
    char toss,face;
    int desci1,desci2,Indbatflag=0,Pakbatflag=0,Indbawlflag=0,Pakbawlflag=0,over,ball=6,i,j,wickets=0,runs=0,strike=1,tot_runs=0,target;
    float rr=0.0;
    int Indplayer_col1[TEAM_SIZE]={0},Indplayer_col2[TEAM_SIZE]={0};
    int Pakplayer_col1[TEAM_SIZE]={0},Pakplayer_col2[TEAM_SIZE]={0};
    const char *Indplayer_names[TEAM_SIZE]={
        "Virat Kohli (c)", "Shikhar Dhavan", "Rohit Sharma", "KL Rahul", "MS Dhoni",
        "Ravindra Jedeja", "Hardik Pandya", "Bhuneshwar Kumar", "Kuldeep Yadav", "Yuzi Chahal",
        "Jasprit Bhumrah"
    };
    const char *Indplayer_types[TEAM_SIZE]={
        "Right hand Batsman", "Left Hand Batsman", "Right Hand Batsman", "Right Hand Batsman", "Right Hand Batsman (wk)",
        "All-Rounder,Left hand batsman,spin", "All-rounder,Right Hand Batsman,pace", "Right Hand Bowler,spin", "Right hand Bowler,pace", "Right hand Bowler,spin", "Right Hand Bowler,spin"
    };
      for(i=0;i<TEAM_SIZE;i++){
        teamInd[i].player_id=i+1;
        strncpy(teamInd[i].player_name,Indplayer_names[i],sizeof(teamInd[i].player_name)-1);
        teamInd[i].player_name[sizeof(teamInd[i].player_name)-1]='\0';
        strncpy(teamInd[i].player_type, Indplayer_types[i],sizeof(teamInd[i].player_type)-1);
        teamInd[i].player_type[sizeof(teamInd[i].player_type)-1]='\0';
    }
    printf("\n\n\t\t\tTeam INDIA\n\n");
    for(i=0;i<TEAM_SIZE;i++){
        printf("%d ) : %s == ",teamInd[i].player_id,teamInd[i].player_name);
        printf(" %s\n\n",teamInd[i].player_type);
    }
// Team Pakistan
    Player teamPak[TEAM_SIZE];
    const char *Pakplayer_names[TEAM_SIZE]={
        "Sarfaraz Ahmad (c)", "Asif Ali", "Babar Azam", "Imam-ul-Haq", "Imad Wasim",
        "Mohammad Hafeez", "Hasan Ali", "Shaheen Afradi", "Wahab Riaz", "Junaid khan",
        "Mohammad Amir"
    };
    const char *Pakplayer_types[TEAM_SIZE]={
        "Right hand Batsman", "Right Hand Batsman", "Right Hand Batsman (wk)", "left Hand Batsman", "All-Rounder,Left hand batsman,spin",
        "All-Rounder,right hand batsman,pace", "Right Hand Bowler,pace", "Left Hand Bowler,pace", "Left hand Bowler,spin", "Right hand Bowler,pace", "Left Hand Bowler,spin"
    };
    for(i=0;i<TEAM_SIZE;i++){
        teamPak[i].player_id=i+1;
        strncpy(teamPak[i].player_name,Pakplayer_names[i],sizeof(teamPak[i].player_name)-1);
        teamPak[i].player_name[sizeof(teamPak[i].player_name)-1]='\0';
        strncpy(teamPak[i].player_type, Pakplayer_types[i], sizeof(teamPak[i].player_type)-1);
        teamPak[i].player_type[sizeof(teamPak[i].player_type)-1]='\0';
    }
    printf("\n\n\t\t\tTeam PAKISTAN\n\n");
    for(i=0;i<TEAM_SIZE;i++){
        printf("%d ) : %s == ",teamPak[i].player_id, teamPak[i].player_name);
        printf(" %s\n\n",teamPak[i].player_type);
    }
// Toss
    printf("\n\n\t\t          0 0 0 0 0\n\t\t        0           0\n\t\t      0         /     0\n\t\t    0  H   H   / TTTTT  0\n\t\t    0  H   H  /    T    0\n\t\t    0  HHHHH /     T    0\n\t\t    0  H   H/      T    0\n\t\t      0    /          0\n\t\t        0           0\n\t\t          0 0 0 0 0\n      ");
    printf("\n\n\t    Enter 'h'/'H' heads or 't'/'T' Tails.");
    printf("\n\t\tTeam IND select coin face: ");
    scanf("%c",&face);
    srand(time(NULL));
    desci1=rand();
    if(face=='h' && desci1%2==0){
        // if INDIA wins the toss
        printf("\n\t\t    ! Ind win the toss !");
        printf("\n\n\t      Select 1 for bat and 2 for ball: ");
        scanf("%d",&desci2);
        if(desci2==1){
            // if INDIA choose to bat
            printf("\n\t    %s selected to bat first",teamInd[0].player_name);
            printf("\n\t\t  1st Inning will start soon");
            printf("\n\n############# Controls switched to umpire #############");
            printf("\n\n\tEnter total overs:  ");
            scanf("%d",&over);
            printf("Strike on %s\n",teamInd[0].player_name);
            for(i=1;i<=over;i++){
                for(j=1;j<=ball;j++){
                    if(i<=over||wickets==10){
                        printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                        printf("\nScoreBoard:\n\n1st INNINGS =>\n\n===================================================================\n\nIND batting\t\t\t\t\t\tPak Bowling");
                        printf("\nEnter runs at %d.%d: ",i,j);
                        scanf("%d",&runs);
                        if(runs==-1){
                            printf("Player %s is out!",strike==1?teamInd[0].player_name:teamInd[1].player_name);
                            wickets++;
                        }
                        else{
                            if(strike==1){
                                Indplayer_col1[0]+=runs;
                                Indplayer_col2[0]++;
                                printf("\n\n%s * = %d,%d\t\t   %s = %d.%d\n^--->%s\t\t\t^--->%s",teamInd[0].player_name,Indplayer_col1[0],Indplayer_col2[0],teamPak[10].player_name,i,j,teamInd[0].player_type,teamPak[10].player_type);
                                printf("\n\n%s = %d,%d\n^--->%s\n",teamInd[1].player_name,Indplayer_col1[1],Indplayer_col2[1],teamInd[1].player_type);
                            }
                            else{
                                Indplayer_col1[1]+=runs; 
                                Indplayer_col2[1]++;
                                printf("\n\n%s = %d,%d\t\t   %s = %d.%d\n^--->%s\t\t\t^--->%s",teamInd[0].player_name,Indplayer_col1[0],Indplayer_col2[0],teamPak[10].player_name,i,j,teamInd[0].player_type,teamPak[10].player_type);
                                printf("\n\n%s * = %d,%d\n^--->%s\n",teamInd[1].player_name,Indplayer_col1[1],Indplayer_col2[1],teamInd[1].player_type);
                            }
                            tot_runs+=runs;
                            if(runs%2==0){
                                strike=(strike==1)?2:1;
                            }
                            printf("\n\t\t\t  |  IND %d / %d  |\n",tot_runs,wickets);
                            if(strike==2){
                                printf("\n%s is on strike\n",teamInd[0].player_name);
                            }
                            else{
                                printf("\n%s is on strike\n",teamInd[1].player_name);
                            }
                            printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                        }
                    }
                    strike=(strike==1||j==6)?2:1;
                    printf("\n");
                }
                target=tot_runs+1;
                printf("\nTotal score from this over: %d\n",tot_runs);
                printf("%s Scored %d runs in %d balls",teamInd[0].player_name,Indplayer_col1[0],Indplayer_col2[0]);
                printf("\n%s Scored %d runs in %d balls",teamInd[1].player_name,Indplayer_col1[1],Indplayer_col2[1]);
            }
            rr=(float)target/(float)(over*6);
            printf("\nIndia set target of %d runs.\nNeed avarage run rate of %.2f",target,rr);
        }
        else if(desci2==2){
            // if India choose to bawl
            printf("\n%s selected to bawl first",teamInd[0].player_name);
        }
        else{
            printf("Select proper side");
        }
    }
    else if(face=='t' && desci1%2==1){
        printf("\nPak win the toss");
        printf("\nSelect 1 for bat and 2 for ball: ");
        printf("Switched to Inning 2nd.");
        scanf("%d",&desci2);
        if(desci2==1){
            printf("\n%s selected to bat first",teamPak[0].player_name);
        }
        else if(desci2==2){
            printf("\n%s selected to bawl first",teamPak[0].player_name);
        }
        else{
            printf("Select proper side");
        }
    }
    else{
        printf("Select proper side");
    }
}