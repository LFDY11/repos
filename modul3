#include <conio.h>
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
 

 
 void main() 
 {
	int **a,*b;
	int i,j,n;
	cout<<"Vvedite razmernost matrisi: ";
	cin>>n;
	b=new int[n];
	cout<<"Vvod elementov matrisi: "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<'['<<i<<"]=";
		cin>>b[i];
	}
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[n];
	{

	for(j=0;j<n;j++)
	{
		
			for(i=0;i<n;i++)
			{
				if(i%2==0)
				a[i][j]=(int)pow(b[n-j-1], i+1);
				else a[i][j]=(int)pow(b[j], i+1);

			}

	
	}
	}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
					cout<<" "<<a[i][j];
					cout<<endl;
				}

}
