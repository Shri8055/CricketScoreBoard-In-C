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
    int desci1,desci2,over,ball=6,i,j,wickets=0,runs=0,strike=1,tot_runs=0,target,par1,par2,bow,over_runs=0,this_over[ball],tot_overs=1,Indflag=0,Pakflag=0;
    float rr=0.0;
    int Indplayer_col1[TEAM_SIZE]={0},Indplayer_col2[TEAM_SIZE]={0},Indplayer_col3[TEAM_SIZE]={0};
    int Pakplayer_col1[TEAM_SIZE]={0},Pakplayer_col2[TEAM_SIZE]={0},Pakplayer_col3[TEAM_SIZE]={0};
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
    while(1){
        printf("\n\n\t\t          0 0 0 0 0\n\t\t        0           0\n\t\t      0         /     0\n\t\t    0  H   H   / TTTTT  0\n\t\t    0  H   H  /    T    0\n\t\t    0  HHHHH /     T    0\n\t\t    0  H   H/      T    0\n\t\t      0    /          0\n\t\t        0           0\n\t\t          0 0 0 0 0\n      ");
        printf("\n\n\t    Enter 'h'/'H' heads or 't'/'T' Tails.");
        printf("\n\t\tTeam IND select coin face: ");
        scanf("%c",&face);
        srand(time(NULL));
        desci1=rand();
        if(face=='h' || desci1%2==0 ){

    // India

            // if INDIA wins the toss
            printf("\n\t\t    ! Ind win the toss !");
            printf("\n\n\t      Select 1 for bat and 2 for ball: ");
            scanf("%d",&desci2);
            if(desci2==1){
                // if INDIA choose to bat
                Indflag=1;
                Pakflag=0;
                printf("\n\t    %s selected to bat first",teamInd[0].player_name);
                printf("\n\t\t  1st Inning will start soon");
                printf("\n\n############# Controls switched to umpire #############");
                printf("\n\t%s choose opening pair:  ",teamInd[0].player_name);
                scanf("%d %d",&par1,&par2); // captain will select opening pair
                printf("\n\t%s select next bowler:  ",teamPak[0].player_name);
                scanf("%d",&bow);
                printf("\nOpening pairs are :  %s & %s",teamInd[par1].player_name,teamInd[par2].player_name);
                Indplayer_col3[par1]=1;
                Indplayer_col3[par2]=1;
                printf("\nBowler is : %s",teamPak[bow].player_name);
                Pakplayer_col3[bow]=1;
                printf("\n\n\tEnter total overs:  ");
                scanf("%d",&over);
                printf("Strike on %s\n",teamInd[par1].player_name);
                for(i=1;i<=over;i++){ // will run until over finishes
                    for(j=1;j<=ball;j++){ // will run until balls finishes
                        if(i<=over||wickets==10){ // will run when entered overs are finished or wickets are = 10
                            printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                            printf("\nScoreBoard:\n\n1st INNINGS =>\n\n===================================================================\n\nIND batting\t\t\t\t\t\tPak Bowling");
                            printf("\nEnter runs at %d.%d: ",i,j); // counting runs at i(over)th and j(ball)th
                            scanf("%d",&runs);
                            // wickets
                            if(runs==-1){ // if batsman gets out
                                printf("Player %s is out!",strike==1?teamInd[par1].player_name:teamInd[par2].player_name);
                                printf("\n%s select next batsman: ",teamInd[0].player_name);
                                if(strike==1){ // swapping new player to out player // if player 1 is out then new player will play at player 1 position
                                    scanf("%d",&par1);
                                    if(Indplayer_col3[par1]==1){
                                        printf("Player already played cant play again.\nPlease enter DN Bat players: ");
                                        scanf("%d",&par1);
                                    }
                                    else{
                                        printf("New batsman is : %s",teamInd[par1].player_name);
                                        Indplayer_col3[par1]=1;
                                    }
                                }
                                else{ // if player 2 is out then new player will play at player 2 position
                                    scanf("%d",&par2);
                                    if(Indplayer_col3[par2]==1){
                                        printf("Player already played cant play again.\nPlease enter DN Bat players: ");
                                        scanf("%d",&par2);
                                    }
                                    else{
                                        printf("New batsman is : %s",teamInd[par2].player_name);
                                        Indplayer_col3[par2]=1;
                                    }
                                }
                                wickets++; // wickets are incremented by 1
                                if(wickets==10){
                                    printf("\n\t\t  |  IND %d / %d  ||  %d / %d  |\n",tot_runs,wickets,tot_overs,over); // score board banner
                                    break;
                                }
                                printf("\n\t\t  |  IND %d / %d  ||  %d / %d  |\n",tot_runs,wickets,tot_overs,over); // score board banner
                            }
                            // runs
                            else{
                                if(strike==1){ // player 1 runs are calculated
                                    Indplayer_col1[par1]+=runs; // runs count
                                    Indplayer_col2[par1]++; // balls count
                                    Indplayer_col3[par1]=1;
                                    printf("\n\n%s * = %d,%d\t\t   %s = %d.%d\n^--->%s\t\t\t^--->%s",teamInd[par1].player_name,Indplayer_col1[par1],Indplayer_col2[par1],teamPak[bow].player_name,i,j,teamInd[par1].player_type,teamPak[bow].player_type);
                                    printf("\n\n%s = %d,%d\n^--->%s\n",teamInd[par2].player_name,Indplayer_col1[par2],Indplayer_col2[par2],teamInd[par2].player_type);
                                }
                                else{ // player 2 runs are calculated
                                    Indplayer_col1[par2]+=runs; // runs count
                                    Indplayer_col2[par2]++; // balls count
                                    Indplayer_col3[par2]=1;
                                    printf("\n\n%s = %d,%d\t\t   %s = %d.%d\n^--->%s\t\t\t^--->%s",teamInd[par1].player_name,Indplayer_col1[par1],Indplayer_col2[par1],teamPak[bow].player_name,i,j,teamInd[par1].player_type,teamPak[bow].player_type);
                                    printf("\n\n%s * = %d,%d\n^--->%s\n",teamInd[par2].player_name,Indplayer_col1[par2],Indplayer_col2[par2],teamInd[par2].player_type);
                                }
                                over_runs+=runs; // overs runs count
                                tot_runs+=runs; // total runs count
                                if(runs%2==0){ // strike change after odd runs
                                    strike=(strike==1)?2:1;
                                }
                                printf("\n\t\t  |  IND %d / %d  ||  %d / %d  |\n",tot_runs,wickets,tot_overs,over); // score board banner
                                if(strike==2){ // strike pointer
                                    printf("\n%s is on strike\n",teamInd[par1].player_name);
                                }
                                else{
                                    printf("\n%s is on strike\n",teamInd[par2].player_name);
                                }
                                printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                            }
                        }
                        strike=(strike==1||j==6)?2:1; // strike rotation after over finish.
                        printf("\n");
                        if(j==6&&i<over){
                            printf("\nTotal score from this over: %d runs with %d wickets.\n",over_runs,wickets);
                            printf("%s select next bowler:  ",teamPak[0].player_name);
                            scanf("%d",&bow);
                            if(Pakplayer_col3[bow]==1){
                                printf("Player already bowled cant bawl again.\nPlease enter DN Bawl players: ");
                                scanf("%d",&bow);
                            }
                            over_runs=0;
                            tot_overs++;
                        }
                    }
                    target=tot_runs+1; // setting target
                    printf("\n%s  %d ,%d",teamInd[par1].player_name,Indplayer_col1[par1],Indplayer_col2[par1]);
                    printf("\n%s  %d ,%d",teamInd[par2].player_name,Indplayer_col1[par2],Indplayer_col2[par2]);
                }
                rr=(float)target/(float)(over*6); // run rate calculator
                printf("\nIndia set target of %d runs.\nPakistan Need avarage run rate of %.2f",target,rr);
                printf("\n\n\t\t|  Target %d  ||  RR %.2f  |\n\n",target,rr);
                printf("\n\n\t2nd Inning will start soon !...");
            }
            else if(desci2==2){
                // if INDIA choose to bawl
                printf("\n%s selected to bawl first",teamInd[0].player_name);
                break;
            }
            else{
                printf("Select proper side");
            }
        }

    // Pakistan

        if(face=='t' || desci1%2==1){
            // if PAKISTAN wins the toss
            printf("\n\t\t    ! Pak win the toss !");
            printf("\n\n\t      Select 1 for bat and 2 for ball: ");
            scanf("%d",&desci2);
            if(desci2==1){
                // if PAKISTAN choose to bat
                Pakflag=1;
                Indflag=0;
                printf("\n\t    %s selected to bat first",teamPak[0].player_name);
                printf("\n\t\t  1st Inning will start soon");
                printf("\n\n############# Controls switched to umpire #############");
                printf("\n\t%s choose opening pair:  ",teamPak[0].player_name);
                scanf("%d %d",&par1,&par2); // captain will select opening pair
                printf("\n\t%s select next bowler:  ",teamInd[0].player_name);
                scanf("%d",&bow);
                printf("\nOpening pairs are :  %s & %s",teamPak[par1].player_name,teamPak[par2].player_name);
                Pakplayer_col3[par1]=1;
                Pakplayer_col3[par2]=1;
                printf("\nBowler is : %s",teamInd[bow].player_name);
                Indplayer_col3[bow]=1;
                printf("\n\n\tEnter total overs:  ");
                scanf("%d",&over);
                printf("Strike on %s\n",teamPak[par1].player_name);
                for(i=1;i<=over;i++){ // will run until over finishes
                    for(j=1;j<=ball;j++){ // will run until balls finishes
                        if(i<=over||wickets==10){ // will run when entered overs are finished or wickets are = 10
                            printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                            printf("\nScoreBoard:\n\n1st INNINGS =>\n\n===================================================================\n\nIND batting\t\t\t\t\t\tPak Bowling");
                            printf("\nEnter runs at %d.%d: ",i,j); // counting runs at i(over)th and j(ball)th
                            scanf("%d",&runs);
                            // wickets
                            if(runs==-1){ // if batsman gets out
                                printf("Player %s is out!",strike==1?teamPak[par1].player_name:teamPak[par2].player_name);
                                printf("\n%s select next batsman: ",teamPak[0].player_name);
                                if(strike==1){ // swapping new player to out player // if player 1 is out then new player will play at player 1 position
                                    scanf("%d",&par1);
                                    if(Pakplayer_col3[par1]==1){
                                        printf("Player already played cant play again.\nPlease enter DN Bat players: ");
                                        scanf("%d",&par1);
                                    }
                                    else{
                                        printf("New batsman is : %s",teamPak[par1].player_name);
                                        Pakplayer_col3[par1]=1;
                                    }
                                }
                                else{ // if player 2 is out then new player will play at player 2 position
                                    scanf("%d",&par2);
                                    if(Pakplayer_col3[par2]==1){
                                        printf("Player already played cant play again.\nPlease enter DN Bat players: ");
                                        scanf("%d",&par2);
                                    }
                                    else{
                                        printf("New batsman is : %s",teamPak[par2].player_name);
                                        Pakplayer_col3[par2]=1;
                                    }
                                }
                                wickets++; // wickets are incremented by 1
                                if(wickets==10){
                                    printf("\n\t\t  |  PAK %d / %d  ||  %d / %d  |\n",tot_runs,wickets,tot_overs,over); // score board banner
                                    break;
                                }
                                printf("\n\t\t  |  PAK %d / %d  ||  %d / %d  |\n",tot_runs,wickets,tot_overs,over); // score board banner
                            }
                            // runs
                            else{
                                if(strike==1){ // player 1 runs are calculated
                                    Pakplayer_col1[par1]+=runs; // runs count
                                    Pakplayer_col2[par1]++; // balls count
                                    Pakplayer_col3[par1]=1;
                                    printf("\n\n%s * = %d,%d\t\t   %s = %d.%d\n^--->%s\t\t\t^--->%s",teamPak[par1].player_name,Pakplayer_col1[par1],Pakplayer_col2[par1],teamInd[bow].player_name,i,j,teamPak[par1].player_type,teamInd[bow].player_type);
                                    printf("\n\n%s = %d,%d\n^--->%s\n",teamPak[par2].player_name,Pakplayer_col1[par2],Pakplayer_col2[par2],teamPak[par2].player_type);
                                }
                                else{ // player 2 runs are calculated
                                    Pakplayer_col1[par2]+=runs; // runs count
                                    Pakplayer_col2[par2]++; // balls count
                                    Pakplayer_col3[par2]=1;
                                    printf("\n\n%s = %d,%d\t\t   %s = %d.%d\n^--->%s\t\t\t^--->%s",teamPak[par1].player_name,Pakplayer_col1[par1],Pakplayer_col2[par1],teamInd[bow].player_name,i,j,teamPak[par1].player_type,teamInd[bow].player_type);
                                    printf("\n\n%s * = %d,%d\n^--->%s\n",teamPak[par2].player_name,Pakplayer_col1[par2],Pakplayer_col2[par2],teamPak[par2].player_type);
                                }
                                over_runs+=runs; // overs runs count
                                tot_runs+=runs; // total runs count
                                if(runs%2==0){ // strike change after odd runs
                                    strike=(strike==1)?2:1;
                                }
                                printf("\n\t\t  |  PAK %d / %d  ||  %d / %d  |\n",tot_runs,wickets,tot_overs,over); // score board banner
                                if(strike==2){ // strike pointer
                                    printf("\n%s is on strike\n",teamPak[par1].player_name);
                                }
                                else{
                                    printf("\n%s is on strike\n",teamPak[par2].player_name);
                                }
                                printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                            }
                        }
                        strike=(strike==1||j==6)?2:1; // strike rotation after over finish.
                        printf("\n");
                        if(j==6&&i<over){
                            printf("\nTotal score from this over: %d runs with %d wickets.\n",over_runs,wickets);
                            printf("%s select next bowler:  ",teamInd[0].player_name); // bowler selection
                            scanf("%d",&bow);
                            if(Indplayer_col3[bow]==1){ // trigger for double player selection
                                printf("Player already bowled cant bawl again.\nPlease enter DN Bawl players: ");
                                scanf("%d",&bow);
                            }
                            over_runs=0;
                            tot_overs++; // overs count
                        }
                    }
                    target=tot_runs+1; // setting target
                    printf("\n%s  %d ,%d",teamPak[par1].player_name,Pakplayer_col1[par1],Pakplayer_col2[par1]);
                    printf("\n%s  %d ,%d",teamPak[par2].player_name,Pakplayer_col1[par2],Pakplayer_col2[par2]);
                }
                rr=(float)target/(float)(over*6); // run rate calculator
                printf("\nPakistan set target of %d runs.\nIndia Need avarage run rate of %.2f",target,rr);
                printf("\n\n\t\t|  Target %d  ||  RR %.2f  |\n\n",target,rr);
                printf("\n\n\t2nd Inning will start soon !...");
            }
            else if(desci2==2){
                // if PAKISTAN choose to bawl
                printf("\n%s selected to bawl first",teamPak[0].player_name);
                break;
            }
            else{
                printf("Select proper side");
            }
        }
    }
}