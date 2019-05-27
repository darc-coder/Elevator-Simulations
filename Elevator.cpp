//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																														//
//																														//
//Elevator Simulation.																									//
//Originally Written by: Ser Nitin Lakra. Dept. of CSE, NIT Rourkela.													//
//																														//
//																														//
//																														//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int init = 1, i=0, j=0, k=0, flag=1; //init is initial position of elevator //flag is 1 for going up '&' 0 for going down
	int per[15][2], pnt[15]={0}, tme=500; 
	
	srand(time(0));
	while(i<15)
	{
	int j=0;
		per[i][j]=rand()% 5 + 1;
			j++;
		per[i][j]=rand()% 10 + (-5);
			i++;
	}
	//lets see output
	cout<<"Initially 15 people 'position' & 'destination' matrix: "<<endl;
	while(k<15)
	{	
		if(per[k][1]>=0)
		cout<<"\t"<<k+1<<") "<<"\t\t"<<per[k][0]<<"\t     "<<per[k][1]<<endl;
		else
		cout<<"\t"<<k+1<<") "<<"\t\t"<<per[k][0]<<"\t    "<<per[k][1]<<endl;
		k++;
	}
	
	i=0; //resett
	
	//count up starts here
	if(flag==1)
	{
		cout<<"\nInitialy Elevetor Going UP ^ Direction: "<<endl<<endl;
		while(i<15)
		{
			j=0;
			while(j<15)
			{
				if(per[j][0]==init && per[j][1]>0 && per[j][0]+per[j][1]<6)
				{
					_sleep(tme); //can be changed to Sleep() as required
					cout<<"person "<<j+1<<" inside the lift"<<endl;
					per[j][1]--;
				}
				if(per[j][1]==0 && pnt[j]==0)
				{
					//cout<<"person "<<j+1<<" exited the lift"<<endl;
					pnt[j]=1;
				}
			j++;
			}
			init++;
		i++;
		}
		flag=0;	
	}
	cout<<"--------------------------------------------------------"<<endl;
	i=0; init--; //resetting values
	
	//count down starts here
	if(flag==0)
	{
		cout<<"\nCurently Elevetor Going DOWN v Direction: "<<endl<<endl;
		while(i<15)
		{
			j=0;
			while(j<15)
			{
				if(per[j][0]==init && per[j][1]<0 && per[j][0]+per[j][1]>0)
				{
					_sleep(tme); //can be changed to Sleep() as required
					cout<<"person "<<j+1<<" inside the lift"<<endl;
					per[j][1]++;
				}
			j++;
			}
			init--;
		i++;
		}
	flag=1;	
	}
}
